
#ifndef PERFORMANCING_H
#define PERFORMANCING_H

#include <iostream>
#include <inttypes.h>
#include <sys/ioctl.h>

#include <linux/perf_event.h>
#include <linux/hw_breakpoint.h>

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <string.h>
#include <asm/unistd.h>
#include <errno.h>
#include <stdint.h>
#include <time.h>
#include <tuple>
#include <chrono>

#include "../Enumerations.h"


class Performancing {
private:
    struct perf_event_attr _performanceEventAttribute;
	uint64_t _idFirst;
    uint64_t _idSecond;
	char _resultBuffer[4096];
	struct read_format* _readFormat;
	int _fileDescriptor;
    PerformanceMetric _performanceMetric;
    unsigned long long _ticks;
    std::chrono::steady_clock::time_point _time;
    std::chrono::duration<int64_t, std::milli> _timeSpan;

    void SetupPerformanceEventAttribute(PerformanceMetric metric);
public:
    Performancing(PerformanceMetric metric);
    ~Performancing();
    void StartMeasuring();
    void StopMeasuring();
    std::tuple<uint64_t, uint64_t> GetValues();
    PerformanceMetric GetMetric();
};

#endif
