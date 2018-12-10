
#include "NetworkSort.h"

#include <algorithm>

#define ConditionalSwapDef(left, right) if (items[left].key > items[right].key) {std::swap(items[left], items[right]);}
#define ConditionalSet(condition, left, right) { left = (condition) ? right : left; }
#define Compare(left, right) { SortableRef itemLeft = items[left]; ConditionalSet(items[right].key < itemLeft.key, items[left], items[right]); ConditionalSet(items[right].key < itemLeft.key, items[right], itemLeft);}
#define CS(l, r) Compare(l, r)

void NetworkSort_Optimised(SortableRef* items) {
	//Greens Network: 60-comparator 10 parallel steps 16-input sorting network
    CS(0, 1)
	CS(2, 3)
	CS(4, 5)
	CS(6, 7)
	CS(8, 9)
	CS(10, 11)
	CS(12, 13)
	CS(14, 15)

	CS(0, 2)
	CS(1, 3)
	CS(4, 6)
	CS(5, 7)
	CS(8, 10)
	CS(9, 11)
	CS(12, 14)
	CS(13, 15)

	CS(0, 4)
	CS(1, 5)
	CS(2, 6)
	CS(3, 7)
	CS(8, 12)
	CS(9, 13)
	CS(10, 14)
	CS(11, 15)

	CS(0, 8)
	CS(1, 9)
	CS(2, 10)
	CS(3, 11)
	CS(4, 12)
	CS(5, 13)
	CS(6, 14)
	CS(7, 15)

	CS(5, 10)
	CS(6, 9)
	CS(1, 2)
	CS(3, 12)
	CS(13, 14)
	CS(4, 8)
	CS(7, 11)

	CS(1, 4)
	CS(2, 8)
	CS(7, 13)
	CS(11, 14)

	CS(2, 4)
	CS(3, 8)
	CS(5, 6)
	CS(7, 12)
	CS(9, 10)
	CS(11, 13)

	CS(3, 5)
	CS(6, 8)
	CS(7, 9)
	CS(10, 12)

	CS(3, 4)
	CS(5, 6)
	CS(7, 8)
	CS(9, 10)
	CS(11, 12)

	CS(6, 7)
	CS(8, 9)
}

void NetworkSort_Naive(SortableRef* items) {
    ConditionalSwapDef(0, 1)
	ConditionalSwapDef(2, 3)
	ConditionalSwapDef(4, 5)
	ConditionalSwapDef(6, 7)
	ConditionalSwapDef(8, 9)
	ConditionalSwapDef(10, 11)
	ConditionalSwapDef(12, 13)
	ConditionalSwapDef(14, 15)

	ConditionalSwapDef(0, 2)
	ConditionalSwapDef(1, 3)
	ConditionalSwapDef(4, 6)
	ConditionalSwapDef(5, 7)
	ConditionalSwapDef(8, 10)
	ConditionalSwapDef(9, 11)
	ConditionalSwapDef(12, 14)
	ConditionalSwapDef(13, 15)

	ConditionalSwapDef(0, 4)
	ConditionalSwapDef(1, 5)
	ConditionalSwapDef(2, 6)
	ConditionalSwapDef(3, 7)
	ConditionalSwapDef(8, 12)
	ConditionalSwapDef(9, 13)
	ConditionalSwapDef(10, 14)
	ConditionalSwapDef(11, 15)

	ConditionalSwapDef(0, 8)
	ConditionalSwapDef(1, 9)
	ConditionalSwapDef(2, 10)
	ConditionalSwapDef(3, 11)
	ConditionalSwapDef(4, 12)
	ConditionalSwapDef(5, 13)
	ConditionalSwapDef(6, 14)
	ConditionalSwapDef(7, 15)

	ConditionalSwapDef(5, 10)
	ConditionalSwapDef(6, 9)
	ConditionalSwapDef(1, 2)
	ConditionalSwapDef(3, 12)
	ConditionalSwapDef(13, 14)
	ConditionalSwapDef(4, 8)
	ConditionalSwapDef(7, 11)

	ConditionalSwapDef(1, 4)
	ConditionalSwapDef(2, 8)
	ConditionalSwapDef(7, 13)
	ConditionalSwapDef(11, 14)

	ConditionalSwapDef(2, 4)
	ConditionalSwapDef(3, 8)
	ConditionalSwapDef(5, 6)
	ConditionalSwapDef(7, 12)
	ConditionalSwapDef(9, 10)
	ConditionalSwapDef(11, 13)

	ConditionalSwapDef(3, 5)
	ConditionalSwapDef(6, 8)
	ConditionalSwapDef(7, 9)
	ConditionalSwapDef(10, 12)

	ConditionalSwapDef(3, 4)
	ConditionalSwapDef(5, 6)
	ConditionalSwapDef(7, 8)
	ConditionalSwapDef(9, 10)
	ConditionalSwapDef(11, 12)

	ConditionalSwapDef(6, 7)
	ConditionalSwapDef(8, 9)
}