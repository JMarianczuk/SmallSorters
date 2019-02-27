
#ifndef ENVIRONMENT_INFO_H
#define ENVIRONMENT_INFO_H

#include <string>
#include <inttypes.h>

namespace environment
{

std::string GetComputerName();
size_t GetCacheSizeInBytes(std::string hostname);

}

#endif