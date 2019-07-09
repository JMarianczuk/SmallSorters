
#ifndef VECTOR_HELPERS_H
#define VECTOR_HELPERS_H

#include <vector>
#include <functional>

namespace codegeneration
{

template <typename ValueType>
void VectorConcatenate(std::vector<ValueType> *source, std::vector<ValueType> *first, std::vector<ValueType> *second, std::vector<ValueType> *third = nullptr)
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

template <typename ValueType>
bool VectorAny(std::vector<ValueType>& source, std::function<bool(ValueType)> predicate)
{
    for (ValueType item : source)
    {
        if (predicate(item))
        {
            return true;
        }
    }
    return false;
}

template<typename ValueType>
std::vector<ValueType>* VectorWhere(std::vector<ValueType>* source, std::function<bool(ValueType)> predicate)
{
    auto result = new std::vector<ValueType>();
    for (ValueType item : *source)
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