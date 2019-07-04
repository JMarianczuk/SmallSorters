
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

#include "Enumerations.h"


class Performancing {
private:
    struct perf_event_attr _performanceEventAttribute;
	uint64_t _id;
	char _resultBuffer[4096];
	struct read_format* _readFormat;
	int _fileDescriptor;
    PerformanceMetric _performanceMetric;
    unsigned long long _ticks;

    void SetupPerformanceEventAttribute(PerformanceMetric metric);
public:
    Performancing(PerformanceMetric metric);
    ~Performancing();
    void StartMeasuring();
    void StopMeasuring();
    uint64_t GetValue();
    PerformanceMetric GetMetric();
};

#endif
