



//------------------------------------------------------------------------------
// <auto-generated>
//     This code was auto-generated from a T4 template
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

template <typename TValueType>
static inline
uint64_t GetKey(TValueType& item)
{
    return 0;
}


template<>
inline
uint64_t GetKey(SortableRef& item)
{
	return item.key;
}
template<>
inline
uint64_t GetKey(Sortable_JumpXchg& item)
{
	return item.key;
}
template<>
inline
uint64_t GetKey(SortableRef_JumpXchg& item)
{
	return item.key;
}
template<>
inline
uint64_t GetKey(Sortable_TwoCmovTemp& item)
{
	return item.key;
}
template<>
inline
uint64_t GetKey(SortableRef_FourCmovTemp& item)
{
	return item.key;
}
template<>
inline
uint64_t GetKey(SortableRef_FourCmovTemp_Split& item)
{
	return item.key;
}
template<>
inline
uint64_t GetKey(Sortable_ThreeCmovRegisterTemp& item)
{
	return item.key;
}
template<>
inline
uint64_t GetKey(SortableRef_SixCmovRegisterTemp& item)
{
	return item.key;
}
template<>
inline
uint64_t GetKey(SortableRef_ClangVersion& item)
{
	return item.key;
}
template<>
inline
uint64_t GetKey(SortableRef_StlVersion& item)
{
	return item.key;
}
template<>
inline
uint64_t GetKey(SortableRef_PointerOptimized& item)
{
	return item.key;
}

#endif
