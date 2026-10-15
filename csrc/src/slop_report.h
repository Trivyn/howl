#ifndef SLOP_report_H
#define SLOP_report_H

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
#include "slop_owl2.h"
#include "slop_select.h"
#include "slop_strlib.h"
#include "slop_probe.h"

slop_string howl_report_node_text(slop_arena* arena, howl_types_Node n);
slop_string howl_report_keyed(slop_arena* arena, slop_string key, slop_string text);
slop_string howl_report_verdict_line(howl_types_Outcome o);
slop_string howl_report_termination_line(howl_types_Termination t);
slop_list_string howl_report_probe_lines(slop_arena* arena, howl_probe_Probing p);
slop_list_string howl_report_answer_lines(slop_arena* arena, howl_probe_Probing p, uint8_t ran);
slop_string howl_report_answer_text(slop_arena* arena, howl_probe_Answered a);
slop_string howl_report_answer_name(howl_probe_ProbeAnswer a);
slop_list_string howl_report_report_lines(slop_arena* arena, howl_types_Outcome o);


#endif
