
#include "WriteNetwork.hpp"

namespace codegeneration
{

void WriteNetwork(CPlusPlusCodeGenerator *gen, std::string headerDefine, std::string sortMethodName, std::string networksJsonFilePath)
{
    std::ifstream input(networksJsonFilePath);
    nlohmann::json networksJson;
    input >> networksJson;

    gen->WriteLine(GetAutogeneratedPreamble());
    gen->WriteLine("");

    gen->WriteHeaderPragma(headerDefine, [=]{
        gen->WriteIncludeQuotes("NetworkSort.h");
        gen->WriteNamespace("networks", [=]{
            for (auto network : networksJson)
            {
                std::string sizeStr = std::to_string(network["NetworkSize"].get<int>());
                gen->WriteLine("template <typename TValueType> static");
                gen->WriteLine("void sort", sizeStr, sortMethodName, "(TValueType* A)");
                gen->WriteBlock([=]{
                    for (auto swap : network["Swaps"])
                    {
                        std::string leftStr = std::to_string(swap["LeftIndex"].get<int>());
                        std::string rightStr = std::to_string(swap["RightIndex"].get<int>());
                        gen->WriteLine("networks::ConditionalSwap(A[", leftStr, "], A[", rightStr, "]);");
                    }
                });
            }
            gen->WriteLine("");
            gen->WriteLine("template <typename TValueType> static");
            gen->WriteLine("void sortN", sortMethodName, "(TValueType* A, size_t n)");
            gen->WriteBlock([=]{
                gen->WriteLine("switch(n)");
                gen->WriteBlock([=]{
                    gen->WriteLine("case 0: break;");
                    gen->WriteLine("case 1: break;");
                    for (auto network : networksJson)
                    {
                        std::string sizeStr = std::to_string(network["NetworkSize"].get<int>());
                        gen->WriteLine("case ", sizeStr, ":");
                        gen->WriteIndented([=]{
                            gen->WriteLine("sort", sizeStr, sortMethodName, "(A);");
                            gen->WriteLine("break;");
                        });
                    }
                    gen->WriteLine("default:");
                    gen->WriteIndented([=]{
                        gen->WriteLine("abort();");
                        gen->WriteLine("break;");
                    });
                });
            });
        }, "");
    });
}

void WriteSortMethodName_ParameterStyle(CodeGenerator *gen, int networkSize, std::string sortMethodName)
{
    gen->Write("void sort");
    gen->Write(networkSize);
    gen->Write(sortMethodName);
    gen->Write("(");
    for (int i = 0; i < networkSize - 1; i += 1)
    {
        gen->Write("TValueType& element");
        gen->Write(i);
        gen->Write(", ");
    }
    gen->Write("TValueType& element");
    gen->Write(networkSize - 1);
    gen->WriteLine(")");
}

void WriteMergeMethodName_ParameterStyle(CodeGenerator *gen, int leftMergeSize, int rightMergeSize, std::string sortMethodName)
{
    gen->Write("void merge");
    gen->Write(leftMergeSize);
    gen->Write("_");
    gen->Write(rightMergeSize);
    gen->Write(sortMethodName);
    gen->Write("(");
    for (int i = 0; i < leftMergeSize; i += 1)
    {
        gen->Write("TValueType& left");
        gen->Write(i);
        gen->Write(", ");
    }
    for (int i = 0; i < rightMergeSize - 1; i += 1)
    {
        gen->Write("TValueType& right");
        gen->Write(i);
        gen->Write(", ");
    }
    gen->Write("TValueType& right");
    gen->Write(rightMergeSize - 1);
    gen->WriteLine(")");
}

void WriteParameters(CodeGenerator *gen, nlohmann::json leftIndices, nlohmann::json rightIndices, std::string leftElementsName, std::string rightElementsName, bool swapped = false)
{
    if (swapped)
    {
        std::swap(leftElementsName, rightElementsName);
    }
    for (auto leftIndex : leftIndices)
    {
        gen->Write(leftElementsName);
        gen->Write(leftIndex.get<int>());
        gen->Write(", ");
    }
    for (auto it = rightIndices.begin(); it < rightIndices.end() - 1; it++)
    {
        gen->Write(rightElementsName);
        gen->Write((*it).get<int>());
        gen->Write(", ");
    }
    gen->Write(rightElementsName);
    gen->Write(rightIndices.back().get<int>());
}

bool IsInline(nlohmann::json network, RecursiveParameterNetworkType networkType)
{
    switch (networkType)
    {
        case RecursiveParameterNetworkType::Split:
            return network["NetworkSize"].get<int>() == 2;
        case RecursiveParameterNetworkType::Merge:
            return (network["LeftMergeSize"].get<int>() + network["RightMergeSize"].get<int>()) <= 3;
    }
    
}

void WriteSorter_ParameterStyle(
    CodeGenerator *gen, 
    nlohmann::json network, 
    std::string sortMethodName,
    bool* splitIndices, 
    bool* mergeIndices, 
    int indexArrayLength)
{
    for (auto step : network["RecursiveSteps"])
    {
        auto stepNetwork = step["Network"];
        auto stepType = stepNetwork["Type"].get<std::string>();
        if (stepType.compare("Split") == 0)
        {
            int length = stepNetwork["NetworkSize"].get<int>();
            if (!splitIndices[length])
            {
                WriteSorter_ParameterStyle(
                    gen, 
                    stepNetwork, 
                    sortMethodName,
                    splitIndices, 
                    mergeIndices, 
                    indexArrayLength);
            }
        }
        if (stepType.compare("Merge") == 0)
        {
            int leftSize = stepNetwork["LeftMergeSize"].get<int>();
            int rightSize = stepNetwork["RightMergeSize"].get<int>();
            if (leftSize > rightSize) 
            {
                std::swap(leftSize, rightSize); //Only do merger 1_2 and 2_2, but not 2_1 because 2_1 is 1_2 with swapped parameters
            }
            if (!mergeIndices[leftSize * indexArrayLength + rightSize])
            {
                WriteSorter_ParameterStyle(
                    gen, 
                    stepNetwork, 
                    sortMethodName,
                    splitIndices, 
                    mergeIndices, 
                    indexArrayLength);
            }
        }
    }

    RecursiveParameterNetworkType networkType;
    auto type = network["Type"].get<std::string>();
    if (type.compare("Split") == 0)
    {
        networkType = RecursiveParameterNetworkType::Split;
    }
    else if (type.compare("Merge") == 0)
    {
        networkType = RecursiveParameterNetworkType::Merge;
    }

    gen->WriteLine("template <typename TValueType> static");
    if (IsInline(network, networkType))
    {
        gen->WriteLine("inline");
    }
    int networkSize;
    int leftMergeSize;
    int rightMergeSize;
    switch (networkType)
    {
        case RecursiveParameterNetworkType::Split:
            networkSize = network["NetworkSize"].get<int>();
            WriteSortMethodName_ParameterStyle(gen, networkSize, sortMethodName);
            splitIndices[networkSize] = true;
            break;
        case RecursiveParameterNetworkType::Merge:
            leftMergeSize = network["LeftMergeSize"].get<int>();
            rightMergeSize = network["RightMergeSize"].get<int>();
            if (leftMergeSize > rightMergeSize)
            {
                return;
            }
            WriteMergeMethodName_ParameterStyle(gen, leftMergeSize, rightMergeSize, sortMethodName);
            mergeIndices[leftMergeSize * indexArrayLength + rightMergeSize] = true;
            if (leftMergeSize == 1 && rightMergeSize == 1)
            {
                gen->WriteBlock([=]{
                    gen->WriteLine("networks::ConditionalSwap(left0, right0);");
                });
                return;
            }
            else if (leftMergeSize == 1 && rightMergeSize == 2)
            {
                gen->WriteBlock([=]{
                    gen->WriteLine("networks::ConditionalSwap(left0, right1);");
                    gen->WriteLine("networks::ConditionalSwap(left0, right0);");
                });
                return;
            }
            else if (leftMergeSize == 2 && rightMergeSize == 1)
            {
                gen->WriteBlock([=]{
                    gen->WriteLine("networks::ConditionalSwap(left0, right0);");
                    gen->WriteLine("networks::ConditionalSwap(left1, right0);");
                });
                return;
            }
            break;
    }
    gen->WriteBlock([=]{
        for (auto step : network["RecursiveSteps"])
        {
            auto stepNetwork = step["Network"];
            auto stepType = stepNetwork["Type"].get<std::string>();
            if (stepType.compare("Split") == 0)
            {
                int stepSize = stepNetwork["NetworkSize"].get<int>();
                auto indicesToUse = step["FirstContextParameterIdsToUse"];
                gen->Write("networks::sort");
                gen->Write(stepSize);
                gen->Write(sortMethodName);
                gen->Write("(");
                for (auto it = indicesToUse.begin(); it < indicesToUse.end() - 1; it++)
                {
                    gen->Write("element");
                    gen->Write((*it).get<int>());
                    gen->Write(", ");
                }
                gen->Write("element");
                gen->Write(indicesToUse.back().get<int>());
                gen->WriteLine(");");
            }
            else 
            {
                int leftMergeSize = stepNetwork["LeftMergeSize"].get<int>();
                int rightMergeSize = stepNetwork["RightMergeSize"].get<int>();
                auto leftIndices = step["FirstContextParameterIdsToUse"];
                auto rightIndices = step["SecondContextParameterIdsToUse"];
                bool swapped = leftMergeSize > rightMergeSize;
                if (swapped)
                {
                    std::swap(leftIndices, rightIndices);
                    std::swap(leftMergeSize, rightMergeSize);
                }
                gen->Write("networks::merge");
                gen->Write(leftMergeSize);
                gen->Write("_");
                gen->Write(rightMergeSize);
                gen->Write(sortMethodName);
                gen->Write("(");
                //Step is merge step
                switch (networkType)
                {
                    case RecursiveParameterNetworkType::Split:
                        WriteParameters(gen, leftIndices, rightIndices, "element", "element");
                        gen->WriteLine(");");
                        break;
                    case RecursiveParameterNetworkType::Merge:
                        WriteParameters(gen, leftIndices, rightIndices, "left", "right", swapped);
                        gen->WriteLine(");");
                        break;
                }
            }
        }  
    });
    gen->WriteLine("");
}

void WriteNetwork_ParameterStyle(CPlusPlusCodeGenerator *gen, std::string headerDefine, std::string sortMethodName, std::string networksJsonFilePath)
{
    std::ifstream input(networksJsonFilePath);
    nlohmann::json networksJson;
    input >> networksJson;

    int maxLength = networksJson.back()["NetworkSize"].get<int>();
    int indexLength = maxLength + 1;
    bool *splitIndices = (bool*) malloc(indexLength * sizeof(bool));
    bool *mergeIndices = (bool*) malloc(indexLength * indexLength * sizeof(bool));

    for (int outer = 0; outer < indexLength; outer += 1)
    {
        splitIndices[outer] = false;
        for (int inner = 0; inner < indexLength; inner += 1)
        {
            mergeIndices[outer * indexLength + inner] = false;
        }
    }

    gen->WriteLine(GetAutogeneratedPreamble());
    gen->WriteLine("");

    gen->WriteHeaderPragma(headerDefine, [=]{
        gen->WriteIncludeQuotes("NetworkSort.h");
        gen->WriteNamespace("networks", [=]{
            for (auto network : networksJson)
            {
                WriteSorter_ParameterStyle(
                    gen, 
                    network, 
                    sortMethodName,
                    splitIndices, 
                    mergeIndices, 
                    maxLength + 1);
            }
            gen->WriteLine("");

            gen->WriteLine("template <typename TValueType> static");
            gen->WriteLine("void sortN", sortMethodName, "(TValueType* A, size_t n)");
            gen->WriteBlock([=]{
                gen->WriteLine("switch(n)");
                gen->WriteBlock([=]{
                    gen->WriteLine("case 0: break;");
                    gen->WriteLine("case 1: break;");
                    for (int arraySize = 2; arraySize <= maxLength; arraySize += 1)
                    {
                        auto sizeStr = std::to_string(arraySize);
                        gen->WriteLine("case ", sizeStr, ":");
                        gen->WriteIndented([=]{
                            gen->Write("sort");
                            gen->Write(sizeStr);
                            gen->Write(sortMethodName);
                            gen->Write("(");
                            for (int i = 0; i < arraySize - 1; i += 1)
                            {
                                gen->Write("A[");
                                gen->Write(i);
                                gen->Write("], ");
                            }
                            gen->Write("A[");
                            gen->Write(arraySize - 1);
                            gen->WriteLine("]);");
                            gen->WriteLine("break;");
                        });
                    }
                });
            });
        }, "");
    });
    free(splitIndices);
    free(mergeIndices);
}

}