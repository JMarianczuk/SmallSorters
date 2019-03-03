

#include <inttypes.h>
#include <string>
#include <stdexcept>

#include "Enumerations.h"
#include "Performancing.h"

struct read_format {
	uint64_t number;
	struct {
		uint64_t value;
		uint64_t id;
	} values[];
};

void Performancing::SetupPerformanceEventAttribute(PerformanceMetric metric)
{
	memset(&_performanceEventAttribute, 0, sizeof(struct perf_event_attr));
	_performanceEventAttribute.type = PERF_TYPE_HARDWARE;
	_performanceEventAttribute.size = sizeof(struct perf_event_attr);
	switch (metric) {
		case PerformanceMetric::CPU_CYCLES:
			_performanceEventAttribute.config = PERF_COUNT_HW_CPU_CYCLES;
			break;
		case PerformanceMetric::CACHE_MISSES:
			_performanceEventAttribute.config = PERF_COUNT_HW_CACHE_MISSES;
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
}

Performancing::Performancing(PerformanceMetric metric) {
	_performanceMetric = metric;
	_readFormat = (struct read_format*) _resultBuffer;
	SetupPerformanceEventAttribute(metric);
	_fileDescriptor = syscall(__NR_perf_event_open, &_performanceEventAttribute, 0, -1, -1, 0);
	ioctl(_fileDescriptor, PERF_EVENT_IOC_ID, &_id);
}
Performancing::~Performancing() {
	close(_fileDescriptor);
}
void Performancing::StartMeasuring() {
	ioctl(_fileDescriptor, PERF_EVENT_IOC_RESET, PERF_IOC_FLAG_GROUP);
	ioctl(_fileDescriptor, PERF_EVENT_IOC_ENABLE, PERF_IOC_FLAG_GROUP);
}
void Performancing::StopMeasuring() {
	ioctl(_fileDescriptor, PERF_EVENT_IOC_DISABLE, PERF_IOC_FLAG_GROUP);
}

uint64_t Performancing::GetValue() {
	auto _ = read(_fileDescriptor, _resultBuffer, sizeof(_resultBuffer));

	for (int i = 0; i < _readFormat->number; i += 1)
	{
		if (_readFormat->values[i].id == _id)
		{
			return _readFormat->values[i].value;
		}
	}
}

PerformanceMetric Performancing::GetMetric() {
	return _performanceMetric;
}
