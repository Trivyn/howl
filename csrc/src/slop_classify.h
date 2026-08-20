#ifndef SLOP_classify_H
#define SLOP_classify_H

#include "../runtime/slop_runtime.h"
#include <stdint.h>
#include <stdbool.h>
#include "slop_rdf.h"
#include "slop_types.h"

uint8_t classify_entails_sub(slop_arena* arena, types_Saturation sat, uint8_t inconsistent, types_Node a, types_Node b);
types_Findings classify_extract_findings(slop_arena* arena, types_Saturation sat);


#endif
