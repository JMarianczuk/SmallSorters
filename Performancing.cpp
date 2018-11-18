// Performancing.cpp : Defines the entry point for the application.
//

#include "Performancing.h"

using namespace std;

struct read_format {
	uint64_t number;
	struct {
		uint64_t value;
		uint64_t id;
	} values[];
};

int main()
{
	/*pid_t pid = 0;
	int cpu = 0;
	int group_fd = -1;
	perf_event_attr attributes;
	attribute.type = PERF_TYPE_HARDWARE;
	attribute.size = sizeof(struct perf_event_attr);
	attribute.config = PERF_COUNT_HW_CPU_CYCLES;
	int fd = perf_event_open(attr, pid, cpu, group_fd, PERF_FLAG_FD_CLOEXEC);*/
	struct perf_event_attr performance_event_attribute;
	uint64_t id;

	char buf[4096];
	struct read_format* rf = (struct read_format*) buf;

	memset(&performance_event_attribute, 0, sizeof(struct perf_event_attr));
	performance_event_attribute.type = PERF_TYPE_HARDWARE;
	performance_event_attribute.size = sizeof(struct perf_event_attr);
	performance_event_attribute.config = PERF_COUNT_HW_CPU_CYCLES;
	performance_event_attribute.disabled = 1;
	performance_event_attribute.exclude_kernel = 1;
	performance_event_attribute.exclude_hv = 1;
	performance_event_attribute.read_format = PERF_FORMAT_GROUP | PERF_FORMAT_ID;
	int file = syscall(__NR_perf_event_open, &performance_event_attribute, 0, -1, -1, 0);
	ioctl(file, PERF_EVENT_IOC_ID, &id);
	ioctl(file, PERF_EVENT_IOC_RESET, PERF_IOC_FLAG_GROUP);
	ioctl(file, PERF_EVENT_IOC_ENABLE, PERF_IOC_FLAG_GROUP);

	int c = 0;
	for (int i = 0; i < 100000; i += 1)
	{
		c += 1;
	}

	ioctl(file, PERF_EVENT_IOC_DISABLE, PERF_IOC_FLAG_GROUP);

	read(file, buf, sizeof(buf));

	printf("%i\n", c);
	for (int i = 0; i < rf->number; i += 1)
	{
		if (rf->values[i].id == id)
		{
			printf("cpu cycles: %"PRIu64"\n", rf->values[i].value);
		}
	}

	close(file);

	return 0;
}
