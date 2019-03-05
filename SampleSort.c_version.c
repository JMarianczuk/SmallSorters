
#include <stdbool.h>

#define NumberOfSplitters 3
#define BlockSize 1
#define NumberOfBuckets NumberOfSplitters + 1

void RegisterSampleSort_C_Style(
    int* array, 
    int elementCount, 
    int baseCaseLimit, 
    void(*baseCaseSortFunc)(int*,int),
    bool(*predicateLess)(int,int))
{
    if (elementCount <= baseCaseLimit)
    {
        baseCaseSortFunc(array, elementCount);
        return;
    }
    
    int splitters[NumberOfSplitters];
    FindSplitters(array, elementCount, splitters, baseCaseSortFunc);
    int splitter0 = splitters[0];
    int splitter1 = splitters[1];
    int splitter2 = splitters[2];
    /*
            Splitter-Tree:
                  1
                /   \
               0     2
              / \   / \
    Buckets: 0   1 2   3
    */

    int* rawbuckets = (int*) malloc(sizeof(int) * 4 * elementCount);
    int* buckets[NumberOfBuckets];
    for (int i = 0; i < NumberOfBuckets; i += 1)
    {
        buckets[i] = &rawbuckets[i * elementCount];
    }

    int state;
    int predicateResult;
    int splitter0x;

    int max = elementCount - BlockSize;
    int current = 0;
    for ( ; current <= max; current += BlockSize)
    {
        state = 0;
        predicateResult = (int) predicateLess(splitter1, array[current]);
        splitter0x = splitter0;
        //BEGIN Asm block
        if (predicateResult > 0)
        {
            splitter0x = splitter2;
            state << 1;
            state = state | 1;
        }
        else 
        {
            state << 1;
        }
        //END Asm block
        predicateResult = (int) predicateLess(splitter0x, array[current]);
        //BEGIN Asm block
        if (predicateResult > 0)
        {
            state << 1;
            state = state | 1;
        }
        else 
        {
            state << 1;
        }
        //END Asm block

        *buckets[state] = array[current];
        buckets[state]++;
    }
}