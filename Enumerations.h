
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

enum class IpsoSampleSortType
{
    SAMPLE_SORT_331,
    SAMPLE_SORT_332,
    INSERTION_SORT_NETWORK_HYBRID,
    NONE
};

enum class IpsoBaseCaseType
{
    INSERTION_SORT,
    BEST_NETWORKS,
    BOSE_NELSON_NETWORKS,
    BOSE_NELSON_RECURSIVE,
    BOSE_NELSON_PARALLEL,
    BOSE_NELSON_UNROLLED,
    CUSTOM_INSERTION_SORT
};

#endif