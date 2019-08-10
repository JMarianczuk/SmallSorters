

#include "GenerateSortableStructs.hpp"

namespace codegeneration
{

void WriteVariables(CodeGenerator* gen, bool hasReference)
{
    gen->WriteLine("uint64_t key;");
    if (hasReference)
    {
        gen->WriteLine("uint64_t reference;");
    }
}

void WriteLargeVariables(CodeGenerator* gen)
{
    gen->WriteLine("float first;");
    gen->WriteLine("float second;");
    gen->WriteLine("float third;");
    gen->WriteLine("uint64_t payload[1024];");
}

void WriteOperator(CodeGenerator* gen, std::string sortableStructName, std::string op, std::function<void(std::string)> compareFunction)
{
    gen->WriteLine("friend bool operator", op, "(const ", sortableStructName, "& left, const ", sortableStructName, "& right)");
    gen->WriteBlock([=]{
        compareFunction(op);
    });
}

void WriteOperators(CodeGenerator* gen, std::string sortableStructName, std::function<void(std::string)> compareFunction)
{
    Multicall<std::string>([=](std::string op) {
        WriteOperator(gen, sortableStructName, op, compareFunction);
    },
    {">", ">=", "==", "<", "<=", "!="});
}

void WriteSortableStructs(CPlusPlusCodeGenerator* gen)
{
    gen->WriteLine(GetAutogeneratedPreamble());
    gen->WriteLine("");
    gen->WriteHeaderPragma("SORTABLE_GENERATED_H", [=]{
        gen->WriteLine("#define ArraySize 16");
        gen->WriteIncludeBrackets("inttypes.h");

        gen->WriteStruct("Sortable", [=]{
            WriteVariables(gen, false);
            WriteOperators(gen, "Sortable", [=](std::string op){
                gen->WriteLine("return left.key ", op, " right.key;");
            });
        });
        gen->WriteStruct("SortableRef", [=]{
            WriteVariables(gen, true);
            WriteOperators(gen, "SortableRef", [=](std::string op){
                gen->WriteLine("return left.key ", op, " right.key;");
            });
        });
        gen->WriteStruct("LargeSortable", [=]{
            WriteLargeVariables(gen);
            WriteOperator(gen, "LargeSortable", "<", [=](std::string op){
                gen->WriteLine("return left.first ", op, " right.first ||");
                gen->WriteIndented([=]{
                    gen->WriteLine("(left.first == right.first &&");
                    gen->WriteIndented([=]{
                        gen->WriteLine("(left.second ", op, " right.second ||");
                        gen->WriteIndented([=]{
                            gen->WriteLine("(left.second == right.second && left.third ", op, "right.third)");
                        });
                        gen->WriteLine(")");
                    });
                    gen->WriteLine(");");
                });
            });
        });
    });
}

}