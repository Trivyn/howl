#ifndef SLOP_test_H
#define SLOP_test_H

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
#include "slop_vocab.h"
#include "slop_decode.h"
#include "slop_gate.h"
#include "slop_normalize.h"
#include "slop_owl2.h"
#include "slop_ttl.h"
#include "slop_sroiq.h"
#include "slop_sriqnormal.h"
#include "slop_sriqelim.h"
#include "slop_sriqnames.h"
#include "slop_sroiqfss.h"
#include "slop_sriqclauses.h"
#include "slop_sriqsubsume.h"
#include "slop_sriq.h"
#include "slop_sriqground.h"
#include "slop_sriqctx.h"
#include "slop_sriqref.h"
#include "slop_sriqsat.h"
#include "slop_sriqabox.h"
#include "slop_sriqindex.h"
#include "slop_sriqorder.h"
#include "slop_file.h"
#include "slop_types.h"
#include "slop_canon.h"
#include "slop_saturate.h"
#include "slop_classify.h"
#include "slop_howl.h"
#include "slop_el.h"
#include "slop_probe.h"
#include "slop_locality.h"
#include "slop_premise.h"
#include "slop_report.h"
#include "slop_strlib.h"
#include "slop_select.h"
#include "slop_kscnormal.h"
#include "slop_kscsat.h"
#include "slop_ksc.h"
#include "slop_kscids.h"
#include "slop_kscpremise.h"
#include "slop_kscnames.h"
#include <string.h>

typedef struct howl_test_Expect howl_test_Expect;
typedef struct howl_test_ProtoCase howl_test_ProtoCase;
typedef struct howl_test_RoundAt howl_test_RoundAt;
typedef struct howl_test_KscFixture howl_test_KscFixture;
typedef struct howl_test_RunAs howl_test_RunAs;

#ifndef SLOP_LIST_U8_DEFINED
#define SLOP_LIST_U8_DEFINED
#define SLOP_LIST_U8_IMPL_DEFINED
SLOP_LIST_DEFINE(uint8_t, slop_list_u8)
#endif

#ifndef SLOP_LIST_U32_DEFINED
#define SLOP_LIST_U32_DEFINED
#define SLOP_LIST_U32_IMPL_DEFINED
SLOP_LIST_DEFINE(uint32_t, slop_list_u32)
#endif

#ifndef SLOP_OPTION_U32_DEFINED
#define SLOP_OPTION_U32_DEFINED
SLOP_OPTION_DEFINE(uint32_t, slop_option_u32)
#endif

#ifndef SLOP_OPTION_U8_DEFINED
#define SLOP_OPTION_U8_DEFINED
SLOP_OPTION_DEFINE(uint8_t, slop_option_u8)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_NODE_DEFINED
#define SLOP_LIST_HOWL_TYPES_NODE_DEFINED
#define SLOP_LIST_HOWL_TYPES_NODE_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_Node, slop_list_howl_types_Node)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_NORMAXIOM_DEFINED
#define SLOP_LIST_HOWL_TYPES_NORMAXIOM_DEFINED
#define SLOP_LIST_HOWL_TYPES_NORMAXIOM_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_NormAxiom, slop_list_howl_types_NormAxiom)
#endif

#ifndef SLOP_LIST_SLOP_RDF_RDF_TRIPLE_DEFINED
#define SLOP_LIST_SLOP_RDF_RDF_TRIPLE_DEFINED
#define SLOP_LIST_SLOP_RDF_RDF_TRIPLE_IMPL_DEFINED
SLOP_LIST_DEFINE(slop_rdf_rdf_Triple, slop_list_slop_rdf_rdf_Triple)
#endif

#ifndef SLOP_LIST_HOWL_OWL2_RAWAXIOM_DEFINED
#define SLOP_LIST_HOWL_OWL2_RAWAXIOM_DEFINED
#define SLOP_LIST_HOWL_OWL2_RAWAXIOM_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_owl2_RawAxiom, slop_list_howl_owl2_RawAxiom)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_AXIOMREF_DEFINED
#define SLOP_LIST_HOWL_TYPES_AXIOMREF_DEFINED
#define SLOP_LIST_HOWL_TYPES_AXIOMREF_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_AxiomRef, slop_list_howl_types_AxiomRef)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_OMISSION_DEFINED
#define SLOP_LIST_HOWL_TYPES_OMISSION_DEFINED
#define SLOP_LIST_HOWL_TYPES_OMISSION_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_Omission, slop_list_howl_types_Omission)
#endif

#ifndef SLOP_LIST_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_LIST_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_LIST_SLOP_RDF_RDF_IRI_IMPL_DEFINED
SLOP_LIST_DEFINE(slop_rdf_rdf_IRI, slop_list_slop_rdf_rdf_IRI)
#endif

#ifndef SLOP_LIST_HOWL_SROIQ_SAXIOM_DEFINED
#define SLOP_LIST_HOWL_SROIQ_SAXIOM_DEFINED
#define SLOP_LIST_HOWL_SROIQ_SAXIOM_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sroiq_SAxiom, slop_list_howl_sroiq_SAxiom)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_DLCLAUSE_DEFINED
#define SLOP_LIST_HOWL_TYPES_DLCLAUSE_DEFINED
#define SLOP_LIST_HOWL_TYPES_DLCLAUSE_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_DlClause, slop_list_howl_types_DlClause)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_LIT_DEFINED
#define SLOP_LIST_HOWL_TYPES_LIT_DEFINED
#define SLOP_LIST_HOWL_TYPES_LIT_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_Lit, slop_list_howl_types_Lit)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_DNAME_DEFINED
#define SLOP_LIST_HOWL_TYPES_DNAME_DEFINED
#define SLOP_LIST_HOWL_TYPES_DNAME_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_DName, slop_list_howl_types_DName)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_DROLE_DEFINED
#define SLOP_LIST_HOWL_TYPES_DROLE_DEFINED
#define SLOP_LIST_HOWL_TYPES_DROLE_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_DRole, slop_list_howl_types_DRole)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_ATERM_DEFINED
#define SLOP_LIST_HOWL_TYPES_ATERM_DEFINED
#define SLOP_LIST_HOWL_TYPES_ATERM_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_ATerm, slop_list_howl_types_ATerm)
#endif

#ifndef SLOP_LIST_HOWL_SRIQORDER_CTERM_DEFINED
#define SLOP_LIST_HOWL_SRIQORDER_CTERM_DEFINED
#define SLOP_LIST_HOWL_SRIQORDER_CTERM_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sriqorder_CTerm, slop_list_howl_sriqorder_CTerm)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_CLAUSE_DEFINED
#define SLOP_LIST_HOWL_TYPES_CLAUSE_DEFINED
#define SLOP_LIST_HOWL_TYPES_CLAUSE_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_Clause, slop_list_howl_types_Clause)
#endif

#ifndef SLOP_LIST_HOWL_SRIQ_PREMISE_DEFINED
#define SLOP_LIST_HOWL_SRIQ_PREMISE_DEFINED
#define SLOP_LIST_HOWL_SRIQ_PREMISE_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sriq_Premise, slop_list_howl_sriq_Premise)
#endif

#ifndef SLOP_LIST_HOWL_SRIQ_CANDS_DEFINED
#define SLOP_LIST_HOWL_SRIQ_CANDS_DEFINED
#define SLOP_LIST_HOWL_SRIQ_CANDS_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sriq_Cands, slop_list_howl_sriq_Cands)
#endif

#ifndef SLOP_LIST_HOWL_SRIQ_SUCCSIG_DEFINED
#define SLOP_LIST_HOWL_SRIQ_SUCCSIG_DEFINED
#define SLOP_LIST_HOWL_SRIQ_SUCCSIG_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sriq_SuccSig, slop_list_howl_sriq_SuccSig)
#endif

#ifndef SLOP_LIST_HOWL_SRIQCTX_STRATEGY_DEFINED
#define SLOP_LIST_HOWL_SRIQCTX_STRATEGY_DEFINED
#define SLOP_LIST_HOWL_SRIQCTX_STRATEGY_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sriqctx_Strategy, slop_list_howl_sriqctx_Strategy)
#endif

#ifndef SLOP_LIST_HOWL_SRIQCTX_EDGE_DEFINED
#define SLOP_LIST_HOWL_SRIQCTX_EDGE_DEFINED
#define SLOP_LIST_HOWL_SRIQCTX_EDGE_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sriqctx_Edge, slop_list_howl_sriqctx_Edge)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_SUBPAIR_DEFINED
#define SLOP_LIST_HOWL_TYPES_SUBPAIR_DEFINED
#define SLOP_LIST_HOWL_TYPES_SUBPAIR_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_SubPair, slop_list_howl_types_SubPair)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_KSCAXIOM_DEFINED
#define SLOP_LIST_HOWL_TYPES_KSCAXIOM_DEFINED
#define SLOP_LIST_HOWL_TYPES_KSCAXIOM_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_KscAxiom, slop_list_howl_types_KscAxiom)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_KNAME_DEFINED
#define SLOP_LIST_HOWL_TYPES_KNAME_DEFINED
#define SLOP_LIST_HOWL_TYPES_KNAME_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_KName, slop_list_howl_types_KName)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_KFACT_DEFINED
#define SLOP_LIST_HOWL_TYPES_KFACT_DEFINED
#define SLOP_LIST_HOWL_TYPES_KFACT_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_KFact, slop_list_howl_types_KFact)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_ADDRESSED_DEFINED
#define SLOP_LIST_HOWL_TYPES_ADDRESSED_DEFINED
#define SLOP_LIST_HOWL_TYPES_ADDRESSED_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_Addressed, slop_list_howl_types_Addressed)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_OUTCOME_DEFINED
#define SLOP_OPTION_HOWL_TYPES_OUTCOME_DEFINED
SLOP_OPTION_DEFINE(howl_types_Outcome, slop_option_howl_types_Outcome)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_NODE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_NODE_DEFINED
SLOP_OPTION_DEFINE(howl_types_Node, slop_option_howl_types_Node)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_NORMAXIOM_DEFINED
#define SLOP_OPTION_HOWL_TYPES_NORMAXIOM_DEFINED
SLOP_OPTION_DEFINE(howl_types_NormAxiom, slop_option_howl_types_NormAxiom)
#endif

#ifndef SLOP_OPTION_SLOP_RDF_RDF_TRIPLE_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_TRIPLE_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_Triple, slop_option_slop_rdf_rdf_Triple)
#endif

#ifndef SLOP_OPTION_HOWL_OWL2_RAWAXIOM_DEFINED
#define SLOP_OPTION_HOWL_OWL2_RAWAXIOM_DEFINED
SLOP_OPTION_DEFINE(howl_owl2_RawAxiom, slop_option_howl_owl2_RawAxiom)
#endif

#ifndef SLOP_OPTION_HOWL_DECODE_STAGE1_DEFINED
#define SLOP_OPTION_HOWL_DECODE_STAGE1_DEFINED
SLOP_OPTION_DEFINE(howl_decode_Stage1, slop_option_howl_decode_Stage1)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_AXIOMREF_DEFINED
#define SLOP_OPTION_HOWL_TYPES_AXIOMREF_DEFINED
SLOP_OPTION_DEFINE(howl_types_AxiomRef, slop_option_howl_types_AxiomRef)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_OMISSION_DEFINED
#define SLOP_OPTION_HOWL_TYPES_OMISSION_DEFINED
SLOP_OPTION_DEFINE(howl_types_Omission, slop_option_howl_types_Omission)
#endif

#ifndef SLOP_OPTION_HOWL_GATE_GATERESULT_DEFINED
#define SLOP_OPTION_HOWL_GATE_GATERESULT_DEFINED
SLOP_OPTION_DEFINE(howl_gate_GateResult, slop_option_howl_gate_GateResult)
#endif

#ifndef SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_IRI, slop_option_slop_rdf_rdf_IRI)
#endif

#ifndef SLOP_OPTION_HOWL_SROIQ_SAXIOM_DEFINED
#define SLOP_OPTION_HOWL_SROIQ_SAXIOM_DEFINED
SLOP_OPTION_DEFINE(howl_sroiq_SAxiom, slop_option_howl_sroiq_SAxiom)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_DLCLAUSE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_DLCLAUSE_DEFINED
SLOP_OPTION_DEFINE(howl_types_DlClause, slop_option_howl_types_DlClause)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_DNAME_DEFINED
#define SLOP_OPTION_HOWL_TYPES_DNAME_DEFINED
SLOP_OPTION_DEFINE(howl_types_DName, slop_option_howl_types_DName)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_LIT_DEFINED
#define SLOP_OPTION_HOWL_TYPES_LIT_DEFINED
SLOP_OPTION_DEFINE(howl_types_Lit, slop_option_howl_types_Lit)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_DROLE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_DROLE_DEFINED
SLOP_OPTION_DEFINE(howl_types_DRole, slop_option_howl_types_DRole)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_ATERM_DEFINED
#define SLOP_OPTION_HOWL_TYPES_ATERM_DEFINED
SLOP_OPTION_DEFINE(howl_types_ATerm, slop_option_howl_types_ATerm)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQORDER_CTERM_DEFINED
#define SLOP_OPTION_HOWL_SRIQORDER_CTERM_DEFINED
SLOP_OPTION_DEFINE(howl_sriqorder_CTerm, slop_option_howl_sriqorder_CTerm)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_CLAUSE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_CLAUSE_DEFINED
SLOP_OPTION_DEFINE(howl_types_Clause, slop_option_howl_types_Clause)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQ_PREMISE_DEFINED
#define SLOP_OPTION_HOWL_SRIQ_PREMISE_DEFINED
SLOP_OPTION_DEFINE(howl_sriq_Premise, slop_option_howl_sriq_Premise)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQ_CANDS_DEFINED
#define SLOP_OPTION_HOWL_SRIQ_CANDS_DEFINED
SLOP_OPTION_DEFINE(howl_sriq_Cands, slop_option_howl_sriq_Cands)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQCLAUSES_SRIQCLAUSES_DEFINED
#define SLOP_OPTION_HOWL_SRIQCLAUSES_SRIQCLAUSES_DEFINED
SLOP_OPTION_DEFINE(howl_sriqclauses_SriqClauses, slop_option_howl_sriqclauses_SriqClauses)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQ_SUCCSIG_DEFINED
#define SLOP_OPTION_HOWL_SRIQ_SUCCSIG_DEFINED
SLOP_OPTION_DEFINE(howl_sriq_SuccSig, slop_option_howl_sriq_SuccSig)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQCTX_STRATEGY_DEFINED
#define SLOP_OPTION_HOWL_SRIQCTX_STRATEGY_DEFINED
SLOP_OPTION_DEFINE(howl_sriqctx_Strategy, slop_option_howl_sriqctx_Strategy)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQCTX_EDGE_DEFINED
#define SLOP_OPTION_HOWL_SRIQCTX_EDGE_DEFINED
SLOP_OPTION_DEFINE(howl_sriqctx_Edge, slop_option_howl_sriqctx_Edge)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_SUBPAIR_DEFINED
#define SLOP_OPTION_HOWL_TYPES_SUBPAIR_DEFINED
SLOP_OPTION_DEFINE(howl_types_SubPair, slop_option_howl_types_SubPair)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_KSCAXIOM_DEFINED
#define SLOP_OPTION_HOWL_TYPES_KSCAXIOM_DEFINED
SLOP_OPTION_DEFINE(howl_types_KscAxiom, slop_option_howl_types_KscAxiom)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_KNAME_DEFINED
#define SLOP_OPTION_HOWL_TYPES_KNAME_DEFINED
SLOP_OPTION_DEFINE(howl_types_KName, slop_option_howl_types_KName)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_KFACT_DEFINED
#define SLOP_OPTION_HOWL_TYPES_KFACT_DEFINED
SLOP_OPTION_DEFINE(howl_types_KFact, slop_option_howl_types_KFact)
#endif

#ifndef SLOP_OPTION_HOWL_NORMALIZE_NORMOUTPUT_DEFINED
#define SLOP_OPTION_HOWL_NORMALIZE_NORMOUTPUT_DEFINED
SLOP_OPTION_DEFINE(howl_normalize_NormOutput, slop_option_howl_normalize_NormOutput)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_ADDRESSED_DEFINED
#define SLOP_OPTION_HOWL_TYPES_ADDRESSED_DEFINED
SLOP_OPTION_DEFINE(howl_types_Addressed, slop_option_howl_types_Addressed)
#endif

#ifndef SLOP_OPTION_HOWL_OWL2_SIGNATURE_DEFINED
#define SLOP_OPTION_HOWL_OWL2_SIGNATURE_DEFINED
SLOP_OPTION_DEFINE(howl_owl2_Signature, slop_option_howl_owl2_Signature)
#endif

struct howl_test_Expect {
    slop_string file;
    int64_t kind;
    slop_string a;
    slop_string b;
};
typedef struct howl_test_Expect howl_test_Expect;

#ifndef SLOP_OPTION_HOWL_TEST_EXPECT_DEFINED
#define SLOP_OPTION_HOWL_TEST_EXPECT_DEFINED
SLOP_OPTION_DEFINE(howl_test_Expect, slop_option_howl_test_Expect)
#endif

#ifndef SLOP_LIST_HOWL_TEST_EXPECT_DEFINED
#define SLOP_LIST_HOWL_TEST_EXPECT_DEFINED
#define SLOP_LIST_HOWL_TEST_EXPECT_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_test_Expect, slop_list_howl_test_Expect)
#endif

struct howl_test_ProtoCase {
    slop_string label;
    howl_sriqref_RefIn in;
    int64_t n;
};
typedef struct howl_test_ProtoCase howl_test_ProtoCase;

#ifndef SLOP_OPTION_HOWL_TEST_PROTOCASE_DEFINED
#define SLOP_OPTION_HOWL_TEST_PROTOCASE_DEFINED
SLOP_OPTION_DEFINE(howl_test_ProtoCase, slop_option_howl_test_ProtoCase)
#endif

#ifndef SLOP_LIST_HOWL_TEST_PROTOCASE_DEFINED
#define SLOP_LIST_HOWL_TEST_PROTOCASE_DEFINED
#define SLOP_LIST_HOWL_TEST_PROTOCASE_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_test_ProtoCase, slop_list_howl_test_ProtoCase)
#endif

struct howl_test_RoundAt {
    int64_t total;
    int64_t next;
};
typedef struct howl_test_RoundAt howl_test_RoundAt;

#ifndef SLOP_OPTION_HOWL_TEST_ROUNDAT_DEFINED
#define SLOP_OPTION_HOWL_TEST_ROUNDAT_DEFINED
SLOP_OPTION_DEFINE(howl_test_RoundAt, slop_option_howl_test_RoundAt)
#endif

#ifndef SLOP_LIST_HOWL_TEST_ROUNDAT_DEFINED
#define SLOP_LIST_HOWL_TEST_ROUNDAT_DEFINED
#define SLOP_LIST_HOWL_TEST_ROUNDAT_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_test_RoundAt, slop_list_howl_test_RoundAt)
#endif

struct howl_test_KscFixture {
    slop_list_howl_types_KscAxiom axioms;
    slop_list_howl_types_KName classes;
};
typedef struct howl_test_KscFixture howl_test_KscFixture;

#ifndef SLOP_OPTION_HOWL_TEST_KSCFIXTURE_DEFINED
#define SLOP_OPTION_HOWL_TEST_KSCFIXTURE_DEFINED
SLOP_OPTION_DEFINE(howl_test_KscFixture, slop_option_howl_test_KscFixture)
#endif

typedef enum {
    howl_test_RunAs_ran,
    howl_test_RunAs_refused,
    howl_test_RunAs_failed
} howl_test_RunAs_tag;

struct howl_test_RunAs {
    howl_test_RunAs_tag tag;
    union {
        howl_types_Profile ran;
        howl_types_Profile refused;
    } data;
};
typedef struct howl_test_RunAs howl_test_RunAs;

#ifndef SLOP_OPTION_HOWL_TEST_RUNAS_DEFINED
#define SLOP_OPTION_HOWL_TEST_RUNAS_DEFINED
SLOP_OPTION_DEFINE(howl_test_RunAs, slop_option_howl_test_RunAs)
#endif


/* Hash/eq functions and list types for struct map/set keys */
#ifndef HOWL_TYPES_NODE_HASH_EQ_DEFINED
#define HOWL_TYPES_NODE_HASH_EQ_DEFINED
#ifndef SLOP_RDF_RDF_IRI_HASH_EQ_DEFINED
#define SLOP_RDF_RDF_IRI_HASH_EQ_DEFINED
static inline uint64_t slop_hash_slop_rdf_rdf_IRI(const void* key) {
    const slop_rdf_rdf_IRI* _k = (const slop_rdf_rdf_IRI*)key;
    uint64_t hash = 14695981039346656037ULL;
    hash ^= slop_hash_string(&_k->value); hash *= 1099511628211ULL;
    return hash;
}
static inline bool slop_eq_slop_rdf_rdf_IRI(const void* a, const void* b) {
    const slop_rdf_rdf_IRI* _a = (const slop_rdf_rdf_IRI*)a;
    const slop_rdf_rdf_IRI* _b = (const slop_rdf_rdf_IRI*)b;
    return true
        && (slop_eq_string(&_a->value, &_b->value))
    ;
}
#endif
#ifndef SLOP_RDF_RDF_IRI_HASH_EQ_DEFINED
#define SLOP_RDF_RDF_IRI_HASH_EQ_DEFINED
static inline uint64_t slop_hash_slop_rdf_rdf_IRI(const void* key) {
    const slop_rdf_rdf_IRI* _k = (const slop_rdf_rdf_IRI*)key;
    uint64_t hash = 14695981039346656037ULL;
    hash ^= slop_hash_string(&_k->value); hash *= 1099511628211ULL;
    return hash;
}
static inline bool slop_eq_slop_rdf_rdf_IRI(const void* a, const void* b) {
    const slop_rdf_rdf_IRI* _a = (const slop_rdf_rdf_IRI*)a;
    const slop_rdf_rdf_IRI* _b = (const slop_rdf_rdf_IRI*)b;
    return true
        && (slop_eq_string(&_a->value, &_b->value))
    ;
}
#endif
static inline uint64_t slop_hash_howl_types_Node(const void* key) {
    const howl_types_Node* _k = (const howl_types_Node*)key;
    switch (_k->tag) {
        case howl_types_Node_class_node:
            return slop_hash_slop_rdf_rdf_IRI(&_k->data.class_node);
        case howl_types_Node_individual_node:
            return slop_hash_slop_rdf_rdf_IRI(&_k->data.individual_node);
        case howl_types_Node_fresh_node:
            return slop_hash_int(&(int64_t){ (int64_t)_k->data.fresh_node });
    }
    return 0;
}
static inline bool slop_eq_howl_types_Node(const void* a, const void* b) {
    const howl_types_Node* _a = (const howl_types_Node*)a;
    const howl_types_Node* _b = (const howl_types_Node*)b;
    if (_a->tag != _b->tag) return false;
    switch (_a->tag) {
        case howl_types_Node_class_node:
            return slop_eq_slop_rdf_rdf_IRI(&_a->data.class_node, &_b->data.class_node);
        case howl_types_Node_individual_node:
            return slop_eq_slop_rdf_rdf_IRI(&_a->data.individual_node, &_b->data.individual_node);
        case howl_types_Node_fresh_node:
            return _a->data.fresh_node == _b->data.fresh_node;
    }
    return false;
}
#endif

#ifndef SLOP_RDF_RDF_IRI_HASH_EQ_DEFINED
#define SLOP_RDF_RDF_IRI_HASH_EQ_DEFINED
static inline uint64_t slop_hash_slop_rdf_rdf_IRI(const void* key) {
    const slop_rdf_rdf_IRI* _k = (const slop_rdf_rdf_IRI*)key;
    uint64_t hash = 14695981039346656037ULL;
    hash ^= slop_hash_string(&_k->value); hash *= 1099511628211ULL;
    return hash;
}
static inline bool slop_eq_slop_rdf_rdf_IRI(const void* a, const void* b) {
    const slop_rdf_rdf_IRI* _a = (const slop_rdf_rdf_IRI*)a;
    const slop_rdf_rdf_IRI* _b = (const slop_rdf_rdf_IRI*)b;
    return true
        && (slop_eq_string(&_a->value, &_b->value))
    ;
}
#endif

#ifndef HOWL_TYPES_KFACT_HASH_EQ_DEFINED
#define HOWL_TYPES_KFACT_HASH_EQ_DEFINED
#ifndef HOWL_TYPES_KELEM_HASH_EQ_DEFINED
#define HOWL_TYPES_KELEM_HASH_EQ_DEFINED
#ifndef SLOP_RDF_RDF_IRI_HASH_EQ_DEFINED
#define SLOP_RDF_RDF_IRI_HASH_EQ_DEFINED
static inline uint64_t slop_hash_slop_rdf_rdf_IRI(const void* key) {
    const slop_rdf_rdf_IRI* _k = (const slop_rdf_rdf_IRI*)key;
    uint64_t hash = 14695981039346656037ULL;
    hash ^= slop_hash_string(&_k->value); hash *= 1099511628211ULL;
    return hash;
}
static inline bool slop_eq_slop_rdf_rdf_IRI(const void* a, const void* b) {
    const slop_rdf_rdf_IRI* _a = (const slop_rdf_rdf_IRI*)a;
    const slop_rdf_rdf_IRI* _b = (const slop_rdf_rdf_IRI*)b;
    return true
        && (slop_eq_string(&_a->value, &_b->value))
    ;
}
#endif
#ifndef HOWL_TYPES_KNAME_HASH_EQ_DEFINED
#define HOWL_TYPES_KNAME_HASH_EQ_DEFINED
#ifndef SLOP_RDF_RDF_IRI_HASH_EQ_DEFINED
#define SLOP_RDF_RDF_IRI_HASH_EQ_DEFINED
static inline uint64_t slop_hash_slop_rdf_rdf_IRI(const void* key) {
    const slop_rdf_rdf_IRI* _k = (const slop_rdf_rdf_IRI*)key;
    uint64_t hash = 14695981039346656037ULL;
    hash ^= slop_hash_string(&_k->value); hash *= 1099511628211ULL;
    return hash;
}
static inline bool slop_eq_slop_rdf_rdf_IRI(const void* a, const void* b) {
    const slop_rdf_rdf_IRI* _a = (const slop_rdf_rdf_IRI*)a;
    const slop_rdf_rdf_IRI* _b = (const slop_rdf_rdf_IRI*)b;
    return true
        && (slop_eq_string(&_a->value, &_b->value))
    ;
}
#endif
static inline uint64_t slop_hash_howl_types_KName(const void* key) {
    const howl_types_KName* _k = (const howl_types_KName*)key;
    switch (_k->tag) {
        case howl_types_KName_k_class:
            return slop_hash_slop_rdf_rdf_IRI(&_k->data.k_class);
        case howl_types_KName_k_fresh:
            return slop_hash_int(&(int64_t){ (int64_t)_k->data.k_fresh });
    }
    return 0;
}
static inline bool slop_eq_howl_types_KName(const void* a, const void* b) {
    const howl_types_KName* _a = (const howl_types_KName*)a;
    const howl_types_KName* _b = (const howl_types_KName*)b;
    if (_a->tag != _b->tag) return false;
    switch (_a->tag) {
        case howl_types_KName_k_class:
            return slop_eq_slop_rdf_rdf_IRI(&_a->data.k_class, &_b->data.k_class);
        case howl_types_KName_k_fresh:
            return _a->data.k_fresh == _b->data.k_fresh;
    }
    return false;
}
#endif
static inline uint64_t slop_hash_howl_types_KElem(const void* key) {
    const howl_types_KElem* _k = (const howl_types_KElem*)key;
    switch (_k->tag) {
        case howl_types_KElem_e_ind:
            return slop_hash_slop_rdf_rdf_IRI(&_k->data.e_ind);
        case howl_types_KElem_e_aux:
            return slop_hash_int(&(int64_t){ (int64_t)_k->data.e_aux });
        case howl_types_KElem_e_class:
            return slop_hash_howl_types_KName(&_k->data.e_class);
    }
    return 0;
}
static inline bool slop_eq_howl_types_KElem(const void* a, const void* b) {
    const howl_types_KElem* _a = (const howl_types_KElem*)a;
    const howl_types_KElem* _b = (const howl_types_KElem*)b;
    if (_a->tag != _b->tag) return false;
    switch (_a->tag) {
        case howl_types_KElem_e_ind:
            return slop_eq_slop_rdf_rdf_IRI(&_a->data.e_ind, &_b->data.e_ind);
        case howl_types_KElem_e_aux:
            return _a->data.e_aux == _b->data.e_aux;
        case howl_types_KElem_e_class:
            return slop_eq_howl_types_KName(&_a->data.e_class, &_b->data.e_class);
    }
    return false;
}
#endif
#ifndef HOWL_TYPES_KTERM_HASH_EQ_DEFINED
#define HOWL_TYPES_KTERM_HASH_EQ_DEFINED
#ifndef HOWL_TYPES_KNAME_HASH_EQ_DEFINED
#define HOWL_TYPES_KNAME_HASH_EQ_DEFINED
#ifndef SLOP_RDF_RDF_IRI_HASH_EQ_DEFINED
#define SLOP_RDF_RDF_IRI_HASH_EQ_DEFINED
static inline uint64_t slop_hash_slop_rdf_rdf_IRI(const void* key) {
    const slop_rdf_rdf_IRI* _k = (const slop_rdf_rdf_IRI*)key;
    uint64_t hash = 14695981039346656037ULL;
    hash ^= slop_hash_string(&_k->value); hash *= 1099511628211ULL;
    return hash;
}
static inline bool slop_eq_slop_rdf_rdf_IRI(const void* a, const void* b) {
    const slop_rdf_rdf_IRI* _a = (const slop_rdf_rdf_IRI*)a;
    const slop_rdf_rdf_IRI* _b = (const slop_rdf_rdf_IRI*)b;
    return true
        && (slop_eq_string(&_a->value, &_b->value))
    ;
}
#endif
static inline uint64_t slop_hash_howl_types_KName(const void* key) {
    const howl_types_KName* _k = (const howl_types_KName*)key;
    switch (_k->tag) {
        case howl_types_KName_k_class:
            return slop_hash_slop_rdf_rdf_IRI(&_k->data.k_class);
        case howl_types_KName_k_fresh:
            return slop_hash_int(&(int64_t){ (int64_t)_k->data.k_fresh });
    }
    return 0;
}
static inline bool slop_eq_howl_types_KName(const void* a, const void* b) {
    const howl_types_KName* _a = (const howl_types_KName*)a;
    const howl_types_KName* _b = (const howl_types_KName*)b;
    if (_a->tag != _b->tag) return false;
    switch (_a->tag) {
        case howl_types_KName_k_class:
            return slop_eq_slop_rdf_rdf_IRI(&_a->data.k_class, &_b->data.k_class);
        case howl_types_KName_k_fresh:
            return _a->data.k_fresh == _b->data.k_fresh;
    }
    return false;
}
#endif
#ifndef SLOP_RDF_RDF_IRI_HASH_EQ_DEFINED
#define SLOP_RDF_RDF_IRI_HASH_EQ_DEFINED
static inline uint64_t slop_hash_slop_rdf_rdf_IRI(const void* key) {
    const slop_rdf_rdf_IRI* _k = (const slop_rdf_rdf_IRI*)key;
    uint64_t hash = 14695981039346656037ULL;
    hash ^= slop_hash_string(&_k->value); hash *= 1099511628211ULL;
    return hash;
}
static inline bool slop_eq_slop_rdf_rdf_IRI(const void* a, const void* b) {
    const slop_rdf_rdf_IRI* _a = (const slop_rdf_rdf_IRI*)a;
    const slop_rdf_rdf_IRI* _b = (const slop_rdf_rdf_IRI*)b;
    return true
        && (slop_eq_string(&_a->value, &_b->value))
    ;
}
#endif
static inline uint64_t slop_hash_howl_types_KTerm(const void* key) {
    const howl_types_KTerm* _k = (const howl_types_KTerm*)key;
    switch (_k->tag) {
        case howl_types_KTerm_k_name:
            return slop_hash_howl_types_KName(&_k->data.k_name);
        case howl_types_KTerm_k_nominal:
            return slop_hash_slop_rdf_rdf_IRI(&_k->data.k_nominal);
    }
    return 0;
}
static inline bool slop_eq_howl_types_KTerm(const void* a, const void* b) {
    const howl_types_KTerm* _a = (const howl_types_KTerm*)a;
    const howl_types_KTerm* _b = (const howl_types_KTerm*)b;
    if (_a->tag != _b->tag) return false;
    switch (_a->tag) {
        case howl_types_KTerm_k_name:
            return slop_eq_howl_types_KName(&_a->data.k_name, &_b->data.k_name);
        case howl_types_KTerm_k_nominal:
            return slop_eq_slop_rdf_rdf_IRI(&_a->data.k_nominal, &_b->data.k_nominal);
    }
    return false;
}
#endif
#ifndef HOWL_TYPES_KELEM_HASH_EQ_DEFINED
#define HOWL_TYPES_KELEM_HASH_EQ_DEFINED
#ifndef SLOP_RDF_RDF_IRI_HASH_EQ_DEFINED
#define SLOP_RDF_RDF_IRI_HASH_EQ_DEFINED
static inline uint64_t slop_hash_slop_rdf_rdf_IRI(const void* key) {
    const slop_rdf_rdf_IRI* _k = (const slop_rdf_rdf_IRI*)key;
    uint64_t hash = 14695981039346656037ULL;
    hash ^= slop_hash_string(&_k->value); hash *= 1099511628211ULL;
    return hash;
}
static inline bool slop_eq_slop_rdf_rdf_IRI(const void* a, const void* b) {
    const slop_rdf_rdf_IRI* _a = (const slop_rdf_rdf_IRI*)a;
    const slop_rdf_rdf_IRI* _b = (const slop_rdf_rdf_IRI*)b;
    return true
        && (slop_eq_string(&_a->value, &_b->value))
    ;
}
#endif
#ifndef HOWL_TYPES_KNAME_HASH_EQ_DEFINED
#define HOWL_TYPES_KNAME_HASH_EQ_DEFINED
#ifndef SLOP_RDF_RDF_IRI_HASH_EQ_DEFINED
#define SLOP_RDF_RDF_IRI_HASH_EQ_DEFINED
static inline uint64_t slop_hash_slop_rdf_rdf_IRI(const void* key) {
    const slop_rdf_rdf_IRI* _k = (const slop_rdf_rdf_IRI*)key;
    uint64_t hash = 14695981039346656037ULL;
    hash ^= slop_hash_string(&_k->value); hash *= 1099511628211ULL;
    return hash;
}
static inline bool slop_eq_slop_rdf_rdf_IRI(const void* a, const void* b) {
    const slop_rdf_rdf_IRI* _a = (const slop_rdf_rdf_IRI*)a;
    const slop_rdf_rdf_IRI* _b = (const slop_rdf_rdf_IRI*)b;
    return true
        && (slop_eq_string(&_a->value, &_b->value))
    ;
}
#endif
static inline uint64_t slop_hash_howl_types_KName(const void* key) {
    const howl_types_KName* _k = (const howl_types_KName*)key;
    switch (_k->tag) {
        case howl_types_KName_k_class:
            return slop_hash_slop_rdf_rdf_IRI(&_k->data.k_class);
        case howl_types_KName_k_fresh:
            return slop_hash_int(&(int64_t){ (int64_t)_k->data.k_fresh });
    }
    return 0;
}
static inline bool slop_eq_howl_types_KName(const void* a, const void* b) {
    const howl_types_KName* _a = (const howl_types_KName*)a;
    const howl_types_KName* _b = (const howl_types_KName*)b;
    if (_a->tag != _b->tag) return false;
    switch (_a->tag) {
        case howl_types_KName_k_class:
            return slop_eq_slop_rdf_rdf_IRI(&_a->data.k_class, &_b->data.k_class);
        case howl_types_KName_k_fresh:
            return _a->data.k_fresh == _b->data.k_fresh;
    }
    return false;
}
#endif
static inline uint64_t slop_hash_howl_types_KElem(const void* key) {
    const howl_types_KElem* _k = (const howl_types_KElem*)key;
    switch (_k->tag) {
        case howl_types_KElem_e_ind:
            return slop_hash_slop_rdf_rdf_IRI(&_k->data.e_ind);
        case howl_types_KElem_e_aux:
            return slop_hash_int(&(int64_t){ (int64_t)_k->data.e_aux });
        case howl_types_KElem_e_class:
            return slop_hash_howl_types_KName(&_k->data.e_class);
    }
    return 0;
}
static inline bool slop_eq_howl_types_KElem(const void* a, const void* b) {
    const howl_types_KElem* _a = (const howl_types_KElem*)a;
    const howl_types_KElem* _b = (const howl_types_KElem*)b;
    if (_a->tag != _b->tag) return false;
    switch (_a->tag) {
        case howl_types_KElem_e_ind:
            return slop_eq_slop_rdf_rdf_IRI(&_a->data.e_ind, &_b->data.e_ind);
        case howl_types_KElem_e_aux:
            return _a->data.e_aux == _b->data.e_aux;
        case howl_types_KElem_e_class:
            return slop_eq_howl_types_KName(&_a->data.e_class, &_b->data.e_class);
    }
    return false;
}
#endif
#ifndef HOWL_TYPES_ROLEID_HASH_EQ_DEFINED
#define HOWL_TYPES_ROLEID_HASH_EQ_DEFINED
#ifndef SLOP_RDF_RDF_IRI_HASH_EQ_DEFINED
#define SLOP_RDF_RDF_IRI_HASH_EQ_DEFINED
static inline uint64_t slop_hash_slop_rdf_rdf_IRI(const void* key) {
    const slop_rdf_rdf_IRI* _k = (const slop_rdf_rdf_IRI*)key;
    uint64_t hash = 14695981039346656037ULL;
    hash ^= slop_hash_string(&_k->value); hash *= 1099511628211ULL;
    return hash;
}
static inline bool slop_eq_slop_rdf_rdf_IRI(const void* a, const void* b) {
    const slop_rdf_rdf_IRI* _a = (const slop_rdf_rdf_IRI*)a;
    const slop_rdf_rdf_IRI* _b = (const slop_rdf_rdf_IRI*)b;
    return true
        && (slop_eq_string(&_a->value, &_b->value))
    ;
}
#endif
#ifndef SLOP_RDF_RDF_IRI_HASH_EQ_DEFINED
#define SLOP_RDF_RDF_IRI_HASH_EQ_DEFINED
static inline uint64_t slop_hash_slop_rdf_rdf_IRI(const void* key) {
    const slop_rdf_rdf_IRI* _k = (const slop_rdf_rdf_IRI*)key;
    uint64_t hash = 14695981039346656037ULL;
    hash ^= slop_hash_string(&_k->value); hash *= 1099511628211ULL;
    return hash;
}
static inline bool slop_eq_slop_rdf_rdf_IRI(const void* a, const void* b) {
    const slop_rdf_rdf_IRI* _a = (const slop_rdf_rdf_IRI*)a;
    const slop_rdf_rdf_IRI* _b = (const slop_rdf_rdf_IRI*)b;
    return true
        && (slop_eq_string(&_a->value, &_b->value))
    ;
}
#endif
static inline uint64_t slop_hash_howl_types_RoleId(const void* key) {
    const howl_types_RoleId* _k = (const howl_types_RoleId*)key;
    switch (_k->tag) {
        case howl_types_RoleId_named_role:
            return slop_hash_slop_rdf_rdf_IRI(&_k->data.named_role);
        case howl_types_RoleId_fresh_role:
            return slop_hash_int(&(int64_t){ (int64_t)_k->data.fresh_role });
        case howl_types_RoleId_inverse_role:
            return slop_hash_slop_rdf_rdf_IRI(&_k->data.inverse_role);
    }
    return 0;
}
static inline bool slop_eq_howl_types_RoleId(const void* a, const void* b) {
    const howl_types_RoleId* _a = (const howl_types_RoleId*)a;
    const howl_types_RoleId* _b = (const howl_types_RoleId*)b;
    if (_a->tag != _b->tag) return false;
    switch (_a->tag) {
        case howl_types_RoleId_named_role:
            return slop_eq_slop_rdf_rdf_IRI(&_a->data.named_role, &_b->data.named_role);
        case howl_types_RoleId_fresh_role:
            return _a->data.fresh_role == _b->data.fresh_role;
        case howl_types_RoleId_inverse_role:
            return slop_eq_slop_rdf_rdf_IRI(&_a->data.inverse_role, &_b->data.inverse_role);
    }
    return false;
}
#endif
#ifndef HOWL_TYPES_KELEM_HASH_EQ_DEFINED
#define HOWL_TYPES_KELEM_HASH_EQ_DEFINED
#ifndef SLOP_RDF_RDF_IRI_HASH_EQ_DEFINED
#define SLOP_RDF_RDF_IRI_HASH_EQ_DEFINED
static inline uint64_t slop_hash_slop_rdf_rdf_IRI(const void* key) {
    const slop_rdf_rdf_IRI* _k = (const slop_rdf_rdf_IRI*)key;
    uint64_t hash = 14695981039346656037ULL;
    hash ^= slop_hash_string(&_k->value); hash *= 1099511628211ULL;
    return hash;
}
static inline bool slop_eq_slop_rdf_rdf_IRI(const void* a, const void* b) {
    const slop_rdf_rdf_IRI* _a = (const slop_rdf_rdf_IRI*)a;
    const slop_rdf_rdf_IRI* _b = (const slop_rdf_rdf_IRI*)b;
    return true
        && (slop_eq_string(&_a->value, &_b->value))
    ;
}
#endif
#ifndef HOWL_TYPES_KNAME_HASH_EQ_DEFINED
#define HOWL_TYPES_KNAME_HASH_EQ_DEFINED
#ifndef SLOP_RDF_RDF_IRI_HASH_EQ_DEFINED
#define SLOP_RDF_RDF_IRI_HASH_EQ_DEFINED
static inline uint64_t slop_hash_slop_rdf_rdf_IRI(const void* key) {
    const slop_rdf_rdf_IRI* _k = (const slop_rdf_rdf_IRI*)key;
    uint64_t hash = 14695981039346656037ULL;
    hash ^= slop_hash_string(&_k->value); hash *= 1099511628211ULL;
    return hash;
}
static inline bool slop_eq_slop_rdf_rdf_IRI(const void* a, const void* b) {
    const slop_rdf_rdf_IRI* _a = (const slop_rdf_rdf_IRI*)a;
    const slop_rdf_rdf_IRI* _b = (const slop_rdf_rdf_IRI*)b;
    return true
        && (slop_eq_string(&_a->value, &_b->value))
    ;
}
#endif
static inline uint64_t slop_hash_howl_types_KName(const void* key) {
    const howl_types_KName* _k = (const howl_types_KName*)key;
    switch (_k->tag) {
        case howl_types_KName_k_class:
            return slop_hash_slop_rdf_rdf_IRI(&_k->data.k_class);
        case howl_types_KName_k_fresh:
            return slop_hash_int(&(int64_t){ (int64_t)_k->data.k_fresh });
    }
    return 0;
}
static inline bool slop_eq_howl_types_KName(const void* a, const void* b) {
    const howl_types_KName* _a = (const howl_types_KName*)a;
    const howl_types_KName* _b = (const howl_types_KName*)b;
    if (_a->tag != _b->tag) return false;
    switch (_a->tag) {
        case howl_types_KName_k_class:
            return slop_eq_slop_rdf_rdf_IRI(&_a->data.k_class, &_b->data.k_class);
        case howl_types_KName_k_fresh:
            return _a->data.k_fresh == _b->data.k_fresh;
    }
    return false;
}
#endif
static inline uint64_t slop_hash_howl_types_KElem(const void* key) {
    const howl_types_KElem* _k = (const howl_types_KElem*)key;
    switch (_k->tag) {
        case howl_types_KElem_e_ind:
            return slop_hash_slop_rdf_rdf_IRI(&_k->data.e_ind);
        case howl_types_KElem_e_aux:
            return slop_hash_int(&(int64_t){ (int64_t)_k->data.e_aux });
        case howl_types_KElem_e_class:
            return slop_hash_howl_types_KName(&_k->data.e_class);
    }
    return 0;
}
static inline bool slop_eq_howl_types_KElem(const void* a, const void* b) {
    const howl_types_KElem* _a = (const howl_types_KElem*)a;
    const howl_types_KElem* _b = (const howl_types_KElem*)b;
    if (_a->tag != _b->tag) return false;
    switch (_a->tag) {
        case howl_types_KElem_e_ind:
            return slop_eq_slop_rdf_rdf_IRI(&_a->data.e_ind, &_b->data.e_ind);
        case howl_types_KElem_e_aux:
            return _a->data.e_aux == _b->data.e_aux;
        case howl_types_KElem_e_class:
            return slop_eq_howl_types_KName(&_a->data.e_class, &_b->data.e_class);
    }
    return false;
}
#endif
#ifndef HOWL_TYPES_KELEM_HASH_EQ_DEFINED
#define HOWL_TYPES_KELEM_HASH_EQ_DEFINED
#ifndef SLOP_RDF_RDF_IRI_HASH_EQ_DEFINED
#define SLOP_RDF_RDF_IRI_HASH_EQ_DEFINED
static inline uint64_t slop_hash_slop_rdf_rdf_IRI(const void* key) {
    const slop_rdf_rdf_IRI* _k = (const slop_rdf_rdf_IRI*)key;
    uint64_t hash = 14695981039346656037ULL;
    hash ^= slop_hash_string(&_k->value); hash *= 1099511628211ULL;
    return hash;
}
static inline bool slop_eq_slop_rdf_rdf_IRI(const void* a, const void* b) {
    const slop_rdf_rdf_IRI* _a = (const slop_rdf_rdf_IRI*)a;
    const slop_rdf_rdf_IRI* _b = (const slop_rdf_rdf_IRI*)b;
    return true
        && (slop_eq_string(&_a->value, &_b->value))
    ;
}
#endif
#ifndef HOWL_TYPES_KNAME_HASH_EQ_DEFINED
#define HOWL_TYPES_KNAME_HASH_EQ_DEFINED
#ifndef SLOP_RDF_RDF_IRI_HASH_EQ_DEFINED
#define SLOP_RDF_RDF_IRI_HASH_EQ_DEFINED
static inline uint64_t slop_hash_slop_rdf_rdf_IRI(const void* key) {
    const slop_rdf_rdf_IRI* _k = (const slop_rdf_rdf_IRI*)key;
    uint64_t hash = 14695981039346656037ULL;
    hash ^= slop_hash_string(&_k->value); hash *= 1099511628211ULL;
    return hash;
}
static inline bool slop_eq_slop_rdf_rdf_IRI(const void* a, const void* b) {
    const slop_rdf_rdf_IRI* _a = (const slop_rdf_rdf_IRI*)a;
    const slop_rdf_rdf_IRI* _b = (const slop_rdf_rdf_IRI*)b;
    return true
        && (slop_eq_string(&_a->value, &_b->value))
    ;
}
#endif
static inline uint64_t slop_hash_howl_types_KName(const void* key) {
    const howl_types_KName* _k = (const howl_types_KName*)key;
    switch (_k->tag) {
        case howl_types_KName_k_class:
            return slop_hash_slop_rdf_rdf_IRI(&_k->data.k_class);
        case howl_types_KName_k_fresh:
            return slop_hash_int(&(int64_t){ (int64_t)_k->data.k_fresh });
    }
    return 0;
}
static inline bool slop_eq_howl_types_KName(const void* a, const void* b) {
    const howl_types_KName* _a = (const howl_types_KName*)a;
    const howl_types_KName* _b = (const howl_types_KName*)b;
    if (_a->tag != _b->tag) return false;
    switch (_a->tag) {
        case howl_types_KName_k_class:
            return slop_eq_slop_rdf_rdf_IRI(&_a->data.k_class, &_b->data.k_class);
        case howl_types_KName_k_fresh:
            return _a->data.k_fresh == _b->data.k_fresh;
    }
    return false;
}
#endif
static inline uint64_t slop_hash_howl_types_KElem(const void* key) {
    const howl_types_KElem* _k = (const howl_types_KElem*)key;
    switch (_k->tag) {
        case howl_types_KElem_e_ind:
            return slop_hash_slop_rdf_rdf_IRI(&_k->data.e_ind);
        case howl_types_KElem_e_aux:
            return slop_hash_int(&(int64_t){ (int64_t)_k->data.e_aux });
        case howl_types_KElem_e_class:
            return slop_hash_howl_types_KName(&_k->data.e_class);
    }
    return 0;
}
static inline bool slop_eq_howl_types_KElem(const void* a, const void* b) {
    const howl_types_KElem* _a = (const howl_types_KElem*)a;
    const howl_types_KElem* _b = (const howl_types_KElem*)b;
    if (_a->tag != _b->tag) return false;
    switch (_a->tag) {
        case howl_types_KElem_e_ind:
            return slop_eq_slop_rdf_rdf_IRI(&_a->data.e_ind, &_b->data.e_ind);
        case howl_types_KElem_e_aux:
            return _a->data.e_aux == _b->data.e_aux;
        case howl_types_KElem_e_class:
            return slop_eq_howl_types_KName(&_a->data.e_class, &_b->data.e_class);
    }
    return false;
}
#endif
#ifndef HOWL_TYPES_ROLEID_HASH_EQ_DEFINED
#define HOWL_TYPES_ROLEID_HASH_EQ_DEFINED
#ifndef SLOP_RDF_RDF_IRI_HASH_EQ_DEFINED
#define SLOP_RDF_RDF_IRI_HASH_EQ_DEFINED
static inline uint64_t slop_hash_slop_rdf_rdf_IRI(const void* key) {
    const slop_rdf_rdf_IRI* _k = (const slop_rdf_rdf_IRI*)key;
    uint64_t hash = 14695981039346656037ULL;
    hash ^= slop_hash_string(&_k->value); hash *= 1099511628211ULL;
    return hash;
}
static inline bool slop_eq_slop_rdf_rdf_IRI(const void* a, const void* b) {
    const slop_rdf_rdf_IRI* _a = (const slop_rdf_rdf_IRI*)a;
    const slop_rdf_rdf_IRI* _b = (const slop_rdf_rdf_IRI*)b;
    return true
        && (slop_eq_string(&_a->value, &_b->value))
    ;
}
#endif
#ifndef SLOP_RDF_RDF_IRI_HASH_EQ_DEFINED
#define SLOP_RDF_RDF_IRI_HASH_EQ_DEFINED
static inline uint64_t slop_hash_slop_rdf_rdf_IRI(const void* key) {
    const slop_rdf_rdf_IRI* _k = (const slop_rdf_rdf_IRI*)key;
    uint64_t hash = 14695981039346656037ULL;
    hash ^= slop_hash_string(&_k->value); hash *= 1099511628211ULL;
    return hash;
}
static inline bool slop_eq_slop_rdf_rdf_IRI(const void* a, const void* b) {
    const slop_rdf_rdf_IRI* _a = (const slop_rdf_rdf_IRI*)a;
    const slop_rdf_rdf_IRI* _b = (const slop_rdf_rdf_IRI*)b;
    return true
        && (slop_eq_string(&_a->value, &_b->value))
    ;
}
#endif
static inline uint64_t slop_hash_howl_types_RoleId(const void* key) {
    const howl_types_RoleId* _k = (const howl_types_RoleId*)key;
    switch (_k->tag) {
        case howl_types_RoleId_named_role:
            return slop_hash_slop_rdf_rdf_IRI(&_k->data.named_role);
        case howl_types_RoleId_fresh_role:
            return slop_hash_int(&(int64_t){ (int64_t)_k->data.fresh_role });
        case howl_types_RoleId_inverse_role:
            return slop_hash_slop_rdf_rdf_IRI(&_k->data.inverse_role);
    }
    return 0;
}
static inline bool slop_eq_howl_types_RoleId(const void* a, const void* b) {
    const howl_types_RoleId* _a = (const howl_types_RoleId*)a;
    const howl_types_RoleId* _b = (const howl_types_RoleId*)b;
    if (_a->tag != _b->tag) return false;
    switch (_a->tag) {
        case howl_types_RoleId_named_role:
            return slop_eq_slop_rdf_rdf_IRI(&_a->data.named_role, &_b->data.named_role);
        case howl_types_RoleId_fresh_role:
            return _a->data.fresh_role == _b->data.fresh_role;
        case howl_types_RoleId_inverse_role:
            return slop_eq_slop_rdf_rdf_IRI(&_a->data.inverse_role, &_b->data.inverse_role);
    }
    return false;
}
#endif
static inline uint64_t slop_hash_howl_types_KFact(const void* key) {
    const howl_types_KFact* _k = (const howl_types_KFact*)key;
    switch (_k->tag) {
        case howl_types_KFact_f_inst:
            {
                uint64_t hash = 14695981039346656037ULL;
                hash ^= slop_hash_howl_types_KElem(&_k->data.f_inst.f0); hash *= 1099511628211ULL;
                hash ^= slop_hash_howl_types_KTerm(&_k->data.f_inst.f1); hash *= 1099511628211ULL;
                return hash;
            }
        case howl_types_KFact_f_triple:
            {
                uint64_t hash = 14695981039346656037ULL;
                hash ^= slop_hash_howl_types_KElem(&_k->data.f_triple.f0); hash *= 1099511628211ULL;
                hash ^= slop_hash_howl_types_RoleId(&_k->data.f_triple.f1); hash *= 1099511628211ULL;
                hash ^= slop_hash_howl_types_KElem(&_k->data.f_triple.f2); hash *= 1099511628211ULL;
                return hash;
            }
        case howl_types_KFact_f_self:
            {
                uint64_t hash = 14695981039346656037ULL;
                hash ^= slop_hash_howl_types_KElem(&_k->data.f_self.f0); hash *= 1099511628211ULL;
                hash ^= slop_hash_howl_types_RoleId(&_k->data.f_self.f1); hash *= 1099511628211ULL;
                return hash;
            }
    }
    return 0;
}
static inline bool slop_eq_howl_types_KFact(const void* a, const void* b) {
    const howl_types_KFact* _a = (const howl_types_KFact*)a;
    const howl_types_KFact* _b = (const howl_types_KFact*)b;
    if (_a->tag != _b->tag) return false;
    switch (_a->tag) {
        case howl_types_KFact_f_inst:
            return true
                && slop_eq_howl_types_KElem(&_a->data.f_inst.f0, &_b->data.f_inst.f0)
                && slop_eq_howl_types_KTerm(&_a->data.f_inst.f1, &_b->data.f_inst.f1)
            ;
        case howl_types_KFact_f_triple:
            return true
                && slop_eq_howl_types_KElem(&_a->data.f_triple.f0, &_b->data.f_triple.f0)
                && slop_eq_howl_types_RoleId(&_a->data.f_triple.f1, &_b->data.f_triple.f1)
                && slop_eq_howl_types_KElem(&_a->data.f_triple.f2, &_b->data.f_triple.f2)
            ;
        case howl_types_KFact_f_self:
            return true
                && slop_eq_howl_types_KElem(&_a->data.f_self.f0, &_b->data.f_self.f0)
                && slop_eq_howl_types_RoleId(&_a->data.f_self.f1, &_b->data.f_self.f1)
            ;
    }
    return false;
}
#endif

#ifndef HOWL_KSCIDS_CFACT_HASH_EQ_DEFINED
#define HOWL_KSCIDS_CFACT_HASH_EQ_DEFINED
static inline uint64_t slop_hash_howl_kscids_CFact(const void* key) {
    const howl_kscids_CFact* _k = (const howl_kscids_CFact*)key;
    uint64_t hash = 14695981039346656037ULL;
    hash ^= slop_hash_uint(&(uint64_t){ (uint64_t)_k->kind }); hash *= 1099511628211ULL;
    hash ^= slop_hash_uint(&(uint64_t){ (uint64_t)_k->a }); hash *= 1099511628211ULL;
    hash ^= slop_hash_uint(&(uint64_t){ (uint64_t)_k->b }); hash *= 1099511628211ULL;
    hash ^= slop_hash_uint(&(uint64_t){ (uint64_t)_k->c }); hash *= 1099511628211ULL;
    return hash;
}
static inline bool slop_eq_howl_kscids_CFact(const void* a, const void* b) {
    const howl_kscids_CFact* _a = (const howl_kscids_CFact*)a;
    const howl_kscids_CFact* _b = (const howl_kscids_CFact*)b;
    return true
        && (_a->kind == _b->kind)
        && (_a->a == _b->a)
        && (_a->b == _b->b)
        && (_a->c == _b->c)
    ;
}
#ifndef SLOP_LIST_HOWL_KSCIDS_CFACT_DEFINED
#define SLOP_LIST_HOWL_KSCIDS_CFACT_DEFINED
#define SLOP_LIST_HOWL_KSCIDS_CFACT_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_kscids_CFact, slop_list_howl_kscids_CFact)
#endif
#endif

#ifndef SLOP_RESULT_HOWL_SATURATE_ROUNDRESULT_HOWL_TYPES_FAULT_DEFINED
#define SLOP_RESULT_HOWL_SATURATE_ROUNDRESULT_HOWL_TYPES_FAULT_DEFINED
typedef struct { bool is_ok; union { howl_saturate_RoundResult ok; howl_types_Fault err; } data; } slop_result_howl_saturate_RoundResult_howl_types_Fault;
#endif

#ifndef SLOP_RESULT_HOWL_DECODE_STAGE1_HOWL_TYPES_FAULT_DEFINED
#define SLOP_RESULT_HOWL_DECODE_STAGE1_HOWL_TYPES_FAULT_DEFINED
typedef struct { bool is_ok; union { howl_decode_Stage1 ok; howl_types_Fault err; } data; } slop_result_howl_decode_Stage1_howl_types_Fault;
#endif

#ifndef SLOP_RESULT_HOWL_SRIQNORMAL_S2_STRING_DEFINED
#define SLOP_RESULT_HOWL_SRIQNORMAL_S2_STRING_DEFINED
typedef struct { bool is_ok; union { howl_sriqnormal_S2 ok; slop_string err; } data; } slop_result_howl_sriqnormal_S2_string;
#endif

#ifndef SLOP_RESULT_HOWL_SRIQELIM_S1_STRING_DEFINED
#define SLOP_RESULT_HOWL_SRIQELIM_S1_STRING_DEFINED
typedef struct { bool is_ok; union { howl_sriqelim_S1 ok; slop_string err; } data; } slop_result_howl_sriqelim_S1_string;
#endif

#ifndef SLOP_RESULT_HOWL_SRIQNORMAL_S0_STRING_DEFINED
#define SLOP_RESULT_HOWL_SRIQNORMAL_S0_STRING_DEFINED
typedef struct { bool is_ok; union { howl_sriqnormal_S0 ok; slop_string err; } data; } slop_result_howl_sriqnormal_S0_string;
#endif

#ifndef SLOP_RESULT_HOWL_SRIQNAMES_SRIQNORMAL_STRING_DEFINED
#define SLOP_RESULT_HOWL_SRIQNAMES_SRIQNORMAL_STRING_DEFINED
typedef struct { bool is_ok; union { howl_sriqnames_SriqNormal ok; slop_string err; } data; } slop_result_howl_sriqnames_SriqNormal_string;
#endif

#ifndef SLOP_RESULT_HOWL_TYPES_OUTCOME_HOWL_TYPES_FAULT_DEFINED
#define SLOP_RESULT_HOWL_TYPES_OUTCOME_HOWL_TYPES_FAULT_DEFINED
typedef struct { bool is_ok; union { howl_types_Outcome ok; howl_types_Fault err; } data; } slop_result_howl_types_Outcome_howl_types_Fault;
#endif

#ifndef SLOP_RESULT_HOWL_SRIQCLAUSES_SRIQCLAUSES_STRING_DEFINED
#define SLOP_RESULT_HOWL_SRIQCLAUSES_SRIQCLAUSES_STRING_DEFINED
typedef struct { bool is_ok; union { howl_sriqclauses_SriqClauses ok; slop_string err; } data; } slop_result_howl_sriqclauses_SriqClauses_string;
#endif

#ifndef SLOP_RESULT_HOWL_SRIQABOX_INPUTS_STRING_DEFINED
#define SLOP_RESULT_HOWL_SRIQABOX_INPUTS_STRING_DEFINED
typedef struct { bool is_ok; union { howl_sriqabox_Inputs ok; slop_string err; } data; } slop_result_howl_sriqabox_Inputs_string;
#endif

howl_types_Saturation howl_test_empty_saturation(slop_arena* arena);
howl_types_Saturation howl_test_outcome_saturation(slop_arena* arena, howl_types_Outcome o);
howl_ElWork howl_test_prepared_el_work(slop_arena* arena, howl_Prepared p);
howl_ElWork howl_test_empty_el_work(slop_arena* arena);
howl_types_Findings howl_test_make_findings(slop_arena* arena, uint8_t inconsistent, int64_t unsat_count);
howl_types_Outcome howl_test_make_outcome(slop_arena* arena, uint8_t inconsistent, int64_t unsat_count, int64_t omitted_count, uint8_t reached_fixpoint);
uint8_t howl_test_verdict_eq(howl_types_Verdict a, howl_types_Verdict b);
uint8_t howl_test_test_coherent_requires_complete(slop_arena* arena);
uint8_t howl_test_test_omission_blocks_coherent(slop_arena* arena);
uint8_t howl_test_test_cap_blocks_coherent(slop_arena* arena);
uint8_t howl_test_test_finding_beats_partial_coverage(slop_arena* arena);
uint8_t howl_test_test_consistent_but_incoherent(slop_arena* arena);
uint8_t howl_test_test_context_starts_with_empty_store(slop_arena* arena);
slop_string howl_test_node_iri(howl_types_Node n);
uint8_t howl_test_test_emit_edge_addresses_both_halves(slop_arena* arena);
slop_option_howl_types_Outcome howl_test_classify_fixture(slop_arena* arena, slop_string path);
slop_option_howl_types_Outcome howl_test_classify_fixture_with(slop_arena* arena, slop_string path, int64_t workers, int64_t cap);
uint8_t howl_test_workers_agree(slop_arena* arena, slop_string path, int64_t cap);
uint8_t howl_test_test_worker_count_does_not_change_the_report(slop_arena* arena);
howl_types_Context howl_test_edge_context(slop_arena* arena, howl_types_Node n, howl_types_RoleId r, howl_types_Node m, uint8_t succ);
uint8_t howl_test_queue_has(howl_types_Saturation sat, howl_types_Node n, howl_types_Derived d);
uint8_t howl_test_stored_edge(howl_types_Saturation sat, howl_types_Node x, howl_types_RoleId r, howl_types_Node y);
int64_t howl_test_queue_len(howl_types_Saturation sat, howl_types_Node n);
uint8_t howl_test_test_commit_dedups_across_deltas(slop_arena* arena);
uint8_t howl_test_test_names_round_trip(slop_arena* arena);
uint8_t howl_test_same_renamed(howl_types_Names names, howl_types_Node n, howl_types_Node expect);
uint8_t howl_test_test_litmus_end_to_end(slop_arena* arena);
uint8_t howl_test_test_role_hierarchy_carries_edges(slop_arena* arena);
uint8_t howl_test_test_role_closure_deep(slop_arena* arena);
uint8_t howl_test_test_smaller_side_joins(slop_arena* arena);
uint8_t howl_test_test_unattested_import_is_inconclusive(slop_arena* arena);
uint8_t howl_test_test_declared_unused_class_gets_a_context(slop_arena* arena);
uint8_t howl_test_test_abox_disjoint_range_is_incoherent(slop_arena* arena);
int64_t howl_test_omitted_count(howl_types_Outcome o);
uint8_t howl_test_test_undeclared_individual_is_reasoned_over(slop_arena* arena);
uint8_t howl_test_test_anonymous_class_assertion_is_read(slop_arena* arena);
uint8_t howl_test_test_annotation_on_annotation_is_consumed(slop_arena* arena);
uint8_t howl_test_test_logical_triple_on_header_node_is_not_swallowed(slop_arena* arena);
uint8_t howl_test_test_repeated_disjoint_member_is_positional(slop_arena* arena);
uint8_t howl_test_report_entails(howl_types_Findings f, howl_types_Node a, howl_types_Node b);
uint8_t howl_test_probe_agrees_with_report(slop_arena* arena, slop_string path);
uint8_t howl_test_test_entails_sub_agrees_with_report(slop_arena* arena);
howl_types_Node howl_test_cls(slop_string name);
howl_types_RoleId howl_test_rol(slop_string name);
slop_result_howl_saturate_RoundResult_howl_types_Fault howl_test_run_fixture(slop_arena* arena, slop_list_howl_types_Node signature, slop_list_howl_types_NormAxiom axioms);
slop_list_howl_types_Node howl_test_litmus_signature(slop_arena* arena);
slop_list_howl_types_NormAxiom howl_test_litmus_axioms(slop_arena* arena, uint8_t correct_polarity);
uint8_t howl_test_litmus_derives_parent(slop_arena* arena, uint8_t correct_polarity);
uint8_t howl_test_test_litmus(slop_arena* arena);
uint8_t howl_test_test_polarity_guard(slop_arena* arena);
uint8_t howl_test_test_cyclic_hierarchy_terminates(slop_arena* arena);
uint8_t howl_test_test_same_round_co_arrival(slop_arena* arena);
uint8_t howl_test_test_late_subsumer_still_concludes(slop_arena* arena);
slop_result_howl_saturate_RoundResult_howl_types_Fault howl_test_unsat_fixture(slop_arena* arena);
uint8_t howl_test_test_unsatisfiable_class_detected(slop_arena* arena);
uint8_t howl_test_test_bottom_compression(slop_arena* arena);
uint8_t howl_test_test_inconsistency_suppresses_both_lists(slop_arena* arena);
uint8_t howl_test_test_derived_eq_compares_both_payloads(slop_arena* arena);
uint8_t howl_test_test_order_independence(slop_arena* arena);
slop_rdf_rdf_IRI howl_test_mk_iri(slop_string v);
uint8_t howl_test_test_string_cmp_is_length_safe(slop_arena* arena);
uint8_t howl_test_test_node_cmp_separates_punned_iris(slop_arena* arena);
uint8_t howl_test_test_sort_orders_and_is_input_determined(slop_arena* arena);
slop_rdf_rdf_Term howl_test_ex_iri(slop_arena* arena, slop_string local);
int64_t howl_test_count_subclass_triples(slop_list_slop_rdf_rdf_Triple ts, slop_rdf_rdf_Term pred);
uint8_t howl_test_test_unattested_import_yields_an_omission(slop_arena* arena);
uint8_t howl_test_test_attested_import_yields_none(slop_arena* arena);
uint8_t howl_test_test_term_store_by_content(slop_arena* arena);
uint8_t howl_test_test_term_store_quoted_and_tagged(slop_arena* arena);
slop_list_slop_rdf_rdf_Triple howl_test_stage0_triples(slop_arena* arena, howl_decode_Stage0 s0);
slop_list_string howl_test_decode_rendered(slop_arena* arena, slop_result_howl_decode_Stage1_howl_types_Fault r);
uint8_t howl_test_decode_store_agrees(slop_arena* arena, slop_string path);
uint8_t howl_test_test_decode_store_answers_as_the_full_store(slop_arena* arena);
slop_string howl_test_stage0_fault_of(slop_arena* arena, slop_list_slop_rdf_rdf_Triple ts);
uint8_t howl_test_test_stage0_fault_follows_the_document(slop_arena* arena);
uint8_t howl_test_test_stage0_rebuild_checks_the_whole_input(slop_arena* arena);
uint8_t howl_test_test_header_and_reification_are_consumed(slop_arena* arena);
int64_t howl_test_count_out_of_profile(slop_list_howl_owl2_RawAxiom axs);
int64_t howl_test_count_disposition(slop_list_howl_owl2_RawAxiom axs, howl_owl2_Disposition want);
slop_option_howl_decode_Stage1 howl_test_decode_fixture(slop_arena* arena, slop_string path);
int64_t howl_test_nary_disjoint_member_count(slop_list_howl_owl2_RawAxiom axs);
uint8_t howl_test_test_nary_disjointness_keeps_its_members(slop_arena* arena);
int64_t howl_test_out_of_profile_count_of(slop_arena* arena, slop_string path);
uint8_t howl_test_test_v0_corpus_decodes_clean(slop_arena* arena);
uint8_t howl_test_test_out_of_profile_corpus_is_caught(slop_arena* arena);
uint8_t howl_test_test_annotation_heavy_decodes_clean(slop_arena* arena);
uint8_t howl_test_test_litmus_decodes_clean(slop_arena* arena);
uint8_t howl_test_test_missing_class_declaration_is_reported(slop_arena* arena);
slop_string howl_test_cites_lines(slop_arena* arena, slop_list_howl_types_AxiomRef refs);
slop_string howl_test_cited_text(slop_arena* arena, howl_gate_GateResult gr, slop_string iri);
uint8_t howl_test_test_missing_declaration_cites_its_axioms(slop_arena* arena);
uint8_t howl_test_test_undeclared_individual_is_not_reported(slop_arena* arena);
int64_t howl_test_accepted_count_of_ttl(slop_arena* arena, slop_string ttl);
uint8_t howl_test_test_reserved_iri_as_individual_is_out_of_profile(slop_arena* arena);
uint8_t howl_test_test_annotation_property_axioms_are_inert(slop_arena* arena);
uint8_t howl_test_decodes_ok(slop_arena* arena, slop_string ttl);
slop_list_howl_types_Omission howl_test_carried_of(slop_arena* arena, howl_decode_Stage0 s0, howl_decode_Stage1 s1);
uint8_t howl_test_test_undeclared_property_is_an_omission(slop_arena* arena);
uint8_t howl_test_undeclared_cites(slop_arena* arena, slop_string ttl, slop_string first, slop_string second);
uint8_t howl_test_test_unknown_owl_vocabulary_still_decodes(slop_arena* arena);
uint8_t howl_test_test_conflicting_declarations_are_an_input_error(slop_arena* arena);
slop_option_howl_gate_GateResult howl_test_gate_ttl(slop_arena* arena, slop_string ttl);
slop_option_howl_gate_GateResult howl_test_gate_ttl_in(slop_arena* arena, slop_string ttl, howl_types_Profile p);
slop_list_howl_owl2_RawAxiom howl_test_axioms_of_ttl(slop_arena* arena, slop_string ttl);
uint8_t howl_test_is_declaration(howl_owl2_RawAxiom ax);
slop_map* howl_test_t_iris(slop_arena* arena, slop_list_string names);
uint8_t howl_test_loc(slop_arena* arena, slop_string label, slop_string ttl, slop_list_string names, uint8_t want);
uint8_t howl_test_test_locality_table(slop_arena* arena);
uint8_t howl_test_test_unreadable_is_omitted(slop_arena* arena);
uint8_t howl_test_test_module_order_free(slop_arena* arena);
slop_list_string howl_test_rendered_sorted(slop_arena* arena, slop_list_howl_owl2_RawAxiom axs);
uint8_t howl_test_lines_equal(slop_list_string a, slop_list_string b);
slop_string howl_test_module_answer(slop_arena* arena, slop_string text, slop_string sub, slop_string sup);
uint8_t howl_test_test_module_answers(slop_arena* arena);
uint8_t howl_test_ends_with_line(slop_arena* arena, slop_string text, slop_string line);
int64_t howl_test_gate_omissions_of_ttl(slop_arena* arena, slop_string ttl);
slop_string howl_test_gate_accepted_of_ttl(slop_arena* arena, slop_string ttl);
slop_string howl_test_rc_prefix(void);
uint8_t howl_test_test_range_composition_table(slop_arena* arena);
slop_string howl_test_rung_prefix(void);
int64_t howl_test_omissions_under(slop_arena* arena, slop_string ttl, howl_types_Profile p);
int64_t howl_test_accepted_under(slop_arena* arena, slop_string ttl, howl_types_Profile p);
uint8_t howl_test_gate_alike_under(slop_arena* arena, slop_string label, slop_string a, slop_string b, howl_types_Profile p);
uint8_t howl_test_rungs_gate_alike(slop_arena* arena, slop_string label, slop_string ttl_a, slop_string ttl_b);
uint8_t howl_test_rungs_omit(slop_arena* arena, slop_string label, slop_string ttl, int64_t el_want, int64_t elpp_want);
uint8_t howl_test_test_data_lemma(slop_arena* arena);
slop_string howl_test_inv_decls(void);
uint8_t howl_test_test_inverses_decode_whole(slop_arena* arena);
uint8_t howl_test_test_data_constructs_decode_as_data(slop_arena* arena);
uint8_t howl_test_test_concept_order_is_total(slop_arena* arena);
howl_owl2_RawConcept* howl_test_box_test_concept(slop_arena* arena, howl_owl2_RawConcept c);
uint8_t howl_test_rungs3_omit(slop_arena* arena, slop_string label, slop_string ttl, int64_t el_want, int64_t elpp_want, int64_t sriq_want);
slop_string howl_test_s0_prefix(void);
slop_string howl_test_render_saxioms(slop_arena* arena, slop_list_howl_sroiq_SAxiom axs);
slop_string howl_test_s0_of(slop_arena* arena, slop_string ttl, uint8_t through_s1);
uint8_t howl_test_s0_is(slop_arena* arena, slop_string label, slop_string ttl, slop_string want);
uint8_t howl_test_s1_is(slop_arena* arena, slop_string label, slop_string ttl, slop_string want);
uint8_t howl_test_test_sriq_s0_rows(slop_arena* arena);
slop_list_string howl_test_sort_strings(slop_arena* arena, slop_list_string xs);
slop_string howl_test_str_at_t(slop_list_string xs, int64_t i);
slop_string howl_test_refusal_line(slop_arena* arena, slop_string m);
slop_string howl_test_s2_text(slop_arena* arena, slop_result_howl_sriqnormal_S2_string r);
slop_string howl_test_s2_after_s1(slop_arena* arena, slop_result_howl_sriqelim_S1_string r);
slop_string howl_test_s2_after_s0(slop_arena* arena, slop_result_howl_sriqnormal_S0_string r);
slop_string howl_test_s2_of(slop_arena* arena, slop_string ttl);
uint8_t howl_test_s2_is(slop_arena* arena, slop_string label, slop_string ttl, slop_string want);
slop_list_string howl_test_sriq_fixtures(slop_arena* arena);
slop_option_howl_gate_GateResult howl_test_gate_triples_in(slop_arena* arena, slop_list_slop_rdf_rdf_Triple ts, howl_types_Profile p);
slop_list_howl_owl2_RawAxiom howl_test_reversed_raw(slop_arena* arena, slop_list_howl_owl2_RawAxiom xs);
slop_list_howl_sroiq_SAxiom howl_test_reversed_saxioms(slop_arena* arena, slop_list_howl_sroiq_SAxiom xs);
slop_result_howl_sriqnames_SriqNormal_string howl_test_s2_to_names(slop_arena* arena, howl_gate_GateResult gr, howl_sriqelim_S1 s1, uint8_t flip);
howl_sriqnormal_S0 howl_test_reversed_s0(slop_arena* arena, howl_sriqnormal_S0 s0);
slop_result_howl_sriqnames_SriqNormal_string howl_test_sriq_nf(slop_arena* arena, howl_gate_GateResult gr, uint8_t flip_accepted, uint8_t flip_s0, uint8_t flip_s2);
slop_list_string howl_test_nf_lines(slop_arena* arena, slop_result_howl_sriqnames_SriqNormal_string r);
uint8_t howl_test_nf_invariants_hold(slop_arena* arena, slop_string path, slop_result_howl_sriqnames_SriqNormal_string r);
uint8_t howl_test_sriq_order_independent(slop_arena* arena, slop_string path);
uint8_t howl_test_test_sriq_ids_row(slop_arena* arena);
uint8_t howl_test_test_sriq_one_clause_from_two_axioms(slop_arena* arena);
uint8_t howl_test_test_sriq_ids_from_content(slop_arena* arena);
uint8_t howl_test_yields_nothing_by_design(howl_owl2_RawAxiom a);
slop_list_howl_owl2_RawAxiom howl_test_one_raw(slop_arena* arena, howl_owl2_RawAxiom a);
uint8_t howl_test_print_alone(slop_arena* arena, howl_owl2_RawAxiom a);
uint8_t howl_test_is_chain_axiom(howl_owl2_RawAxiom a);
int64_t howl_test_yield_kind(slop_arena* arena, howl_owl2_RawAxiom a, howl_owl2_Signature sig);
uint8_t howl_test_every_axiom_yields(slop_arena* arena, slop_string path);
uint8_t howl_test_test_sriq_every_axiom_yields(slop_arena* arena);
slop_string howl_test_s1_text(slop_arena* arena, howl_sriqelim_S1 s1);
slop_string howl_test_s1_bounded_of(slop_arena* arena, slop_string ttl, int64_t bound);
uint8_t howl_test_s1_bounded_is(slop_arena* arena, slop_string label, slop_string ttl, int64_t bound, slop_string want);
uint8_t howl_test_test_sriq_guard_witnesses(slop_arena* arena);
uint8_t howl_test_test_sriq_s1_rows(slop_arena* arena);
uint8_t howl_test_s1_invariants_hold(slop_arena* arena, slop_string path);
uint8_t howl_test_print_problems(slop_string path, slop_list_string bad);
uint8_t howl_test_test_sriq_s1_invariants(slop_arena* arena);
uint8_t howl_test_test_sriq_s2_refuses_a_count_past_the_bound(slop_arena* arena);
uint8_t howl_test_test_sriq_s2_rows(slop_arena* arena);
slop_rdf_rdf_IRI howl_test_x_iri(slop_arena* arena, slop_string local);
howl_types_DName howl_test_dn(slop_arena* arena, slop_string local);
howl_types_DRole howl_test_dp(slop_arena* arena, slop_string local);
slop_list_slop_rdf_rdf_IRI howl_test_iris_of(slop_arena* arena, slop_list_string locals);
slop_list_string howl_test_strs(slop_arena* arena, slop_string text);
slop_list_string howl_test_split_lines(slop_arena* arena, slop_string text);
int64_t howl_test_module_dump(slop_arena* arena, slop_string path, slop_string seeds_path);
slop_list_howl_owl2_RawAxiom howl_test_file_axioms(slop_arena* arena, slop_string path);
int64_t howl_test_unreadable_count(slop_list_howl_owl2_RawAxiom axs);
void howl_test_dump_one_module(slop_arena* arena, slop_list_howl_owl2_RawAxiom axs, slop_string line);
slop_list_string howl_test_line1(slop_arena* arena, slop_string text);
howl_sriqnames_SriqNormal howl_test_row_normal(slop_arena* arena, slop_list_howl_types_DlClause cs, int64_t nfresh, int64_t nsub, int64_t nfns);
slop_string howl_test_clause_text(slop_arena* arena, howl_sriqnames_SriqNormal n);
uint8_t howl_test_clauses_sound(slop_arena* arena, howl_sriqnames_SriqNormal n);
uint8_t howl_test_table1_is(slop_arena* arena, slop_string label, howl_sriqnames_SriqNormal n, slop_string want);
slop_list_howl_types_DlClause howl_test_one_dl(slop_arena* arena, howl_types_DlClause c);
howl_types_DlClause howl_test_dl1_of(slop_arena* arena, slop_string body, slop_string head);
slop_list_int howl_test_fn_ids(slop_arena* arena, int64_t n);
howl_types_DlClause howl_test_dl4_of(slop_arena* arena, slop_string sub, int64_t n, slop_option_howl_types_DName filler);
howl_types_DlClause howl_test_dl2_of(slop_arena* arena, slop_string sub, howl_types_DRole role, int64_t n, slop_option_howl_types_DName filler);
uint8_t howl_test_table1_rows_names(slop_arena* arena);
uint8_t howl_test_table1_rows_dl4(slop_arena* arena);
uint8_t howl_test_table1_rows_roles(slop_arena* arena);
uint8_t howl_test_test_sriq_table1_rows(slop_arena* arena);
uint8_t howl_test_boundary_refuses(slop_arena* arena, slop_string label, howl_sriqnames_SriqNormal n, slop_string want);
uint8_t howl_test_test_sriq_clauses_cover_every_name(slop_arena* arena);
slop_list_howl_types_Lit howl_test_lits_of(slop_arena* arena, howl_types_Lit a, howl_types_Lit b, howl_types_Lit c);
slop_list_howl_types_Lit howl_test_no_lits(slop_arena* arena);
slop_list_howl_types_Lit howl_test_one_lit(slop_arena* arena, howl_types_Lit a);
uint8_t howl_test_not_canonical(slop_list_howl_types_Lit body, slop_list_howl_types_Lit head);
uint8_t howl_test_canonical_rejects(slop_arena* arena);
slop_list_howl_types_Lit howl_test_lits2_of(slop_arena* arena, howl_types_Lit a, howl_types_Lit b);
slop_map* howl_test_index_classes(slop_arena* arena, slop_list_howl_types_DName ds);
slop_map* howl_test_index_iris(slop_arena* arena, slop_list_slop_rdf_rdf_IRI xs);
uint8_t howl_test_permuted_tables_flagged(slop_arena* arena, howl_types_Clause ok_clause);
slop_list_howl_types_DRole howl_test_bars_swapped(slop_arena* arena);
slop_map* howl_test_bar_index(slop_arena* arena);
uint8_t howl_test_shape_rejects(slop_arena* arena);
uint8_t howl_test_flagged(slop_arena* arena, howl_sriqclauses_SriqIds ids, howl_types_Clause c);
uint8_t howl_test_ids_dense_rejects(slop_arena* arena);
slop_list_howl_types_DName howl_test_reverse_dnames(slop_arena* arena, slop_list_howl_types_DName xs);
uint8_t howl_test_test_sriq_clause_checks_reject(slop_arena* arena);
slop_list_howl_types_ATerm howl_test_sample_aterms(slop_arena* arena);
uint8_t howl_test_oriented_pair_ok(howl_types_ATerm s, howl_types_ATerm t, uint8_t same);
uint8_t howl_test_test_sriq_eq_orientation(slop_arena* arena);
slop_list_string howl_test_clause_lines(slop_arena* arena, slop_result_howl_sriqnames_SriqNormal_string r);
uint8_t howl_test_fixture_clauses_ok(slop_arena* arena, slop_string path);
uint8_t howl_test_test_sriq_clauses_on_fixtures(slop_arena* arena);
howl_sriqorder_SriqOrder howl_test_ord_table(slop_arena* arena);
slop_list_int howl_test_ord_label(slop_arena* arena, howl_sriqorder_SriqOrder ord, uint32_t u);
int64_t howl_test_ord_ints_cmp(slop_list_int a, slop_list_int b);
uint8_t howl_test_ref_const_gt(slop_arena* arena, howl_sriqorder_SriqOrder ord, uint32_t a, uint32_t b);
uint8_t howl_test_ref_is_var(howl_types_ATerm t);
uint8_t howl_test_ref_has_arg(howl_types_ATerm t);
howl_types_ATerm howl_test_ref_arg(howl_types_ATerm t);
uint8_t howl_test_ref_prec_gt(slop_arena* arena, howl_sriqorder_SriqOrder ord, howl_types_ATerm a, howl_types_ATerm b);
uint8_t howl_test_ref_same_head(howl_types_ATerm a, howl_types_ATerm b);
uint8_t howl_test_ref_lpo(slop_arena* arena, howl_sriqorder_SriqOrder ord, howl_types_ATerm s, howl_types_ATerm t);
uint8_t howl_test_ord_aterm_same(howl_types_ATerm a, howl_types_ATerm b);
slop_list_howl_types_ATerm howl_test_ord_aterms(slop_arena* arena);
slop_list_howl_sriqorder_CTerm howl_test_ord_push_binary(slop_arena* arena, slop_list_howl_sriqorder_CTerm out, howl_types_ATerm l, howl_types_ATerm r);
slop_list_howl_sriqorder_CTerm howl_test_ord_universe(slop_arena* arena);
slop_list_howl_sriqorder_CTerm howl_test_ord_universe_n(slop_arena* arena, int64_t npred);
howl_sriqorder_CTerm howl_test_ord_ct_at(slop_list_howl_sriqorder_CTerm xs, int64_t i);
uint8_t howl_test_ord_get(slop_list_u8 m, int64_t n, int64_t i, int64_t j);
uint8_t howl_test_ord_ge(slop_list_u8 m, int64_t n, slop_list_howl_sriqorder_CTerm u, int64_t i, int64_t j);
int64_t howl_test_ord_index(slop_list_howl_sriqorder_CTerm u, howl_types_ATerm t);
uint8_t howl_test_ord_arg_ge(slop_list_u8 m, int64_t n, slop_list_howl_sriqorder_CTerm u, howl_types_ATerm arg, int64_t j);
uint8_t howl_test_ord_p_args_le(slop_list_u8 m, int64_t n, slop_list_howl_sriqorder_CTerm u, howl_types_Lit a, howl_types_Lit b);
uint8_t howl_test_ord_generated(slop_arena* arena, howl_sriqorder_SriqOrder ord, slop_list_u8 m, int64_t n, slop_list_howl_sriqorder_CTerm u, int64_t i, int64_t j);
uint8_t howl_test_ord_rank_step(howl_sriqorder_SriqOrder ord, howl_types_Lit a, howl_types_Lit b);
uint8_t howl_test_ord_items_1_3(slop_arena* arena, howl_sriqorder_SriqOrder ord, howl_types_ATerm s, howl_types_ATerm t);
slop_list_u8 howl_test_ord_step(slop_arena* arena, howl_sriqorder_SriqOrder ord, slop_list_u8 m, int64_t n, slop_list_howl_sriqorder_CTerm u);
slop_list_u8 howl_test_ord_close(slop_list_u8 m, int64_t n);
uint8_t howl_test_ord_close_row(slop_list_u8 m, int64_t n, int64_t i, int64_t k);
int64_t howl_test_ord_count(slop_list_u8 m);
slop_list_u8 howl_test_ord_least(slop_arena* arena, howl_sriqorder_SriqOrder ord, slop_list_howl_sriqorder_CTerm u);
slop_string howl_test_ct_text(slop_arena* arena, howl_sriqorder_CTerm c);
slop_string howl_test_aterm_code(slop_arena* arena, howl_types_ATerm t);
int64_t howl_test_akind_code(howl_types_AKind k);
uint8_t howl_test_test_sriq_order_closure(slop_arena* arena);
uint8_t howl_test_test_sriq_ranked_order_closure(slop_arena* arena);
uint8_t howl_test_order_closure_on(slop_arena* arena, howl_sriqorder_SriqOrder ord, slop_list_howl_sriqorder_CTerm u);
int64_t howl_test_ord_row_mismatches(slop_arena* arena, howl_sriqorder_SriqOrder ord, slop_list_howl_sriqorder_CTerm u, slop_list_u8 m, int64_t i, int64_t seen);
uint8_t howl_test_test_sriq_order_strict_and_admissible(slop_arena* arena);
uint8_t howl_test_test_sriq_ranked_order_strict_and_admissible(slop_arena* arena);
uint8_t howl_test_order_strict_on(slop_arena* arena, howl_sriqorder_SriqOrder ord, slop_list_howl_sriqorder_CTerm u);
uint8_t howl_test_ord_pair_ok(slop_arena* arena, howl_sriqorder_SriqOrder ord, slop_list_howl_sriqorder_CTerm u, howl_sriqorder_CTerm s, howl_sriqorder_CTerm t);
uint8_t howl_test_ord_def7_5_bound(howl_types_Lit l);
uint8_t howl_test_test_sriq_order_c2(slop_arena* arena);
uint8_t howl_test_test_sriq_ranked_order_c2(slop_arena* arena);
uint8_t howl_test_order_c2_on(slop_arena* arena, howl_sriqorder_SriqOrder ord, slop_list_howl_sriqorder_CTerm u);
uint8_t howl_test_ord_c2_exempt(howl_sriqorder_CTerm s);
uint8_t howl_test_test_sriq_const_order(slop_arena* arena);
uint8_t howl_test_const_row_ok(slop_arena* arena, howl_sriqorder_SriqOrder ord, slop_list_int ranks, int64_t a);
slop_string howl_test_flags_text(slop_arena* arena, slop_list_u8 fs);
uint8_t howl_test_flags_are(slop_arena* arena, slop_string label, slop_list_howl_types_Lit head, slop_string want);
uint8_t howl_test_flags_under(slop_arena* arena, howl_sriqorder_SriqOrder ord, slop_string label, slop_list_howl_types_Lit head, slop_string want);
slop_list_howl_types_Lit howl_test_two_lits(slop_arena* arena, howl_types_Lit a, howl_types_Lit b);
uint8_t howl_test_test_sriq_max_flags_rows(slop_arena* arena);
uint8_t howl_test_test_sriq_ranked_max_flags_rows(slop_arena* arena);
slop_list_howl_types_Lit howl_test_ranked_sample_lits(slop_arena* arena);
slop_list_howl_types_Lit howl_test_sample_lits(slop_arena* arena);
uint8_t howl_test_lits_strict(slop_arena* arena, howl_sriqorder_SriqOrder ord, slop_list_howl_types_Lit ls);
slop_list_howl_types_Lit howl_test_letter_atoms(slop_arena* arena, slop_string letters);
howl_types_Clause howl_test_cl(slop_arena* arena, slop_string body, slop_string head);
howl_types_Clause howl_test_with_lit(slop_arena* arena, howl_types_Clause c, howl_types_Lit l);
slop_list_howl_types_Clause howl_test_clauses_of(slop_arena* arena, howl_types_Clause a, howl_types_Clause b);
uint8_t howl_test_test_sriq_inhat_rows(slop_arena* arena);
slop_list_howl_types_Clause howl_test_reference_min(slop_arena* arena, slop_list_howl_types_Clause xs);
uint8_t howl_test_in_list(slop_list_howl_types_Clause xs, howl_types_Clause c);
uint8_t howl_test_same_clause_set(slop_list_howl_types_Clause a, slop_list_howl_types_Clause b);
slop_list_howl_types_Clause howl_test_commit_w(slop_arena* arena);
slop_list_howl_types_Clause howl_test_commit_candidates(slop_arena* arena);
howl_types_Clause howl_test_clause_list_at(slop_list_howl_types_Clause xs, int64_t i, howl_types_Clause fallback);
slop_list_howl_types_Clause howl_test_permuted(slop_arena* arena, slop_list_howl_types_Clause xs, int64_t code);
slop_list_howl_types_Clause howl_test_appended(slop_arena* arena, slop_list_howl_types_Clause a, slop_list_howl_types_Clause b);
slop_list_howl_types_Clause howl_test_new_members(slop_arena* arena, slop_list_howl_types_Clause xs, slop_list_howl_types_Clause ws);
uint8_t howl_test_order_ok(slop_arena* arena, slop_list_howl_types_Clause ws, slop_list_howl_types_Clause order, slop_list_howl_types_Clause want, slop_list_howl_types_Clause want_added);
uint8_t howl_test_test_sriq_commit_min_permutation(slop_arena* arena);
uint8_t howl_test_keeps_but_adds_not(slop_arena* arena);
uint8_t howl_test_test_sriq_commit_survivors(slop_arena* arena);
uint8_t howl_test_test_sriq_inhat_persists(slop_arena* arena);
howl_types_Lit howl_test_r_atom(int64_t c, howl_types_ATerm t);
howl_types_Lit howl_test_r_role(int64_t r, howl_types_ATerm a, howl_types_ATerm b);
howl_types_ATerm howl_test_r_fx(int64_t f);
howl_types_Clause howl_test_r_clause(slop_arena* arena, slop_list_howl_types_Lit body, slop_list_howl_types_Lit head);
slop_list_howl_sriq_Premise howl_test_r_premises(slop_arena* arena, howl_sriqorder_SriqOrder ord, howl_types_Clause c);
slop_list_howl_sriq_Cands howl_test_r_cands(slop_arena* arena, howl_sriqorder_SriqOrder ord, int64_t atoms, slop_list_howl_types_Clause cs);
slop_list_howl_types_Clause howl_test_r_hyper(slop_arena* arena, howl_sriq_HState start, howl_types_Clause ont, slop_list_howl_types_Clause cs);
slop_list_howl_types_Clause howl_test_r_useful(slop_arena* arena, slop_list_howl_types_Clause cs);
slop_list_howl_types_Clause howl_test_r_one(slop_arena* arena, howl_types_Clause c);
uint8_t howl_test_hyper_is(slop_arena* arena, slop_string label, slop_list_howl_types_Clause got, slop_list_howl_types_Clause want);
howl_sriq_Premise howl_test_r_premise(slop_arena* arena, howl_sriqorder_SriqOrder ord, howl_types_Clause c, howl_types_Lit l);
uint8_t howl_test_test_sriq_hyper_rows(slop_arena* arena);
uint8_t howl_test_test_sriq_hyper_dl4(slop_arena* arena);
uint8_t howl_test_test_sriq_hyper_root_rows(slop_arena* arena);
uint8_t howl_test_test_sriq_hyper_example1(slop_arena* arena);
uint8_t howl_test_test_sriq_ineq_factor_core_rows(slop_arena* arena);
uint8_t howl_test_test_sriq_factor_each_condition(slop_arena* arena);
howl_sriq_Pos howl_test_r_pos(int64_t k, uint8_t inner);
howl_types_Clause howl_test_r_top(slop_arena* arena, slop_list_howl_types_Lit head);
howl_sriq_RConcl howl_test_r_eq(slop_arena* arena, uint8_t root, howl_types_Clause c1, howl_types_Lit l1, int64_t k1, howl_types_Clause c2, howl_types_Lit l2, howl_sriq_Pos p);
uint8_t howl_test_eq_gives(slop_arena* arena, slop_string label, howl_sriq_RConcl r, howl_types_Clause want);
uint8_t howl_test_test_sriq_eq_rows(slop_arena* arena);
int64_t howl_test_side_of(howl_types_Lit l, howl_types_ATerm s);
uint8_t howl_test_test_sriq_eq_excluded(slop_arena* arena);
uint8_t howl_test_test_sriq_join_rows(slop_arena* arena);
howl_sriq_BodyView howl_test_r_body(slop_arena* arena, howl_types_Clause c, howl_types_Lit l);
howl_sriqorder_SriqOrder howl_test_r_kids_order(slop_arena* arena);
slop_list_u32 howl_test_r_ids(slop_arena* arena, int64_t a, int64_t b);
uint8_t howl_test_test_sriq_nom_rows(slop_arena* arena);
uint8_t howl_test_test_sriq_depth_limit(slop_arena* arena);
uint8_t howl_test_want(slop_string label, uint8_t got, uint8_t expected);
uint8_t howl_test_want_int(slop_arena* arena, slop_string label, int64_t got, int64_t expected);
slop_list_howl_types_Clause howl_test_o1_clauses(slop_arena* arena);
howl_sriqctx_Triggers howl_test_o1_triggers(slop_arena* arena);
uint8_t howl_test_test_sriq_triggers_rows(slop_arena* arena);
uint8_t howl_test_triggers_edge_rows(slop_arena* arena);
uint8_t howl_test_shape_rows(void);
uint8_t howl_test_test_sriq_strategy_rows(slop_arena* arena);
uint8_t howl_test_core_is(slop_arena* arena, slop_string label, howl_sriqctx_CoreChoice cc, slop_list_howl_types_Lit k1, slop_list_howl_types_Lit expected);
uint8_t howl_test_test_sriq_structure_rows(slop_arena* arena);
uint8_t howl_test_ctx_root_is(howl_sriqctx_Structure st, int64_t v, uint8_t root);
uint8_t howl_test_all_sets_empty(howl_sriqctx_Structure st);
uint8_t howl_test_role_triggers_ok(howl_sriqctx_Triggers tr, howl_types_Lit l);
uint8_t howl_test_body_lit_triggers_ok(howl_sriqctx_Triggers tr, howl_types_Lit l);
uint8_t howl_test_body_triggers_ok(howl_sriqctx_Triggers tr, howl_types_Clause c);
uint8_t howl_test_test_sriq_triggers_on_fixtures(slop_arena* arena);
slop_option_howl_sriqclauses_SriqClauses howl_test_fixture_sc(slop_arena* arena, slop_string path);
slop_list_howl_types_Clause howl_test_o3_clauses(slop_arena* arena);
slop_list_howl_types_Clause howl_test_o3_fixed_clauses(slop_arena* arena);
howl_sriqctx_Triggers howl_test_o3_triggers(slop_arena* arena);
uint8_t howl_test_lits_same_set(slop_list_howl_types_Lit a, slop_list_howl_types_Lit b);
howl_sriq_SuccSig howl_test_sig_of(int64_t f);
howl_sriq_SuccSig howl_test_sig_root(int64_t f, int64_t u);
slop_list_howl_types_Clause howl_test_o1_va(slop_arena* arena);
uint8_t howl_test_succ_is(slop_arena* arena, slop_string label, howl_sriq_SuccConcl c, uint8_t fires, howl_sriqctx_CoreKind kind, slop_list_howl_types_Lit adds);
uint8_t howl_test_test_sriq_succ_rows(slop_arena* arena);
uint8_t howl_test_succ_edge_rows(slop_arena* arena, howl_sriqctx_Triggers tr, howl_sriqorder_SriqOrder ord);
uint8_t howl_test_succ_covers_rows(slop_arena* arena, howl_sriq_KSets ksf);
uint8_t howl_test_succ_ground_and_root(slop_arena* arena, howl_sriqctx_Triggers tr, howl_sriqorder_SriqOrder ord);
uint8_t howl_test_pre_is(howl_sriq_SuccSig sg, howl_types_Lit a);
uint8_t howl_test_test_sriq_succ_pre_inverts(slop_arena* arena);
slop_list_howl_sriq_SuccSig howl_test_lits_sigs(slop_arena* arena, int64_t f);
uint8_t howl_test_test_sriq_rsucc_rows(slop_arena* arena);
uint8_t howl_test_rsucc_is(howl_sriq_RSuccConcl c, uint8_t fires, howl_types_Lit l);
slop_list_howl_sriq_Premise howl_test_side_cands(slop_arena* arena, howl_sriqorder_SriqOrder ord, slop_list_howl_types_Clause ws);
slop_list_howl_types_Clause howl_test_pred_concls(slop_arena* arena, howl_sriqorder_SriqOrder ord, howl_sriqctx_Triggers tr, uint8_t to_root, howl_sriq_CSub s, uint8_t edge, howl_types_Clause c, slop_list_howl_types_Lit core, slop_list_howl_types_Clause ws);
uint8_t howl_test_test_sriq_pred_rows(slop_arena* arena);
uint8_t howl_test_pred_edge_rows(slop_arena* arena, howl_sriqctx_Triggers tr, howl_sriqorder_SriqOrder ord);
uint8_t howl_test_pred_root_rows(slop_arena* arena);
slop_list_howl_types_Clause howl_test_rpred_concls(slop_arena* arena, howl_sriqorder_SriqOrder ord, howl_sriqctx_Triggers tr, howl_types_Clause c, slop_list_u32 edges, slop_list_howl_types_Clause ws);
uint8_t howl_test_slot_has_edge(howl_types_Lit l, slop_list_u32 edges);
uint8_t howl_test_test_sriq_rpred_rows(slop_arena* arena);
slop_list_u32 howl_test_r_u32s(slop_arena* arena, int64_t u);
howl_sriqref_RefConfig howl_test_ref_cfg(howl_sriqctx_Strategy s);
howl_sriqref_RefIn howl_test_ref_in(slop_arena* arena, slop_list_howl_types_Clause onto, int64_t nclass, int64_t nquery, int64_t nrole, int64_t nfn, int64_t nconst);
slop_list_howl_sriqctx_Strategy howl_test_strategies(slop_arena* arena);
slop_string howl_test_strat_name(howl_sriqctx_Strategy s);
uint8_t howl_test_complete_run(howl_sriqref_RefResult r);
uint8_t howl_test_ref_says(slop_string label, howl_sriqctx_Strategy s, uint8_t got, uint8_t expected);
uint8_t howl_test_run_checks(slop_arena* arena, slop_string label, howl_sriqref_RefIn in, howl_sriqctx_Strategy s, howl_sriqref_RefResult r);
uint8_t howl_test_run_checks_with(slop_arena* arena, slop_string label, howl_sriqref_RefIn in, howl_sriqctx_Strategy s, howl_sriqref_RefResult r, uint8_t stable);
uint8_t howl_test_all_ctx_clauses(slop_arena* arena, howl_sriqctx_Structure st);
uint8_t howl_test_all_min(slop_arena* arena, howl_sriqctx_Structure st);
uint8_t howl_test_set_min(slop_list_howl_types_Clause cs);
slop_list_howl_types_Clause howl_test_o4_clauses(slop_arena* arena);
uint8_t howl_test_test_sriq_ref_papers(slop_arena* arena);
uint8_t howl_test_papers_under(slop_arena* arena, howl_sriqref_RefIn o1, howl_sriqref_RefIn o3, howl_sriqref_RefIn o3p, howl_sriqref_RefIn o4, howl_sriqctx_Strategy s);
uint8_t howl_test_o1_holds(slop_arena* arena, howl_sriqref_RefIn o1, howl_sriqctx_Strategy s, howl_sriqref_RefResult r1);
uint8_t howl_test_o3_holds(slop_arena* arena, howl_sriqref_RefIn o3, howl_sriqref_RefIn o3p, howl_sriqctx_Strategy s, howl_sriqref_RefResult r3, howl_sriqref_RefResult r3p);
uint8_t howl_test_o4_holds(slop_arena* arena, howl_sriqref_RefIn o4, howl_sriqctx_Strategy s, howl_sriqref_RefResult r4);
slop_list_howl_types_Clause howl_test_e4_clauses(slop_arena* arena);
slop_list_howl_types_Clause howl_test_core_row_clauses(slop_arena* arena);
slop_list_howl_types_Clause howl_test_thing_row_clauses(slop_arena* arena);
slop_list_howl_types_Clause howl_test_rsucc_row_clauses(slop_arena* arena);
slop_list_howl_types_Clause howl_test_not_dl4_clauses(slop_arena* arena);
uint8_t howl_test_root_rows(slop_arena* arena, howl_sriqctx_Strategy s);
uint8_t howl_test_not_dl4_row(slop_arena* arena, howl_sriqctx_Strategy s);
uint8_t howl_test_test_sriq_ref_e4_rows(slop_arena* arena);
slop_list_howl_test_Expect howl_test_expects(slop_arena* arena);
slop_list_howl_test_Expect howl_test_abox_expects(slop_arena* arena);
uint32_t howl_test_class_named(slop_arena* arena, howl_sriqclauses_SriqIds ids, slop_string name);
uint8_t howl_test_expect_holds(slop_arena* arena, howl_sriqclauses_SriqIds ids, howl_sriqctx_Structure st, howl_test_Expect e);
slop_string howl_test_fixture_path(slop_arena* arena, slop_string name);
slop_list_u8 howl_test_raw_answers(slop_arena* arena, howl_sriqclauses_SriqIds ids, howl_sriqctx_Structure st);
uint8_t howl_test_same_bools(slop_list_u8 a, slop_list_u8 b);
uint8_t howl_test_fixture_ref(slop_arena* arena, slop_string name);
uint8_t howl_test_fixture_ref_sc(slop_arena* arena, slop_string name, howl_sriqclauses_SriqClauses sc);
uint8_t howl_test_expects_met(slop_arena* arena, slop_string name, howl_sriqclauses_SriqIds ids, howl_sriqctx_Strategy s, howl_sriqref_RefResult r);
uint8_t howl_test_test_sriq_ref_fixtures(slop_arena* arena);
uint8_t howl_test_test_sriq_ref_limits(slop_arena* arena);
slop_list_u8 howl_test_o4_answers(slop_arena* arena, howl_sriqctx_Structure st);
slop_list_howl_types_Clause howl_test_reversed_clauses(slop_arena* arena, slop_list_howl_types_Clause cs);
howl_sriqsat_SatConfig howl_test_sat_cfg(howl_sriqctx_Strategy s, int64_t perm);
howl_sriqsat_SatConfig howl_test_sat_cfg_at(howl_sriqctx_Strategy s, int64_t perm, uint8_t defer);
howl_sriqsat_SatConfig howl_test_sat_fuel(howl_sriqctx_Strategy s, int64_t fuel);
slop_list_u8 howl_test_answers_of(slop_arena* arena, howl_sriqctx_Structure st, int64_t n);
uint8_t howl_test_implied(slop_list_u8 a, slop_list_u8 b);
uint8_t howl_test_proto_says(slop_arena* arena, slop_string label, howl_sriqctx_Strategy s, uint8_t ok);
uint8_t howl_test_proto_agrees(slop_arena* arena, slop_string label, howl_sriqref_RefIn in, int64_t n, howl_sriqctx_Strategy s);
uint8_t howl_test_kidx_agrees(slop_arena* arena, howl_sriqref_RefIn in, howl_sriqctx_Structure st);
uint8_t howl_test_kidx_one(slop_arena* arena, howl_sriqctx_Triggers tr, howl_sriqctx_Structure st, uint8_t root, slop_list_howl_types_Clause cs);
uint8_t howl_test_kidx_clause(slop_arena* arena, howl_sriqctx_Triggers tr, howl_sriqctx_Structure st, uint8_t root, slop_list_howl_types_Clause cs, howl_sriqindex_KIdx kx, howl_types_Clause c);
uint8_t howl_test_same_ksets(howl_sriq_KSets a, howl_sriq_KSets b);
howl_sriqref_RefResult howl_test_as_m(slop_arena* arena, howl_sriqref_RefIn in, howl_sriqref_RefResult r);
uint8_t howl_test_proto_perms(slop_arena* arena, slop_string label, howl_sriqref_RefIn in, int64_t n, howl_sriqctx_Strategy s, howl_sriqsat_SatResult p);
uint8_t howl_test_perm_same(slop_arena* arena, slop_string label, howl_sriqref_RefIn in, int64_t n, howl_sriqctx_Strategy s, howl_sriqsat_SatResult p, int64_t perm);
uint8_t howl_test_proto_caps(slop_arena* arena, slop_string label, howl_sriqref_RefIn in, int64_t n, howl_sriqctx_Strategy s, howl_sriqsat_SatResult p);
slop_list_howl_types_Clause howl_test_rpred_late_clauses(slop_arena* arena);
uint8_t howl_test_test_sriq_rpred_late(slop_arena* arena);
slop_list_howl_types_Clause howl_test_view_eq_clauses(slop_arena* arena);
slop_list_howl_types_Clause howl_test_root_hyper_clauses(slop_arena* arena);
slop_list_howl_types_Clause howl_test_view_join_clauses(slop_arena* arena);
slop_list_howl_types_Clause howl_test_view_units_clauses(slop_arena* arena);
uint8_t howl_test_test_sriq_view_eq(slop_arena* arena);
slop_list_howl_test_ProtoCase howl_test_proto_cases(slop_arena* arena);
uint8_t howl_test_test_sriq_proto_rows(slop_arena* arena);
uint8_t howl_test_test_sriq_proto_work(slop_arena* arena);
uint8_t howl_test_o1_work(slop_arena* arena, uint8_t defer, int64_t succs);
uint8_t howl_test_qualified_max_rounds(slop_arena* arena);
uint8_t howl_test_test_sriq_proto_fixtures(slop_arena* arena);
uint8_t howl_test_fixture_proto(slop_arena* arena, slop_string name);
uint8_t howl_test_fixture_proto_sc(slop_arena* arena, slop_string name, howl_sriqclauses_SriqClauses sc);
uint8_t howl_test_same_list(slop_list_howl_types_Clause a, slop_list_howl_types_Clause b);
uint8_t howl_test_commits_agree(slop_arena* arena, slop_list_howl_types_Clause ws, slop_list_howl_types_Clause cs);
howl_types_Clause howl_test_dropped_last(slop_arena* arena, howl_types_Clause c);
slop_list_howl_types_Lit howl_test_but_last(slop_arena* arena, slop_list_howl_types_Lit ls);
uint8_t howl_test_split_agrees(slop_arena* arena, slop_list_howl_types_Clause s);
uint8_t howl_test_structure_agrees(slop_arena* arena, howl_sriqctx_Structure st);
uint8_t howl_test_commit_edge_row(slop_arena* arena);
uint8_t howl_test_scan_same(slop_arena* arena, slop_string label, howl_sriqref_RefIn in, int64_t n, howl_sriqctx_Strategy s);
uint8_t howl_test_same_edges(slop_list_howl_sriqctx_Edge a, slop_list_howl_sriqctx_Edge b);
uint8_t howl_test_test_nt_escape(slop_arena* arena);
uint8_t howl_test_test_sriq_wired(slop_arena* arena);
uint8_t howl_test_wired_says(slop_arena* arena, slop_string label, uint8_t ok);
uint8_t howl_test_wired_fixture(slop_arena* arena, slop_string name);
uint8_t howl_test_wired_agrees(slop_arena* arena, slop_string name, howl_types_Outcome o, howl_sriqabox_Inputs in);
uint8_t howl_test_is_fixpoint(howl_types_Termination t);
slop_list_slop_rdf_rdf_IRI howl_test_query_classes(slop_arena* arena, howl_sriqclauses_SriqIds ids);
slop_list_slop_rdf_rdf_IRI howl_test_raw_unsat(slop_arena* arena, howl_sriqctx_Structure st, slop_list_slop_rdf_rdf_IRI classes);
slop_list_howl_types_SubPair howl_test_raw_pairs(slop_arena* arena, howl_sriqctx_Structure st, slop_list_slop_rdf_rdf_IRI classes);
slop_list_howl_types_SubPair howl_test_raw_class_rows(slop_arena* arena, howl_sriqctx_Structure st, slop_list_slop_rdf_rdf_IRI classes, int64_t b);
slop_list_howl_types_SubPair howl_test_distinct_sub_pairs(slop_arena* arena, slop_list_howl_types_SubPair ps);
uint8_t howl_test_same_iri_lists(slop_list_slop_rdf_rdf_IRI a, slop_list_slop_rdf_rdf_IRI b);
uint8_t howl_test_same_pair_lists(slop_list_howl_types_SubPair a, slop_list_howl_types_SubPair b);
slop_result_howl_types_Outcome_howl_types_Fault howl_test_sriq_run_cfg(slop_arena* arena, slop_string name, howl_types_ReasonerConfig cfg);
howl_types_ReasonerConfig howl_test_with_rounds(int64_t k);
slop_option_howl_types_Outcome howl_test_outcome_of(slop_result_howl_types_Outcome_howl_types_Fault r);
int64_t howl_test_h_rounds_of(howl_types_Outcome o);
uint8_t howl_test_wired_cap_rows(slop_arena* arena);
uint8_t howl_test_wired_shared_budget(slop_arena* arena, howl_types_Outcome o);
uint8_t howl_test_wired_budget_row(slop_arena* arena);
uint8_t howl_test_wired_abandon_scan(slop_arena* arena, slop_string name, uint8_t run_c);
slop_list_howl_test_RoundAt howl_test_round_profile(slop_arena* arena, howl_sriqref_RefIn h);
int64_t howl_test_expected_stop(slop_list_howl_test_RoundAt ps, int64_t b);
int64_t howl_test_abandon_at(slop_arena* arena, howl_sriqref_RefIn run, slop_list_slop_rdf_rdf_IRI classes, slop_list_howl_test_RoundAt ps, int64_t b);
uint8_t howl_test_wired_cancel_row(slop_arena* arena);
uint8_t howl_test_is_cancelled(slop_result_howl_types_Outcome_howl_types_Fault r);
uint8_t howl_test_wired_omission_rows(slop_arena* arena);
slop_list_howl_owl2_RawAxiom howl_test_twice(slop_arena* arena, slop_list_howl_owl2_RawAxiom xs);
uint8_t howl_test_test_sriq_views(slop_arena* arena);
uint8_t howl_test_fixture_views(slop_arena* arena, slop_string name);
uint8_t howl_test_views_says(slop_arena* arena, slop_string label, howl_sriqctx_Strategy s, uint8_t ok);
uint8_t howl_test_views_same(slop_arena* arena, slop_string name, howl_sriqref_RefIn in, int64_t n, howl_sriqctx_Strategy s);
uint8_t howl_test_test_sriq_split_fixtures(slop_arena* arena);
uint8_t howl_test_fixture_split(slop_arena* arena, slop_string name);
uint8_t howl_test_split_says(slop_arena* arena, slop_string label, howl_sriqctx_Strategy s, uint8_t ok);
uint8_t howl_test_split_run_agrees(slop_arena* arena, slop_string name, howl_sriqclauses_SriqClauses sc, howl_sriqabox_Inputs in, howl_sriqctx_Strategy s);
uint8_t howl_test_split_expects(slop_arena* arena, slop_string name, howl_sriqclauses_SriqIds ids, howl_sriqctx_Strategy s, howl_sriqabox_SplitRun sp);
uint8_t howl_test_test_sriq_split_rows(slop_arena* arena);
uint8_t howl_test_split_omitted_row(slop_arena* arena, slop_string name, uint8_t incons);
uint8_t howl_test_split_omitted_in(slop_arena* arena, slop_string name, uint8_t incons, howl_sriqabox_Inputs in);
slop_rdf_rdf_IRI howl_test_t_iri(slop_string local);
uint8_t howl_test_split_odd_list_row(slop_arena* arena);
howl_owl2_RawConcept* howl_test_boxed(slop_arena* arena, howl_owl2_RawConcept c);
uint8_t howl_test_list_has_different(slop_list_howl_owl2_RawAxiom axs, int64_t n);
uint8_t howl_test_split_h_as_ref(slop_arena* arena, slop_string name, howl_sriqabox_Inputs in, howl_sriqctx_Strategy s, howl_sriqabox_SplitRun sp);
uint8_t howl_test_test_sriq_defer_rows(slop_arena* arena);
uint8_t howl_test_defer_activates(slop_arena* arena);
uint8_t howl_test_defer_retargets(slop_arena* arena);
uint8_t howl_test_top_edge_to(slop_arena* arena, howl_sriqctx_Structure st, uint32_t b);
uint8_t howl_test_test_sriq_index(slop_arena* arena);
uint8_t howl_test_fixture_scan_same(slop_arena* arena, slop_string name);
slop_option_howl_sriqctx_Strategy howl_test_parse_strategy(slop_string name);
slop_string howl_test_status_name(howl_sriqref_RefStatus s);
int64_t howl_test_print_ref_report(slop_arena* arena, howl_sriqclauses_SriqIds ids, howl_sriqctx_Structure st, slop_string who, howl_sriqctx_Strategy s, int64_t rounds);
int64_t howl_test_print_report_as(slop_arena* arena, howl_sriqclauses_SriqIds ids, howl_sriqctx_Structure st, uint8_t inconsistent, slop_string who, howl_sriqctx_Strategy s, int64_t rounds);
int64_t howl_test_print_thing_rows(slop_arena* arena, howl_sriqclauses_SriqIds ids, howl_sriqctx_Structure st, slop_string thing);
int64_t howl_test_print_class_rows(slop_arena* arena, howl_sriqclauses_SriqIds ids, howl_sriqctx_Structure st, uint32_t b, slop_string thing, slop_string nothing);
slop_result_howl_sriqclauses_SriqClauses_string howl_test_sriq_load(slop_arena* arena, slop_string path);
int64_t howl_test_sriq_ref(slop_arena* arena, slop_string path, slop_string strat, uint8_t proto, uint8_t counts);
int64_t howl_test_sriq_proto(slop_arena* arena, slop_string path, slop_string strat, uint8_t counts, int64_t rounds, uint8_t defer, uint8_t split, uint8_t views);
slop_result_howl_sriqabox_Inputs_string howl_test_split_load(slop_arena* arena, slop_string path);
int64_t howl_test_split_report(slop_arena* arena, slop_string path, howl_sriqctx_Strategy s, uint8_t counts, int64_t rounds, uint8_t defer, uint8_t views);
slop_string howl_test_split_na(slop_arena* arena, howl_sriqabox_SplitRun sp);
uint8_t howl_test_finished_run(howl_sriqref_RefResult r);
int64_t howl_test_ref_report(slop_arena* arena, howl_sriqclauses_SriqClauses sc, howl_sriqctx_Strategy s);
howl_sriqsat_SatConfig howl_test_proto_cfg(howl_sriqctx_Strategy s, int64_t rounds, uint8_t defer, uint8_t views);
int64_t howl_test_proto_report(slop_arena* arena, howl_sriqclauses_SriqClauses sc, howl_sriqctx_Strategy s, uint8_t counts, int64_t rounds, uint8_t defer, uint8_t views);
int64_t howl_test_count_line(slop_arena* arena, slop_string name, int64_t n);
int64_t howl_test_root_kinds(slop_arena* arena, howl_sriqctx_Structure st);
uint8_t howl_test_clause_has_fterm(howl_types_Clause c);
int64_t howl_test_print_counts(slop_arena* arena, howl_sriqsat_SatResult p);
uint8_t howl_test_test_sriq_gate_table(slop_arena* arena);
uint8_t howl_test_test_el_plus_plus_gate_table(slop_arena* arena);
uint8_t howl_test_test_top_role_tautology_is_dropped(slop_arena* arena);
slop_string howl_test_ksc_form_of_ttl(slop_arena* arena, slop_string ttl);
uint8_t howl_test_ksc_form_is(slop_arena* arena, slop_string label, slop_string ttl, slop_string want);
slop_option_howl_test_KscFixture howl_test_ksc_fixture(slop_arena* arena, slop_string path);
slop_string howl_test_kname_label(slop_arena* arena, howl_types_KName n);
uint8_t howl_test_ksc_engine_matches_reference(slop_arena* arena, slop_string label, slop_string ttl);
int64_t howl_test_ksc_holds(slop_arena* arena, slop_string ttl, slop_string a, slop_string b);
int64_t howl_test_ksc_inconsistent(slop_arena* arena, slop_string ttl);
int64_t howl_test_ksc_fixture_count(void);
slop_string howl_test_ksc_fixture_at(int64_t i);
howl_types_ReasonerConfig howl_test_cap_config(int64_t cap);
int64_t howl_test_incomplete_answers(howl_types_KscResult r);
uint8_t howl_test_says_resource_limit(howl_types_KscResult r);
int64_t howl_test_capped_incomplete(slop_arena* arena, howl_test_KscFixture fx);
uint8_t howl_test_test_ksc_cut_runs_say_resource_limit(slop_arena* arena);
howl_types_KFact howl_test_ex_class_fact(slop_arena* arena, slop_string ind, slop_string cls);
uint8_t howl_test_test_ksc_g_stops_at_bottom(slop_arena* arena);
uint8_t howl_test_test_ksc_engine_matches_reference(slop_arena* arena);
uint8_t howl_test_test_ksc_entailments(slop_arena* arena);
slop_option_howl_types_Outcome howl_test_classify_fixture_in(slop_arena* arena, slop_string path, howl_types_Profile profile);
slop_list_string howl_test_rung_neutral_lines(slop_arena* arena, howl_types_Outcome o);
uint8_t howl_test_rungs_agree_on(slop_arena* arena, slop_string path);
uint8_t howl_test_rung_pair_agrees(slop_arena* arena, slop_string path, howl_types_Profile x, howl_types_Profile y);
uint8_t howl_test_test_el_plus_plus_and_sriq_agree(slop_arena* arena);
int64_t howl_test_pp_sriq_compare(slop_arena* arena, slop_string path);
uint8_t howl_test_complete_outcome(howl_types_Outcome o);
uint8_t howl_test_test_el_and_el_plus_plus_agree(slop_arena* arena);
howl_types_KscResult howl_test_ksc_run(slop_arena* arena, slop_list_howl_types_KscAxiom axioms, slop_list_howl_types_KName classes, howl_types_ReasonerConfig config);
int64_t howl_test_cancel_flag_set(void);
uint8_t howl_test_test_ksc_cancelled(slop_arena* arena);
uint8_t howl_test_cancelled_under(slop_arena* arena, howl_types_ReasonerConfig base_cfg);
uint8_t howl_test_ids_round_trip(slop_arena* arena, slop_list_howl_types_KscAxiom axioms, slop_list_howl_types_KName classes);
uint8_t howl_test_test_ksc_ids_round_trip(slop_arena* arena);
uint8_t howl_test_holds_under(howl_kscpremise_KscIndex idx, slop_list_howl_types_KFact fs, howl_types_KElem x, howl_types_RoleId v, howl_types_KElem y);
uint8_t howl_test_g_matches_reference(slop_arena* arena, slop_list_howl_types_KscAxiom axioms, slop_list_howl_types_KName classes);
uint8_t howl_test_test_ksc_g_matches_reference(slop_arena* arena);
uint8_t howl_test_commit_agrees(slop_arena* arena, slop_list_howl_types_KscAxiom axioms, slop_list_howl_types_KName classes, uint8_t stop, uint8_t with_classes);
uint8_t howl_test_commit_shapes_agree(slop_arena* arena, howl_test_KscFixture fx, int64_t i);
uint8_t howl_test_test_ksc_commit_identical(slop_arena* arena);
howl_types_ReasonerConfig howl_test_ksc_config(int64_t workers, int64_t cap);
uint8_t howl_test_answers_equal(howl_types_KscResult a, howl_types_KscResult b);
uint8_t howl_test_test_ksc_workers_agree(slop_arena* arena);
uint8_t howl_test_same_run(howl_types_KscResult a, howl_types_KscResult b);
slop_list_int howl_test_workers_under_test(slop_arena* arena);
uint8_t howl_test_test_ksc_seed_unsat_counts_no_round(slop_arena* arena);
int64_t howl_test_nothing_run_rounds(howl_types_KscResult r);
int64_t howl_test_max_run_rounds(howl_types_KscResult r);
uint8_t howl_test_test_ksc_cap(slop_arena* arena);
uint8_t howl_test_test_ksc_normal_form_rows(slop_arena* arena);
slop_string howl_test_omissions_of_ttl(slop_arena* arena, slop_string ttl);
uint8_t howl_test_omits_exactly(slop_arena* arena, slop_string label, slop_string ttl, slop_string want);
slop_string howl_test_eq_prefix(void);
uint8_t howl_test_test_equality_never_drops_an_operand(slop_arena* arena);
uint8_t howl_test_test_anonymous_members_are_omissions_not_faults(slop_arena* arena);
uint8_t howl_test_test_negative_assertion_decodes_whole(slop_arena* arena);
uint8_t howl_test_test_literal_has_value_is_data(slop_arena* arena);
slop_string howl_test_neg_prefix(void);
uint8_t howl_test_accepts_exactly(slop_arena* arena, slop_string label, slop_string ttl, slop_string want);
uint8_t howl_test_test_negation_rewrites_to_bottom_gcis(slop_arena* arena);
uint8_t howl_test_test_negation_rewrites_whole_axioms_or_none(slop_arena* arena);
uint8_t howl_test_test_negative_range_normalizes_to_bottom(slop_arena* arena);
uint8_t howl_test_norm_eq(howl_types_NormAxiom a, howl_types_NormAxiom b);
uint8_t howl_test_norm_contains(slop_list_howl_types_NormAxiom xs, howl_types_NormAxiom a);
slop_option_howl_normalize_NormOutput howl_test_normalize_fixture(slop_arena* arena, slop_string path);
uint8_t howl_test_test_litmus_reproduces_the_m1_normal_form(slop_arena* arena);
uint8_t howl_test_test_normalization_polarity_is_negative_on_the_left(slop_arena* arena);
uint8_t howl_test_test_range_elimination_introduces_a_shared_filler(slop_arena* arena);
uint8_t howl_test_test_asserted_edges_seed_their_range(slop_arena* arena);
uint8_t howl_test_test_range_complex_fillers_stay_apart(slop_arena* arena);
uint8_t howl_test_complex_range_fillers_distinct(slop_arena* arena, slop_string path);
uint8_t howl_test_test_inverse_expressions_are_omissions(slop_arena* arena);
slop_list_string howl_test_m0_fixture_paths(slop_arena* arena);
uint8_t howl_test_accounting_exempt(howl_owl2_RawAxiom ax);
uint8_t howl_test_axiom_accounted(slop_arena* arena, howl_owl2_RawAxiom ax);
uint8_t howl_test_test_accounting_holds(slop_arena* arena);
uint8_t howl_test_same_rendering(slop_arena* arena, slop_list_howl_owl2_RawAxiom xs, slop_list_howl_owl2_RawAxiom ys);
uint8_t howl_test_test_canonicalization_is_idempotent(slop_arena* arena);
slop_list_howl_types_Node howl_test_norm_nodes(slop_arena* arena, howl_types_NormAxiom ax);
uint8_t howl_test_fresh_ids_dense(slop_arena* arena, howl_normalize_NormOutput no);
uint8_t howl_test_test_fresh_nodes_are_fresh(slop_arena* arena);
slop_list_slop_rdf_rdf_Triple howl_test_reversed_triples(slop_arena* arena, slop_list_slop_rdf_rdf_Triple ts);
slop_option_howl_normalize_NormOutput howl_test_normalize_triples(slop_arena* arena, slop_list_slop_rdf_rdf_Triple ts);
uint8_t howl_test_same_normal_form(howl_normalize_NormOutput a, howl_normalize_NormOutput b);
uint8_t howl_test_same_report(howl_types_Outcome a, howl_types_Outcome b);
uint8_t howl_test_same_lines(slop_list_string a, slop_list_string b);
uint8_t howl_test_encoded_agrees(slop_arena* arena, slop_string path, howl_types_ProfileSelection selection);
uint8_t howl_test_test_classify_encoded_is_classify(slop_arena* arena);
slop_option_string howl_test_file_text(slop_arena* arena, slop_string path);
slop_list_string howl_test_api_lines(slop_arena* arena, howl_Run r);
uint8_t howl_test_api_agrees(slop_arena* arena, slop_string path, howl_types_Profile profile);
howl_FaultKind howl_test_api_fault(howl_Options o);
uint8_t howl_test_test_public_api(slop_arena* arena);
slop_option_howl_types_Outcome howl_test_classify_in(slop_arena* arena, slop_string path, howl_types_Profile profile);
slop_list_slop_rdf_rdf_IRI howl_test_report_classes(slop_arena* arena, howl_types_Findings f);
slop_list_slop_rdf_rdf_IRI howl_test_unique_classes(slop_arena* arena, slop_list_slop_rdf_rdf_IRI sorted);
howl_probe_ProbeAnswer howl_test_expected_answer(howl_types_Outcome o, slop_string a, slop_string b);
uint8_t howl_test_probe_answer_is(howl_Run r, int64_t i, howl_probe_QueryKind kind, slop_string a, slop_string b, howl_probe_ProbeAnswer want);
uint8_t howl_test_answers_agree(howl_Run r, howl_types_Outcome o, slop_list_slop_rdf_rdf_IRI cs);
uint8_t howl_test_test_doc_at_skips_empty_documents(slop_arena* arena);
slop_rdf_rdf_Triple howl_test_ex_triple(slop_arena* arena, slop_string s, slop_string o);
uint8_t howl_test_ints_are(slop_list_int xs, slop_list_int want);
uint8_t howl_test_test_probe_document_numbers_its_documents(slop_arena* arena);
slop_list_int howl_test_omission_documents(slop_arena* arena, slop_list_string texts);
slop_list_string howl_test_lines_of_documents(slop_arena* arena, slop_list_string texts);
uint8_t howl_test_test_omissions_name_their_document(slop_arena* arena);
uint8_t howl_test_main_lines_unchanged(slop_arena* arena, howl_Run r, slop_list_string want);
uint8_t howl_test_probes_agree_with_report(slop_arena* arena, slop_string path, howl_types_Profile profile);
uint8_t howl_test_probes_agree_on(slop_arena* arena, slop_string text, howl_types_Outcome o, slop_string path, howl_types_Profile profile);
void howl_test_ask_every_pair(howl_Input in, slop_list_slop_rdf_rdf_IRI subs, slop_list_slop_rdf_rdf_IRI cs);
slop_list_slop_rdf_rdf_IRI howl_test_reversed_iris(slop_arena* arena, slop_list_slop_rdf_rdf_IRI xs);
uint8_t howl_test_test_probes_agree_with_report(slop_arena* arena);
uint8_t howl_test_test_answer_equals_two_run(slop_arena* arena);
uint8_t howl_test_answer_equals_two_run(slop_arena* arena, slop_string path, howl_types_Profile profile);
uint8_t howl_test_answer_equals_on(slop_arena* arena, slop_string text, slop_list_slop_rdf_rdf_IRI cs, slop_string path, howl_types_Profile profile);
uint8_t howl_test_answer_run_shape(slop_arena* arena, howl_Run a);
uint8_t howl_test_answer_run_agrees(howl_Run r, howl_Run a);
slop_string howl_test_lines_text(slop_arena* arena, howl_Run r);
uint8_t howl_test_test_answer_run_edges(slop_arena* arena);
howl_Run howl_test_du_run(slop_arena* arena, slop_string text);
uint8_t howl_test_test_disjoint_union_builtin_head(slop_arena* arena);
slop_string howl_test_probe_prefixes(void);
slop_string howl_test_probe_tail(slop_arena* arena, howl_Run r);
uint8_t howl_test_tail_is(slop_arena* arena, slop_string label, howl_Run r, slop_string want);
slop_string howl_test_scenario_main(void);
slop_string howl_test_scenario_probes(void);
howl_Input howl_test_scenario_input(slop_arena* arena, slop_string extra);
uint8_t howl_test_scenario_tail(slop_arena* arena, slop_string label, slop_string extra, howl_types_Profile profile, int64_t cap, slop_string want);
uint8_t howl_test_test_probe_scenarios(slop_arena* arena);
uint8_t howl_test_test_probe_refusals(slop_arena* arena);
uint8_t howl_test_order_independent(slop_arena* arena, slop_string path);
uint8_t howl_test_test_triple_order_independence(slop_arena* arena);
uint8_t howl_test_addressed_subset(slop_list_howl_types_Addressed xs, slop_list_howl_types_Addressed ys);
uint8_t howl_test_same_conclusions(slop_arena* arena, howl_types_Context ctx, howl_types_Derived d, howl_premise_RuleIndex idx, slop_list_howl_types_NormAxiom axioms);
uint8_t howl_test_dispatch_agrees(slop_arena* arena, slop_string path);
uint8_t howl_test_test_indexed_dispatch_matches_reference(slop_arena* arena);
uint8_t howl_test_test_quoted_triple_header_subjects(slop_arena* arena);
int64_t howl_test_strict_outcome(slop_arena* arena, slop_string path);
howl_test_RunAs howl_test_profile_run(slop_arena* arena, slop_string path, howl_types_ProfileSelection selection);
uint8_t howl_test_ran_as(howl_test_RunAs r, howl_types_Profile want);
uint8_t howl_test_refused_as(howl_test_RunAs r, howl_types_Profile want);
uint8_t howl_test_test_profile_selection(slop_arena* arena);
uint8_t howl_test_test_auto_step_down(slop_arena* arena);
uint8_t howl_test_test_choices_budget(slop_arena* arena);
uint8_t howl_test_choices_stopped(slop_arena* arena, slop_string path);
uint8_t howl_test_step_says(slop_arena* arena, slop_string label, uint8_t ok);
howl_types_ReasonerConfig howl_test_with_budget(howl_types_ProfileSelection sel, int64_t rounds, int64_t budget);
howl_types_ReasonerConfig howl_test_cancelled_cfg(howl_types_ReasonerConfig cfg);
slop_result_howl_types_Outcome_howl_types_Fault howl_test_classify_cfg(slop_arena* arena, slop_string path, howl_types_ReasonerConfig cfg);
uint8_t howl_test_answered_by(slop_result_howl_types_Outcome_howl_types_Fault r, howl_types_Profile p, uint8_t stepped);
uint8_t howl_test_capped_sriq(slop_result_howl_types_Outcome_howl_types_Fault r);
uint8_t howl_test_step_scan(slop_arena* arena, slop_string path);
int64_t howl_test_step_at(slop_arena* arena, slop_string path, int64_t b);
uint8_t howl_test_step_agrees(slop_result_howl_types_Outcome_howl_types_Fault a, uint8_t want);
uint8_t howl_test_test_profile_names_round_trip(slop_arena* arena);
uint8_t howl_test_test_dropped_rung_refusal(slop_arena* arena);
uint8_t howl_test_name_round_trips(howl_types_Profile p);
uint8_t howl_test_test_strict_refuses_past_omissions(slop_arena* arena);
uint8_t howl_test_test_nary_chain_decomposes_left_associated(slop_arena* arena);
slop_option_u8 howl_test_regularity_of(slop_arena* arena, slop_string path);
uint8_t howl_test_test_regularity_rejects_mutual_recursion(slop_arena* arena);
uint8_t howl_test_test_regularity_accepts_equivalence_and_transitivity(slop_arena* arena);
uint8_t howl_test_test_regularity_accepts_plain_subproperty(slop_arena* arena);
uint8_t howl_test_test_regularity_accepts_nary_chain(slop_arena* arena);
uint8_t howl_test_test_irregular_rbox_is_omitted_whole(slop_arena* arena);
slop_option_howl_gate_GateResult howl_test_gate_fixture(slop_arena* arena, slop_string path);
slop_option_howl_gate_GateResult howl_test_gate_fixture_in(slop_arena* arena, slop_string path, howl_types_Profile p);
int64_t howl_test_count_variant_chain(slop_list_howl_owl2_RawAxiom axs);
int64_t howl_test_count_variant_disjoint(slop_list_howl_owl2_RawAxiom axs);
int64_t howl_test_count_variant_subclass(slop_list_howl_owl2_RawAxiom axs);
uint8_t howl_test_test_gate_annotation_heavy_is_clean(slop_arena* arena);
uint8_t howl_test_test_gate_carries_import_omissions(slop_arena* arena);
uint8_t howl_test_test_sugar_transitivity_becomes_a_chain(slop_arena* arena);
uint8_t howl_test_test_sugar_nary_disjointness_becomes_pairs(slop_arena* arena);
uint8_t howl_test_test_sugar_equivalence_is_a_star_not_all_pairs(slop_arena* arena);
int64_t howl_test_gate_omission_count(slop_arena* arena, slop_string path);
uint8_t howl_test_test_gate_accepts_every_v0_fixture(slop_arena* arena);
uint8_t howl_test_test_gate_rejects_every_out_of_profile_fixture(slop_arena* arena);
slop_option_howl_owl2_Signature howl_test_signature_of_fixture(slop_arena* arena, slop_string path);
uint8_t howl_test_test_declared_unused_class_reaches_the_signature(slop_arena* arena);
uint8_t howl_test_test_builtins_are_declared(slop_arena* arena);
uint8_t howl_test_test_custom_annotation_property_is_recognized(slop_arena* arena);
uint8_t howl_test_is_named_class(howl_owl2_RawConcept c, slop_string iri);
uint8_t howl_test_is_some_person(howl_owl2_RawConcept c, slop_string role_iri, slop_string filler_iri);
uint8_t howl_test_test_decode_litmus_class_expression(slop_arena* arena);
uint8_t howl_test_test_decode_represents_out_of_profile_rather_than_failing(slop_arena* arena);
uint8_t howl_test_test_decode_blank_node_cycle_is_bounded(slop_arena* arena);
uint8_t howl_test_test_rdf_list_well_formed(slop_arena* arena);
uint8_t howl_test_test_rdf_list_truncation_is_a_fault(slop_arena* arena);
uint8_t howl_test_test_rdf_list_cycle_terminates(slop_arena* arena);
uint8_t howl_test_test_rdf_list_branching_is_a_fault(slop_arena* arena);
slop_list_slop_rdf_rdf_Triple howl_test_rest_forked(slop_arena* arena);
uint8_t howl_test_list_branches(slop_arena* arena, slop_list_slop_rdf_rdf_Triple ts, slop_rdf_rdf_Term head);
slop_string howl_test_decode_prefix(void);
slop_string howl_test_decoded_text(slop_arena* arena, slop_string ttl);
uint8_t howl_test_decodes_exactly(slop_arena* arena, slop_string label, slop_string ttl, slop_string want);
uint8_t howl_test_test_decode_rows(slop_arena* arena);
uint8_t howl_test_test_sort_is_stable(slop_arena* arena);
uint8_t howl_test_test_sort_is_a_permutation(slop_arena* arena);
void howl_test_print_test_result(slop_string name, uint8_t passed);
slop_string howl_test_arg_text(uint8_t** argv, int64_t i);
slop_list_slop_rdf_rdf_IRI howl_test_dump_classes(slop_arena* arena, howl_owl2_Signature sig);
int64_t howl_test_print_lines(slop_list_string ls);
int64_t howl_test_dump_refused(slop_string m);
int64_t howl_test_dump_s1(slop_arena* arena, howl_gate_GateResult gr, slop_result_howl_sriqnormal_S0_string r, int64_t bound);
int64_t howl_test_dump_s1_invariants(slop_arena* arena, howl_gate_GateResult gr, int64_t bound);
uint8_t howl_test_s1_guarded(slop_arena* arena, howl_gate_GateResult gr, int64_t bound);
uint8_t howl_test_uses_reserved(slop_arena* arena, howl_owl2_Signature sig);
int64_t howl_test_clauses_report(slop_arena* arena, howl_sriqclauses_SriqClauses sc);
int64_t howl_test_clauses_check(slop_arena* arena, slop_result_howl_sriqnames_SriqNormal_string r);
int64_t howl_test_dump_stage(slop_arena* arena, slop_string stage, howl_gate_GateResult gr, int64_t bound);
int64_t howl_test_sriq_dump(slop_arena* arena, slop_string stage, slop_string path, int64_t bound);
int64_t howl_test_bound_arg(slop_string s);
int64_t howl_test_dump_tagged(slop_string tag, slop_string text);
int64_t howl_test_dump_axiom_list(slop_arena* arena, slop_string tag, slop_list_howl_owl2_RawAxiom axs);
int64_t howl_test_dump_axiom_ref(slop_string tag, howl_types_AxiomRef r);
int64_t howl_test_dump_cited(slop_string tag, howl_types_Omission o);
int64_t howl_test_dump_omission_list(slop_arena* arena, slop_string tag, slop_list_howl_types_Omission os);
int64_t howl_test_dump_fault(slop_arena* arena, howl_types_Fault f);
int64_t howl_test_dump_signature(slop_arena* arena, howl_owl2_Signature sig);
int64_t howl_test_dump_triple(slop_arena* arena, howl_termstore_IdTriple t);
int64_t howl_test_dump_stage0(slop_arena* arena, howl_decode_Stage0 s0);
int64_t howl_test_dump_regularity(slop_arena* arena, slop_list_howl_owl2_RawAxiom axs);
int64_t howl_test_dump_rung(slop_arena* arena, howl_decode_Stage0 s0, howl_decode_Stage1 s1, howl_types_Profile p, slop_string tag);
int64_t howl_test_dump_decoded(slop_arena* arena, howl_decode_Stage0 s0, howl_decode_Stage1 s1);
int64_t howl_test_front_dump(slop_arena* arena, slop_string path);
slop_string howl_test_yes_no(uint8_t b);
int64_t howl_test_dump_num(slop_arena* arena, slop_string tag, int64_t n);
int64_t howl_test_dump_flag(slop_string tag, uint8_t b);
int64_t howl_test_dump_cfact(slop_arena* arena, howl_kscids_CFact c);
int64_t howl_test_dump_ksc_run(slop_arena* arena, slop_string tag, howl_kscsat_RunResult r);
slop_list_howl_types_KFact howl_test_ksc_seeds(slop_arena* arena, howl_kscpremise_KscIndex idx, slop_list_howl_types_KName classes, uint8_t w_phase);
int64_t howl_test_dump_ksc_phases(slop_arena* arena, howl_kscpremise_KscIndex idx, howl_kscids_KscIds ids, slop_list_howl_types_KName classes, int64_t w);
int64_t howl_test_dump_answer(slop_arena* arena, howl_types_ClassAnswer a);
int64_t howl_test_dump_ksc_result(slop_arena* arena, howl_types_KscResult r);
int64_t howl_test_dump_ksc_classify(slop_arena* arena, howl_test_KscFixture fx, int64_t w, int64_t cap);
int64_t howl_test_dump_ksc_caps(slop_arena* arena, howl_test_KscFixture fx, int64_t w);
int64_t howl_test_ksc_dump(slop_arena* arena, slop_string path);
int main(int argc, char** _c_argv);
int64_t howl_test_sriq_run_args(slop_arena* arena, int64_t argc, uint8_t** argv);
int64_t howl_test_run_suite(void);

#ifndef SLOP_OPTION_HOWL_TYPES_OUTCOME_DEFINED
#define SLOP_OPTION_HOWL_TYPES_OUTCOME_DEFINED
SLOP_OPTION_DEFINE(howl_types_Outcome, slop_option_howl_types_Outcome)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_NODE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_NODE_DEFINED
SLOP_OPTION_DEFINE(howl_types_Node, slop_option_howl_types_Node)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_NORMAXIOM_DEFINED
#define SLOP_OPTION_HOWL_TYPES_NORMAXIOM_DEFINED
SLOP_OPTION_DEFINE(howl_types_NormAxiom, slop_option_howl_types_NormAxiom)
#endif

#ifndef SLOP_OPTION_SLOP_RDF_RDF_TRIPLE_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_TRIPLE_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_Triple, slop_option_slop_rdf_rdf_Triple)
#endif

#ifndef SLOP_OPTION_HOWL_OWL2_RAWAXIOM_DEFINED
#define SLOP_OPTION_HOWL_OWL2_RAWAXIOM_DEFINED
SLOP_OPTION_DEFINE(howl_owl2_RawAxiom, slop_option_howl_owl2_RawAxiom)
#endif

#ifndef SLOP_OPTION_HOWL_DECODE_STAGE1_DEFINED
#define SLOP_OPTION_HOWL_DECODE_STAGE1_DEFINED
SLOP_OPTION_DEFINE(howl_decode_Stage1, slop_option_howl_decode_Stage1)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_AXIOMREF_DEFINED
#define SLOP_OPTION_HOWL_TYPES_AXIOMREF_DEFINED
SLOP_OPTION_DEFINE(howl_types_AxiomRef, slop_option_howl_types_AxiomRef)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_OMISSION_DEFINED
#define SLOP_OPTION_HOWL_TYPES_OMISSION_DEFINED
SLOP_OPTION_DEFINE(howl_types_Omission, slop_option_howl_types_Omission)
#endif

#ifndef SLOP_OPTION_HOWL_GATE_GATERESULT_DEFINED
#define SLOP_OPTION_HOWL_GATE_GATERESULT_DEFINED
SLOP_OPTION_DEFINE(howl_gate_GateResult, slop_option_howl_gate_GateResult)
#endif

#ifndef SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_IRI, slop_option_slop_rdf_rdf_IRI)
#endif

#ifndef SLOP_OPTION_HOWL_SROIQ_SAXIOM_DEFINED
#define SLOP_OPTION_HOWL_SROIQ_SAXIOM_DEFINED
SLOP_OPTION_DEFINE(howl_sroiq_SAxiom, slop_option_howl_sroiq_SAxiom)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_DLCLAUSE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_DLCLAUSE_DEFINED
SLOP_OPTION_DEFINE(howl_types_DlClause, slop_option_howl_types_DlClause)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_DNAME_DEFINED
#define SLOP_OPTION_HOWL_TYPES_DNAME_DEFINED
SLOP_OPTION_DEFINE(howl_types_DName, slop_option_howl_types_DName)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_LIT_DEFINED
#define SLOP_OPTION_HOWL_TYPES_LIT_DEFINED
SLOP_OPTION_DEFINE(howl_types_Lit, slop_option_howl_types_Lit)
#endif

#ifndef SLOP_OPTION_U32_DEFINED
#define SLOP_OPTION_U32_DEFINED
SLOP_OPTION_DEFINE(uint32_t, slop_option_u32)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_DROLE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_DROLE_DEFINED
SLOP_OPTION_DEFINE(howl_types_DRole, slop_option_howl_types_DRole)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_ATERM_DEFINED
#define SLOP_OPTION_HOWL_TYPES_ATERM_DEFINED
SLOP_OPTION_DEFINE(howl_types_ATerm, slop_option_howl_types_ATerm)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQORDER_CTERM_DEFINED
#define SLOP_OPTION_HOWL_SRIQORDER_CTERM_DEFINED
SLOP_OPTION_DEFINE(howl_sriqorder_CTerm, slop_option_howl_sriqorder_CTerm)
#endif

#ifndef SLOP_OPTION_U8_DEFINED
#define SLOP_OPTION_U8_DEFINED
SLOP_OPTION_DEFINE(uint8_t, slop_option_u8)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_CLAUSE_DEFINED
#define SLOP_OPTION_HOWL_TYPES_CLAUSE_DEFINED
SLOP_OPTION_DEFINE(howl_types_Clause, slop_option_howl_types_Clause)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQ_PREMISE_DEFINED
#define SLOP_OPTION_HOWL_SRIQ_PREMISE_DEFINED
SLOP_OPTION_DEFINE(howl_sriq_Premise, slop_option_howl_sriq_Premise)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQ_CANDS_DEFINED
#define SLOP_OPTION_HOWL_SRIQ_CANDS_DEFINED
SLOP_OPTION_DEFINE(howl_sriq_Cands, slop_option_howl_sriq_Cands)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQCLAUSES_SRIQCLAUSES_DEFINED
#define SLOP_OPTION_HOWL_SRIQCLAUSES_SRIQCLAUSES_DEFINED
SLOP_OPTION_DEFINE(howl_sriqclauses_SriqClauses, slop_option_howl_sriqclauses_SriqClauses)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQ_SUCCSIG_DEFINED
#define SLOP_OPTION_HOWL_SRIQ_SUCCSIG_DEFINED
SLOP_OPTION_DEFINE(howl_sriq_SuccSig, slop_option_howl_sriq_SuccSig)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQCTX_STRATEGY_DEFINED
#define SLOP_OPTION_HOWL_SRIQCTX_STRATEGY_DEFINED
SLOP_OPTION_DEFINE(howl_sriqctx_Strategy, slop_option_howl_sriqctx_Strategy)
#endif

#ifndef SLOP_OPTION_HOWL_TEST_EXPECT_DEFINED
#define SLOP_OPTION_HOWL_TEST_EXPECT_DEFINED
SLOP_OPTION_DEFINE(howl_test_Expect, slop_option_howl_test_Expect)
#endif

#ifndef SLOP_OPTION_HOWL_TEST_PROTOCASE_DEFINED
#define SLOP_OPTION_HOWL_TEST_PROTOCASE_DEFINED
SLOP_OPTION_DEFINE(howl_test_ProtoCase, slop_option_howl_test_ProtoCase)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQCTX_EDGE_DEFINED
#define SLOP_OPTION_HOWL_SRIQCTX_EDGE_DEFINED
SLOP_OPTION_DEFINE(howl_sriqctx_Edge, slop_option_howl_sriqctx_Edge)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_SUBPAIR_DEFINED
#define SLOP_OPTION_HOWL_TYPES_SUBPAIR_DEFINED
SLOP_OPTION_DEFINE(howl_types_SubPair, slop_option_howl_types_SubPair)
#endif

#ifndef SLOP_OPTION_HOWL_TEST_ROUNDAT_DEFINED
#define SLOP_OPTION_HOWL_TEST_ROUNDAT_DEFINED
SLOP_OPTION_DEFINE(howl_test_RoundAt, slop_option_howl_test_RoundAt)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_KSCAXIOM_DEFINED
#define SLOP_OPTION_HOWL_TYPES_KSCAXIOM_DEFINED
SLOP_OPTION_DEFINE(howl_types_KscAxiom, slop_option_howl_types_KscAxiom)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_KNAME_DEFINED
#define SLOP_OPTION_HOWL_TYPES_KNAME_DEFINED
SLOP_OPTION_DEFINE(howl_types_KName, slop_option_howl_types_KName)
#endif

#ifndef SLOP_OPTION_HOWL_TEST_KSCFIXTURE_DEFINED
#define SLOP_OPTION_HOWL_TEST_KSCFIXTURE_DEFINED
SLOP_OPTION_DEFINE(howl_test_KscFixture, slop_option_howl_test_KscFixture)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_KFACT_DEFINED
#define SLOP_OPTION_HOWL_TYPES_KFACT_DEFINED
SLOP_OPTION_DEFINE(howl_types_KFact, slop_option_howl_types_KFact)
#endif

#ifndef SLOP_OPTION_HOWL_NORMALIZE_NORMOUTPUT_DEFINED
#define SLOP_OPTION_HOWL_NORMALIZE_NORMOUTPUT_DEFINED
SLOP_OPTION_DEFINE(howl_normalize_NormOutput, slop_option_howl_normalize_NormOutput)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_ADDRESSED_DEFINED
#define SLOP_OPTION_HOWL_TYPES_ADDRESSED_DEFINED
SLOP_OPTION_DEFINE(howl_types_Addressed, slop_option_howl_types_Addressed)
#endif

#ifndef SLOP_OPTION_HOWL_TEST_RUNAS_DEFINED
#define SLOP_OPTION_HOWL_TEST_RUNAS_DEFINED
SLOP_OPTION_DEFINE(howl_test_RunAs, slop_option_howl_test_RunAs)
#endif

#ifndef SLOP_OPTION_HOWL_OWL2_SIGNATURE_DEFINED
#define SLOP_OPTION_HOWL_OWL2_SIGNATURE_DEFINED
SLOP_OPTION_DEFINE(howl_owl2_Signature, slop_option_howl_owl2_Signature)
#endif

#ifndef SLOP_OPTION_ARENA_PTR_DEFINED
#define SLOP_OPTION_ARENA_PTR_DEFINED
SLOP_OPTION_DEFINE(slop_arena*, slop_option_arena_ptr)
#endif

#ifndef SLOP_OPTION_MAP_PTR_DEFINED
#define SLOP_OPTION_MAP_PTR_DEFINED
SLOP_OPTION_DEFINE(slop_map*, slop_option_map_ptr)
#endif

#ifndef SLOP_OPTION_HOWL_SATURATE_ROUNDDELTA_DEFINED
#define SLOP_OPTION_HOWL_SATURATE_ROUNDDELTA_DEFINED
SLOP_OPTION_DEFINE(howl_saturate_RoundDelta, slop_option_howl_saturate_RoundDelta)
#endif

#ifndef SLOP_OPTION_HOWL_SROIQ_SCONCEPT_DEFINED
#define SLOP_OPTION_HOWL_SROIQ_SCONCEPT_DEFINED
SLOP_OPTION_DEFINE(howl_sroiq_SConcept, slop_option_howl_sroiq_SConcept)
#endif

#ifndef SLOP_OPTION_OPTION_HOWL_TYPES_DNAME_DEFINED
#define SLOP_OPTION_OPTION_HOWL_TYPES_DNAME_DEFINED
SLOP_OPTION_DEFINE(slop_option_howl_types_DName, slop_option_option_howl_types_DName)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQORDER_CONSTENTRY_DEFINED
#define SLOP_OPTION_HOWL_SRIQORDER_CONSTENTRY_DEFINED
SLOP_OPTION_DEFINE(howl_sriqorder_ConstEntry, slop_option_howl_sriqorder_ConstEntry)
#endif

#ifndef SLOP_OPTION_HOWL_SRIQ_PCANDS_DEFINED
#define SLOP_OPTION_HOWL_SRIQ_PCANDS_DEFINED
SLOP_OPTION_DEFINE(howl_sriq_PCands, slop_option_howl_sriq_PCands)
#endif

#ifndef SLOP_OPTION_HOWL_TYPES_CLASSANSWER_DEFINED
#define SLOP_OPTION_HOWL_TYPES_CLASSANSWER_DEFINED
SLOP_OPTION_DEFINE(howl_types_ClassAnswer, slop_option_howl_types_ClassAnswer)
#endif

#ifndef SLOP_OPTION_HOWL_PROBE_QUERY_DEFINED
#define SLOP_OPTION_HOWL_PROBE_QUERY_DEFINED
SLOP_OPTION_DEFINE(howl_probe_Query, slop_option_howl_probe_Query)
#endif

#ifndef SLOP_LIST_ARENA_PTR_DEFINED
#define SLOP_LIST_ARENA_PTR_DEFINED
#define SLOP_LIST_ARENA_PTR_IMPL_DEFINED
SLOP_LIST_DEFINE(slop_arena*, slop_list_arena_ptr)
#endif

#ifndef SLOP_LIST_HOWL_SATURATE_ROUNDDELTA_DEFINED
#define SLOP_LIST_HOWL_SATURATE_ROUNDDELTA_DEFINED
#define SLOP_LIST_HOWL_SATURATE_ROUNDDELTA_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_saturate_RoundDelta, slop_list_howl_saturate_RoundDelta)
#endif

#ifndef SLOP_LIST_HOWL_SROIQ_SCONCEPT_DEFINED
#define SLOP_LIST_HOWL_SROIQ_SCONCEPT_DEFINED
#define SLOP_LIST_HOWL_SROIQ_SCONCEPT_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sroiq_SConcept, slop_list_howl_sroiq_SConcept)
#endif

#ifndef SLOP_LIST_OPTION_HOWL_TYPES_DNAME_DEFINED
#define SLOP_LIST_OPTION_HOWL_TYPES_DNAME_DEFINED
#define SLOP_LIST_OPTION_HOWL_TYPES_DNAME_IMPL_DEFINED
SLOP_LIST_DEFINE(slop_option_howl_types_DName, slop_list_option_howl_types_DName)
#endif

#ifndef SLOP_LIST_HOWL_SRIQORDER_CONSTENTRY_DEFINED
#define SLOP_LIST_HOWL_SRIQORDER_CONSTENTRY_DEFINED
#define SLOP_LIST_HOWL_SRIQORDER_CONSTENTRY_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sriqorder_ConstEntry, slop_list_howl_sriqorder_ConstEntry)
#endif

#ifndef SLOP_LIST_HOWL_SRIQ_PCANDS_DEFINED
#define SLOP_LIST_HOWL_SRIQ_PCANDS_DEFINED
#define SLOP_LIST_HOWL_SRIQ_PCANDS_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_sriq_PCands, slop_list_howl_sriq_PCands)
#endif

#ifndef SLOP_LIST_HOWL_TYPES_CLASSANSWER_DEFINED
#define SLOP_LIST_HOWL_TYPES_CLASSANSWER_DEFINED
#define SLOP_LIST_HOWL_TYPES_CLASSANSWER_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_types_ClassAnswer, slop_list_howl_types_ClassAnswer)
#endif

#ifndef SLOP_LIST_HOWL_PROBE_QUERY_DEFINED
#define SLOP_LIST_HOWL_PROBE_QUERY_DEFINED
#define SLOP_LIST_HOWL_PROBE_QUERY_IMPL_DEFINED
SLOP_LIST_DEFINE(howl_probe_Query, slop_list_howl_probe_Query)
#endif


#endif
