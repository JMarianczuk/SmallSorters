
#include "CodeGeneration.hpp"

namespace codegeneration
{

std::vector<std::string> autogeneratedPreambleLines = 
{
    "------------------------------------------------------------------------------",
    " <auto-generated>",
    "     This code was auto-generated",
    "",
    "     Changes to this file may cause incorrect behavior and will be lost if",
    "     the code is regenerated.",
    " </auto-generated>",
    "------------------------------------------------------------------------------"
};

std::string GetAutogeneratedPreamble(std::string commentString, std::string newline)
{
    std::string result = "";
    for (auto line : autogeneratedPreambleLines)
    {
        result += commentString + line + newline;
    }
    return result;
}

//General Code Generation

CodeGenerator::CodeGenerator(std::string filename, std::string indent) : _filename(filename), _indent(indent)
{
    MakeStream();
}

CodeGenerator::~CodeGenerator()
{
    _fileStream.flush();
    _fileStream.close();
}

void CodeGenerator::MakeStream()
{
    _fileStream.open(_filename, std::ios::out);
}

void CodeGenerator::Write(std::string content)
{
    WriteIndent();
    _fileStream << content;
}
void CodeGenerator::Write(int number)
{
    WriteIndent();
    _fileStream << number;
}

void CodeGenerator::WriteEndl()
{
    Write("\n");
    _indentBeforeWrite = true;
}

void CodeGenerator::WriteIndent()
{
    if(_indentBeforeWrite)
    {
        for (auto indent : _indentationStack)
        {
            _fileStream << indent;
        }
        _indentBeforeWrite = false;
    } 
}

void CodeGenerator::PushIndent()
{
    PushIndent(_indent);
}
void CodeGenerator::PushIndent(std::string indent)
{
    _indentationStack.push_back(indent);
}
void CodeGenerator::PopIndent()
{
    _indentationStack.pop_back();
}
void CodeGenerator::WriteIndented(std::function<void()> writeFunc)
{
    WriteIndented(writeFunc, _indent);
}
void CodeGenerator::WriteIndented(std::function<void()> writeFunc, std::string indent)
{
    PushIndent(indent);
    writeFunc();
    PopIndent();
}
void CodeGenerator::WriteBlock(std::function<void()> writeFunc)
{
    WriteBlock(writeFunc, _indent);
}
void CodeGenerator::WriteBlock(std::function<void()> writeFunc, std::string indent)
{
    WriteLine("{");
    WriteIndented(writeFunc, indent);
    WriteLine("}");
}
void CodeGenerator::WriteForLoop(std::string loopVariableName, int lowerInclusive, int upperExclusive, std::function<void()> writeFunc)
{
    WriteForLoop(loopVariableName, lowerInclusive, upperExclusive, writeFunc, _indent);
}
void CodeGenerator::WriteForLoop(std::string loopVariableName, int lowerInclusive, int upperExclusive, std::function<void()> writeFunc, std::string indent)
{
    WriteLine("for (int ", loopVariableName, " = ", std::to_string(lowerInclusive), "; ", loopVariableName, " < ", std::to_string(upperExclusive), "; ", loopVariableName, " += 1)");
    WriteBlock(writeFunc, indent);
}
void CodeGenerator::WriteForLoop(std::string loopVariableName, int lowerInclusive, std::string upperExclusive, std::function<void()> writeFunc)
{
    WriteForLoop(loopVariableName, lowerInclusive, upperExclusive, writeFunc, _indent);
}
void CodeGenerator::WriteForLoop(std::string loopVariableName, int lowerInclusive, std::string upperExclusive, std::function<void()> writeFunc, std::string indent)
{
    WriteLine("for (int ", loopVariableName, " = ", std::to_string(lowerInclusive), "; ", loopVariableName, " < ", upperExclusive, "; ", loopVariableName, " += 1)");
    WriteBlock(writeFunc, indent);
}
void CodeGenerator::WriteForEachLoop(std::string loopVariableName, std::string source, std::function<void()> writeFunc, std::string loopVariableType)
{
    WriteForEachLoop(loopVariableName, source, writeFunc, _indent, loopVariableName);
}
void CodeGenerator::WriteForEachLoop(std::string loopVariableName, std::string source, std::function<void()> writeFunc, std::string indent, std::string loopVariableType)
{
    WriteLine("for (", loopVariableType, " ", loopVariableName, " : ", source, ")");
    WriteBlock(writeFunc, indent);
}

//C Plus Plus

void CPlusPlusCodeGenerator::WriteStructOrClassBlock(std::function<void()> writeFunc, std::string indent)
{
    WriteLine("{");
    WriteIndented(writeFunc, indent);
    WriteLine("};");
}
void CPlusPlusCodeGenerator::WriteStruct(std::string structName, std::function<void()> writeFunc)
{
    WriteStruct(structName, writeFunc, _indent);
}
void CPlusPlusCodeGenerator::WriteStruct(std::string structName, std::function<void()> writeFunc, std::string indent)
{
    WriteLine("struct ", structName);
    WriteStructOrClassBlock(writeFunc, indent);
}
void CPlusPlusCodeGenerator::WriteClassDeclaration(std::string className, std::function<void()> writePrivateFunc, std::function<void()> writePublicFunc)
{
    WriteClassDeclaration(className, writePrivateFunc, writePublicFunc, _indent);
}
void CPlusPlusCodeGenerator::WriteClassDeclaration(std::string className, std::function<void()> writePrivateFunc, std::function<void()> writePublicFunc, std::string indent)
{
    WriteLine("class ", className);
    WriteStructOrClassBlock([=]{
        WriteLine("private:");
        WriteIndented(writePrivateFunc, indent);
        WriteLine("public:");
        WriteIndented(writePublicFunc, indent);
    }, "");
}
void CPlusPlusCodeGenerator::WriteHeaderPragma(std::string headerName, std::function<void()> writeFunc)
{
    WriteLine("#ifndef ", headerName);
    WriteLine("#define ", headerName);
    WriteLine("");
    writeFunc();
    WriteLine("");
    WriteLine("#endif // ", headerName);
}
void CPlusPlusCodeGenerator::WriteNamespace(std::string namespaceName, std::function<void()> writeFunc)
{
    WriteNamespace(namespaceName, writeFunc, _indent);
}
void CPlusPlusCodeGenerator::WriteNamespace(std::string namespaceName, std::function<void()> writeFunc, std::string indent)
{
    WriteLine("namespace ", namespaceName);
    WriteBlock(writeFunc, indent);
}
void CPlusPlusCodeGenerator::WriteInclude(std::vector<std::string> fileNames, std::string beforeFileName, std::string afterFileName)
{
    for (std::string fileName : fileNames)
    {
        WriteLine("#include ", beforeFileName, fileName, afterFileName);
    }
}

//Latex

void LatexCodeGenerator::WriteCommand(std::string commandName, std::string content)
{
    WriteLine("\\", commandName, "{", content, "}");
}
void LatexCodeGenerator::WriteCommand(std::string commandName, std::string content, std::string options)
{
    WriteLine("\\", commandName, "[", options, "]{", content, "}");
}

void LatexCodeGenerator::WriteUsepackage(std::string packageName)
{
    WriteCommand("usepackage", packageName);
}
void LatexCodeGenerator::WriteUsepackage(std::string packageName, std::string options)
{
    WriteCommand("usepackage", packageName, options);
}

void LatexCodeGenerator::WriteEnvironment(std::string environmentName, std::function<void()> writeFunc)
{
    WriteEnvironment(environmentName, writeFunc, _indent);
}
void LatexCodeGenerator::WriteEnvironment(std::string environmentName, std::function<void()> writeFunc, std::string indent)
{
    WriteLine("\\begin{", environmentName, "}");
    WriteIndented(writeFunc, indent);
    WriteLine("\\end{", environmentName, "}");
}

}