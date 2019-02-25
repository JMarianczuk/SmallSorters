
#ifndef CODE_GENERATION_H
#define CODE_GENERATION_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <functional>
#include <tuple>
#include <cstdarg>

namespace codegeneration
{

const std::string AutogeneratedPreamble = "//------------------------------------------------------------------------------\n// <auto-generated>\n//     This code was auto-generated\n//\n//     Changes to this file may cause incorrect behavior and will be lost if\n//     the code is regenerated.\n// </auto-generated>\n//------------------------------------------------------------------------------";

class CodeGenerator
{
private:
    std::string _filename;
    std::string _indent;
    std::vector<std::string> _indentationStack;
    std::ofstream _fileStream;
    bool _indentBeforeWrite;
    void MakeStream();
    void WriteIndent();
    void WriteEndl();
    void WriteInclude(std::vector<std::string> fileNames, std::string beforeFileName, std::string afterFileName);
    void WriteStructOrClassBlock(std::function<void()> writeFunc, std::string indent);
public:
    CodeGenerator(std::string filename, std::string indent = "\t");
    ~CodeGenerator();
    void Write(std::string content);
    void Write(int number);
    template <typename... TInputs> void WriteLine(TInputs... inputs);
    void PushIndent();
    void PushIndent(std::string indent);
    void PopIndent();
    void WriteIndented(std::function<void()> writeFunc);
    void WriteIndented(std::function<void()> writeFunc, std::string indent);
    void WriteBlock(std::function<void()> writeFunc);
    void WriteBlock(std::function<void()> writeFunc, std::string indent);
    void WriteForLoop(std::string loopVariableName, int lowerInclusive, int upperExclusive, std::function<void()> writeFunc);
    void WriteForLoop(std::string loopVariableName, int lowerInclusive, int upperExclusive, std::function<void()> writeFunc, std::string indent);
    void WriteForLoop(std::string loopVariableName, int lowerInclusive, std::string upperExclusive, std::function<void()> writeFunc);
    void WriteForLoop(std::string loopVariableName, int lowerInclusive, std::string upperExclusive, std::function<void()> writeFunc, std::string indent);
    void WriteForEachLoop(std::string loopVariableName, std::string source, std::function<void()> writeFunc, std::string loopVariableType = "auto");
    void WriteForEachLoop(std::string loopVariableName, std::string source, std::function<void()> writeFunc, std::string indent, std::string loopVariableType = "auto");
    void WriteStruct(std::string structName, std::function<void()> writeFunc);
    void WriteStruct(std::string structName, std::function<void()> writeFunc, std::string indent);
    void WriteClassDeclaration(std::string className, std::function<void()> writePrivateFunc, std::function<void()> writePublicFunc);
    void WriteClassDeclaration(std::string className, std::function<void()> writePrivateFunc, std::function<void()> writePublicFunc, std::string indent);
    void WriteHeaderPragma(std::string headerName, std::function<void()> writeFunc);
    void WriteNamespace(std::string namespaceName, std::function<void()> writeFunc);
    void WriteNamespace(std::string namespaceName, std::function<void()> writeFunc, std::string indent);    
    template <typename... TInputs> void WriteIncludeBrackets(TInputs... inputs);
    template <typename... TInputs> void WriteIncludeQuotes(TInputs... inputs);

};

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
    // _fileStream = new std::ofstream();
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

template <typename... TInputs>
void CodeGenerator::WriteLine(TInputs... inputs)
{
    std::vector<std::string> args = {inputs...};
    
    for (std::string arg : args)
    {
        Write(arg);
    }
    WriteEndl();
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
void CodeGenerator::WriteStructOrClassBlock(std::function<void()> writeFunc, std::string indent)
{
    WriteLine("{");
    WriteIndented(writeFunc, indent);
    WriteLine("};");
}
void CodeGenerator::WriteStruct(std::string structName, std::function<void()> writeFunc)
{
    WriteStruct(structName, writeFunc, _indent);
}
void CodeGenerator::WriteStruct(std::string structName, std::function<void()> writeFunc, std::string indent)
{
    WriteLine("struct ", structName);
    WriteStructOrClassBlock(writeFunc, indent);
}
void CodeGenerator::WriteClassDeclaration(std::string className, std::function<void()> writePrivateFunc, std::function<void()> writePublicFunc)
{
    WriteClassDeclaration(className, writePrivateFunc, writePublicFunc, _indent);
}
void CodeGenerator::WriteClassDeclaration(std::string className, std::function<void()> writePrivateFunc, std::function<void()> writePublicFunc, std::string indent)
{
    WriteLine("class ", className);
    WriteStructOrClassBlock([=]{
        WriteLine("private:");
        WriteIndented(writePrivateFunc, indent);
        WriteLine("public:");
        WriteIndented(writePublicFunc, indent);
    }, "");
}
void CodeGenerator::WriteHeaderPragma(std::string headerName, std::function<void()> writeFunc)
{
    WriteLine("#ifndef ", headerName);
    WriteLine("#define ", headerName);
    WriteLine("");
    writeFunc();
    WriteLine("");
    WriteLine("#endif");
}
void CodeGenerator::WriteNamespace(std::string namespaceName, std::function<void()> writeFunc)
{
    WriteNamespace(namespaceName, writeFunc, _indent);
}
void CodeGenerator::WriteNamespace(std::string namespaceName, std::function<void()> writeFunc, std::string indent)
{
    WriteLine("namespace ", namespaceName);
    WriteBlock(writeFunc, indent);
}
void CodeGenerator::WriteInclude(std::vector<std::string> fileNames, std::string beforeFileName, std::string afterFileName)
{
    for (std::string fileName : fileNames)
    {
        WriteLine("#include ", beforeFileName, fileName, afterFileName);
    }
}
template <typename... TInputs>
void CodeGenerator::WriteIncludeBrackets(TInputs... inputs)
{
    std::vector<std::string> args = {inputs...};
    WriteInclude(args, "<", ">");
}
template <typename... TInputs>
void CodeGenerator::WriteIncludeQuotes(TInputs... inputs)
{
    std::vector<std::string> args = {inputs...};
    WriteInclude(args, "\"", "\"");
}
    
}

#endif