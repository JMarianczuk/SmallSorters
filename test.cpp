
// #include <fstream>

// #include "NetworkSort_Simple.h"

// #define TestArraySize 6

// void test()
// {
//     SortableRef_ClangVersion* arr = (SortableRef_ClangVersion*) malloc(TestArraySize * sizeof(SortableRef_ClangVersion));
//     int start = 425;
//     for (int i = 0; i < TestArraySize; i+= 1)
//     {
//         arr[i].key = start - 3*i;
//         arr[i].reference = start + i;
//     }

//     networks::sortN(arr, TestArraySize);
//     printf("Key of number 3: %" PRIu64 ".", arr[3].key);
// }