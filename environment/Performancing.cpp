

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

// struct read_format {
// 	uint64_t number;
// 	struct {
// 		uint64_t value;
// 		uint64_t id;
// 	} values[];
// };
struct read_format {
	uint64_t value;
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
			break;
		case PerformanceMetric::L1_INSTR_CACHE_MISSES:
			_performanceEventAttribute.type = PERF_TYPE_HW_CACHE;
			_performanceEventAttribute.config = PERF_COUNT_HW_CACHE_L1I | (PERF_COUNT_HW_CACHE_OP_READ << 8) | (PERF_COUNT_HW_CACHE_RESULT_ACCESS << 16);
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
	_performanceEventAttribute.read_format = PERF_FORMAT_GROUP | PERF_FORMAT_ID;
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
	// ioctl(_fileDescriptor, PERF_EVENT_IOC_ID, &_idFirst);
	if (metric == PerformanceMetric::L1_INSTR_CACHE_MISSES)
	{
		_childFileDescriptor = syscall(__NR_perf_event_open, &_performanceChildEventAttribute, 0, -1, _fileDescriptor, 0);
		// ioctl(_fileDescriptor, PERF_EVENT_IOC_ID, &_idSecond);
	}
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
	// _ticks = ReadTicks();
	// _time = std::chrono::steady_clock::now();
	ioctl(_fileDescriptor, PERF_EVENT_IOC_ENABLE, PERF_IOC_FLAG_GROUP);
#endif
}
void Performancing::StopMeasuring() {
#ifndef IGNORE_MEASUREMENT
	// auto newTicks = ReadTicks();
    // std::chrono::steady_clock::time_point timeEnd = std::chrono::steady_clock::now();
	ioctl(_fileDescriptor, PERF_EVENT_IOC_DISABLE, PERF_IOC_FLAG_GROUP);
	// _ticks = newTicks - _ticks;
	// _timeSpan = std::chrono::duration_cast<std::chrono::duration<int64_t, std::milli>>(timeEnd - _time);
#endif
}

std::tuple<uint64_t, uint64_t> Performancing::GetValues() {
#ifndef IGNORE_MEASUREMENT
	auto _ = read(_fileDescriptor, _resultBuffer, sizeof(_resultBuffer));

	uint64_t value = _readFormat->value;
	uint64_t childValue;
	if (_performanceMetric == PerformanceMetric::L1_INSTR_CACHE_MISSES)
	{
		_ = read(_childFileDescriptor, _resultBuffer, sizeof(_resultBuffer));
		childValue = _readFormat->value;
	}
	// for (int i = 0; i < _readFormat->number; i += 1)
	// {
	// 	if (_readFormat->values[i].id == _idFirst)
	// 	{
	// 		value = _readFormat->values[i].value;
	// 	}
	// 	if (_readFormat->values[i].id == _idSecond)
	// 	{
	// 		childValue = _readFormat->values[i].value;
	// 	}
	// }
	return {value, childValue};
#else
	return 0;
#endif
}

PerformanceMetric Performancing::GetMetric() {
	return _performanceMetric;
}
