
#ifndef FUNCTIONAL_HELPERS_H
#define FUNCTIONAL_HELPERS_H

#include <functional>
#include <vector>
#include <utility>

namespace codegeneration
{

template <typename ValueType>
void Multicall(std::function<void(ValueType)> action, std::vector<ValueType> arguments)
{
    for (ValueType parameter : arguments)
    {
        action(parameter);
    }
}

} // namespace codegeneration

#endif