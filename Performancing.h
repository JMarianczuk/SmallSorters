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


enum class PerformanceMetric {
	CPU_CYCLES
};

class Performancing {
private:
    
public:
    Performancing(PerformanceMetric metric);
    ~Performancing();
    void StartMeasuring();
    void StopMeasuring();
    uint64_t GetValue();
};

// TODO: Reference additional headers your program requires here.
