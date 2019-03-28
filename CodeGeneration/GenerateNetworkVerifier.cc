
#include <string>
#include "FunctionalHelpers.hpp"

#include "GenerateNetworkVerifier.hpp"

namespace codegeneration
{

void WriteNetworkVerification(CPlusPlusCodeGenerator* gen)
{
    gen->WriteLine(GetAutogeneratedPreamble());
    gen->WriteHeaderPragma("VERIFY_NETWORKS_GENERATED_H", [=](){
        gen->WriteIncludeBrackets(
            "inttypes.h",
            "ostream");
        gen->WriteLine("");

        gen->WriteIncludeQuotes(
            "BestNetworks.generated.h",
            "BoseNelson.generated.h",
            "BoseNelsonParallel.generated.h",
            "BoseNelsonParameter.generated.h",
            "VerifyNetworks.h",
            "DebugHelper.h");
        gen->WriteLine("");

        gen->WriteNamespace("verification", [=](){
            gen->WriteLine("");

            std::vector<std::string> networkNames = {"best", "bosenelson", "bosenelsonparallel", "bosenelsonparameter"};
            gen->WriteLine("void VerifyNetworks()");
            gen->WriteBlock([=]{
                gen->WriteLine("int numberOfIncorrectNetworks = 0;");
                Multicall<std::string>(
                    [=](std::string name)
                    {
                        gen->WriteLine("debug::WriteLine(\"verifying ", name, " networks\");");
                        gen->WriteForLoop("arraySize", 2, 17, [=](){
                            gen->WriteLine("debug::WriteLine(\"verifying size \", std::to_string(arraySize));");
                            gen->WriteLine("bool result = verification::VerifyNetwork(arraySize, &networks::sortN", name, "<int>);");
                            gen->WriteLine("if (!result)");
                            gen->WriteBlock([=]{
                                gen->WriteLine("debug::WriteLine(\"incorrect network: '", name, "' for size '\", std::to_string(arraySize), \"'.\");");
                                gen->WriteLine("numberOfIncorrectNetworks += 1;");
                            });
                        });
                    },
                    networkNames);
                std::string totalNetworksStr = std::to_string(networkNames.size() * (16-2+1));
                gen->WriteLine("debug::WriteLine(\"finished verification. \", std::to_string(", totalNetworksStr, " - numberOfIncorrectNetworks), \" networks out of ", totalNetworksStr, " sorted correctly.\");");
            });
        }, "");
    });
}

}