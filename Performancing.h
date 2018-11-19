// Performancing.h : Include file for standard system include files,
// or project specific include files.

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
    struct perf_event_attr performance_event_attribute;
	uint64_t id;

	char buf[4096];
	struct read_format* rf;

	int file_descriptor;
public:
    Performancing(PerformanceMetric metric);
    ~Performancing();
    void StartMeasuring();
    void StopMeasuring();
    uint64_t GetValue();
};

#endif

// TODO: Reference additional headers your program requires here.
