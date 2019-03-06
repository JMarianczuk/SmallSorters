
#ifndef GENERATE_SORTABLE_STRUCTS_H
#define GENERATE_SORTABLE_STRUCTS_H

#include "CodeGeneration.hpp"
#include "SortableDefinitions.hpp"
#include "FunctionalHelpers.hpp"

namespace codegeneration
{

void WriteVariables(CodeGenerator* gen, SortableStruct* sortableStruct);
void WriteOperator(CodeGenerator* gen, SortableStruct* sortableStruct, std::string op);
void WriteOperators(CodeGenerator* gen, SortableStruct* sortableStruct);
void WriteSortableStructs(CPlusPlusCodeGenerator* gen);

}

#endif