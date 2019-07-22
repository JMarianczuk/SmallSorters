
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

void WriteSplitterComparisonGeneric(CodeGenerator* gen)
{
    gen->WriteLine("if (predicateResult > 0)");
    gen->WriteBlock([=]{
        gen->WriteLine("splitterx = splitter2;");
    });
}

void WriteSplitterComparisonX86(CodeGenerator* gen)
{
    WriteAsmBlock(gen, [=]{
        WriteAsmLine(gen, "cmp %[predResult],%[zero]");
        WriteAsmLine(gen, "cmovcq %[splitter2],%[splitterx]");

        gen->WriteLine(": [splitterx] \"=&r\"(splitterx)");
        gen->WriteLine(": \"0\"(splitterx), [splitter2] \"r\"(splitter2), [predResult] \"r\"(predResult), [zero] \"r\"(0)");
        gen->WriteLine(": \"cc\"");
    });
}

void WriteSplitterComparisonARM(CodeGenerator* gen)
{
    WriteSplitterComparisonGeneric(gen);
}

void WriteSplitterComparisonRoutine(CodeGenerator* gen)
{
    gen->WriteLine("template <typename Key>");
    gen->WriteLine("inline");
    gen->WriteLine("void PerformSplitterComparison(Key &splitterx, Key &splitter2, int &predResult)");
    gen->WriteBlock([=]{
        gen->WriteLine("");
        gen->WriteLine("#if __x86_64__");
        gen->WriteIndented([=]{
            WriteSplitterComparisonX86(gen);
        });
        gen->WriteLine("#elif defined(__i386__)");
        gen->WriteIndented([=]{
            WriteSplitterComparisonX86(gen);
        });
        gen->WriteLine("#elif __aarch64__");
        gen->WriteIndented([=]{
            WriteSplitterComparisonARM(gen);
        });
        gen->WriteLine("#elif __arm__");
        gen->WriteIndented([=]{
            WriteSplitterComparisonARM(gen);
        });
        gen->WriteLine("#else");
        gen->WriteIndented([=]{
            WriteSplitterComparisonGeneric(gen);
        });
        gen->WriteLine("#endif");
        gen->WriteLine("");
    });
}

void WriteSortElementsIntoBuckets(CodeGenerator* gen, int numberOfSplitters, int blockSize)
{
    for (int i = 0; i < blockSize; i += 1)
    {
        gen->WriteLine("predicateResult", i, " = (int) predicateLess(splitter1, A[current", GetPlusI(i), "]);");
        gen->WriteLine("state", i, " = predicateResult", i, ";");
        gen->WriteLine("splitter0", i, "x = splitter0;");
    }
    for (int i = 0; i < blockSize; i += 1)
    {
        gen->WriteLine("PerformSplitterComparison(splitter0", i, "x, splitter2, predicateResult", i, ");");
        // WriteAsmBlock(gen, [=]{
        //     WriteAsmLine(gen, "cmp %[predResult],%[zero]");
        //     WriteAsmLine(gen, "cmovcq %[splitter2],%[splitterx]");

        //     gen->WriteLine(": [splitterx] \"=&r\"(splitter0", i, "x)");
        //     gen->WriteLine(": \"0\"(splitter0", i, "x), [splitter2] \"r\"(splitter2), [predResult] \"r\"(predicateResult", i, "), [zero] \"r\"(0)");
        //     gen->WriteLine(": \"cc\"");
        // });
    }
    for (int i = 0; i < blockSize; i += 1)
    {
        gen->WriteLine("predicateResult", i, " = (int) predicateLess(splitter0", i, "x, A[current", GetPlusI(i), "]);");
    }
    for (int i = 0; i < blockSize; i += 1)
    {
        gen->WriteLine("state", i, " = (state", i, " << 1) + predicateResult", i, ";");
    }
    for (int i = 0; i < blockSize; i += 1)
    {
        gen->WriteLine("*buckets[state", i, "] = A[current", GetPlusI(i), "];");
        gen->WriteLine("buckets[state", i, "]++;");
    }
}

void WriteFindSplitters(CodeGenerator* gen, int numberOfSplitters, int oversamplingFactor)
{
    int sampleSize = numberOfSplitters * oversamplingFactor;
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
        gen->WriteLine("ValueType sample[", sampleSize, "];");
        
        gen->WriteLine("int blockSize = elementCount / ", sampleSize, ";");

        gen->WriteForLoop("i", 0, sampleSize, [=]{
            gen->WriteLine("sample[i] = items[i * blockSize];");
        });
        gen->WriteLine("sortFunc(sample, ", sampleSize, ");");
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

    gen->WriteLine("template <typename ValueType, typename TKey>");
    gen->WriteLine("inline");
    gen->WriteLine("void SampleSortInternal", GetName(numberOfSplitters, oversamplingFactor), blockSize, "BlockSize(");
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

        gen->WriteLine("TKey splitters[", numberOfSplitters, "];");
        gen->WriteLine("Find", GetName(numberOfSplitters, oversamplingFactor), "(A, elementCount, splitters, sortFunc, getKeyFunc);");
        for (int i = 0; i < numberOfSplitters; i += 1)
        {
            gen->WriteLine("TKey splitter", i, " = splitters[", i, "];");
        }
        gen->WriteLine("");

        gen->WriteLine("ValueType *rawbuckets = (ValueType*) malloc(sizeof(ValueType) * ", numberOfBuckets, " * elementCount);");
        gen->WriteLine("ValueType* buckets[", numberOfBuckets, "];");
        gen->WriteForLoop("i", 0, numberOfBuckets, [=]{
            gen->WriteLine("buckets[i] = &rawbuckets[i * elementCount];");
        });

        for(int i = 0; i < blockSize; i += 1)
        {
            gen->WriteLine("int state", i, ";");
            gen->WriteLine("int predicateResult", i, ";");
            gen->WriteLine("TKey splitter0", i, "x;");
        }
        gen->WriteLine("");

        gen->WriteLine("int max = elementCount - ", blockSize, ";");
        gen->WriteLine("int current = 0;");
        gen->WriteLine("//Sort 'blockSize' elements simultaneously into the buckets");
        gen->WriteLine("for ( ; current <= max; current += ", blockSize, ")");
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
        gen->WriteLine("int bucketSize[", numberOfBuckets, "];");

        gen->WriteLine("int exclusiveBucketSizePrefixSum[", numberOfBuckets, "];");
        
        gen->WriteForLoop("currentBucket", 0, numberOfBuckets, [=]{
            gen->WriteLine("bucketSize[currentBucket] = (int) (buckets[currentBucket] - &rawbuckets[currentBucket * elementCount]);");
            gen->WriteLine("std::memcpy((void*) currentPos, (void*) &rawbuckets[currentBucket * elementCount], bucketSize[currentBucket] * sizeof(ValueType));");
            gen->WriteLine("currentPos += bucketSize[currentBucket];");
        });
        gen->WriteLine("free(rawbuckets);");
        gen->WriteLine("");

        for (int i = 0; i < numberOfBuckets; i += 1)
        {
            int iMinus = i - 1;
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
                gen->WriteLine("exclusiveBucketSizePrefixSum[", i, "] = exclusiveBucketSizePrefixSum[", iMinus, "] + bucketSize[", iMinus, "];");
            }
        }
        gen->WriteLine("");

        gen->WriteForLoop("currentBucket", 0, numberOfBuckets, [=]{
            gen->WriteLine("SampleSortInternal", GetName(numberOfSplitters, oversamplingFactor), blockSize, "BlockSize(&A[exclusiveBucketSizePrefixSum[currentBucket]], bucketSize[currentBucket], baseCaseLimit, sortFunc, predicateLess, getKeyFunc, depthLimit - 1);");
        });
    });

    gen->WriteLine("template <typename ValueType, typename TKey>");
    gen->WriteLine("void SampleSort", GetName(numberOfSplitters, oversamplingFactor), blockSize, "BlockSize(");
    gen->WriteIndented([=]{
        gen->WriteLine("ValueType* A,");
        gen->WriteLine("size_t elementCount,");
        gen->WriteLine("size_t baseCaseLimit,");
        gen->WriteLine("void(*sortFunc)(ValueType*,size_t),");
        gen->WriteLine("bool(*predicateLess)(TKey&,ValueType&),");
        gen->WriteLine("TKey(*getKeyFunc)(ValueType&))");
    });
    gen->WriteBlock([=]{
        gen->WriteLine("SampleSortInternal", GetName(numberOfSplitters, oversamplingFactor), blockSize, "BlockSize(A, elementCount, baseCaseLimit, sortFunc, predicateLess, getKeyFunc, custommath::intlog2(elementCount) * ", std::to_string(2.0 / log2(numberOfSplitters + 1)), "); //log to base {(numberOfSplitters + 1) / 2}");
    });
}

}