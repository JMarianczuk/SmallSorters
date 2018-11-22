
#include "NetworkSort.h"

#define ConditionalSwap(left, right) if (items[left].key > items[right].key) {Sortable temp = items[left]; items[left] = items[right]; items[right] = temp;}
#define ConditionalSet(condition, left, right) { left = (condition) ? right : left; }
#define Compare(left, right) { Sortable itemLeft = items[left]; ConditionalSet(items[right].key < itemLeft.key, items[left], items[right]); ConditionalSet(items[right].key < itemLeft.key, items[right], itemLeft);}
#define CS(l, r) Compare(l, r)

void NetworkSort_Optimised(Sortable* items) {
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

void NetworkSort_Naive(Sortable* items) {
    ConditionalSwap(0, 1)
	ConditionalSwap(2, 3)
	ConditionalSwap(4, 5)
	ConditionalSwap(6, 7)
	ConditionalSwap(8, 9)
	ConditionalSwap(10, 11)
	ConditionalSwap(12, 13)
	ConditionalSwap(14, 15)

	ConditionalSwap(0, 2)
	ConditionalSwap(1, 3)
	ConditionalSwap(4, 6)
	ConditionalSwap(5, 7)
	ConditionalSwap(8, 10)
	ConditionalSwap(9, 11)
	ConditionalSwap(12, 14)
	ConditionalSwap(13, 15)

	ConditionalSwap(0, 4)
	ConditionalSwap(1, 5)
	ConditionalSwap(2, 6)
	ConditionalSwap(3, 7)
	ConditionalSwap(8, 12)
	ConditionalSwap(9, 13)
	ConditionalSwap(10, 14)
	ConditionalSwap(11, 15)

	ConditionalSwap(0, 8)
	ConditionalSwap(1, 9)
	ConditionalSwap(2, 10)
	ConditionalSwap(3, 11)
	ConditionalSwap(4, 12)
	ConditionalSwap(5, 13)
	ConditionalSwap(6, 14)
	ConditionalSwap(7, 15)

	ConditionalSwap(5, 10)
	ConditionalSwap(6, 9)
	ConditionalSwap(1, 2)
	ConditionalSwap(3, 12)
	ConditionalSwap(13, 14)
	ConditionalSwap(4, 8)
	ConditionalSwap(7, 11)

	ConditionalSwap(1, 4)
	ConditionalSwap(2, 8)
	ConditionalSwap(7, 13)
	ConditionalSwap(11, 14)

	ConditionalSwap(2, 4)
	ConditionalSwap(3, 8)
	ConditionalSwap(5, 6)
	ConditionalSwap(7, 12)
	ConditionalSwap(9, 10)
	ConditionalSwap(11, 13)

	ConditionalSwap(3, 5)
	ConditionalSwap(6, 8)
	ConditionalSwap(7, 9)
	ConditionalSwap(10, 12)

	ConditionalSwap(3, 4)
	ConditionalSwap(5, 6)
	ConditionalSwap(7, 8)
	ConditionalSwap(9, 10)
	ConditionalSwap(11, 12)

	ConditionalSwap(6, 7)
	ConditionalSwap(8, 9)
}