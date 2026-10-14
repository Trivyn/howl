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
