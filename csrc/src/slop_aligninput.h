#ifndef SLOP_aligninput_H
#define SLOP_aligninput_H

#include "../runtime/slop_runtime.h"
#ifndef SLOP_RUNTIME_ABI
#error "this module was generated for SLOP runtime ABI 2026-1 (SLOP_RUNTIME_ABI 202601), but slop_runtime.h predates runtime ABI versioning: use the slop_runtime.h of the SLOP release that generated this code"
#elif SLOP_RUNTIME_ABI != 202601
#error "this module was generated for SLOP runtime ABI 2026-1 (SLOP_RUNTIME_ABI 202601), which this slop_runtime.h does not provide (SLOP_RUNTIME_ABI differs): regenerate the C with the SLOP release that matches the runtime, or use the slop_runtime.h of the release that generated it"
#endif
#include <stdint.h>
#include <stdbool.h>
#include "slop_rdf.h"
#include "slop_termstore.h"
#include "slop_types.h"
#include "slop_owl2.h"
#include "slop_decode.h"
#include "slop_normalize.h"
#include "slop_canon.h"
#include "slop_strlib.h"

typedef struct howl_aligninput_AlignmentBase howl_aligninput_AlignmentBase;

#ifndef SLOP_LIST_U8_DEFINED
#define SLOP_LIST_U8_DEFINED
#define SLOP_LIST_U8_IMPL_DEFINED
SLOP_LIST_DEFINE(uint8_t, slop_list_u8)
#endif

#ifndef SLOP_OPTION_U8_DEFINED
#define SLOP_OPTION_U8_DEFINED
SLOP_OPTION_DEFINE(uint8_t, slop_option_u8)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_AXIOMREF_DEFINED
#define SLOP_LIST_HOWL_TYPES_AXIOMREF_DEFINED
#define SLOP_LIST_HOWL_TYPES_AXIOMREF_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_AxiomRef, slop_list_howl_types_AxiomRef)
#endif

#ifndef SLOP_LIST_HOWL_OWL2_RAWCONCEPT_DEFINED
#define SLOP_LIST_HOWL_OWL2_RAWCONCEPT_DEFINED
#define SLOP_LIST_HOWL_OWL2_RAWCONCEPT_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_owl2_RawConcept, slop_list_howl_owl2_RawConcept)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_ROLEID_DEFINED
#define SLOP_LIST_HOWL_TYPES_ROLEID_DEFINED
#define SLOP_LIST_HOWL_TYPES_ROLEID_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_RoleId, slop_list_howl_types_RoleId)
#endif

#ifndef SLOP_LIST_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_LIST_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_LIST_SLOP_RDF_RDF_IRI_IMPL_DEFINED
SLOP_LIST_DEFINE(slop_rdf_rdf_IRI, slop_list_slop_rdf_rdf_IRI)
#endif

#ifndef SLOP_LIST_HOWL_TERMSTORE_IDTRIPLE_DEFINED
#define SLOP_LIST_HOWL_TERMSTORE_IDTRIPLE_DEFINED
#define SLOP_LIST_HOWL_TERMSTORE_IDTRIPLE_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_termstore_IdTriple, slop_list_howl_termstore_IdTriple)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_AXIOMREF_DEFINED
#define SLOP_OPTION_HOWL_TYPES_AXIOMREF_DEFINED
SLOP_OPTION_DEFINE(howl_types_AxiomRef, slop_option_howl_types_AxiomRef)
#endif

#ifndef SLOP_OPTION_HOWL_OWL2_RAWCONCEPT_DEFINED
#define SLOP_OPTION_HOWL_OWL2_RAWCONCEPT_DEFINED
SLOP_OPTION_DEFINE(howl_owl2_RawConcept, slop_option_howl_owl2_RawConcept)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_ROLEID_DEFINED
#define SLOP_OPTION_HOWL_TYPES_ROLEID_DEFINED
SLOP_OPTION_DEFINE(howl_types_RoleId, slop_option_howl_types_RoleId)
#endif

#ifndef SLOP_OPTION_HOWL_OWL2_RAWAXIOM_DEFINED
#define SLOP_OPTION_HOWL_OWL2_RAWAXIOM_DEFINED
SLOP_OPTION_DEFINE(howl_owl2_RawAxiom, slop_option_howl_owl2_RawAxiom)
#endif

#ifndef SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_IRI, slop_option_slop_rdf_rdf_IRI)
#endif

#ifndef SLOP_OPTION_HOWL_TERMSTORE_IDTRIPLE_DEFINED
#define SLOP_OPTION_HOWL_TERMSTORE_IDTRIPLE_DEFINED
SLOP_OPTION_DEFINE(howl_termstore_IdTriple, slop_option_howl_termstore_IdTriple)
#endif

struct howl_aligninput_AlignmentBase {
    howl_decode_Stage0 stage;
    howl_owl2_Signature signature;
    int64_t documents;
    slop_list_howl_types_AxiomRef mappings;
    slop_map* anchors;
    slop_list_u8 scaffolds;
    slop_map* negative_roots;
    slop_list_u8 negative_parts;
    slop_map* owned;
};
typedef struct howl_aligninput_AlignmentBase howl_aligninput_AlignmentBase;

#ifndef SLOP_OPTION_HOWL_ALIGNINPUT_ALIGNMENTBASE_DEFINED
#define SLOP_OPTION_HOWL_ALIGNINPUT_ALIGNMENTBASE_DEFINED
SLOP_OPTION_DEFINE(howl_aligninput_AlignmentBase, slop_option_howl_aligninput_AlignmentBase)
#endif

#ifndef SLOP_RESULT_HOWL_ALIGNINPUT_ALIGNMENTBASE_HOWL_TYPES_FAULT_DEFINED
#define SLOP_RESULT_HOWL_ALIGNINPUT_ALIGNMENTBASE_HOWL_TYPES_FAULT_DEFINED
typedef struct { bool is_ok; union { howl_aligninput_AlignmentBase ok; howl_types_Fault err; } data; } slop_result_howl_aligninput_AlignmentBase_howl_types_Fault;
#endif

#ifndef SLOP_RESULT_HOWL_NORMALIZE_DECODED_HOWL_TYPES_FAULT_DEFINED
#define SLOP_RESULT_HOWL_NORMALIZE_DECODED_HOWL_TYPES_FAULT_DEFINED
typedef struct { bool is_ok; union { howl_normalize_Decoded ok; howl_types_Fault err; } data; } slop_result_howl_normalize_Decoded_howl_types_Fault;
#endif

int64_t howl_aligninput_int_at(slop_list_int xs, int64_t i);
uint8_t howl_aligninput_bool_at(slop_list_u8 xs, int64_t i);
slop_string howl_aligninput_ref_key(slop_arena* arena, howl_types_AxiomRef r);
uint8_t howl_aligninput_concept_usable(howl_owl2_RawConcept c);
uint8_t howl_aligninput_concepts_usable(slop_list_howl_owl2_RawConcept cs);
howl_owl2_RawConcept howl_aligninput_canonical_concept(slop_arena* arena, howl_owl2_RawConcept c);
slop_list_howl_owl2_RawConcept howl_aligninput_append_operands(slop_arena* arena, slop_list_howl_owl2_RawConcept cs, uint8_t flatten, uint8_t conjunction);
howl_types_RoleId howl_aligninput_role_at(slop_list_howl_types_RoleId rs, int64_t i);
slop_list_howl_types_RoleId howl_aligninput_sort_roles(slop_arena* arena, slop_list_howl_types_RoleId rs);
slop_list_howl_owl2_RawConcept howl_aligninput_canonical_concepts(slop_arena* arena, slop_list_howl_owl2_RawConcept cs, uint8_t flatten, uint8_t conjunction);
slop_option_howl_owl2_RawAxiom howl_aligninput_canonical_mapping_axiom(slop_arena* arena, howl_owl2_RawAxiom ax);
uint8_t howl_aligninput_ascii_letter(int64_t c);
uint8_t howl_aligninput_source_iri_valid(slop_string s);
uint8_t howl_aligninput_metadata_problem(slop_list_slop_rdf_rdf_IRI sources, slop_list_u8 mapping_docs, int64_t documents);
slop_result_howl_aligninput_AlignmentBase_howl_types_Fault howl_aligninput_alignment_base(slop_arena* arena, howl_termstore_Encoded doc, slop_list_slop_rdf_rdf_IRI imports, slop_list_slop_rdf_rdf_IRI sources, slop_list_u8 mapping_docs);
howl_aligninput_AlignmentBase howl_aligninput_inventory(slop_arena* arena, howl_decode_Stage0 stage, howl_decode_Stage1 decoded, slop_list_slop_rdf_rdf_IRI sources, slop_list_u8 mapping_docs);
slop_map* howl_aligninput_live_negative(slop_arena* arena, slop_list_howl_termstore_IdTriple triples, slop_map* anchors, slop_map* removed, slop_map* roots);
slop_map* howl_aligninput_reachable(slop_arena* arena, slop_list_howl_termstore_IdTriple triples, slop_list_u8 scaffolds, slop_map* anchors, slop_map* removed, slop_map* negative_live, slop_list_u8 negative_parts);
slop_result_howl_normalize_Decoded_howl_types_Fault howl_aligninput_subset_decoded(slop_arena* arena, howl_aligninput_AlignmentBase base, slop_list_int removed);
slop_result_howl_normalize_Decoded_howl_types_Fault howl_aligninput_subset_with(slop_arena* arena, howl_aligninput_AlignmentBase base, slop_map* gone);

#ifndef SLOP_OPTION_HOWL_TYPES_AXIOMREF_DEFINED
#define SLOP_OPTION_HOWL_TYPES_AXIOMREF_DEFINED
SLOP_OPTION_DEFINE(howl_types_AxiomRef, slop_option_howl_types_AxiomRef)
#endif

#ifndef SLOP_OPTION_U8_DEFINED
#define SLOP_OPTION_U8_DEFINED
SLOP_OPTION_DEFINE(uint8_t, slop_option_u8)
#endif

#ifndef SLOP_OPTION_HOWL_ALIGNINPUT_ALIGNMENTBASE_DEFINED
#define SLOP_OPTION_HOWL_ALIGNINPUT_ALIGNMENTBASE_DEFINED
SLOP_OPTION_DEFINE(howl_aligninput_AlignmentBase, slop_option_howl_aligninput_AlignmentBase)
#endif

#ifndef SLOP_OPTION_HOWL_OWL2_RAWCONCEPT_DEFINED
#define SLOP_OPTION_HOWL_OWL2_RAWCONCEPT_DEFINED
SLOP_OPTION_DEFINE(howl_owl2_RawConcept, slop_option_howl_owl2_RawConcept)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_ROLEID_DEFINED
#define SLOP_OPTION_HOWL_TYPES_ROLEID_DEFINED
SLOP_OPTION_DEFINE(howl_types_RoleId, slop_option_howl_types_RoleId)
#endif

#ifndef SLOP_OPTION_HOWL_OWL2_RAWAXIOM_DEFINED
#define SLOP_OPTION_HOWL_OWL2_RAWAXIOM_DEFINED
SLOP_OPTION_DEFINE(howl_owl2_RawAxiom, slop_option_howl_owl2_RawAxiom)
#endif

#ifndef SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_IRI, slop_option_slop_rdf_rdf_IRI)
#endif

#ifndef SLOP_OPTION_HOWL_TERMSTORE_IDTRIPLE_DEFINED
#define SLOP_OPTION_HOWL_TERMSTORE_IDTRIPLE_DEFINED
SLOP_OPTION_DEFINE(howl_termstore_IdTriple, slop_option_howl_termstore_IdTriple)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_OMISSION_DEFINED
#define SLOP_OPTION_HOWL_TYPES_OMISSION_DEFINED
SLOP_OPTION_DEFINE(howl_types_Omission, slop_option_howl_types_Omission)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_OMISSION_DEFINED
#define SLOP_LIST_HOWL_TYPES_OMISSION_DEFINED
#define SLOP_LIST_HOWL_TYPES_OMISSION_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_Omission, slop_list_howl_types_Omission)
#endif


#endif
