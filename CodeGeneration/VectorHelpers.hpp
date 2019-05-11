
#ifndef VECTOR_HELPERS_H
#define VECTOR_HELPERS_H

#include <vector>
#include <functional>

namespace codegeneration
{

template <typename TValueType>
void VectorConcatenate(std::vector<TValueType> *source, std::vector<TValueType> *first, std::vector<TValueType> *second, std::vector<TValueType> *third = nullptr)
{
    source->insert(source->end(), first->begin(), first->end());
    source->insert(source->end(), second->begin(), second->end());
    delete first;
    delete second;
    if (third != nullptr)
    {
        source->insert(source->end(), third->begin(), third->end());
        delete third;
    }
}

template <typename TValueType>
bool VectorAny(std::vector<TValueType>& source, std::function<bool(TValueType)> predicate)
{
    for (TValueType item : source)
    {
        if (predicate(item))
        {
            return true;
        }
    }
    return false;
}

template<typename TValueType>
std::vector<TValueType>* VectorWhere(std::vector<TValueType>* source, std::function<bool(TValueType)> predicate)
{
    auto result = new std::vector<TValueType>();
    for (TValueType item : *source)
    {
        if (predicate(item))
        {
            result->push_back(item);
        }
    }
    return result;
}

}

#endif