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
fn an_unbuilt_profile_is_refused_by_name() {
    let config = Config { selection: ProfileSelection::Explicit(Profile::Sriq), ..Config::default() };
    match Reasoner::with_config(config).classify(&turtle(UNSAT_TTL)) {
        Err(Fault::ProfileUnavailable(Profile::Sriq)) => {}
        other => panic!("expected ProfileUnavailable(Sriq), got {other:?}"),
    }
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
/// count, on both built rungs.
#[test]
fn reports_are_identical_across_worker_counts() {
    let input = turtle(&fixture("imports/root.ttl"));
    for p in [Profile::El, Profile::ElPlusPlus] {
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
