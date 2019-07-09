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
struct Sortable
{
	uint64_t key;
	friend bool operator>(const Sortable& left, const Sortable& right)
	{
		return left.key > right.key;
	}
	friend bool operator>=(const Sortable& left, const Sortable& right)
	{
		return left.key >= right.key;
	}
	friend bool operator==(const Sortable& left, const Sortable& right)
	{
		return left.key == right.key;
	}
	friend bool operator<(const Sortable& left, const Sortable& right)
	{
		return left.key < right.key;
	}
	friend bool operator<=(const Sortable& left, const Sortable& right)
	{
		return left.key <= right.key;
	}
	friend bool operator!=(const Sortable& left, const Sortable& right)
	{
		return left.key != right.key;
	}
};
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

#endif // SORTABLE_GENERATED_H
