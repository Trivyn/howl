//! The binding's own behaviour: triples built in Rust, faults, imports,
//! cancellation, worker counts, and threads.

use howl::{CancelToken, Config, Fault, Input, Profile, ProfileSelection, Reasoner, Report, Term, Termination, Verdict};
use std::fs;
use std::path::Path;

const RDF_TYPE: &str = "http://www.w3.org/1999/02/22-rdf-syntax-ns#type";
const RDFS_SUBCLASS: &str = "http://www.w3.org/2000/01/rdf-schema#subClassOf";
const RDFS_LABEL: &str = "http://www.w3.org/2000/01/rdf-schema#label";
const OWL_CLASS: &str = "http://www.w3.org/2002/07/owl#Class";
const OWL_NOTHING: &str = "http://www.w3.org/2002/07/owl#Nothing";
const EX: &str = "http://example.org/t#";

fn ex(n: &str) -> Term {
    Term::iri(format!("{EX}{n}"))
}

fn fixture(rel: &str) -> String {
    let p = Path::new(env!("CARGO_MANIFEST_DIR")).join("../corpus/fixtures").join(rel);
    fs::read_to_string(&p).unwrap_or_else(|e| panic!("{}: {e}", p.display()))
}

fn turtle(text: &str) -> Input {
    let mut input = Input::new();
    input.add_turtle(text).unwrap();
    input
}

fn classify_with(input: &Input, config: Config) -> Report {
    Reasoner::with_config(config).classify(input).unwrap()
}

/// A ⊑ B, B ⊑ ⊥, built as Rust terms, literals included.
fn unsat_triples() -> Vec<(Term, Term, Term)> {
    let ty = Term::iri(RDF_TYPE);
    let sub = Term::iri(RDFS_SUBCLASS);
    vec![
        (ex("A"), ty.clone(), Term::iri(OWL_CLASS)),
        (ex("B"), ty, Term::iri(OWL_CLASS)),
        (ex("A"), sub.clone(), ex("B")),
        (ex("B"), sub, Term::iri(OWL_NOTHING)),
        (
            ex("A"),
            Term::iri(RDFS_LABEL),
            Term::Literal { value: "A".into(), datatype: None, lang: Some("en".into()) },
        ),
    ]
}

const UNSAT_TTL: &str = r#"
@prefix : <http://example.org/t#> .
@prefix owl: <http://www.w3.org/2002/07/owl#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .
:A a owl:Class . :B a owl:Class .
:A rdfs:subClassOf :B . :B rdfs:subClassOf owl:Nothing .
:A rdfs:label "A"@en .
"#;

#[test]
fn rust_built_triples_classify() {
    let mut input = Input::new();
    input.add_triples(&unsat_triples());
    let r = Reasoner::new().classify(&input).unwrap();
    assert_eq!(r.verdict, Verdict::Incoherent);
    assert_eq!(r.profile, Profile::El);
    assert!(!r.inconsistent);
    assert_eq!(r.unsatisfiable, vec![format!("{EX}A"), format!("{EX}B")]);
    assert_eq!(r.termination, Termination::Fixpoint);
    assert!(r.omissions.is_empty(), "{:?}", r.omissions);
}

/// The same ontology as Rust terms and as Turtle gives the same report.
#[test]
fn triples_and_turtle_agree() {
    let mut a = Input::new();
    a.add_triples(&unsat_triples());
    let b = turtle(UNSAT_TTL);
    let r = Reasoner::new();
    assert_eq!(r.classify(&a).unwrap(), r.classify(&b).unwrap());
}

/// The report's lists are its lines, not a second rendering.
#[test]
fn fields_match_the_report_lines() {
    let r = classify_with(&turtle(&fixture("imports/root.ttl")), Config::default());
    let lines = r.lines();
    let subs: Vec<String> = r.subsumptions.iter().map(|(a, b)| format!("sub {a} {b}")).collect();
    let oms: Vec<String> = r.omissions.iter().map(|o| format!("omission {o}")).collect();
    assert!(subs.iter().all(|s| lines.contains(s)));
    assert!(oms.iter().all(|o| lines.contains(o)));
    assert!(lines.contains(&format!("subsumptions {}", r.subsumptions.len())));
    assert!(lines.contains(&format!("rounds {}", r.rounds)));
}

const ROOT: &str = r#"
@prefix owl: <http://www.w3.org/2002/07/owl#> .
<http://example.org/root> a owl:Ontology ; owl:imports <http://example.org/imp> .
<http://example.org/t#A> a owl:Class .
"#;
const IMP: &str = r#"
@prefix owl: <http://www.w3.org/2002/07/owl#> .
<http://example.org/imp> a owl:Ontology .
<http://example.org/t#B> a owl:Class .
"#;

/// An unattested import is a coverage gap — inconclusive, never a pass —
/// and the attestation is what closes it.
#[test]
fn imports_need_attestation() {
    let mut input = turtle(ROOT);
    input.add_turtle(IMP).unwrap();
    let r = Reasoner::new().classify(&input).unwrap();
    assert_eq!(r.verdict, Verdict::Inconclusive);
    assert_eq!(r.omissions.len(), 1, "{:?}", r.omissions);

    input.attest_import("http://example.org/imp");
    let r = Reasoner::new().classify(&input).unwrap();
    assert_eq!(r.verdict, Verdict::Coherent, "{:?}", r.omissions);
}

/// An undeclared property is an omission naming it (issue #70): the run
/// goes on and reads the rest, but is inconclusive, never a pass.
#[test]
fn an_undeclared_property_is_an_omission() {
    let r = Reasoner::new().classify(&turtle(&fixture("hazards/undeclared-property.ttl"))).unwrap();
    assert_eq!(r.verdict, Verdict::Inconclusive);
    assert_eq!(
        r.omissions,
        vec![
            format!("UndeclaredProperty({EX}editorNote)"),
            format!("UndeclaredProperty({EX}p)"),
        ]
    );
    assert!(r.subsumptions.iter().any(|(s, t)| s == &format!("{EX}B") && t == &format!("{EX}A")));
}

/// Each detail is its plain omission's text, with that text's head token
/// as its kind.
fn assert_details_agree(texts: &[String], details: &[howl::Omission]) {
    assert_eq!(details.len(), texts.len());
    for (t, d) in texts.iter().zip(details) {
        assert_eq!(&d.text, t);
        assert_eq!(d.kind, t[..t.find('(').unwrap()]);
        assert_eq!(d.entity_kind.is_some(), d.kind == "MissingDeclaration", "{d:?}");
    }
}

/// `(document, text)` for each detail, for comparing in one assertion.
fn placed(details: &[howl::Omission]) -> Vec<(Option<howl::Document>, &str)> {
    details.iter().map(|d| (d.document, d.text.as_str())).collect()
}

const PREFIXES: &str = r#"
@prefix : <http://example.org/t#> .
@prefix owl: <http://www.w3.org/2002/07/owl#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .
"#;

/// Issue #67: a background ontology and the host's own document. Each
/// omission names the document that introduced it, a blank node's
/// included (HasKey's list, rendered as its triples), so the host can
/// tell its own coverage gaps from the background's in one run.
#[test]
fn omissions_name_the_document_they_came_from() {
    let background = format!(
        "{PREFIXES}
        :A a owl:Class . :B a owl:Class . :C a owl:Class . :p a owl:ObjectProperty .
        :A rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :p ; owl:allValuesFrom :B ] .
        :A owl:hasKey ( :p ) ."
    );
    let own = format!(
        "{PREFIXES}
        <http://example.org/own> a owl:Ontology ; owl:imports <http://example.org/elsewhere> .
        :B rdfs:subClassOf [ owl:unionOf ( :A :C ) ] .
        :C owl:hasKey ( :p ) .
        :A :q :B ."
    );
    let mut input = turtle(&background);
    input.add_turtle(&own).unwrap();
    let r = Reasoner::new().classify(&input).unwrap();
    assert_details_agree(&r.omissions, r.omission_details());

    use howl::Document::Input as Doc;
    let p = |n: &str| format!("<{EX}{n}>");
    let has_key_0 = format!("HasKey({} <http://www.w3.org/2002/07/owl#hasKey> _:b1 .)", p("A"));
    let has_key_1 = format!("HasKey({} <http://www.w3.org/2002/07/owl#hasKey> _:b5 .)", p("C"));
    let all_0 = format!("SubClassOf({EX}A ObjectAllValuesFrom({EX}p {EX}B))");
    let union_1 = format!("SubClassOf({EX}B ObjectUnionOf({EX}A {EX}C))");
    let import_1 = "UnresolvedImport(http://example.org/elsewhere)".to_string();
    let undeclared_1 = format!("UndeclaredProperty({EX}q)");
    assert_eq!(
        placed(r.omission_details()),
        vec![
            (Some(Doc(0)), has_key_0.as_str()),
            (Some(Doc(1)), has_key_1.as_str()),
            (Some(Doc(0)), all_0.as_str()),
            (Some(Doc(1)), union_1.as_str()),
            (Some(Doc(1)), import_1.as_str()),
            (Some(Doc(1)), undeclared_1.as_str()),
        ]
    );
    // The report is the one a run without provenance prints.
    assert_eq!(r.lines().iter().filter(|l| l.starts_with("omission ")).count(), 6);
}

/// A MissingDeclaration names its entity's kind, and its document when
/// every axiom citing it is from one; cited from two, it has none.
#[test]
fn a_missing_declaration_names_its_entity_kind() {
    let first = format!("{PREFIXES} :A a owl:Class . :A rdfs:subClassOf :Z .");
    let second = format!("{PREFIXES} :B a owl:Class . :B rdfs:subClassOf :Y . :B rdfs:subClassOf :Z .");
    let mut input = turtle(&first);
    input.add_turtle(&second).unwrap();
    let r = Reasoner::new().classify(&input).unwrap();
    assert_details_agree(&r.omissions, r.omission_details());
    let got: Vec<_> = r.omission_details().iter().map(|d| (d.entity_kind, d.document, d.text.as_str())).collect();
    use howl::{Document::Input as Doc, EntityKind};
    let (y, z) = (format!("MissingDeclaration(Class({EX}Y))"), format!("MissingDeclaration(Class({EX}Z))"));
    assert_eq!(
        got,
        vec![(Some(EntityKind::Class), Some(Doc(1)), y.as_str()), (Some(EntityKind::Class), None, z.as_str())]
    );
}

/// The same axiom stated in two documents: el keeps both copies, one per
/// document; sriq keeps it once, and it takes the first document.
#[test]
fn an_axiom_in_two_documents_is_placed_by_each_copy() {
    let doc = format!(
        "{PREFIXES} :A a owl:Class . :B a owl:Class . :p a owl:ObjectProperty .
        :A rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :p ; owl:allValuesFrom :B ] .
        :A owl:equivalentClass [ owl:oneOf ( :i :j ) ] . :i a owl:NamedIndividual . :j a owl:NamedIndividual ."
    );
    let mut input = turtle(&doc);
    input.add_turtle(&doc).unwrap();
    use howl::Document::Input as Doc;
    let el = classify_with(&input, Config { selection: ProfileSelection::Explicit(Profile::El), ..Config::default() });
    assert_details_agree(&el.omissions, el.omission_details());
    let docs: Vec<_> = el.omission_details().iter().map(|d| d.document).collect();
    assert_eq!(docs, [0, 1, 0, 1, 0, 1].map(|n| Some(Doc(n))));
    let sriq = classify_with(&input, Config { selection: ProfileSelection::Explicit(Profile::Sriq), ..Config::default() });
    assert_details_agree(&sriq.omissions, sriq.omission_details());
    // `A ≡ {i, j}` is two inclusions; sriq omits only the nominal halves.
    let docs: Vec<_> = sriq.omission_details().iter().map(|d| d.document).collect();
    assert_eq!(docs, [Some(Doc(0)), Some(Doc(0))]);
}

/// One document: every omission is from it.
#[test]
fn a_single_document_owns_every_omission() {
    let r = Reasoner::new().classify(&turtle(&fixture("hazards/undeclared-property.ttl"))).unwrap();
    assert_details_agree(&r.omissions, r.omission_details());
    assert!(!r.omissions.is_empty());
    assert!(r.omission_details().iter().all(|d| d.document == Some(howl::Document::Input(0))));
    assert!(r.probe_omission_details().is_empty());
}

/// The probe run's omissions name their document among the input's or
/// among the probe documents, in classify's report and in an answer run.
#[test]
fn probe_document_omissions_are_attributed_as_probe() {
    let main = format!(
        "{PREFIXES} :A a owl:Class . :C a owl:Class .
        :A rdfs:subClassOf [ owl:unionOf ( :A :C ) ] ."
    );
    let mut input = turtle(&format!("{PREFIXES} :D a owl:Class ."));
    input.add_turtle(&main).unwrap();
    input.add_probe_turtle(&format!("{PREFIXES} <urn:probe:1> rdfs:subClassOf :A .")).unwrap();
    input.add_probe_turtle(&format!("{PREFIXES} <urn:probe:2> rdfs:subClassOf [ owl:unionOf ( :A :C ) ] .")).unwrap();
    input.ask_unsatisfiable("urn:probe:2");
    let config = Config { selection: ProfileSelection::Explicit(Profile::El), ..Config::default() };
    let r = classify_with(&input, config);
    assert_details_agree(&r.omissions, r.omission_details());
    assert_details_agree(&r.probe_omissions, r.probe_omission_details());
    use howl::Document::{Input as Doc, Probe};
    assert_eq!(r.omission_details().iter().map(|d| d.document).collect::<Vec<_>>(), [Some(Doc(1))]);
    assert_eq!(
        placed(r.probe_omission_details()),
        vec![
            (Some(Doc(1)), format!("SubClassOf({EX}A ObjectUnionOf({EX}A {EX}C))").as_str()),
            (Some(Probe(1)), "SubClassOf(urn:probe:2 ObjectUnionOf(http://example.org/t#A http://example.org/t#C))"),
            // Not asked about, so not declared for the probe run.
            (Some(Probe(0)), "MissingDeclaration(Class(urn:probe:1))"),
        ]
    );
    // The answer run is answered by urn:probe:2's module, which holds both
    // unions but not urn:probe:1's axiom, so not its missing declaration
    // either. Each omission keeps the document the two-run mode gives it.
    let a = Reasoner::with_config(config).answer(&input).unwrap();
    assert_details_agree(&a.omissions, a.omission_details());
    assert_eq!(a.omission_details(), &r.probe_omission_details()[..2]);
}

/// 0.6.1: a background document and the host's own, whose class carries
/// a datatype restriction no rung reads. The answer run answers from the
/// class's module and does not classify the background: its one omission
/// is the host's, in document 1, not the background's in document 0. A
/// `yes` from the read axioms stands beside it.
#[test]
fn an_omission_no_rung_reads_keeps_the_answer_on_the_module() {
    use howl::Answer;
    const DATA: &str = "@prefix xsd: <http://www.w3.org/2001/XMLSchema#> .";
    let background = format!(
        "{PREFIXES} {DATA} :B a owl:Class . :X a owl:Class . :code a owl:DatatypeProperty .
        :X rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :code ;
            owl:maxQualifiedCardinality \"1\"^^xsd:nonNegativeInteger ; owl:onDataRange xsd:string ] ."
    );
    let host = format!(
        "{PREFIXES} {DATA} :A a owl:Class . :name a owl:DatatypeProperty .
        :A rdfs:subClassOf :B , [ a owl:Restriction ; owl:onProperty :name ;
            owl:maxQualifiedCardinality \"1\"^^xsd:nonNegativeInteger ; owl:onDataRange xsd:string ] ."
    );
    let mut input = turtle(&background);
    input.add_turtle(&host).unwrap();
    input.ask_unsatisfiable(&format!("{EX}A"));
    input.ask_subsumed(&format!("{EX}A"), &format!("{EX}B"));
    for selection in [ProfileSelection::Auto, ProfileSelection::Explicit(Profile::El), ProfileSelection::Explicit(Profile::Sriq)] {
        let a = Reasoner::with_config(Config { selection, ..Config::default() }).answer(&input).unwrap();
        let answers: Vec<_> = a.probes.iter().map(|p| p.answer).collect();
        assert_eq!(answers, [Answer::Unknown, Answer::Yes], "{selection:?}");
        assert_details_agree(&a.omissions, a.omission_details());
        let d = &a.omission_details()[..];
        assert_eq!(d.len(), 1, "{selection:?}: {:?}", a.omissions);
        assert_eq!((d[0].kind.as_str(), d[0].document), ("SubClassOf", Some(howl::Document::Input(1))), "{selection:?}");
        assert!(d[0].text.contains(&format!("{EX}name")), "{selection:?}: {}", d[0].text);
    }
}

/// Issue #68: whether `:p` can have a value, asked through a probe class
/// the host never has to declare, filter out or re-verdict. `:p`'s two
/// domains are disjoint, so it cannot; `:q` can.
#[test]
fn probes_are_answered_apart_from_the_report() {
    let main = r#"
        @prefix : <http://example.org/t#> .
        @prefix owl: <http://www.w3.org/2002/07/owl#> .
        @prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .
        :p a owl:ObjectProperty . :q a owl:ObjectProperty .
        :D a owl:Class . :E a owl:Class . :D owl:disjointWith :E .
        :p rdfs:domain :D , :E .
    "#;
    let probes = r#"
        @prefix : <http://example.org/t#> .
        @prefix owl: <http://www.w3.org/2002/07/owl#> .
        @prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .
        <urn:probe:p> rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :p ; owl:someValuesFrom owl:Thing ] .
        <urn:probe:q> rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :q ; owl:someValuesFrom owl:Thing ] .
    "#;
    let mut input = turtle(main);
    let plain = Reasoner::new().classify(&input).unwrap();
    input.add_probe_turtle(probes).unwrap();
    input.ask_unsatisfiable("urn:probe:q");
    input.ask_unsatisfiable("urn:probe:p");
    input.ask_subsumed("urn:probe:p", &format!("{EX}D"));
    let r = Reasoner::new().classify(&input).unwrap();

    use howl::{Answer, ProbeAnswer, Query};
    assert_eq!(
        r.probes,
        vec![
            ProbeAnswer { query: Query::Unsatisfiable("urn:probe:p".into()), answer: Answer::Yes },
            ProbeAnswer { query: Query::Unsatisfiable("urn:probe:q".into()), answer: Answer::No },
            ProbeAnswer { query: Query::Subsumed("urn:probe:p".into(), format!("{EX}D")), answer: Answer::Yes },
        ]
    );
    assert!(!r.probe_inconsistent);
    assert!(r.probe_omissions.is_empty());
    // The main run is the run without probes, line for line.
    assert_eq!(r.verdict, Verdict::Coherent);
    assert_eq!((&r.unsatisfiable, &r.subsumptions, &r.omissions), (&plain.unsatisfiable, &plain.subsumptions, &plain.omissions));
    assert_eq!(&r.lines()[..plain.lines().len()], plain.lines());
    assert_eq!(r.lines()[plain.lines().len()], "probes 3");
    assert!(plain.probes.is_empty());
}

/// The answer run (SPEC §8.4): the same answers as `classify`'s probe
/// run, under every profile, with no main run and no report.
#[test]
fn answer_gives_classify_probe_answers_alone() {
    let main = r#"
        @prefix : <http://example.org/t#> .
        @prefix owl: <http://www.w3.org/2002/07/owl#> .
        @prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .
        :p a owl:ObjectProperty . :q a owl:ObjectProperty .
        :D a owl:Class . :E a owl:Class . :D owl:disjointWith :E .
        :p rdfs:domain :D , :E .
    "#;
    let probes = r#"
        @prefix : <http://example.org/t#> .
        @prefix owl: <http://www.w3.org/2002/07/owl#> .
        @prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .
        <urn:probe:p> rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :p ; owl:someValuesFrom owl:Thing ] .
        <urn:probe:q> rdfs:subClassOf [ a owl:Restriction ; owl:onProperty :q ; owl:someValuesFrom owl:Thing ] .
    "#;
    let mut input = turtle(main);
    let nothing = Reasoner::new().answer(&input).unwrap();
    assert_eq!((nothing.profile, nothing.probes.len()), (None, 0));
    input.add_probe_turtle(probes).unwrap();
    input.ask_unsatisfiable("urn:probe:q");
    input.ask_unsatisfiable("urn:probe:p");
    input.ask_subsumed("urn:probe:p", &format!("{EX}D"));
    for p in [Profile::El, Profile::ElPlusPlus, Profile::Sriq] {
        let config = Config { selection: ProfileSelection::Explicit(p), ..Config::default() };
        let r = Reasoner::with_config(config).classify(&input).unwrap();
        let a = Reasoner::with_config(config).answer(&input).unwrap();
        assert_eq!(a.profile, Some(p));
        assert_eq!((&a.probes, a.inconsistent, &a.omissions), (&r.probes, r.probe_inconsistent, &r.probe_omissions));
        // `profile P`, then exactly the probe lines classify prints after its report.
        let tail = &r.lines()[r.lines().iter().position(|l| l.starts_with("probes ")).unwrap()..];
        assert_eq!(&a.lines()[0], r.lines().iter().find(|l| l.starts_with("profile ")).unwrap());
        assert_eq!(&a.lines()[1..], tail);
    }
}

#[test]
fn bad_turtle_is_an_input_error_and_poisons_the_input() {
    let mut input = Input::new();
    match input.add_turtle("<http://example.org/a> <http://example.org/b> .") {
        Err(Fault::InputError(m)) => assert!(m.contains("line"), "{m}"),
        other => panic!("expected an input error, got {other:?}"),
    }
    match Reasoner::new().classify(&input) {
        Err(Fault::InputError(_)) => {}
        other => panic!("a poisoned input classified: {other:?}"),
    }
}

#[test]
fn an_empty_input_is_coherent() {
    let r = Reasoner::new().classify(&Input::new()).unwrap();
    assert_eq!(r.verdict, Verdict::Coherent);
    let r = Reasoner::new().classify(&turtle("")).unwrap();
    assert_eq!(r.verdict, Verdict::Coherent);
}

#[test]
fn sriq_runs_as_asked() {
    let config = Config { selection: ProfileSelection::Explicit(Profile::Sriq), ..Config::default() };
    let r = classify_with(&turtle(UNSAT_TTL), config);
    assert_eq!(r.profile, Profile::Sriq);
    assert_eq!(r.verdict, classify_with(&turtle(UNSAT_TTL), Config::default()).verdict);
}

/// A union is outside el and el++ and inside sriq, so auto runs sriq.
#[test]
fn auto_chooses_sriq_for_a_union() {
    let config = Config { selection: ProfileSelection::Auto, ..Config::default() };
    let r = classify_with(&turtle(&fixture("out-of-profile/union.ttl")), config);
    assert_eq!(r.profile, Profile::Sriq);
    assert_eq!(r.verdict, Verdict::Coherent);
}

#[test]
#[allow(deprecated)]
fn the_dropped_profile_is_refused() {
    let config = Config { selection: ProfileSelection::Explicit(Profile::HornSriq), ..Config::default() };
    match Reasoner::with_config(config).classify(&turtle(UNSAT_TTL)) {
        Err(f @ Fault::ProfileUnavailable(Profile::HornSriq)) => {
            assert_eq!(f.to_string(), "profile horn-sriq was dropped; sriq covers its language")
        }
        other => panic!("expected ProfileUnavailable(HornSriq), got {other:?}"),
    }
}

#[test]
fn auto_names_the_rung_that_ran() {
    let config = Config { selection: ProfileSelection::Auto, ..Config::default() };
    let r = classify_with(&turtle(UNSAT_TTL), config);
    assert_eq!(r.profile, Profile::El);
}

/// An answer run is cancelled as a classify run is: no answers, at any cap.
#[test]
fn a_cancelled_answer_run_answers_nothing() {
    let cancel = CancelToken::new();
    cancel.cancel();
    let mut input = turtle(&fixture("v0/litmus.ttl"));
    input.ask_subsumed(&format!("{EX}Mother"), &format!("{EX}Parent"));
    for cap in [1000, 0] {
        let config = Config { max_iterations: cap, ..Config::default() };
        match Reasoner::with_config(config).answer_cancellable(&input, &cancel) {
            Err(Fault::Cancelled) => {}
            other => panic!("cap {cap}: expected Cancelled, got {other:?}"),
        }
    }
    // An unset token changes nothing.
    let fresh = CancelToken::new();
    assert_eq!(Reasoner::new().answer_cancellable(&input, &fresh).unwrap(), Reasoner::new().answer(&input).unwrap());
}

/// Under `Auto`, the answer run names the profile that answered, chosen for
/// its module (SPEC §8.4): a query the probe document's union touches runs
/// under sriq, one it does not runs under el, while the two-run mode's probe
/// run takes sriq for both and the main run stays in el.
#[test]
fn answer_under_auto_names_the_profile_that_answered() {
    let config = Config { selection: ProfileSelection::Auto, ..Config::default() };
    for (sub, sup, want) in [("C", "A", Profile::Sriq), ("Mother", "Parent", Profile::El)] {
        let mut input = turtle(&fixture("v0/litmus.ttl"));
        input.add_probe_turtle(&fixture("out-of-profile/union.ttl")).unwrap();
        input.ask_subsumed(&format!("{EX}{sub}"), &format!("{EX}{sup}"));
        let r = Reasoner::with_config(config).classify(&input).unwrap();
        let a = Reasoner::with_config(config).answer(&input).unwrap();
        assert_eq!((r.profile, a.profile), (Profile::El, Some(want)), "{sub} ⊑ {sup}");
        assert_eq!((&a.probes, a.inconsistent), (&r.probes, r.probe_inconsistent), "{sub} ⊑ {sup}");
    }
}

#[test]
fn a_cancelled_run_returns_no_report() {
    let cancel = CancelToken::new();
    cancel.cancel();
    let input = turtle(&fixture("imports/root.ttl"));
    match Reasoner::new().classify_cancellable(&input, &cancel) {
        Err(Fault::Cancelled) => {}
        other => panic!("expected Cancelled, got {other:?}"),
    }
    // An unset token changes nothing.
    let fresh = CancelToken::new();
    assert_eq!(
        Reasoner::new().classify_cancellable(&input, &fresh).unwrap(),
        Reasoner::new().classify(&input).unwrap()
    );
}

#[test]
fn a_round_cap_is_inconclusive() {
    let config = Config { max_iterations: 0, ..Config::default() };
    let r = classify_with(&turtle(&fixture("imports/root.ttl")), config);
    assert_eq!(r.termination, Termination::ResourceLimit(0));
    assert_eq!(r.verdict, Verdict::Inconclusive);
}

/// M1 (e) at the binding: the report is identical at every worker
/// count, on every built rung.
#[test]
fn reports_are_identical_across_worker_counts() {
    let input = turtle(&fixture("imports/root.ttl"));
    for p in [Profile::El, Profile::ElPlusPlus, Profile::Sriq] {
        let at = |w: u8| {
            classify_with(&input, Config { worker_count: w, selection: ProfileSelection::Explicit(p), ..Config::default() })
        };
        let one = at(1);
        for w in [2, 4, 8] {
            assert_eq!(at(w), one, "{} at W={w}", p.name());
        }
    }
}

/// Classifying reads the input and does not consume it.
#[test]
fn an_input_classifies_again_unchanged() {
    let input = turtle(&fixture("imports/root.ttl"));
    let r = Reasoner::new();
    assert_eq!(r.classify(&input).unwrap(), r.classify(&input).unwrap());
}

#[test]
fn concurrent_runs_on_separate_inputs_agree() {
    let text = fixture("imports/root.ttl");
    let want = Reasoner::new().classify(&turtle(&text)).unwrap();
    let handles: Vec<_> = (0..4)
        .map(|_| {
            let text = text.clone();
            std::thread::spawn(move || Reasoner::new().classify(&turtle(&text)).unwrap())
        })
        .collect();
    for h in handles {
        assert_eq!(h.join().unwrap(), want);
    }
}

#[test]
fn thread_safety_is_what_a_host_needs() {
    fn send<T: Send>() {}
    fn sync<T: Sync>() {}
    send::<Reasoner>();
    sync::<Reasoner>();
    send::<Report>();
    sync::<Report>();
    send::<Input>();
    send::<CancelToken>();
    sync::<CancelToken>();
}
