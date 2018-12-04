
#ifndef ENVIRONMENT_INFO_H
#define ENVIRONMENT_INFO_H

#include <string>

std::string Environment_GetComputerName();

struct EnvironmentInfo {
    std::string commit, hostname;
};

#endif