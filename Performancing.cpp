// Performancing.cpp : Defines the entry point for the application.
//

#include "Performancing.h"
#include "Result.h"

using namespace std;

struct read_format {
	uint64_t number;
	struct {
		uint64_t value;
		uint64_t id;
	} values[];
};


Performancing::Performancing(PerformanceMetric metric) {
	memset(&performance_event_attribute, 0, sizeof(struct perf_event_attr));
	performance_event_attribute.type = PERF_TYPE_HARDWARE;
	performance_event_attribute.size = sizeof(struct perf_event_attr);
	performance_event_attribute.config = PERF_COUNT_HW_CPU_CYCLES;
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

int main()
{
	auto perf = new Performancing(PerformanceMetric::CPU_CYCLES);

	for (int iteration = 0; iteration < 100; iteration += 1)
	{
		perf->StartMeasuring();

		int c = 0;
		for (int i = 0; i < 1000; i += 1)
		{
			c += 1;
		}

		perf->StopMeasuring();

		// printf("Count: %i, Iteration %i\n", c, iteration);
		// printf("cpu cycles: %"PRIu64"\n", perf->GetValue());
		WriteResultLine(
			Sorter::INSERTION_SORT, 
			PerformanceMetric::CPU_CYCLES, 
			perf->GetValue(), 
			iteration);
	}
	
	delete perf;

	return 0;
}
