
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
    gen->WriteLine("if (predResult > 0)");
    gen->WriteBlock([=]{
        gen->WriteLine("splitterx = splitter2;");
    });
}

void WriteSplitterComparisonX86(CodeGenerator* gen)
{
    //Reworked this to use tst instead of cmp to not need zero in register anymore
    WriteAsmBlock(gen, [=]{
        WriteAsmLine(gen, "test %[predResult],%[predResult]");
        WriteAsmLine(gen, "cmovne %[splitter2],%[splitterx]");

        gen->WriteLine(": [splitterx] \"=&r\"(splitterx)");
        gen->WriteLine(": \"0\"(splitterx), [splitter2] \"r\"(splitter2), [predResult] \"r\"(predResult)");
        gen->WriteLine(": \"cc\"");
    });

    // WriteAsmBlock(gen, [=]{
    //     WriteAsmLine(gen, "cmp %[predResult],%[zero]");
    //     WriteAsmLine(gen, "cmovcq %[splitter2],%[splitterx]");

    //     gen->WriteLine(": [splitterx] \"=&r\"(splitterx)");
    //     gen->WriteLine(": \"0\"(splitterx), [splitter2] \"r\"(splitter2), [predResult] \"r\"(predResult), [zero] \"r\"(0)");
    //     gen->WriteLine(": \"cc\"");
    // });
}

void WriteSplitterComparisonARM32(CodeGenerator* gen)
{
    WriteAsmBlock(gen, [=]{
        WriteAsmLine(gen, "tst %[predResult],%[predResult]");
        WriteAsmLine(gen, "movne %[splitterx], %[splitter2]");

        gen->WriteLine(": [splitterx] \"=&r\"(splitterx)");
        gen->WriteLine(": \"0\"(splitterx), [splitter2] \"r\"(splitter2), [predResult] \"r\"(predResult)");
        gen->WriteLine(": \"cc\"");
    });
}

void WriteSplitterComparisonARM64(CodeGenerator* gen)
{
    WriteAsmBlock(gen, [=]{
        WriteAsmLine(gen, "tst %[predResult],%[predResult]");
        WriteAsmLine(gen, "csel %[splitterx], %[splitter2], %[splitterx], NE");

        gen->WriteLine(": [splitterx] \"=&r\"(splitterx)");
        gen->WriteLine(": \"0\"(splitterx), [splitter2] \"r\"(splitter2), [predResult] \"r\"(predResult)");
        gen->WriteLine(": \"cc\"");
    });
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
            WriteSplitterComparisonARM64(gen);
        });
        gen->WriteLine("#elif __arm__");
        gen->WriteIndented([=]{
            WriteSplitterComparisonARM32(gen);
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
    gen->WriteLine("template <typename BaseCaseSorter, typename KeyGetter, typename ValueType, typename Key>");
    gen->WriteLine("static inline");
    gen->WriteLine("void Find", GetName(numberOfSplitters, oversamplingFactor), "(");

    gen->WriteIndented([=]{
        gen->WriteLine("ValueType* items,");
        gen->WriteLine("size_t elementCount,");
        gen->WriteLine("Key* splitterDestination)");
    });
    gen->WriteBlock([=]{
        gen->WriteLine("ValueType sample[", sampleSize, "];");
        
        gen->WriteLine("int blockSize = elementCount / ", sampleSize, ";");

        gen->WriteForLoop("i", 0, sampleSize, [=]{
            gen->WriteLine("sample[i] = items[i * blockSize];");
        });
        gen->WriteLine("BaseCaseSorter::sort(sample, ", sampleSize, ");");
        gen->WriteLine("");

        gen->WriteForLoop("i", 0, numberOfSplitters, [=]{
            gen->Write("splitterDestination[i] = KeyGetter::get(sample[i * ");
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

    gen->WriteLine("template <typename BaseCaseSorter, typename KeyGetter, typename ValueType, typename Key>");
    gen->WriteLine("inline");
    gen->WriteLine("void SampleSortInternal", GetName(numberOfSplitters, oversamplingFactor), blockSize, "BlockSize(");
    gen->WriteIndented([=]{
        gen->WriteLine("ValueType* A,");
        gen->WriteLine("size_t elementCount,");
        gen->WriteLine("size_t baseCaseLimit,");
        gen->WriteLine("bool(*predicateLess)(Key&,ValueType&),");
        gen->WriteLine("int depthLimit)");
    });
    gen->WriteBlock([=]{
        gen->WriteLine("if (elementCount <= baseCaseLimit)");
        gen->WriteBlock([=]{
            gen->WriteLine("BaseCaseSorter::sort(A, elementCount);");
            gen->WriteLine("return;");
        });
        gen->WriteLine("");
        gen->WriteLine("if (depthLimit == 0)");
        gen->WriteBlock([=]{
            gen->WriteLine("insertionsort::InsertionSort<insertionsort::InsertionSort_Default>(A, elementCount);");
            gen->WriteLine("return;");
        });

        gen->WriteLine("Key splitters[", numberOfSplitters, "];");
        gen->WriteLine("Find", GetName(numberOfSplitters, oversamplingFactor), "<BaseCaseSorter, KeyGetter>(A, elementCount, splitters);");
        for (int i = 0; i < numberOfSplitters; i += 1)
        {
            gen->WriteLine("Key splitter", i, " = splitters[", i, "];");
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
            gen->WriteLine("Key splitter0", i, "x;");
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
            gen->WriteLine("SampleSortInternal", GetName(numberOfSplitters, oversamplingFactor), blockSize, "BlockSize<BaseCaseSorter, KeyGetter>(&A[exclusiveBucketSizePrefixSum[currentBucket]], bucketSize[currentBucket], baseCaseLimit, predicateLess, depthLimit - 1);");
        });
    });

    gen->WriteLine("template <typename BaseCaseSorter, typename KeyGetter, typename ValueType, typename Key>");
    gen->WriteLine("void SampleSort", GetName(numberOfSplitters, oversamplingFactor), blockSize, "BlockSize(");
    gen->WriteIndented([=]{
        gen->WriteLine("ValueType* A,");
        gen->WriteLine("size_t elementCount,");
        gen->WriteLine("size_t baseCaseLimit,");
        gen->WriteLine("bool(*predicateLess)(Key&,ValueType&))");
    });
    gen->WriteBlock([=]{
        gen->WriteLine("SampleSortInternal", GetName(numberOfSplitters, oversamplingFactor), blockSize, "BlockSize<BaseCaseSorter, KeyGetter>(A, elementCount, baseCaseLimit, predicateLess, custommath::intlog2(elementCount) * ", std::to_string(2.0 / log2(numberOfSplitters + 1)), "); //log to base {(numberOfSplitters + 1) / 2}");
    });
}

}