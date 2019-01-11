
#ifndef RANDOMISATION_H
#define RANDOMISATION_H

#include <stdlib.h>
#include <inttypes.h>
#include <stdexcept>
#include <random>

#include "Numbers.h"
#include "Sortable.generated.h"

namespace randomisation {

std::default_random_engine generator;
std::uniform_int_distribution<unsigned long long> distribution(0, UINT_64_MAX_VALUE);

void SetSeed(unsigned long seed) {
    generator.seed(seed);
}

uint64_t GenerateRandomUint64() {
    return (uint64_t) distribution(generator);
}

template <typename TValueType>
void GenerateRandomArray(TValueType* arr, int arraySize) {
    throw std::logic_error("Not implemented for generic type");
}



template<>
void GenerateRandomArray<int>(int* arr, int arraySize) {
    for (int i = 0; i < arraySize; i += 1) {
        arr[i] = rand();
    }
}
template<>
void GenerateRandomArray<uint64_t>(uint64_t* arr, int arraySize) {
    for (int i = 0; i < arraySize; i += 1) {
        arr[i] = GenerateRandomUint64();
    }
}



template<>
void GenerateRandomArray<SortableRef>(SortableRef* arr, int arraySize) {
    uint64_t reference = GenerateRandomUint64();
    for (int i = 0; i < arraySize; i += 1) {
        arr[i].key = GenerateRandomUint64();
        arr[i].reference = reference + i;
    }
}



template<>
void GenerateRandomArray<Sortable_JumpXchg>(Sortable_JumpXchg* arr, int arraySize) {
    for (int i = 0; i < arraySize; i += 1) {
        arr[i].key = GenerateRandomUint64();
    }
}
template<>
void GenerateRandomArray<SortableRef_JumpXchg>(SortableRef_JumpXchg* arr, int arraySize) {
    uint64_t reference = GenerateRandomUint64();
    for (int i = 0; i < arraySize; i += 1) {
        arr[i].key = GenerateRandomUint64();
        arr[i].reference = reference + i;
    }
}



template<>
void GenerateRandomArray<Sortable_TwoCmovTemp>(Sortable_TwoCmovTemp* arr, int arraySize) {
    for (int i = 0; i < arraySize; i += 1) {
        arr[i].key = GenerateRandomUint64();
    }
}
template<>
void GenerateRandomArray<SortableRef_FourCmovTemp>(SortableRef_FourCmovTemp* arr, int arraySize) {
    uint64_t reference = GenerateRandomUint64();
    for (int i = 0; i < arraySize; i += 1) {
        arr[i].key = GenerateRandomUint64();
        arr[i].reference = reference + i;
    }
}



template<>
void GenerateRandomArray<Sortable_ThreeCmovRegisterTemp>(Sortable_ThreeCmovRegisterTemp* arr, int arraySize) {
    for (int i = 0; i < arraySize; i += 1) {
        arr[i].key = GenerateRandomUint64();
    }
}
template<>
void GenerateRandomArray<SortableRef_SixCmovRegisterTemp>(SortableRef_SixCmovRegisterTemp* arr, int arraySize) {
    uint64_t reference = GenerateRandomUint64();
    for (int i = 0; i < arraySize; i += 1) {
        arr[i].key = GenerateRandomUint64();
        arr[i].reference = reference + i;
    }
}



template<>
void GenerateRandomArray<SortableRef_ClangVersion>(SortableRef_ClangVersion* arr, int arraySize) {
    uint64_t reference = GenerateRandomUint64();
    for (int i = 0; i < arraySize; i += 1) {
        arr[i].key = GenerateRandomUint64();
        arr[i].reference = reference + i;
    }
}

}

#endif