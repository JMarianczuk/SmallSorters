//------------------------------------------------------------------------------
// <auto-generated>
//     This code was auto-generated by CodeGeneration/Generate.cc
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

#ifndef STRUCT_HELPERS_H
#define STRUCT_HELPERS_H

#define ArraySize 16
#include <inttypes.h>
#include "Sortable.generated.h"

template <typename ValueType>
static inline
uint64_t GetKey(ValueType& item)
{
	return 0;
}
template <typename ValueType>
static inline
uint64_t GetReference(ValueType& item)
{
	return 0;
}

template <>
inline
uint64_t GetKey(Sortable& item)
{
	return item.key;
}
template <>
inline
uint64_t GetKey(SortableRef& item)
{
	return item.key;
}
template <>
inline
uint64_t GetReference(SortableRef& item)
{
	return item.reference;
}

#endif // STRUCT_HELPERS_H
