

#include <tuple>
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <asm/unistd.h>

#include <cstring>

#include "../DebugHelper.h"
#include "../Enumerations.h"
#include "Performancing.h"

struct read_format {
	uint64_t value;
	uint64_t id;
};

void Performancing::SetupPerformanceEventAttribute(PerformanceMetric metric)
{
	memset(&_performanceEventAttribute, 0, sizeof(struct perf_event_attr));
	_performanceEventAttribute.size = sizeof(struct perf_event_attr);
	memset(&_performanceChildEventAttribute, 0, sizeof(struct perf_event_attr));
	_performanceChildEventAttribute.size = sizeof(struct perf_event_attr);
	switch (metric) {
		case PerformanceMetric::CPU_CYCLES:
			_performanceEventAttribute.type = PERF_TYPE_HARDWARE;
			_performanceEventAttribute.config = PERF_COUNT_HW_CPU_CYCLES;
			_performanceChildEventAttribute.type = PERF_TYPE_HW_CACHE;
			_performanceChildEventAttribute.config = PERF_COUNT_HW_CACHE_L1I | (PERF_COUNT_HW_CACHE_OP_READ << 8) | (PERF_COUNT_HW_CACHE_RESULT_MISS << 16);
			break;
		case PerformanceMetric::BRANCH_MISSES:
			_performanceEventAttribute.config = PERF_COUNT_HW_BRANCH_MISSES;
			break;
		default:
			throw std::logic_error("Performancing::Performancing => Missing Performance Metric!");
	}
	_performanceEventAttribute.disabled = 1;
	_performanceEventAttribute.exclude_kernel = 1;
	_performanceEventAttribute.exclude_hv = 1;
	_performanceEventAttribute.read_format = PERF_FORMAT_ID;
	_performanceChildEventAttribute.disabled = 0;
	_performanceChildEventAttribute.exclude_kernel = 1;
	_performanceChildEventAttribute.exclude_hv = 1;
	_performanceChildEventAttribute.read_format = PERF_FORMAT_ID;
}

Performancing::Performancing(PerformanceMetric metric) {
	_performanceMetric = metric;
	_readFormat = (struct read_format*) _resultBuffer;
	SetupPerformanceEventAttribute(metric);
	_fileDescriptor = syscall(__NR_perf_event_open, &_performanceEventAttribute, 0, -1, -1, 0);
	_childFileDescriptor = syscall(__NR_perf_event_open, &_performanceChildEventAttribute, 0, -1, _fileDescriptor, 0);
	// if (metric == PerformanceMetric::L1_INSTR_CACHE_MISSES)
	// {
	// 	_childFileDescriptor = syscall(__NR_perf_event_open, &_performanceChildEventAttribute, 0, -1, _fileDescriptor, 0);
	// }
}
Performancing::~Performancing() {
	close(_fileDescriptor);
}
static inline 
unsigned long long ReadTicks()
{
	unsigned high = 0;
	unsigned low = 0;
	
#if __x86_64__
	__asm__ volatile (
		"rdtsc"
		: "=a"(low), "=d"(high)
	);
#elif defined(__i386__)
	__asm__ volatile (
		"rdtsc"
		: "=a"(low), "=d"(high)
	);
#elif __aarch64__
	int64_t svalue;
	__asm__ volatile (
		"mrs %0, cntvct_el0"
		: "=r"(svalue)
	);
	return (uint64_t) svalue;
#elif __arm__
	uint32_t raw_value;
	__asm__ volatile (
		"mrc p15, 0, %0, c9, c13, 0" 
		: "=r"(raw_value)
	);
	return ((uint64_t) (raw_value)) * 64;
#endif
	return 
	( 
		(unsigned long long) low
	) | 
	(
		(
			(unsigned long long) high
		) << 32
	);
}

void Performancing::StartMeasuring() {
#ifndef IGNORE_MEASUREMENT
	ioctl(_fileDescriptor, PERF_EVENT_IOC_RESET, PERF_IOC_FLAG_GROUP);
	ioctl(_fileDescriptor, PERF_EVENT_IOC_ENABLE, PERF_IOC_FLAG_GROUP);

	// _ticks = ReadTicks();

	_time = std::chrono::steady_clock::now();
#endif
}
void Performancing::StopMeasuring() {
#ifndef IGNORE_MEASUREMENT
	ioctl(_fileDescriptor, PERF_EVENT_IOC_DISABLE, PERF_IOC_FLAG_GROUP);

	// auto newTicks = ReadTicks();
	// _ticks = newTicks - _ticks;
	
    std::chrono::steady_clock::time_point timeEnd = std::chrono::steady_clock::now();
	_timeSpan = std::chrono::duration_cast<std::chrono::duration<int64_t, std::milli>>(timeEnd - _time);
#endif
}

std::tuple<uint64_t, uint64_t> Performancing::GetValues() {
#ifndef IGNORE_MEASUREMENT
	auto _ = read(_fileDescriptor, _resultBuffer, sizeof(_resultBuffer));
	uint64_t value = _readFormat->value;

	_ = read(_childFileDescriptor, _resultBuffer, sizeof(_resultBuffer));
	uint64_t value2 = _readFormat->value;

	return {value, value2};
#else
	return 0;
#endif
}

PerformanceMetric Performancing::GetMetric() {
	return _performanceMetric;
}
