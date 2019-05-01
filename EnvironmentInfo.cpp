
#include <unistd.h>
#include <limits.h>

#include "EnvironmentInfo.h"

namespace environment
{

std::string GetComputerName() {
    char hostname[HOST_NAME_MAX];
    gethostname(hostname, HOST_NAME_MAX);
    std::string result(hostname);
    return result;
}

size_t GetCacheSizeInBytes(std::string hostname)
{
    size_t kilobytes = 1024;
    size_t megabytes = 1024 * kilobytes;
    if (hostname.compare("i10pc129") == 0)
    {
        return 20 * megabytes;
    }
    else if (hostname.compare("i10pc130") == 0)
    {
        return 30 * megabytes;
    }
    else if (hostname.compare("i10pc133") == 0)
    {
        return 8 * megabytes;
    }
    else
    {
        return 1 * megabytes;
    }
}

}



