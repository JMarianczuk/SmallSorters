//------------------------------------------------------------------------------
// <auto-generated>
//     This code was auto-generated
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

#ifndef SORTABLE_GENERATED_H
#define SORTABLE_GENERATED_H

#define ArraySize 16
#include <inttypes.h>
struct SortableRef
{
	uint64_t key;
	uint64_t reference;
	friend bool operator>(const SortableRef& left, const SortableRef& right)
	{
		return left.key > right.key;
	}
	friend bool operator>=(const SortableRef& left, const SortableRef& right)
	{
		return left.key >= right.key;
	}
	friend bool operator==(const SortableRef& left, const SortableRef& right)
	{
		return left.key == right.key;
	}
	friend bool operator<(const SortableRef& left, const SortableRef& right)
	{
		return left.key < right.key;
	}
	friend bool operator<=(const SortableRef& left, const SortableRef& right)
	{
		return left.key <= right.key;
	}
	friend bool operator!=(const SortableRef& left, const SortableRef& right)
	{
		return left.key != right.key;
	}
};
struct Sortable_JumpXchg
{
	uint64_t key;
	friend bool operator>(const Sortable_JumpXchg& left, const Sortable_JumpXchg& right)
	{
		return left.key > right.key;
	}
	friend bool operator>=(const Sortable_JumpXchg& left, const Sortable_JumpXchg& right)
	{
		return left.key >= right.key;
	}
	friend bool operator==(const Sortable_JumpXchg& left, const Sortable_JumpXchg& right)
	{
		return left.key == right.key;
	}
	friend bool operator<(const Sortable_JumpXchg& left, const Sortable_JumpXchg& right)
	{
		return left.key < right.key;
	}
	friend bool operator<=(const Sortable_JumpXchg& left, const Sortable_JumpXchg& right)
	{
		return left.key <= right.key;
	}
	friend bool operator!=(const Sortable_JumpXchg& left, const Sortable_JumpXchg& right)
	{
		return left.key != right.key;
	}
};
struct SortableRef_JumpXchg
{
	uint64_t key;
	uint64_t reference;
	friend bool operator>(const SortableRef_JumpXchg& left, const SortableRef_JumpXchg& right)
	{
		return left.key > right.key;
	}
	friend bool operator>=(const SortableRef_JumpXchg& left, const SortableRef_JumpXchg& right)
	{
		return left.key >= right.key;
	}
	friend bool operator==(const SortableRef_JumpXchg& left, const SortableRef_JumpXchg& right)
	{
		return left.key == right.key;
	}
	friend bool operator<(const SortableRef_JumpXchg& left, const SortableRef_JumpXchg& right)
	{
		return left.key < right.key;
	}
	friend bool operator<=(const SortableRef_JumpXchg& left, const SortableRef_JumpXchg& right)
	{
		return left.key <= right.key;
	}
	friend bool operator!=(const SortableRef_JumpXchg& left, const SortableRef_JumpXchg& right)
	{
		return left.key != right.key;
	}
};
struct Sortable_TwoCmovTemp
{
	uint64_t key;
	friend bool operator>(const Sortable_TwoCmovTemp& left, const Sortable_TwoCmovTemp& right)
	{
		return left.key > right.key;
	}
	friend bool operator>=(const Sortable_TwoCmovTemp& left, const Sortable_TwoCmovTemp& right)
	{
		return left.key >= right.key;
	}
	friend bool operator==(const Sortable_TwoCmovTemp& left, const Sortable_TwoCmovTemp& right)
	{
		return left.key == right.key;
	}
	friend bool operator<(const Sortable_TwoCmovTemp& left, const Sortable_TwoCmovTemp& right)
	{
		return left.key < right.key;
	}
	friend bool operator<=(const Sortable_TwoCmovTemp& left, const Sortable_TwoCmovTemp& right)
	{
		return left.key <= right.key;
	}
	friend bool operator!=(const Sortable_TwoCmovTemp& left, const Sortable_TwoCmovTemp& right)
	{
		return left.key != right.key;
	}
};
struct SortableRef_FourCmovTemp
{
	uint64_t key;
	uint64_t reference;
	friend bool operator>(const SortableRef_FourCmovTemp& left, const SortableRef_FourCmovTemp& right)
	{
		return left.key > right.key;
	}
	friend bool operator>=(const SortableRef_FourCmovTemp& left, const SortableRef_FourCmovTemp& right)
	{
		return left.key >= right.key;
	}
	friend bool operator==(const SortableRef_FourCmovTemp& left, const SortableRef_FourCmovTemp& right)
	{
		return left.key == right.key;
	}
	friend bool operator<(const SortableRef_FourCmovTemp& left, const SortableRef_FourCmovTemp& right)
	{
		return left.key < right.key;
	}
	friend bool operator<=(const SortableRef_FourCmovTemp& left, const SortableRef_FourCmovTemp& right)
	{
		return left.key <= right.key;
	}
	friend bool operator!=(const SortableRef_FourCmovTemp& left, const SortableRef_FourCmovTemp& right)
	{
		return left.key != right.key;
	}
};
struct SortableRef_FourCmovTemp_Split
{
	uint64_t key;
	uint64_t reference;
	friend bool operator>(const SortableRef_FourCmovTemp_Split& left, const SortableRef_FourCmovTemp_Split& right)
	{
		return left.key > right.key;
	}
	friend bool operator>=(const SortableRef_FourCmovTemp_Split& left, const SortableRef_FourCmovTemp_Split& right)
	{
		return left.key >= right.key;
	}
	friend bool operator==(const SortableRef_FourCmovTemp_Split& left, const SortableRef_FourCmovTemp_Split& right)
	{
		return left.key == right.key;
	}
	friend bool operator<(const SortableRef_FourCmovTemp_Split& left, const SortableRef_FourCmovTemp_Split& right)
	{
		return left.key < right.key;
	}
	friend bool operator<=(const SortableRef_FourCmovTemp_Split& left, const SortableRef_FourCmovTemp_Split& right)
	{
		return left.key <= right.key;
	}
	friend bool operator!=(const SortableRef_FourCmovTemp_Split& left, const SortableRef_FourCmovTemp_Split& right)
	{
		return left.key != right.key;
	}
};
struct Sortable_ThreeCmovRegisterTemp
{
	uint64_t key;
	friend bool operator>(const Sortable_ThreeCmovRegisterTemp& left, const Sortable_ThreeCmovRegisterTemp& right)
	{
		return left.key > right.key;
	}
	friend bool operator>=(const Sortable_ThreeCmovRegisterTemp& left, const Sortable_ThreeCmovRegisterTemp& right)
	{
		return left.key >= right.key;
	}
	friend bool operator==(const Sortable_ThreeCmovRegisterTemp& left, const Sortable_ThreeCmovRegisterTemp& right)
	{
		return left.key == right.key;
	}
	friend bool operator<(const Sortable_ThreeCmovRegisterTemp& left, const Sortable_ThreeCmovRegisterTemp& right)
	{
		return left.key < right.key;
	}
	friend bool operator<=(const Sortable_ThreeCmovRegisterTemp& left, const Sortable_ThreeCmovRegisterTemp& right)
	{
		return left.key <= right.key;
	}
	friend bool operator!=(const Sortable_ThreeCmovRegisterTemp& left, const Sortable_ThreeCmovRegisterTemp& right)
	{
		return left.key != right.key;
	}
};
struct SortableRef_SixCmovRegisterTemp
{
	uint64_t key;
	uint64_t reference;
	friend bool operator>(const SortableRef_SixCmovRegisterTemp& left, const SortableRef_SixCmovRegisterTemp& right)
	{
		return left.key > right.key;
	}
	friend bool operator>=(const SortableRef_SixCmovRegisterTemp& left, const SortableRef_SixCmovRegisterTemp& right)
	{
		return left.key >= right.key;
	}
	friend bool operator==(const SortableRef_SixCmovRegisterTemp& left, const SortableRef_SixCmovRegisterTemp& right)
	{
		return left.key == right.key;
	}
	friend bool operator<(const SortableRef_SixCmovRegisterTemp& left, const SortableRef_SixCmovRegisterTemp& right)
	{
		return left.key < right.key;
	}
	friend bool operator<=(const SortableRef_SixCmovRegisterTemp& left, const SortableRef_SixCmovRegisterTemp& right)
	{
		return left.key <= right.key;
	}
	friend bool operator!=(const SortableRef_SixCmovRegisterTemp& left, const SortableRef_SixCmovRegisterTemp& right)
	{
		return left.key != right.key;
	}
};
struct SortableRef_ClangVersion
{
	uint64_t key;
	uint64_t reference;
	friend bool operator>(const SortableRef_ClangVersion& left, const SortableRef_ClangVersion& right)
	{
		return left.key > right.key;
	}
	friend bool operator>=(const SortableRef_ClangVersion& left, const SortableRef_ClangVersion& right)
	{
		return left.key >= right.key;
	}
	friend bool operator==(const SortableRef_ClangVersion& left, const SortableRef_ClangVersion& right)
	{
		return left.key == right.key;
	}
	friend bool operator<(const SortableRef_ClangVersion& left, const SortableRef_ClangVersion& right)
	{
		return left.key < right.key;
	}
	friend bool operator<=(const SortableRef_ClangVersion& left, const SortableRef_ClangVersion& right)
	{
		return left.key <= right.key;
	}
	friend bool operator!=(const SortableRef_ClangVersion& left, const SortableRef_ClangVersion& right)
	{
		return left.key != right.key;
	}
};
struct SortableRef_StlVersion
{
	uint64_t key;
	uint64_t reference;
	friend bool operator>(const SortableRef_StlVersion& left, const SortableRef_StlVersion& right)
	{
		return left.key > right.key;
	}
	friend bool operator>=(const SortableRef_StlVersion& left, const SortableRef_StlVersion& right)
	{
		return left.key >= right.key;
	}
	friend bool operator==(const SortableRef_StlVersion& left, const SortableRef_StlVersion& right)
	{
		return left.key == right.key;
	}
	friend bool operator<(const SortableRef_StlVersion& left, const SortableRef_StlVersion& right)
	{
		return left.key < right.key;
	}
	friend bool operator<=(const SortableRef_StlVersion& left, const SortableRef_StlVersion& right)
	{
		return left.key <= right.key;
	}
	friend bool operator!=(const SortableRef_StlVersion& left, const SortableRef_StlVersion& right)
	{
		return left.key != right.key;
	}
};
struct SortableRef_PointerOptimized
{
	uint64_t key;
	uint64_t reference;
	friend bool operator>(const SortableRef_PointerOptimized& left, const SortableRef_PointerOptimized& right)
	{
		return left.key > right.key;
	}
	friend bool operator>=(const SortableRef_PointerOptimized& left, const SortableRef_PointerOptimized& right)
	{
		return left.key >= right.key;
	}
	friend bool operator==(const SortableRef_PointerOptimized& left, const SortableRef_PointerOptimized& right)
	{
		return left.key == right.key;
	}
	friend bool operator<(const SortableRef_PointerOptimized& left, const SortableRef_PointerOptimized& right)
	{
		return left.key < right.key;
	}
	friend bool operator<=(const SortableRef_PointerOptimized& left, const SortableRef_PointerOptimized& right)
	{
		return left.key <= right.key;
	}
	friend bool operator!=(const SortableRef_PointerOptimized& left, const SortableRef_PointerOptimized& right)
	{
		return left.key != right.key;
	}
};
struct SortableRef_ArrayIndex_FirstCheck
{
	uint64_t key;
	uint64_t reference;
	friend bool operator>(const SortableRef_ArrayIndex_FirstCheck& left, const SortableRef_ArrayIndex_FirstCheck& right)
	{
		return left.key > right.key;
	}
	friend bool operator>=(const SortableRef_ArrayIndex_FirstCheck& left, const SortableRef_ArrayIndex_FirstCheck& right)
	{
		return left.key >= right.key;
	}
	friend bool operator==(const SortableRef_ArrayIndex_FirstCheck& left, const SortableRef_ArrayIndex_FirstCheck& right)
	{
		return left.key == right.key;
	}
	friend bool operator<(const SortableRef_ArrayIndex_FirstCheck& left, const SortableRef_ArrayIndex_FirstCheck& right)
	{
		return left.key < right.key;
	}
	friend bool operator<=(const SortableRef_ArrayIndex_FirstCheck& left, const SortableRef_ArrayIndex_FirstCheck& right)
	{
		return left.key <= right.key;
	}
	friend bool operator!=(const SortableRef_ArrayIndex_FirstCheck& left, const SortableRef_ArrayIndex_FirstCheck& right)
	{
		return left.key != right.key;
	}
};

#endif
