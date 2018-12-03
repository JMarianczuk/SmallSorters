// Performancing.cpp : Defines the entry point for the application.
//

#include "Performancing.h"
#include "Result.h"

struct read_format {
	uint64_t number;
	struct {
		uint64_t value;
		uint64_t id;
	} values[];
};

Performancing::Performancing(PerformanceMetric metric) {
	performance_metric = metric;
	rf = (struct read_format*) buf;
	memset(&performance_event_attribute, 0, sizeof(struct perf_event_attr));
	performance_event_attribute.type = PERF_TYPE_HARDWARE;
	performance_event_attribute.size = sizeof(struct perf_event_attr);
	switch (metric) {
		case PerformanceMetric::CPU_CYCLES:
			performance_event_attribute.config = PERF_COUNT_HW_CPU_CYCLES;
			break;
		case PerformanceMetric::CACHE_MISSES:
			performance_event_attribute.config = PERF_COUNT_HW_CACHE_MISSES;
			break;
		case PerformanceMetric::BRANCH_MISSES:
			performance_event_attribute.config = PERF_COUNT_HW_BRANCH_MISSES;
			break;
		default:
			throw std::logic_error("Missing Performance Metric!");
	}
	performance_event_attribute.disabled = 1;
	performance_event_attribute.exclude_kernel = 1;
	performance_event_attribute.exclude_hv = 1;
	performance_event_attribute.read_format = PERF_FORMAT_GROUP | PERF_FORMAT_ID;
	file_descriptor = syscall(__NR_perf_event_open, &performance_event_attribute, 0, -1, -1, 0);
	ioctl(file_descriptor, PERF_EVENT_IOC_ID, &id);
}
Performancing::~Performancing() {
	close(file_descriptor);
}
void Performancing::StartMeasuring() {
	ioctl(file_descriptor, PERF_EVENT_IOC_RESET, PERF_IOC_FLAG_GROUP);
	ioctl(file_descriptor, PERF_EVENT_IOC_ENABLE, PERF_IOC_FLAG_GROUP);
}
void Performancing::StopMeasuring() {
	ioctl(file_descriptor, PERF_EVENT_IOC_DISABLE, PERF_IOC_FLAG_GROUP);
}

uint64_t Performancing::GetValue() {
	read(file_descriptor, buf, sizeof(buf));

	for (int i = 0; i < rf->number; i += 1)
	{
		if (rf->values[i].id == id)
		{
			return rf->values[i].value;
		}
	}
}

PerformanceMetric Performancing::GetMetric() {
	return performance_metric;
}
