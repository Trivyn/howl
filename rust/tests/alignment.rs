use howl::{AlignmentInput, CancelToken, Fault, Reasoner, RepairOptions, Verdict};

const PREFIXES: &str = r#"
@prefix : <http://example.org/align#> .
@prefix owl: <http://www.w3.org/2002/07/owl#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .
"#;
const FIXED_SOURCE: &str = "http://example.org/source/fixed";
const MAPPING_SOURCE: &str = "http://example.org/source/mappings";

fn conflicting_input() -> AlignmentInput {
    let mut input = AlignmentInput::new();
    input
        .add_fixed_turtle(
            FIXED_SOURCE,
            &format!("{PREFIXES} :A a owl:Class . :B a owl:Class . :C a owl:Class . :A owl:disjointWith :B ."),
        )
        .unwrap();
    input
        .add_mapping_turtle(
            MAPPING_SOURCE,
            &format!("{PREFIXES} :C rdfs:subClassOf :A . :C rdfs:subClassOf :B ."),
        )
        .unwrap();
    input
}

#[test]
fn returns_the_entire_ordered_minimal_repair_family() {
    let input = conflicting_input();
    let reasoner = Reasoner::new();

    let check_only = reasoner.align(&input, None).unwrap();
    assert_eq!(check_only.merged.verdict, Verdict::Incoherent);
    assert!(check_only.repair.is_none());

    let with_repair = reasoner
        .align(&input, Some(RepairOptions::default()))
        .unwrap();
    assert_eq!(with_repair.merged.verdict, Verdict::Incoherent);
    let search = with_repair.repair.unwrap();
    assert!(search.complete, "search did not finish: {search:?}");
    assert!(!search.already_coherent);
    assert!(!search.unrepairable_by_mappings);
    assert!(search.candidates.is_empty());
    assert_eq!(search.mappings.len(), 2);
    assert!(search.mappings.iter().all(|m| m.source == MAPPING_SOURCE));
    assert!(search.mappings[0].text < search.mappings[1].text);
    assert_eq!(
        search.repairs,
        vec![
            vec![search.mappings[0].clone()],
            vec![search.mappings[1].clone()]
        ]
    );
}

#[test]
fn coherent_and_unrepairable_are_distinct_terminal_results() {
    let mut coherent = AlignmentInput::new();
    coherent
        .add_fixed_turtle(FIXED_SOURCE, &format!("{PREFIXES} :A a owl:Class ."))
        .unwrap();
    let report = Reasoner::new()
        .align(&coherent, Some(RepairOptions::default()))
        .unwrap();
    let search = report.repair.unwrap();
    assert_eq!(report.merged.verdict, Verdict::Coherent);
    assert!(search.complete && search.already_coherent);
    assert!(!search.unrepairable_by_mappings);
    assert!(search.repairs.is_empty());

    let mut unrepairable = AlignmentInput::new();
    unrepairable
        .add_fixed_turtle(
            FIXED_SOURCE,
            &format!("{PREFIXES} :A a owl:Class . :A rdfs:subClassOf owl:Nothing ."),
        )
        .unwrap();
    unrepairable
        .add_mapping_turtle(MAPPING_SOURCE, &format!("{PREFIXES} :B a owl:Class ."))
        .unwrap();
    let report = Reasoner::new()
        .align(&unrepairable, Some(RepairOptions::default()))
        .unwrap();
    let search = report.repair.unwrap();
    assert_eq!(report.merged.verdict, Verdict::Incoherent);
    assert!(search.unrepairable_by_mappings);
    assert!(!search.already_coherent);
    assert!(search.repairs.is_empty());
}

#[test]
fn cancellation_is_a_fault_without_a_partial_repair() {
    let token = CancelToken::new();
    token.cancel();
    let result = Reasoner::new().align_cancellable(
        &conflicting_input(),
        Some(RepairOptions::default()),
        &token,
    );
    assert!(matches!(result, Err(Fault::Cancelled)), "{result:?}");
}

#[test]
fn capped_search_does_not_claim_all_repairs() {
    let limits = RepairOptions {
        conflict_calls: 0,
        ..RepairOptions::default()
    };
    let report = Reasoner::new()
        .align(&conflicting_input(), Some(limits))
        .unwrap();
    assert_eq!(report.merged.verdict, Verdict::Incoherent);
    let search = report.repair.unwrap();
    assert!(!search.complete);
    assert!(search.phases.conflicts.capped);
}

#[test]
fn alignment_sources_must_be_absolute_and_distinct() {
    let mut input = AlignmentInput::new();
    assert!(matches!(
        input.add_fixed_turtle("relative/source", &format!("{PREFIXES} :A a owl:Class .")),
        Err(Fault::InputError(_))
    ));

    let mut input = AlignmentInput::new();
    input
        .add_fixed_turtle(FIXED_SOURCE, &format!("{PREFIXES} :A a owl:Class ."))
        .unwrap();
    assert!(matches!(
        input.add_mapping_turtle(FIXED_SOURCE, &format!("{PREFIXES} :B a owl:Class .")),
        Err(Fault::InputError(_))
    ));
}
