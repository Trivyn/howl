/* Windows has no <sys/resource.h>. The CLI includes it for one call, peak-mb's
 * getrusage(RUSAGE_SELF) (cli/main.slop), so the Windows build puts
 * cli/windows on the include path (Makefile, CLI_EXTRA) and this header
 * answers that call: ru_maxrss is the process's peak working set, in
 * kilobytes as on Linux. Only the memory line of --timings reads it; no report
 * does. */
#ifndef HOWL_WINDOWS_SYS_RESOURCE_H
#define HOWL_WINDOWS_SYS_RESOURCE_H

#include <windows.h>
#include <psapi.h>

#define RUSAGE_SELF 0

struct rusage {
    long ru_maxrss;
};

static inline int getrusage(int who, struct rusage *ru) {
    PROCESS_MEMORY_COUNTERS pmc;
    (void)who;
    ru->ru_maxrss = 0;
    if (!K32GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof pmc)) return -1;
    ru->ru_maxrss = (long)(pmc.PeakWorkingSetSize / 1024);
    return 0;
}

#endif
