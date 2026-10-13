/* Linked into the Windows CLI only (Makefile, CLI_EXTRA). The MinGW C runtime
 * opens stdout in text mode, which writes every "\n" as "\r\n". A report must
 * be the same bytes on every platform (SPEC.md §6.8; .gitattributes pins the
 * goldens to LF), so stdout is switched to binary mode before main runs. */
#include <fcntl.h>
#include <io.h>
#include <stdio.h>

__attribute__((constructor)) static void howl_lf_stdout(void) {
    _setmode(_fileno(stdout), _O_BINARY);
}
