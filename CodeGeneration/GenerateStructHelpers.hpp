
#ifndef GENERATE_STRUCT_HELPERS_H
#define GENERATE_STRUCT_HELPERS_H

#include "CodeGeneration.hpp"
#include "SortableDefinitions.hpp"

namespace codegeneration
{

void WriteStructHelpers(CodeGenerator* gen)
{
    gen->WriteLine(AutogeneratedPreamble);
    gen->WriteHeaderPragma("STRUCT_HELPERS_H", [=]{
        gen->WriteLine("#define ArraySize 16");
        gen->WriteIncludeBrackets("inttypes.h");
        gen->WriteIncludeQuotes("Sortable.generated.h");
        gen->WriteLine("");

        gen->WriteLine("template <typename TValueType>");
        gen->WriteLine("static inline");
        gen->WriteLine("uint64_t GetKey(TValueType& item)");
        gen->WriteBlock([=]{
            gen->WriteLine("return 0;");
        });
        gen->WriteLine("template <typename TValueType>");
        gen->WriteLine("static inline");
        gen->WriteLine("uint64_t GetReference(TValueType& item)");
        gen->WriteBlock([=]{
            gen->WriteLine("return 0;");
        });
        gen->WriteLine("");

        for (SortableStruct* sortableStruct : sortableStructs)
        {
            gen->WriteLine("template <>");
            gen->WriteLine("inline");
            gen->WriteLine("uint64_t GetKey(", sortableStruct->FullName(), "& item)");
            gen->WriteBlock([=]{
                gen->WriteLine("return item.key;");
            });
        }
        for (SortableStruct* sortableStruct : *VectorWhere<SortableStruct*>(sortableStructs, [=](SortableStruct* ss){return ss->HasReference;}))
        {
            gen->WriteLine("template <>");
            gen->WriteLine("inline");
            gen->WriteLine("uint64_t GetReference(", sortableStruct->FullName(), "& item)");
            gen->WriteBlock([=]{
                gen->WriteLine("return item.reference;");
            });
        }
    });
}

}

#endif