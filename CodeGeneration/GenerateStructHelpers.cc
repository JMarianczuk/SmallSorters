
#include "GenerateStructHelpers.hpp"

namespace codegeneration
{

void WriteStructHelpers(CPlusPlusCodeGenerator* gen)
{
    gen->WriteLine(GetAutogeneratedPreamble());
    gen->WriteHeaderPragma("STRUCT_HELPERS_H", [=]{
        gen->WriteLine("#define ArraySize 16");
        gen->WriteIncludeBrackets("inttypes.h");
        gen->WriteIncludeQuotes("Sortable.generated.h");
        gen->WriteLine("");

        gen->WriteLine("template <typename ValueType>");
        gen->WriteLine("static inline");
        gen->WriteLine("uint64_t GetKey(ValueType& item)");
        gen->WriteBlock([=]{
            gen->WriteLine("return 0;");
        });
        gen->WriteLine("template <typename ValueType>");
        gen->WriteLine("static inline");
        gen->WriteLine("uint64_t GetReference(ValueType& item)");
        gen->WriteBlock([=]{
            gen->WriteLine("return 0;");
        });
        gen->WriteLine("");

        std::vector<SortableStruct*> structs = 
        {
            new SortableStruct("", "", "", false),
            new SortableStruct("", "", "", true)
        };

        for (SortableStruct* sortableStruct : structs)
        {
            gen->WriteLine("template <>");
            gen->WriteLine("inline");
            gen->WriteLine("uint64_t GetKey(", sortableStruct->FullName(), "& item)");
            gen->WriteBlock([=]{
                gen->WriteLine("return item.key;");
            });
        }
        for (SortableStruct* sortableStruct : *VectorWhere<SortableStruct*>(&structs, [=](SortableStruct* ss){return ss->HasReference;}))
        {
            gen->WriteLine("template <>");
            gen->WriteLine("inline");
            gen->WriteLine("uint64_t GetReference(", sortableStruct->FullName(), "& item)");
            gen->WriteBlock([=]{
                gen->WriteLine("return item.reference;");
            });
        }

        gen->WriteClassDeclaration("SortableRefKeyGetter", []{}, [=]{
            gen->WriteLine("static inline uint64_t get(SortableRef& item)");
            gen->WriteBlock([=]{
                gen->WriteLine("return item.key;");
            });
        });
    });
}

}