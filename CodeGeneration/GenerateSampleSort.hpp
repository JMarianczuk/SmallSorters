
#ifndef GENERATE_SAMPLESORT_H
#define GENERATE_SAMPLESORT_H

#include <string>
#include <functional>

#include "CodeGeneration.hpp"

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
        gen->WriteLine("element", iStr, " = A[current", GetPlusI(i), "];");
        gen->WriteLine("state", iStr, " = 0;");
        gen->WriteLine("splitter0", iStr, "x = splitter0;");
    }
    for (int i = 0; i < blockSize; i += 1)
    {
        std::string iStr = std::to_string(i);
        WriteAsmBlock(gen, [=]{
            WriteAsmLine(gen, "cmp %[ele],%[splitter1]");
            WriteAsmLine(gen, "cmovc %[splitter2],%[splitterx]");
            WriteAsmLine(gen, "rcl $1,%[state]");
            gen->WriteLine(": [splitterx] \"+r\"(splitter0", iStr, "x), [state] \"=r\"(state", iStr, ")");
            gen->WriteLine(": \"1\"(state", iStr, "), [ele] \"r\"(element", iStr, "), [splitter1] \"r\"(splitter1), [splitter2] \"r\"(splitter2)");
            gen->WriteLine(": \"cc\"");
        });
        WriteAsmBlock(gen, [=]{
            WriteAsmLine(gen, "cmp %[ele],%[splitterx]");
            WriteAsmLine(gen, "rcl $1,%[state]");
            gen->WriteLine(": [state] \"=r\"(state", iStr, ")");
            gen->WriteLine(": \"0\"(state", iStr, "), [ele] \"r\"(element", iStr, "), [splitterx] \"r\"(splitter0", iStr, "x)");
            gen->WriteLine(": \"cc\"");
        });
    }
    for (int i = 0; i < blockSize; i += 1)
    {
        std::string iStr = std::to_string(i);
        gen->WriteLine("*buckets[state", iStr, "] = element", iStr, ";");
        gen->WriteLine("buckets[state", iStr, "]++;");
    }
}

void WriteFindSplitters(CodeGenerator* gen, int numberOfSplitters, int oversamplingFactor)
{
    int sampleSize = numberOfSplitters * oversamplingFactor;
    std::string sampleSizeStr = std::to_string(sampleSize);
    gen->WriteLine("template <typename TValueType>");
    gen->WriteLine("static inline");
    gen->WriteLine("void Find", GetName(numberOfSplitters, oversamplingFactor), "(");

    gen->WriteIndented([=]{
        gen->WriteLine("TValueType* items,");
        gen->WriteLine("size_t elementCount,");
        gen->WriteLine("TValueType* splitterDestination,");
        gen->WriteLine("void(*sortFunc)(TValueType*,size_t))");
    });
    gen->WriteBlock([=]{
        gen->WriteLine("TValueType sample[", sampleSizeStr, "];");
        
        gen->WriteLine("int blockSize = elementCount / ", sampleSizeStr, ";");

        gen->WriteForLoop("i", 0, sampleSize, [=]{
            gen->WriteLine("sample[i] = items[i * blockSize];");
        });
        gen->WriteLine("sortFunc(sample, ", sampleSizeStr, ");");
        gen->WriteLine("");

        gen->WriteForLoop("i", 0, numberOfSplitters, [=]{
            gen->Write("splitterDestination[i] = sample[i * ");
            gen->Write(oversamplingFactor);
            gen->Write(" + ");
            gen->Write(oversamplingFactor / 2);
            gen->WriteLine("];");
        });
    });
}

void WriteRegisterSampleSort(CodeGenerator* gen, int numberOfSplitters, int oversamplingFactor, int blockSize)
{
    int numberOfBuckets = numberOfSplitters + 1;
    std::string blockSizeStr = std::to_string(blockSize);
    std::string numberOfSplittersStr = std::to_string(numberOfSplitters);
    std::string numberOfBucketsStr = std::to_string(numberOfBuckets);
    gen->WriteLine("template <typename TValueType>");
    gen->WriteLine("static inline");
    gen->WriteLine("void SampleSort", GetName(numberOfSplitters, oversamplingFactor), blockSizeStr, "BlockSize(");
    gen->WriteIndented([=]{
        gen->WriteLine("TValueType* A,");
        gen->WriteLine("size_t elementCount,");
        gen->WriteLine("size_t baseCaseLimit,");
        gen->WriteLine("void(*sortFunc)(TValueType*,size_t))");
    });
    gen->WriteBlock([=]{
        gen->WriteLine("if (elementCount <= baseCaseLimit)");
        gen->WriteBlock([=]{
            gen->WriteLine("sortFunc(A, elementCount);");
            gen->WriteLine("return;");
        });
        gen->WriteLine("");

        gen->WriteLine("TValueType splitters[", numberOfSplittersStr, "];");
        gen->WriteLine("Find", GetName(numberOfSplitters, oversamplingFactor), "(A, elementCount, splitters, sortFunc);");
        for (int i = 0; i < numberOfSplitters; i += 1)
        {
            std::string iStr = std::to_string(i);
            gen->WriteLine("register TValueType splitter", iStr, " = splitters[", iStr, "];");
        }
        gen->WriteLine("");

        gen->WriteLine("TValueType rawbuckets[", numberOfBucketsStr, " * elementCount];");
        gen->WriteLine("TValueType* buckets[", numberOfBucketsStr, "];");
        gen->WriteForLoop("i", 0, numberOfBuckets, [=]{
            gen->WriteLine("buckets[i] = &rawbuckets[i * elementCount];");
        });

        for(int i = 0; i < blockSize; i += 1)
        {
            std::string iStr = std::to_string(i);
            gen->WriteLine("register TValueType element", iStr, ";");
            gen->WriteLine("register int state", iStr, ";");
            gen->WriteLine("register TValueType splitter0", iStr, "x;");
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

        gen->WriteLine("TValueType* currentPos = A;");
        gen->WriteLine("int bucketSize[", numberOfBucketsStr, "];");

        gen->WriteLine("int exclusiveBucketSizePrefixSum[", numberOfBucketsStr, "];");
        
        gen->WriteForLoop("currentBucket", 0, numberOfBuckets, [=]{
            gen->WriteLine("bucketSize[currentBucket] = (int) (buckets[currentBucket] - &rawbuckets[currentBucket * elementCount]);");
            gen->WriteLine("std::memcpy((void*) currentPos, (void*) &rawbuckets[currentBucket * elementCount], bucketSize[currentBucket] * sizeof(TValueType));");
            gen->WriteLine("currentPos += bucketSize[currentBucket];");
        });
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
            gen->WriteLine("SampleSort", GetName(numberOfSplitters, oversamplingFactor), blockSizeStr, "BlockSize(&A[exclusiveBucketSizePrefixSum[currentBucket]], bucketSize[currentBucket], baseCaseLimit, sortFunc);");
        });
    });
}

}

#endif