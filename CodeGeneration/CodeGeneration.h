
#ifndef CODE_GENERATION_H
#define CODE_GENERATION_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>

#include "nlohmann/json.hpp"

namespace codegeneration
{

class CodeGenerator
{
private:
    std::string _filename;
    std::string _indent;
    std::vector<std::string> _indentationStack;
    std::ofstream _fileStream;
    void MakeStream();
public:
    CodeGenerator(std::string filename);
    CodeGenerator(std::string filename, std::string indent);
    ~CodeGenerator();
    void Write(std::string content);
    void Write(int number);
    void WriteJson(nlohmann::json json);
    void WriteLine(std::string content);
    void PushIndent();
    void PushIndent(std::string indent);
    void PopIndent();
    void WriteIndented(void (*writeFunc)());
    void WriteIndented(void (*writeFunc)(), std::string indent);
    void WriteBlock(void (*writeFunc)());
    void WriteBlock(void (*writeFunc)(), std::string indent);
};

CodeGenerator& operator<<(CodeGenerator& gen, std::string content)
{
    gen.Write(content);
}
CodeGenerator& operator<<(CodeGenerator& gen, int number)
{
    gen.Write(number);
}

CodeGenerator::CodeGenerator(std::string filename) : _filename(filename), _indent("\t")
{
    MakeStream();
}

CodeGenerator::CodeGenerator(std::string filename, std::string indent) : _filename(filename), _indent(indent)
{
    MakeStream();
}

void CodeGenerator::MakeStream()
{
    // _fileStream = new std::ofstream();
    _fileStream.open(_filename, std::ios::out);
}

void CodeGenerator::Write(std::string content)
{
    _fileStream << content;
}
void CodeGenerator::Write(int number)
{
    _fileStream << number;
}

void CodeGenerator::WriteJson(nlohmann::json json)
{
    _fileStream << std::setw(4) << json << std::endl;
}

void CodeGenerator::WriteLine(std::string content)
{
    Write(content);
    Write("\n");
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
void CodeGenerator::WriteIndented(void (*writeFunc)())
{
    PushIndent();
    writeFunc();
    PopIndent();
}
void CodeGenerator::WriteIndented(void (*writeFunc)(), std::string indent)
{
    PushIndent(indent);
    writeFunc();
    PopIndent();
}
void CodeGenerator::WriteBlock(void (*writeFunc)())
{
    WriteLine("{");
    WriteIndented(writeFunc);
    WriteLine("}");
}
void CodeGenerator::WriteBlock(void (*writeFunc)(), std::string indent)
{
    WriteLine("{");
    WriteIndented(writeFunc, indent);
    WriteLine("}");
}

CodeGenerator::~CodeGenerator()
{
    _fileStream.flush();
    _fileStream.close();
    // delete _fileStream;
}
    
}

#endif