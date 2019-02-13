
#ifndef SORTABLE_DEFINITIONS_H
#define SORTABLE_DEFINITIONS_H

#include <string>
#include <vector>
#include <iostream>

#include "VectorHelpers.h"

namespace codegeneration 
{

class SortableStruct
{
private:
    bool IsInsertionSortOnly();
public:
    std::string Name;
    std::string DisplayName;
    bool HasReference;

    SortableStruct(std::string name, bool hasReference);
    SortableStruct(std::string name, bool hasReference, std::string displayName);
    ~SortableStruct();

    std::string FullName();
    bool UseForNetworkSort();
    bool UseForInsertionSort();
};

std::vector<SortableStruct*> sortableStructs = 
{
    new SortableStruct("", true, "KR-Default"),
    new SortableStruct("JumpXchg", false),
    new SortableStruct("JumpXchg", true),
    new SortableStruct("TwoCmovTemp", false),
    new SortableStruct("FourCmovTemp", true),
    new SortableStruct("FourCmovTemp_Split", true),
    new SortableStruct("ThreeCmovRegisterTemp", false),
    new SortableStruct("SixCmovRegisterTemp", true),
    new SortableStruct("ClangVersion", true),
    new SortableStruct("StlVersion", true),
    new SortableStruct("PointerOptimized", true),
};
std::vector<std::string> insertionSortOnlyNames = 
{
    "StlVersion",
    "PointerOptimized"
};

SortableStruct::SortableStruct(std::string name, bool hasReference) : Name(name), HasReference(hasReference)
{
    DisplayName = "K";
    if (HasReference)
    {
        DisplayName += "R";
    }
    DisplayName += "-";
    DisplayName += Name;
}
SortableStruct::SortableStruct(std::string name, bool hasReference, std::string displayName) : Name(name), HasReference(hasReference), DisplayName(displayName)
{

}
SortableStruct::~SortableStruct()
{

}

std::string SortableStruct::FullName()
{
    std::string result = "Sortable";
    if (HasReference)
    {
        result += "Ref";
    }
    if (Name.size() != 0)
    {
        result += "_";
        result += Name;
    }
    return result;
}
bool SortableStruct::UseForNetworkSort()
{
    return HasReference && !IsInsertionSortOnly();
}
bool SortableStruct::UseForInsertionSort()
{
    return FullName() == "SortableRef" || IsInsertionSortOnly();
}
bool SortableStruct::IsInsertionSortOnly()
{
    std::string fullName = FullName();
    return VectorAny<std::string>(
        insertionSortOnlyNames, 
        [fullName](std::string name){
            return fullName.find(name) != std::string::npos;
        });
}



}

#endif