
#ifndef WRITE_NETWORK_H
#define WRITE_NETWORK_H

#include <string>
#include <iostream>
#include <fstream>

#include "CodeGeneration.h"
#include "nlohmann/json.hpp"

namespace codegeneration
{

void WriteNetwork(CodeGenerator *gen, std::string headerDefine, std::string sortMethodName, std::string networksJsonFilePath)
{
    std::ifstream input(networksJsonFilePath);
    nlohmann::json networksJson;
    input >> networksJson;

    gen->WriteLine(AutogeneratedPreamble);
    gen->WriteLine("");

    gen->Write("#ifndef ");
    gen->Write(headerDefine);
    gen->WriteLine("");
    gen->Write("#define ");
    gen->Write(headerDefine);
    gen->WriteLine("");
    gen->WriteLine("");

    gen->WriteIncludeQuotes("NetworkSort.h");

    gen->WriteNamespace("networks", [=]{
        for (auto network : networksJson)
        {
            gen->WriteLine("template <typename TValueType> static inline");
            gen->Write("void sort");
            gen->Write(network["NetworkSize"].get<int>());
            gen->Write(sortMethodName);
            gen->Write("(TValueType* A)");
            gen->WriteLine("");

            gen->WriteBlock([=]{
                for (auto swap : network["Swaps"])
                {
                    gen->Write("networks::ConditionalSwap(A[");
                    gen->Write(swap["LeftIndex"].get<int>());
                    gen->Write("], A[");
                    gen->Write(swap["RightIndex"].get<int>());
                    gen->Write("]);");
                    gen->WriteLine("");

                }
            });
        }
        gen->WriteLine("");
        gen->WriteLine("template <typename TValueType> static inline");
        gen->Write("void sortN");
        gen->Write(sortMethodName);
        gen->Write("(TValueType* A, size_t n)");
        gen->WriteLine("");

        gen->WriteBlock([=]{
            gen->WriteLine("switch(n)");
            gen->WriteBlock([=]{
                gen->WriteLine("case 0: break;");
                gen->WriteLine("case 1: break;");
                for (auto network : networksJson)
                {
                    gen->Write("case ");
                    gen->Write(network["NetworkSize"].get<int>());
                    gen->Write(":");
                    gen->WriteLine("");

                    gen->WriteIndented([=]{
                        gen->Write("sort");
                        gen->Write(network["NetworkSize"].get<int>());
                        gen->Write(sortMethodName);
                        gen->Write("(A);");
                        gen->WriteLine("");

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

    gen->WriteLine("#endif");
}

}

#endif