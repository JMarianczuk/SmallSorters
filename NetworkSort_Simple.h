
#ifndef NETWORK_SORT_SIMPLE_H
#define NETWORK_SORT_SIMPLE_H

#include "Sortable.h"

void NetworkSortSimple_Generic(Sortable* items);

void SortTestJumpXchg(Sortable* items);
void SortTestTwoCmovTemp(Sortable* items);
void SortTestThreeCmovVolatileTemp(Sortable* items);
void SortTestThreeCmovRegisterTemp(Sortable* items);

#endif