
#include <unistd.h>
#include <limits.h>

#include "EnvironmentInfo.h"

std::string Environment_GetComputerName() {
    char hostname[HOST_NAME_MAX];
    gethostname(hostname, HOST_NAME_MAX);
    std::string result(hostname);
    return result;
}

