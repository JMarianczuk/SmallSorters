//------------------------------------------------------------------------------
// <auto-generated>
//     This code was auto-generated by CodeGeneration/Generate.cc
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
	const uint8_t at_radix(size_t depth) const
	{
		return (uint8_t) ( key >> (8 * (7 - depth)) );
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
	const uint8_t at_radix(size_t depth) const
	{
		return (uint8_t) ( key >> (8 * (7 - depth)) );
	}
};
struct LargeSortable
{
	float first;
	float second;
	float third;
	uint64_t payload[1024];
	friend bool operator<(const LargeSortable& left, const LargeSortable& right)
	{
		return left.first < right.first ||
			(left.first == right.first &&
				(left.second < right.second ||
					(left.second == right.second && left.third <right.third)
				)
			);
	}
};

#endif // SORTABLE_GENERATED_H
