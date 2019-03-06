
#ifndef WRITE_NETWORK_H
#define WRITE_NETWORK_H

#include <string>
#include <iostream>
#include <fstream>
#include <functional>

#include "CodeGeneration.hpp"
#include "nlohmann/json.hpp"
#include "GenerateBoseNelson.hpp"

namespace codegeneration
{

void WriteNetwork(CPlusPlusCodeGenerator *gen, std::string headerDefine, std::string sortMethodName, std::string networksJsonFilePath);
void WriteNetwork_ParameterStyle(CPlusPlusCodeGenerator *gen, std::string headerDefine, std::string sortMethodName, std::string networksJsonFilePath);

}

#endif