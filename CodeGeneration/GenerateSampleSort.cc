
#include <math.h>

#include "GenerateSampleSort.hpp"

namespace codegeneration
{

std::string GetName(int numberOfSplitters, int oversamplingFactor)
{
    return std::to_string(numberOfSplitters) + "Splitters" + std::to_string(oversamplingFactor) + "OversamplingFactor";
}

std::string GetPlusI(int i)
{
    return i > 0 ? " + " + std::to_string(i) : "";
}

void WriteAsmBlock(CodeGenerator* gen, std::function<void()> writeFunc)
{
    gen->WriteLine("__asm__(");
    gen->WriteIndented(writeFunc);
    gen->WriteLine(");");
}

void WriteAsmLine(CodeGenerator* gen, std::string content)
{
    gen->WriteLine("\"", content, "\\n\\t\"");
}

void WriteSortElementsIntoBuckets(CodeGenerator* gen, int numberOfSplitters, int blockSize)
{
    for (int i = 0; i < blockSize; i += 1)
    {
        std::string iStr = std::to_string(i);
        gen->WriteLine("predicateResult", iStr, " = (int) predicateLess(splitter1, A[current", GetPlusI(i), "]);");
        gen->WriteLine("state", iStr, " = predicateResult", iStr, ";");
        gen->WriteLine("splitter0", iStr, "x = splitter0;");
    }
    for (int i = 0; i < blockSize; i += 1)
    {
        std::string iStr = std::to_string(i);
        // gen->WriteLine("splitter0", iStr, "x = predicateResult", iStr, " ? splitter2 : splitter0", iStr, "x;");
        // gen->WriteLine("state", iStr, " = predicateResult", iStr, " << 1;");

        WriteAsmBlock(gen, [=]{
            WriteAsmLine(gen, "cmp %[predResult],%[zero]");
            WriteAsmLine(gen, "cmovcq %[splitter2],%[splitterx]");
            // WriteAsmLine(gen, "rcl $1,%[state]");
            gen->WriteLine(": [splitterx] \"=&r\"(splitter0", iStr, "x)");
            // gen->WriteLine(": [splitterx] \"=&r\"(splitter0", iStr, "x), [state] \"=&r\"(state", iStr, ")");
            gen->WriteLine(": \"0\"(splitter0", iStr, "x), [splitter2] \"r\"(splitter2), [predResult] \"r\"(predicateResult", iStr, "), [zero] \"r\"(0)");
            // gen->WriteLine(": \"0\"(splitter0", iStr, "x), \"1\"(state", iStr, "), [splitter2] \"r\"(splitter2), [predResult] \"r\"(predicateResult", iStr, "), [zero] \"r\"(0)");
            gen->WriteLine(": \"cc\"");
        });
    }
    for (int i = 0; i < blockSize; i += 1)
    {
        std::string iStr = std::to_string(i);
        gen->WriteLine("predicateResult", iStr, " = (int) predicateLess(splitter0", iStr, "x, A[current", GetPlusI(i), "]);");
    }
    for (int i = 0; i < blockSize; i += 1)
    {
        std::string iStr = std::to_string(i);
        // gen->WriteLine("state", iStr, " = state", iStr, " + predicateResult", iStr, ";");

        gen->WriteLine("state", iStr, " = (state", iStr, " << 1) + predicateResult", iStr, ";");

        // WriteAsmBlock(gen, [=]{
        //     WriteAsmLine(gen, "cmp %[predResult],%[zero]");
        //     WriteAsmLine(gen, "rcl $1,%[state]");
        //     gen->WriteLine(": [state] \"=&r\"(state", iStr, ")");
        //     gen->WriteLine(": \"0\"(state", iStr, "), [predResult] \"r\"(predicateResult", iStr, "), [zero] \"r\"(zero)");
        //     gen->WriteLine(": \"cc\"");
        // });
    }
    for (int i = 0; i < blockSize; i += 1)
    {
        std::string iStr = std::to_string(i);
        gen->WriteLine("*buckets[state", iStr, "] = A[current", GetPlusI(i), "];");
        gen->WriteLine("buckets[state", iStr, "]++;");
    }
}

void WriteFindSplitters(CodeGenerator* gen, int numberOfSplitters, int oversamplingFactor)
{
    int sampleSize = numberOfSplitters * oversamplingFactor;
    std::string sampleSizeStr = std::to_string(sampleSize);
    gen->WriteLine("template <typename ValueType, typename TKey>");
    gen->WriteLine("static inline");
    gen->WriteLine("void Find", GetName(numberOfSplitters, oversamplingFactor), "(");

    gen->WriteIndented([=]{
        gen->WriteLine("ValueType* items,");
        gen->WriteLine("size_t elementCount,");
        gen->WriteLine("TKey* splitterDestination,");
        gen->WriteLine("void(*sortFunc)(ValueType*,size_t),");
        gen->WriteLine("TKey(*getKeyFunc)(ValueType&))");
    });
    gen->WriteBlock([=]{
        gen->WriteLine("ValueType sample[", sampleSizeStr, "];");
        
        gen->WriteLine("int blockSize = elementCount / ", sampleSizeStr, ";");

        gen->WriteForLoop("i", 0, sampleSize, [=]{
            gen->WriteLine("sample[i] = items[i * blockSize];");
        });
        gen->WriteLine("sortFunc(sample, ", sampleSizeStr, ");");
        gen->WriteLine("");

        gen->WriteForLoop("i", 0, numberOfSplitters, [=]{
            gen->Write("splitterDestination[i] = getKeyFunc(sample[i * ");
            gen->Write(oversamplingFactor);
            gen->Write(" + ");
            gen->Write(oversamplingFactor / 2);
            gen->WriteLine("]);");
        });
    });
}

void WriteRegisterSampleSort(CodeGenerator* gen, int numberOfSplitters, int oversamplingFactor, int blockSize)
{
    int numberOfBuckets = numberOfSplitters + 1;
    std::string blockSizeStr = std::to_string(blockSize);
    std::string numberOfSplittersStr = std::to_string(numberOfSplitters);
    std::string numberOfBucketsStr = std::to_string(numberOfBuckets);

    gen->WriteLine("template <typename ValueType, typename TKey>");
    gen->WriteLine("inline");
    gen->WriteLine("void SampleSortInternal", GetName(numberOfSplitters, oversamplingFactor), blockSizeStr, "BlockSize(");
    gen->WriteIndented([=]{
        gen->WriteLine("ValueType* A,");
        gen->WriteLine("size_t elementCount,");
        gen->WriteLine("size_t baseCaseLimit,");
        gen->WriteLine("void(*sortFunc)(ValueType*,size_t),");
        gen->WriteLine("bool(*predicateLess)(TKey&,ValueType&),");
        gen->WriteLine("TKey(*getKeyFunc)(ValueType&),");
        gen->WriteLine("int depthLimit)");
    });
    gen->WriteBlock([=]{
        gen->WriteLine("if (elementCount <= baseCaseLimit)");
        gen->WriteBlock([=]{
            gen->WriteLine("sortFunc(A, elementCount);");
            gen->WriteLine("return;");
        });
        gen->WriteLine("");
        gen->WriteLine("if (depthLimit == 0)");
        gen->WriteBlock([=]{
            gen->WriteLine("insertionsort::InsertionSort<insertionsort::InsertionSort_Default>(A, elementCount);");
            gen->WriteLine("return;");
        });

        gen->WriteLine("TKey splitters[", numberOfSplittersStr, "];");
        gen->WriteLine("Find", GetName(numberOfSplitters, oversamplingFactor), "(A, elementCount, splitters, sortFunc, getKeyFunc);");
        for (int i = 0; i < numberOfSplitters; i += 1)
        {
            std::string iStr = std::to_string(i);
            gen->WriteLine("TKey splitter", iStr, " = splitters[", iStr, "];");
        }
        gen->WriteLine("");

        gen->WriteLine("ValueType *rawbuckets = (ValueType*) malloc(sizeof(ValueType) * ", numberOfBucketsStr, " * elementCount);");
        gen->WriteLine("ValueType* buckets[", numberOfBucketsStr, "];");
        gen->WriteForLoop("i", 0, numberOfBuckets, [=]{
            gen->WriteLine("buckets[i] = &rawbuckets[i * elementCount];");
        });

        for(int i = 0; i < blockSize; i += 1)
        {
            std::string iStr = std::to_string(i);
            gen->WriteLine("int state", iStr, ";");
            gen->WriteLine("int predicateResult", iStr, ";");
            gen->WriteLine("TKey splitter0", iStr, "x;");
        }
        gen->WriteLine("");

        gen->WriteLine("int max = elementCount - ", blockSizeStr, ";");
        gen->WriteLine("int current = 0;");
        gen->WriteLine("//Sort 'blockSize' elements simultaneously into the buckets");
        gen->WriteLine("for ( ; current <= max; current += ", blockSizeStr, ")");
        gen->WriteBlock([=]{
            WriteSortElementsIntoBuckets(gen, numberOfSplitters, blockSize);
        });
        gen->WriteLine("");

        gen->WriteLine("//Sort the remaining k < 'blockSize' elements into the buckets");
        gen->WriteLine("for ( ; current < elementCount; current += 1)");
        gen->WriteBlock([=]{
            WriteSortElementsIntoBuckets(gen, numberOfSplitters, 1);
        });
        gen->WriteLine("");

        gen->WriteLine("ValueType* currentPos = A;");
        gen->WriteLine("int bucketSize[", numberOfBucketsStr, "];");

        gen->WriteLine("int exclusiveBucketSizePrefixSum[", numberOfBucketsStr, "];");
        
        gen->WriteForLoop("currentBucket", 0, numberOfBuckets, [=]{
            gen->WriteLine("bucketSize[currentBucket] = (int) (buckets[currentBucket] - &rawbuckets[currentBucket * elementCount]);");
            gen->WriteLine("std::memcpy((void*) currentPos, (void*) &rawbuckets[currentBucket * elementCount], bucketSize[currentBucket] * sizeof(ValueType));");
            gen->WriteLine("currentPos += bucketSize[currentBucket];");
        });
        gen->WriteLine("free(rawbuckets);");
        gen->WriteLine("");

        for (int i = 0; i < numberOfBuckets; i += 1)
        {
            std::string iStr = std::to_string(i);
            std::string iMinus = std::to_string(i - 1);
            if (i == 0)
            {
                gen->WriteLine("exclusiveBucketSizePrefixSum[0] = 0;");
            }
            else if (i == 1)
            {
                gen->WriteLine("exclusiveBucketSizePrefixSum[1] = bucketSize[0];");
            }
            else 
            {
                gen->WriteLine("exclusiveBucketSizePrefixSum[", iStr, "] = exclusiveBucketSizePrefixSum[", iMinus, "] + bucketSize[", iMinus, "];");
            }
        }
        gen->WriteLine("");

        gen->WriteForLoop("currentBucket", 0, numberOfBuckets, [=]{
            gen->WriteLine("SampleSortInternal", GetName(numberOfSplitters, oversamplingFactor), blockSizeStr, "BlockSize(&A[exclusiveBucketSizePrefixSum[currentBucket]], bucketSize[currentBucket], baseCaseLimit, sortFunc, predicateLess, getKeyFunc, depthLimit - 1);");
        });
    });

    gen->WriteLine("template <typename ValueType, typename TKey>");
    gen->WriteLine("void SampleSort", GetName(numberOfSplitters, oversamplingFactor), blockSizeStr, "BlockSize(");
    gen->WriteIndented([=]{
        gen->WriteLine("ValueType* A,");
        gen->WriteLine("size_t elementCount,");
        gen->WriteLine("size_t baseCaseLimit,");
        gen->WriteLine("void(*sortFunc)(ValueType*,size_t),");
        gen->WriteLine("bool(*predicateLess)(TKey&,ValueType&),");
        gen->WriteLine("TKey(*getKeyFunc)(ValueType&))");
    });
    gen->WriteBlock([=]{
        gen->WriteLine("SampleSortInternal", GetName(numberOfSplitters, oversamplingFactor), blockSizeStr, "BlockSize(A, elementCount, baseCaseLimit, sortFunc, predicateLess, getKeyFunc, custommath::intlog2(elementCount) * ", std::to_string(2.0 / log2(numberOfSplitters + 1)), "); //log to base {(numberOfSplitters + 1) / 2}");
    });
}

}