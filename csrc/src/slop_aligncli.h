#ifndef SLOP_aligncli_H
#define SLOP_aligncli_H

#include "../runtime/slop_runtime.h"
#ifndef SLOP_RUNTIME_ABI
#error "this module was generated for SLOP runtime ABI 2026-1 (SLOP_RUNTIME_ABI 202601), but slop_runtime.h predates runtime ABI versioning: use the slop_runtime.h of the SLOP release that generated this code"
#elif SLOP_RUNTIME_ABI != 202601
#error "this module was generated for SLOP runtime ABI 2026-1 (SLOP_RUNTIME_ABI 202601), which this slop_runtime.h does not provide (SLOP_RUNTIME_ABI differs): regenerate the C with the SLOP release that matches the runtime, or use the slop_runtime.h of the release that generated it"
#endif
#include <stdint.h>
#include <stdbool.h>
#include "slop_rdf.h"
#include "slop_types.h"
#include "slop_howl.h"
#include "slop_alignmentreport.h"
#include "slop_aligninput.h"
#include "slop_report.h"
#include "slop_termstore.h"
#include "slop_select.h"
#include "slop_strlib.h"
#include "slop_ttl.h"
#include "slop_vocab.h"
#include "slop_canon.h"
#include <string.h>
#include <sys/resource.h>

#ifndef SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_IRI, slop_option_slop_rdf_rdf_IRI)
#endif

int64_t howl_cli_aligncli_peak_mb(void);
slop_string howl_cli_aligncli_arg(uint8_t** argv, int64_t i);
slop_string howl_cli_aligncli_file_source(slop_arena* a, slop_string path);
uint8_t howl_cli_aligncli_parse_into(slop_arena* arena, howl_termstore_Encoded* enc, slop_string path);
slop_option_slop_rdf_rdf_IRI howl_cli_aligncli_ontology_iri_from(howl_termstore_Encoded e, int64_t from);
uint8_t howl_cli_aligncli_all_digits(slop_string s);
slop_option_int howl_cli_aligncli_whole_number(slop_string s);
void howl_cli_aligncli_print_fault(slop_arena* a, howl_types_Fault f);
int64_t howl_cli_aligncli_fault_exit(howl_types_Fault f);
int64_t howl_cli_aligncli_outcome_exit(howl_types_Outcome o);
slop_string howl_cli_aligncli_source_of(slop_arena* a, slop_string path, slop_string override);
int64_t howl_cli_aligncli_align_main(int64_t argc, uint8_t** argv);

#ifndef SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_OPTION_SLOP_RDF_RDF_IRI_DEFINED
SLOP_OPTION_DEFINE(slop_rdf_rdf_IRI, slop_option_slop_rdf_rdf_IRI)
#endif

#ifndef SLOP_OPTION_U8_DEFINED
#define SLOP_OPTION_U8_DEFINED
SLOP_OPTION_DEFINE(uint8_t, slop_option_u8)
#endif

#ifndef SLOP_LIST_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_LIST_SLOP_RDF_RDF_IRI_DEFINED
#define SLOP_LIST_SLOP_RDF_RDF_IRI_IMPL_DEFINED
SLOP_LIST_DEFINE(slop_rdf_rdf_IRI, slop_list_slop_rdf_rdf_IRI)
#endif

#ifndef SLOP_LIST_U8_DEFINED
#define SLOP_LIST_U8_DEFINED
#define SLOP_LIST_U8_IMPL_DEFINED
SLOP_LIST_DEFINE(uint8_t, slop_list_u8)
#endif


#endif
