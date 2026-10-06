#ifndef SLOP_howl_H
#define SLOP_howl_H

#include "../runtime/slop_runtime.h"
#include <stdint.h>
#include <stdbool.h>
#include "slop_rdf.h"
#include "slop_types.h"
#include "slop_normalize.h"
#include "slop_termstore.h"
#include "slop_select.h"
#include "slop_saturate.h"
#include "slop_classify.h"
#include "slop_gate.h"
#include "slop_kscnormal.h"
#include "slop_kscsat.h"
#include "slop_premise.h"

typedef struct howl_ElWork howl_ElWork;
typedef struct howl_KscWork howl_KscWork;
typedef struct howl_Work howl_Work;
typedef struct howl_Prepared howl_Prepared;

typedef enum {
    howl_Verdict_verdict_coherent,
    howl_Verdict_verdict_incoherent,
    howl_Verdict_verdict_inconclusive
} howl_Verdict;

#ifndef SLOP_LIST_TYPES_NORMAXIOM_DEFINED
#define SLOP_LIST_TYPES_NORMAXIOM_DEFINED
#define SLOP_LIST_TYPES_NORMAXIOM_IMPL_DEFINED
SLOP_LIST_DEFINE(types_NormAxiom, slop_list_types_NormAxiom)
#endif

#ifndef SLOP_LIST_TYPES_KSCAXIOM_DEFINED
#define SLOP_LIST_TYPES_KSCAXIOM_DEFINED
#define SLOP_LIST_TYPES_KSCAXIOM_IMPL_DEFINED
SLOP_LIST_DEFINE(types_KscAxiom, slop_list_types_KscAxiom)
#endif

#ifndef SLOP_LIST_TYPES_KNAME_DEFINED
#define SLOP_LIST_TYPES_KNAME_DEFINED
#define SLOP_LIST_TYPES_KNAME_IMPL_DEFINED
SLOP_LIST_DEFINE(types_KName, slop_list_types_KName)
#endif

#ifndef SLOP_LIST_RDF_TRIPLE_DEFINED
#define SLOP_LIST_RDF_TRIPLE_DEFINED
#define SLOP_LIST_RDF_TRIPLE_IMPL_DEFINED
SLOP_LIST_DEFINE(rdf_Triple, slop_list_rdf_Triple)
#endif

#ifndef SLOP_LIST_RDF_IRI_DEFINED
#define SLOP_LIST_RDF_IRI_DEFINED
#define SLOP_LIST_RDF_IRI_IMPL_DEFINED
SLOP_LIST_DEFINE(rdf_IRI, slop_list_rdf_IRI)
#endif

#ifndef SLOP_LIST_TYPES_OMISSION_DEFINED
#define SLOP_LIST_TYPES_OMISSION_DEFINED
#define SLOP_LIST_TYPES_OMISSION_IMPL_DEFINED
SLOP_LIST_DEFINE(types_Omission, slop_list_types_Omission)
#endif

#ifndef SLOP_OPTION_TYPES_NORMAXIOM_DEFINED
#define SLOP_OPTION_TYPES_NORMAXIOM_DEFINED
SLOP_OPTION_DEFINE(types_NormAxiom, slop_option_types_NormAxiom)
#endif

#ifndef SLOP_OPTION_TYPES_KSCAXIOM_DEFINED
#define SLOP_OPTION_TYPES_KSCAXIOM_DEFINED
SLOP_OPTION_DEFINE(types_KscAxiom, slop_option_types_KscAxiom)
#endif

#ifndef SLOP_OPTION_TYPES_KNAME_DEFINED
#define SLOP_OPTION_TYPES_KNAME_DEFINED
SLOP_OPTION_DEFINE(types_KName, slop_option_types_KName)
#endif

#ifndef SLOP_OPTION_RDF_TRIPLE_DEFINED
#define SLOP_OPTION_RDF_TRIPLE_DEFINED
SLOP_OPTION_DEFINE(rdf_Triple, slop_option_rdf_Triple)
#endif

#ifndef SLOP_OPTION_RDF_IRI_DEFINED
#define SLOP_OPTION_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(rdf_IRI, slop_option_rdf_IRI)
#endif

#ifndef SLOP_OPTION_TYPES_OMISSION_DEFINED
#define SLOP_OPTION_TYPES_OMISSION_DEFINED
SLOP_OPTION_DEFINE(types_Omission, slop_option_types_Omission)
#endif

struct howl_ElWork {
    slop_list_types_NormAxiom axioms;
    premise_RuleIndex index;
    types_Saturation saturation;
};
typedef struct howl_ElWork howl_ElWork;

#ifndef SLOP_OPTION_HOWL_ELWORK_DEFINED
#define SLOP_OPTION_HOWL_ELWORK_DEFINED
SLOP_OPTION_DEFINE(howl_ElWork, slop_option_howl_ElWork)
#endif

struct howl_KscWork {
    slop_list_types_KscAxiom axioms;
    slop_list_types_KName classes;
};
typedef struct howl_KscWork howl_KscWork;

#ifndef SLOP_OPTION_HOWL_KSCWORK_DEFINED
#define SLOP_OPTION_HOWL_KSCWORK_DEFINED
SLOP_OPTION_DEFINE(howl_KscWork, slop_option_howl_KscWork)
#endif

typedef enum {
    howl_Work_el_work,
    howl_Work_ksc_work
} howl_Work_tag;

struct howl_Work {
    howl_Work_tag tag;
    union {
        howl_ElWork el_work;
        howl_KscWork ksc_work;
    } data;
};
typedef struct howl_Work howl_Work;

#ifndef SLOP_OPTION_HOWL_WORK_DEFINED
#define SLOP_OPTION_HOWL_WORK_DEFINED
SLOP_OPTION_DEFINE(howl_Work, slop_option_howl_Work)
#endif

struct howl_Prepared {
    types_Profile profile;
    howl_Work work;
    types_Coverage coverage;
    types_Names names;
};
typedef struct howl_Prepared howl_Prepared;

#ifndef SLOP_OPTION_HOWL_PREPARED_DEFINED
#define SLOP_OPTION_HOWL_PREPARED_DEFINED
SLOP_OPTION_DEFINE(howl_Prepared, slop_option_howl_Prepared)
#endif

#ifndef SLOP_RESULT_NORMALIZE_DECODED_TYPES_FAULT_DEFINED
#define SLOP_RESULT_NORMALIZE_DECODED_TYPES_FAULT_DEFINED
typedef struct { bool is_ok; union { normalize_Decoded ok; types_Fault err; } data; } slop_result_normalize_Decoded_types_Fault;
#endif

#ifndef SLOP_RESULT_HOWL_PREPARED_TYPES_FAULT_DEFINED
#define SLOP_RESULT_HOWL_PREPARED_TYPES_FAULT_DEFINED
typedef struct { bool is_ok; union { howl_Prepared ok; types_Fault err; } data; } slop_result_howl_Prepared_types_Fault;
#endif

#ifndef SLOP_RESULT_TYPES_OUTCOME_TYPES_FAULT_DEFINED
#define SLOP_RESULT_TYPES_OUTCOME_TYPES_FAULT_DEFINED
typedef struct { bool is_ok; union { types_Outcome ok; types_Fault err; } data; } slop_result_types_Outcome_types_Fault;
#endif

howl_Verdict howl_verdict(types_Outcome o);
slop_result_normalize_Decoded_types_Fault howl_decode(slop_arena* arena, slop_list_rdf_Triple triples, slop_list_rdf_IRI imports_resolved);
slop_result_normalize_Decoded_types_Fault howl_decode_from(slop_arena* arena, termstore_Encoded doc, slop_list_rdf_IRI imports_resolved);
slop_result_normalize_Decoded_types_Fault howl_own_decoded(slop_arena* arena, slop_result_normalize_Decoded_types_Fault r);
slop_result_normalize_Decoded_types_Fault howl_decode_owned(slop_arena* arena, slop_list_rdf_Triple triples, slop_list_rdf_IRI imports_resolved);
slop_result_howl_Prepared_types_Fault howl_prepare_decoded(slop_arena* arena, normalize_Decoded d, types_ReasonerConfig config);
int64_t howl_out_of_profile_count(slop_list_types_Omission oms);
types_Profile howl_auto_profile(normalize_Decoded d);
slop_result_howl_Prepared_types_Fault howl_prepare_in_profile(slop_arena* arena, normalize_Decoded d, types_ReasonerConfig config, types_Profile profile);
uint8_t howl_strict_refuses(types_ReasonerConfig config, types_Coverage cov);
slop_result_howl_Prepared_types_Fault howl_prepare_el(slop_arena* arena, normalize_Decoded d, types_ReasonerConfig config, types_Profile profile);
slop_result_howl_Prepared_types_Fault howl_prepare_ksc(slop_arena* arena, normalize_Decoded d, types_ReasonerConfig config, types_Profile profile);
slop_list_types_KName howl_copy_knames(slop_arena* arena, slop_list_types_KName ns);
slop_result_howl_Prepared_types_Fault howl_prepare(slop_arena* arena, slop_list_rdf_Triple triples, slop_list_rdf_IRI imports_resolved, types_ReasonerConfig config);
slop_result_types_Outcome_types_Fault howl_reason(slop_arena* arena, howl_Prepared p, types_ReasonerConfig config);
slop_result_types_Outcome_types_Fault howl_classify(slop_arena* arena, slop_list_rdf_Triple triples, slop_list_rdf_IRI imports_resolved, types_ReasonerConfig config);
void howl_release_outcome(types_Outcome o);
slop_result_howl_Prepared_types_Fault howl_prepare_encoded(slop_arena* arena, termstore_Encoded doc, slop_list_rdf_IRI imports_resolved, types_ReasonerConfig config);
slop_result_types_Outcome_types_Fault howl_classify_encoded(slop_arena* arena, termstore_Encoded doc, slop_list_rdf_IRI imports_resolved, types_ReasonerConfig config);

#ifndef SLOP_OPTION_TYPES_NORMAXIOM_DEFINED
#define SLOP_OPTION_TYPES_NORMAXIOM_DEFINED
SLOP_OPTION_DEFINE(types_NormAxiom, slop_option_types_NormAxiom)
#endif

#ifndef SLOP_OPTION_HOWL_ELWORK_DEFINED
#define SLOP_OPTION_HOWL_ELWORK_DEFINED
SLOP_OPTION_DEFINE(howl_ElWork, slop_option_howl_ElWork)
#endif

#ifndef SLOP_OPTION_TYPES_KSCAXIOM_DEFINED
#define SLOP_OPTION_TYPES_KSCAXIOM_DEFINED
SLOP_OPTION_DEFINE(types_KscAxiom, slop_option_types_KscAxiom)
#endif

#ifndef SLOP_OPTION_TYPES_KNAME_DEFINED
#define SLOP_OPTION_TYPES_KNAME_DEFINED
SLOP_OPTION_DEFINE(types_KName, slop_option_types_KName)
#endif

#ifndef SLOP_OPTION_HOWL_KSCWORK_DEFINED
#define SLOP_OPTION_HOWL_KSCWORK_DEFINED
SLOP_OPTION_DEFINE(howl_KscWork, slop_option_howl_KscWork)
#endif

#ifndef SLOP_OPTION_HOWL_WORK_DEFINED
#define SLOP_OPTION_HOWL_WORK_DEFINED
SLOP_OPTION_DEFINE(howl_Work, slop_option_howl_Work)
#endif

#ifndef SLOP_OPTION_HOWL_PREPARED_DEFINED
#define SLOP_OPTION_HOWL_PREPARED_DEFINED
SLOP_OPTION_DEFINE(howl_Prepared, slop_option_howl_Prepared)
#endif

#ifndef SLOP_OPTION_RDF_TRIPLE_DEFINED
#define SLOP_OPTION_RDF_TRIPLE_DEFINED
SLOP_OPTION_DEFINE(rdf_Triple, slop_option_rdf_Triple)
#endif

#ifndef SLOP_OPTION_RDF_IRI_DEFINED
#define SLOP_OPTION_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(rdf_IRI, slop_option_rdf_IRI)
#endif

#ifndef SLOP_OPTION_TYPES_OMISSION_DEFINED
#define SLOP_OPTION_TYPES_OMISSION_DEFINED
SLOP_OPTION_DEFINE(types_Omission, slop_option_types_Omission)
#endif

#ifndef SLOP_OPTION_ARENA_PTR_DEFINED
#define SLOP_OPTION_ARENA_PTR_DEFINED
SLOP_OPTION_DEFINE(slop_arena*, slop_option_arena_ptr)
#endif

#ifndef SLOP_LIST_ARENA_PTR_DEFINED
#define SLOP_LIST_ARENA_PTR_DEFINED
#define SLOP_LIST_ARENA_PTR_IMPL_DEFINED
SLOP_LIST_DEFINE(slop_arena*, slop_list_arena_ptr)
#endif


#endif
