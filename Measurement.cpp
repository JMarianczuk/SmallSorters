
// #include "Result.h"
// #include "NetworkSort_Simple.h"
// #include "InsertionSort.h"
// #include "Randomisation.h"
// #include "ArrayHelpers.h"
// #include "Sortable.h"

// #include "Measurement.h"

// Measurement::Measurement(Performancing* perf, EnvironmentInfo info, int numOfIterations)
// {
//     performancing = perf;
//     envInfo = info;
//     numberOfIterations = numOfIterations;
// }

// template <typename TValueType>
// void Measurement::MeasureNetworkSort(int arraySize, std::string sorterName)
// {
//     TValueType* arr = (TValueType*) malloc(arraySize * sizeof(TValueType));

//     int numberOfBadSorts = 0;
//     GenerateRandomArray(arr, arraySize);
//     networks::sortN(arr, arraySize);
//     if (!IsSorted(arr, arraySize)) 
//     {
//         numberOfBadSorts += 1;
//     }

//     performancing->StartMeasuring();
//     for (int i = 0; i < numberOfIterations; i += 1)
//     {
//         GenerateRandomArray(arr, arraySize);
//         networks::sortN(arr, arraySize);
//         if (!IsSorted(arr, arraySize)) 
//         {
//             numberOfBadSorts += 1;
//         }
//     }
//     performancing->StopMeasuring();

//     WriteResultLine(
//         sorterName,
//         performancing,
//         envInfo,
//         sizeof(TValueType),
//         arraySize,
//         numberOfIterations,
//         numberOfBadSorts
//     );

//     free(arr);
// }

// template <typename TValueType>
// void Measurement::MeasureInsertionSort(int arraySize, std::string sorterName) 
// {
//     TValueType* arr = (TValueType*) malloc(arraySize * sizeof(TValueType));
    
//     int numberOfBadSorts = 0;
//     GenerateRandomArray(arr, arraySize);
//     insertionsort::InsertionSort(arr, arraySize);
//     if (!IsSorted(arr, arraySize)) 
//     {
//         numberOfBadSorts += 1;
//     }

//     performancing->StartMeasuring();
//     for (int i = 0; i < numberOfIterations; i += 1)
//     {
//         GenerateRandomArray(arr, arraySize);
//         insertionsort::InsertionSort(arr, arraySize);
//         if (!IsSorted(arr, arraySize))
//         {
//             numberOfBadSorts += 1;
//         }
//     }
//     performancing->StopMeasuring();

//     WriteResultLine(
//         sorterName,
//         performancing,
//         envInfo,
//         sizeof(TValueType),
//         arraySize,
//         numberOfIterations,
//         numberOfBadSorts
//     );

//     free(arr);
// }