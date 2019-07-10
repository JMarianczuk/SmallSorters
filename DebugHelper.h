
#ifndef DEBUG_HELPER_H
#define DEBUG_HELPER_H

#include <iostream>
#include <fstream>

#include <string>
#include <vector>

namespace debug
{

template <typename Single>
void WriteLineRec(Single s)
{
    std::cerr << s;
    std::cerr << std::endl;
}

template <typename First, typename... Inputs>
void WriteLineRec(First first, Inputs... inputs)
{
    std::cerr << first;
    WriteLineRec(inputs...);
}
    
template <typename... TInputs>
void WriteLine(TInputs... inputs)
{
    WriteLineRec(inputs...);
}

} // namespace debug

#endif