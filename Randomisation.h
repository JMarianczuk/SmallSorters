
#ifndef RANDOMISATION_H
#define RANDOMISATION_H

#include <stdlib.h>
#include <inttypes.h>
#include <stdexcept>

#include "Sortable.h"

static uint64_t GenerateRandomUint64() {
    uint64_t number = rand();
    for (int i = 0; i < 3; i += 1) {
        number = (number << 16) | rand();
    }
    return number;
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
void GenerateRandomArray<Sortable_ThreeCmovVolatileTemp>(Sortable_ThreeCmovVolatileTemp* arr, int arraySize) {
    for (int i = 0; i < arraySize; i += 1) {
        arr[i].key = GenerateRandomUint64();
    }
}
template<>
void GenerateRandomArray<SortableRef_SixCmovVolatileTemp>(SortableRef_SixCmovVolatileTemp* arr, int arraySize) {
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


// void GenerateRandomArray(Sortable* arr, uint64_t limit) {
//     uint64_t pointer = GenerateRandomUint64() % limit;
// 	for (int i = 0; i < ArraySize; i += 1)
// 	{
// 		arr[i].key = GenerateRandomUint64() % limit;
//         arr[i].reference = (pointer + i) % limit;
// 	}
// }
// void GenerateRandomArray(Sortable* arr) {
//     uint64_t max = 1 << 20;
//     max -= 1;
//     max << 1;
//     max += 1;
//     printf("Max uint: %" PRIu64 "\n", max);
//     GenerateRandomArray(arr, max);
// }

#endif