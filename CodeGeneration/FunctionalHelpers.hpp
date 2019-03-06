
#ifndef FUNCTIONAL_HELPERS_H
#define FUNCTIONAL_HELPERS_H

#include <functional>
#include <vector>

namespace codegeneration
{

template <typename TValueType>
void Multicall(std::function<void(TValueType)> action, std::vector<TValueType> arguments)
{
    for (TValueType parameter : arguments)
    {
        action(parameter);
    }
}

}

#endif