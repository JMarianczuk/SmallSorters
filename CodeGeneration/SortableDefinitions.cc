
#include "SortableDefinitions.hpp"

namespace codegeneration
{

std::vector<SortableStruct*> structs =
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
    new SortableStruct("ArrayIndex_FirstCheck", true)
};

std::vector<SortableStruct*>* sortableStructs() 
{
    return &structs;
}
std::vector<std::string> insertionSortOnlyNames =
{
    "StlVersion",
    "PointerOptimized",
    "ArrayIndex_FirstCheck"
};

SortableStruct::SortableStruct(std::string name, bool hasReference) : Name(name), HasReference(hasReference)
{
    DisplayName = "K";
    if (HasReference)
    {
        DisplayName += "R";
    }
    DisplayName += "-";
    std::string nameReplaced(name);
    size_t occ;
    while ((occ = nameReplaced.find("_")) != std::string::npos)
    {
        nameReplaced = nameReplaced.replace(occ, 1, "-");
    }
    DisplayName += nameReplaced;
}
SortableStruct::SortableStruct(std::string name, bool hasReference, std::string displayName) : Name(name), HasReference(hasReference), DisplayName(displayName)
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