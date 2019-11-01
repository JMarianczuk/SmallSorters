
#ifndef PERFORMANCING_H
#define PERFORMANCING_H

#include <inttypes.h>

#include <linux/perf_event.h>
#include <linux/hw_breakpoint.h>

#include <chrono>
#include <tuple>

#include "../Enumerations.h"

class Performancing final {
private:
    struct perf_event_attr _performanceEventAttribute;
    struct perf_event_attr _performanceChildEventAttribute;
	uint64_t _idFirst;
    uint64_t _idSecond;
	char _resultBuffer[4096];
	struct read_format* _readFormat;
	int _fileDescriptor;
    int _childFileDescriptor;
    PerformanceMetric _performanceMetric;
    unsigned long long _ticks;
    int64_t _timestamp;
    std::chrono::steady_clock::time_point _time;
    std::chrono::duration<int64_t, std::milli> _timeSpan;

    void SetupPerformanceEventAttribute(PerformanceMetric metric);
public:
    Performancing(PerformanceMetric metric);
    ~Performancing();
    void StartMeasuring();
    void StopMeasuring();
    std::tuple<uint64_t, uint64_t, int64_t> GetValues();
    PerformanceMetric GetMetric();
};

#endif
