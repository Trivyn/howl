#ifndef SLOP_report_H
#define SLOP_report_H

#include "../runtime/slop_runtime.h"
#include <stdint.h>
#include <stdbool.h>
#include "slop_rdf.h"
#include "slop_types.h"
#include "slop_owl2.h"
#include "slop_howl.h"
#include "slop_select.h"

slop_string report_node_text(slop_arena* arena, types_Node n);
slop_string report_keyed(slop_arena* arena, slop_string key, slop_string text);
slop_string report_verdict_line(types_Outcome o);
slop_string report_termination_line(types_Termination t);
slop_list_string report_report_lines(slop_arena* arena, types_Outcome o);


#endif
