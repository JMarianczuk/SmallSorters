
#include "GenerateRandomisation.hpp"

namespace codegeneration
{

void WriteRandomArrayMethodName(CodeGenerator* gen, std::string fullName, bool isDeclaration = false)
{
    gen->WriteLine("template<>");
    gen->WriteLine("void GenerateRandomArray<", fullName, ">(", fullName, "* arr, size_t arraySize)", (isDeclaration ? ";" : ""));
}

void GenerateRandomArrayMethod(CodeGenerator* gen, std::string fullName, bool hasReference)
{
    WriteRandomArrayMethodName(gen, fullName, false);

    gen->WriteBlock([=]{
        if (hasReference)
        {
            gen->WriteLine("uint64_t reference = randomisation::GenerateRandomUint64();");
        }
        gen->WriteForLoop("i", 0, "arraySize", [=]{
            gen->WriteLine("arr[i].key = randomisation::GenerateRandomUint64();");
            if (hasReference)
            {
                gen->WriteLine("arr[i].reference = reference + i;");
            }
        });
    });
}

void WriteRandomisation(CPlusPlusCodeGenerator* headerGen, CPlusPlusCodeGenerator* implGen)
{
    std::vector<SortableStruct*> structs = 
    {
        new SortableStruct("", "", "", false),
        new SortableStruct("", "", "", true)
    };
    
    headerGen->WriteLine(GetAutogeneratedPreamble());
    headerGen->WriteHeaderPragma("RANDOMISATION_GENERATED_H", [=]{
        headerGen->WriteIncludeBrackets(
            "stdexcept",
            "cstddef");
        headerGen->WriteIncludeQuotes(
            "Randomisation.h",
            "Sortable.generated.h");
        headerGen->WriteNamespace("randomisation", [=]{
            headerGen->WriteLine("template <typename ValueType>");
            headerGen->WriteLine("void GenerateRandomArray(ValueType* arr, size_t arraySize)");
            headerGen->WriteBlock([=]{
                headerGen->WriteLine("throw std::logic_error(\"randomisation::GenerateRandomArray => Not implemented for generic type\");");
            });
            
            for (SortableStruct* sortableStruct : structs)
            {
                WriteRandomArrayMethodName(headerGen, sortableStruct->FullName(), true);
            }
        }, "");
    });

    implGen->WriteLine(GetAutogeneratedPreamble());
    implGen->WriteIncludeQuotes("Randomisation.generated.h");
    implGen->WriteNamespace("randomisation", [=]{
        for (SortableStruct* sortableStruct : structs)
        {
            GenerateRandomArrayMethod(implGen, sortableStruct->FullName(), sortableStruct->HasReference);
        }
    }, "");
}

}