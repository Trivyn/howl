#ifndef SLOP_probe_H
#define SLOP_probe_H

#include "../runtime/slop_runtime.h"
#include <stdint.h>
#include <stdbool.h>
#include "slop_rdf.h"
#include "slop_vocab.h"
#include "slop_types.h"
#include "slop_canon.h"
#include "slop_termstore.h"
#include "slop_classify.h"

typedef struct probe_Query probe_Query;
typedef struct probe_Answered probe_Answered;
typedef struct probe_Probing probe_Probing;

typedef enum {
    probe_QueryKind_query_unsatisfiable,
    probe_QueryKind_query_subsumed
} probe_QueryKind;

typedef enum {
    probe_ProbeAnswer_answer_yes,
    probe_ProbeAnswer_answer_no,
    probe_ProbeAnswer_answer_unknown
} probe_ProbeAnswer;

#ifndef SLOP_OPTION_U8_DEFINED
#define SLOP_OPTION_U8_DEFINED
SLOP_OPTION_DEFINE(uint8_t, slop_option_u8)
#endif

#ifndef SLOP_LIST_TYPES_OMISSION_DEFINED
#define SLOP_LIST_TYPES_OMISSION_DEFINED
#define SLOP_LIST_TYPES_OMISSION_IMPL_DEFINED
SLOP_LIST_DEFINE(types_Omission, slop_list_types_Omission)
#endif

#ifndef SLOP_OPTION_TYPES_OMISSION_DEFINED
#define SLOP_OPTION_TYPES_OMISSION_DEFINED
SLOP_OPTION_DEFINE(types_Omission, slop_option_types_Omission)
#endif

struct probe_Query {
    probe_QueryKind kind;
    rdf_IRI sub;
    rdf_IRI sup;
};
typedef struct probe_Query probe_Query;

#ifndef SLOP_OPTION_PROBE_QUERY_DEFINED
#define SLOP_OPTION_PROBE_QUERY_DEFINED
SLOP_OPTION_DEFINE(probe_Query, slop_option_probe_Query)
#endif

#ifndef SLOP_LIST_PROBE_QUERY_DEFINED
#define SLOP_LIST_PROBE_QUERY_DEFINED
#define SLOP_LIST_PROBE_QUERY_IMPL_DEFINED
SLOP_LIST_DEFINE(probe_Query, slop_list_probe_Query)
#endif

struct probe_Answered {
    probe_Query query;
    probe_ProbeAnswer answer;
};
typedef struct probe_Answered probe_Answered;

#ifndef SLOP_OPTION_PROBE_ANSWERED_DEFINED
#define SLOP_OPTION_PROBE_ANSWERED_DEFINED
SLOP_OPTION_DEFINE(probe_Answered, slop_option_probe_Answered)
#endif

#ifndef SLOP_LIST_PROBE_ANSWERED_DEFINED
#define SLOP_LIST_PROBE_ANSWERED_DEFINED
#define SLOP_LIST_PROBE_ANSWERED_IMPL_DEFINED
SLOP_LIST_DEFINE(probe_Answered, slop_list_probe_Answered)
#endif

struct probe_Probing {
    slop_list_probe_Answered answers;
    uint8_t inconsistent;
    slop_list_types_Omission omissions;
};
typedef struct probe_Probing probe_Probing;

#ifndef SLOP_OPTION_PROBE_PROBING_DEFINED
#define SLOP_OPTION_PROBE_PROBING_DEFINED
SLOP_OPTION_DEFINE(probe_Probing, slop_option_probe_Probing)
#endif

int64_t probe_kind_rank(probe_QueryKind k);
int64_t probe_query_cmp(probe_Query a, probe_Query b);
probe_Query probe_query_at(slop_list_probe_Query qs, int64_t i);
slop_list_probe_Query probe_sort_queries(slop_arena* arena, slop_list_probe_Query qs);
termstore_Encoded* probe_probe_document(slop_arena* arena, termstore_Encoded main, termstore_Encoded probes, slop_list_probe_Query queries);
rdf_Triple probe_class_declaration(slop_arena* arena, rdf_IRI c);
slop_list_probe_Answered probe_answer_queries(slop_arena* arena, types_Outcome o, slop_list_probe_Query queries);
probe_ProbeAnswer probe_answer_of(types_Outcome o, probe_Query q);
rdf_IRI probe_query_target(probe_Query q);
slop_option_u8 probe_query_holds(types_Outcome o, probe_Query q);
slop_option_u8 probe_findings_hold(types_Findings f, rdf_IRI a, rdf_IRI b);
uint8_t probe_node_is(types_Node n, rdf_IRI i);
slop_option_u8 probe_el_holds(types_Saturation sat, types_Outcome o, rdf_IRI a, rdf_IRI b);
uint8_t probe_has_context(types_Saturation sat, types_Outcome o, types_Node n);
slop_option_u8 probe_ksc_holds(types_KscResult r, rdf_IRI a, rdf_IRI b);

#ifndef SLOP_OPTION_PROBE_QUERY_DEFINED
#define SLOP_OPTION_PROBE_QUERY_DEFINED
SLOP_OPTION_DEFINE(probe_Query, slop_option_probe_Query)
#endif

#ifndef SLOP_OPTION_PROBE_ANSWERED_DEFINED
#define SLOP_OPTION_PROBE_ANSWERED_DEFINED
SLOP_OPTION_DEFINE(probe_Answered, slop_option_probe_Answered)
#endif

#ifndef SLOP_OPTION_TYPES_OMISSION_DEFINED
#define SLOP_OPTION_TYPES_OMISSION_DEFINED
SLOP_OPTION_DEFINE(types_Omission, slop_option_types_Omission)
#endif

#ifndef SLOP_OPTION_PROBE_PROBING_DEFINED
#define SLOP_OPTION_PROBE_PROBING_DEFINED
SLOP_OPTION_DEFINE(probe_Probing, slop_option_probe_Probing)
#endif

#ifndef SLOP_OPTION_U8_DEFINED
#define SLOP_OPTION_U8_DEFINED
SLOP_OPTION_DEFINE(uint8_t, slop_option_u8)
#endif

#ifndef SLOP_OPTION_TYPES_CONTEXT_DEFINED
#define SLOP_OPTION_TYPES_CONTEXT_DEFINED
SLOP_OPTION_DEFINE(types_Context, slop_option_types_Context)
#endif


#endif
