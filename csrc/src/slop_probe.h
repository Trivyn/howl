#ifndef SLOP_probe_H
#define SLOP_probe_H

#include "../runtime/slop_runtime.h"
#ifndef SLOP_RUNTIME_ABI
#error "this module was generated for SLOP runtime ABI 2026-1 (SLOP_RUNTIME_ABI 202601), but slop_runtime.h predates runtime ABI versioning: use the slop_runtime.h of the SLOP release that generated this code"
#elif SLOP_RUNTIME_ABI != 202601
#error "this module was generated for SLOP runtime ABI 2026-1 (SLOP_RUNTIME_ABI 202601), which this slop_runtime.h does not provide (SLOP_RUNTIME_ABI differs): regenerate the C with the SLOP release that matches the runtime, or use the slop_runtime.h of the release that generated it"
#endif
#include <stdint.h>
#include <stdbool.h>
#include "slop_rdf.h"
#include "slop_vocab.h"
#include "slop_types.h"
#include "slop_canon.h"
#include "slop_termstore.h"
#include "slop_classify.h"

typedef struct howl_probe_Query howl_probe_Query;
typedef struct howl_probe_Answered howl_probe_Answered;
typedef struct howl_probe_Probing howl_probe_Probing;

typedef enum {
    howl_probe_QueryKind_query_unsatisfiable,
    howl_probe_QueryKind_query_subsumed
} howl_probe_QueryKind;

typedef enum {
    howl_probe_ProbeAnswer_answer_yes,
    howl_probe_ProbeAnswer_answer_no,
    howl_probe_ProbeAnswer_answer_unknown
} howl_probe_ProbeAnswer;

#ifndef SLOP_OPTION_U8_DEFINED
#define SLOP_OPTION_U8_DEFINED
SLOP_OPTION_DEFINE(uint8_t, slop_option_u8)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_OMISSION_DEFINED
#define SLOP_LIST_HOWL_TYPES_OMISSION_DEFINED
#define SLOP_LIST_HOWL_TYPES_OMISSION_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_Omission, slop_list_howl_types_Omission)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_OMISSION_DEFINED
#define SLOP_OPTION_HOWL_TYPES_OMISSION_DEFINED
SLOP_OPTION_DEFINE(howl_types_Omission, slop_option_howl_types_Omission)
#endif

struct howl_probe_Query {
    howl_probe_QueryKind kind;
    slop_rdf_rdf_IRI sub;
    slop_rdf_rdf_IRI sup;
};
typedef struct howl_probe_Query howl_probe_Query;

#ifndef SLOP_OPTION_HOWL_PROBE_QUERY_DEFINED
#define SLOP_OPTION_HOWL_PROBE_QUERY_DEFINED
SLOP_OPTION_DEFINE(howl_probe_Query, slop_option_howl_probe_Query)
#endif

#ifndef SLOP_LIST_HOWL_PROBE_QUERY_DEFINED
#define SLOP_LIST_HOWL_PROBE_QUERY_DEFINED
#define SLOP_LIST_HOWL_PROBE_QUERY_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_probe_Query, slop_list_howl_probe_Query)
#endif

struct howl_probe_Answered {
    howl_probe_Query query;
    howl_probe_ProbeAnswer answer;
};
typedef struct howl_probe_Answered howl_probe_Answered;

#ifndef SLOP_OPTION_HOWL_PROBE_ANSWERED_DEFINED
#define SLOP_OPTION_HOWL_PROBE_ANSWERED_DEFINED
SLOP_OPTION_DEFINE(howl_probe_Answered, slop_option_howl_probe_Answered)
#endif

#ifndef SLOP_LIST_HOWL_PROBE_ANSWERED_DEFINED
#define SLOP_LIST_HOWL_PROBE_ANSWERED_DEFINED
#define SLOP_LIST_HOWL_PROBE_ANSWERED_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_probe_Answered, slop_list_howl_probe_Answered)
#endif

struct howl_probe_Probing {
    slop_list_howl_probe_Answered answers;
    uint8_t inconsistent;
    slop_list_howl_types_Omission omissions;
    howl_types_Profile profile;
    slop_list_int origins;
    int64_t input_docs;
    int64_t probe_docs;
};
typedef struct howl_probe_Probing howl_probe_Probing;

#ifndef SLOP_OPTION_HOWL_PROBE_PROBING_DEFINED
#define SLOP_OPTION_HOWL_PROBE_PROBING_DEFINED
SLOP_OPTION_DEFINE(howl_probe_Probing, slop_option_howl_probe_Probing)
#endif

int64_t howl_probe_kind_rank(howl_probe_QueryKind k);
int64_t howl_probe_query_cmp(howl_probe_Query a, howl_probe_Query b);
howl_probe_Query howl_probe_query_at(slop_list_howl_probe_Query qs, int64_t i);
slop_list_howl_probe_Query howl_probe_sort_queries(slop_arena* arena, slop_list_howl_probe_Query qs);
howl_termstore_Encoded* howl_probe_probe_document(slop_arena* arena, howl_termstore_Encoded main, howl_termstore_Encoded probes, slop_list_howl_probe_Query queries);
slop_rdf_rdf_Triple howl_probe_class_declaration(slop_arena* arena, slop_rdf_rdf_IRI c);
slop_list_howl_probe_Answered howl_probe_answer_queries(slop_arena* arena, howl_types_Outcome o, slop_list_howl_probe_Query queries);
howl_probe_ProbeAnswer howl_probe_answer_of(howl_types_Outcome o, howl_probe_Query q);
slop_rdf_rdf_IRI howl_probe_query_target(howl_probe_Query q);
slop_option_u8 howl_probe_query_holds(howl_types_Outcome o, howl_probe_Query q);
slop_option_u8 howl_probe_findings_hold(howl_types_Findings f, slop_rdf_rdf_IRI a, slop_rdf_rdf_IRI b);
uint8_t howl_probe_node_is(howl_types_Node n, slop_rdf_rdf_IRI i);
slop_option_u8 howl_probe_el_holds(howl_types_Saturation sat, howl_types_Outcome o, slop_rdf_rdf_IRI a, slop_rdf_rdf_IRI b);
uint8_t howl_probe_has_context(howl_types_Saturation sat, howl_types_Outcome o, howl_types_Node n);
slop_option_u8 howl_probe_ksc_holds(howl_types_KscResult r, slop_rdf_rdf_IRI a, slop_rdf_rdf_IRI b);

#ifndef SLOP_OPTION_HOWL_PROBE_QUERY_DEFINED
#define SLOP_OPTION_HOWL_PROBE_QUERY_DEFINED
SLOP_OPTION_DEFINE(howl_probe_Query, slop_option_howl_probe_Query)
#endif

#ifndef SLOP_OPTION_HOWL_PROBE_ANSWERED_DEFINED
#define SLOP_OPTION_HOWL_PROBE_ANSWERED_DEFINED
SLOP_OPTION_DEFINE(howl_probe_Answered, slop_option_howl_probe_Answered)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_OMISSION_DEFINED
#define SLOP_OPTION_HOWL_TYPES_OMISSION_DEFINED
SLOP_OPTION_DEFINE(howl_types_Omission, slop_option_howl_types_Omission)
#endif

#ifndef SLOP_OPTION_HOWL_PROBE_PROBING_DEFINED
#define SLOP_OPTION_HOWL_PROBE_PROBING_DEFINED
SLOP_OPTION_DEFINE(howl_probe_Probing, slop_option_howl_probe_Probing)
#endif

#ifndef SLOP_OPTION_U8_DEFINED
#define SLOP_OPTION_U8_DEFINED
SLOP_OPTION_DEFINE(uint8_t, slop_option_u8)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_CONTEXT_DEFINED
#define SLOP_OPTION_HOWL_TYPES_CONTEXT_DEFINED
SLOP_OPTION_DEFINE(howl_types_Context, slop_option_howl_types_Context)
#endif


#endif
