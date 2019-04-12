
#ifndef GENERATE_RANDOMISATION_H
#define GENERATE_RANDOMISATION_H

#include <string>

#include "SortableDefinitions.hpp"
#include "CodeGeneration.hpp"

namespace codegeneration
{

void WriteRandomisation(CPlusPlusCodeGenerator* headerGen, CPlusPlusCodeGenerator* implGen);

}

#endif