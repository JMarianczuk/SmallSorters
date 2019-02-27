
#ifndef DEBUG_HELPER_H
#define DEBUG_HELPER_H

#include <iostream>
#include <fstream>

#include <string>
#include <vector>

namespace debug
{
    
template <typename... TInputs>
void WriteLine(TInputs... inputs)
{
    std::vector<std::string> args = {inputs...};
    for (auto arg : args)
    {
        std::cerr << arg;
    }
    std::cerr << std::endl;
}

}

#endif