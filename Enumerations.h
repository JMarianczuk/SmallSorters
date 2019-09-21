
#ifndef ENUMERATIONS_H
#define ENUMERATIONS_H

enum class PerformanceMetric {
	CPU_CYCLES,
    L1_INSTR_CACHE_MISSES,
    BRANCH_MISSES,
};

enum class RandomisationMode
{
    DEFAULT,
    SORTED,
    INVERSE_SORTED
};

#endif