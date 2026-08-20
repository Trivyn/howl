#ifndef SLOP_main_H
#define SLOP_main_H

#include "../runtime/slop_runtime.h"
#include <stdint.h>
#include <stdbool.h>
#include "slop_rdf.h"
#include "slop_types.h"
#include "slop_howl.h"
#include <string.h>

#ifndef SLOP_RESULT_TYPES_OUTCOME_TYPES_FAULT_DEFINED
#define SLOP_RESULT_TYPES_OUTCOME_TYPES_FAULT_DEFINED
typedef struct { bool is_ok; union { types_Outcome ok; types_Fault err; } data; } slop_result_types_Outcome_types_Fault;
#endif

int64_t main_exit_code_for(slop_result_types_Outcome_types_Fault r);
slop_string main_argv_to_string(uint8_t** argv, int64_t index);
void main_print_usage(void);
int main(int argc, char** _c_argv);


#endif
