
#ifndef VECTOR_HEPLER_H
#define VECTOR_HELPER_H

#include <vector>

namespace codegeneration
{

template <typename TValueType>
void Concatenate(std::vector<TValueType>& source, std::vector<TValueType> first, std::vector<TValueType> second, std::vector<TValueType> third)
{
    source.insert(source.end(), first.begin(), first.end());
    source.insert(source.end(), second.begin(), second.end());
    source.insert(source.end(), third.begin(), third.end());
}

}

#endif