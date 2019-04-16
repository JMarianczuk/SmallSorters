
#include "SortableDefinitions.hpp"

namespace codegeneration
{

std::vector<SortableStruct*> structs =
{
    new SortableStruct("", "Def", true, "KR-Default"),
    new SortableStruct("JumpXchg", "JXc", false),
    new SortableStruct("JumpXchg", "JXc", true),
    new SortableStruct("TwoCmovTemp", "2Cm", false),
    new SortableStruct("FourCmovTemp", "4Cm", true),
    new SortableStruct("FourCmovTemp_Split", "4CS", true),
    new SortableStruct("ThreeCmovRegisterTemp", "3Cm", false),
    new SortableStruct("SixCmovRegisterTemp", "6Cm", true),
    new SortableStruct("ClangVersion", "Cla", true),
    new SortableStruct("ClangPredicate", "CPr", true),
    new SortableStruct("Tie", "Tie", true),
    new SortableStruct("QMark", "QMa", true),
    new SortableStruct("StlVersion", "STL", true),
    new SortableStruct("PointerOptimized", "POp", true),
    new SortableStruct("ArrayIndex_FirstCheck", "AIF", true)
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

SortableStruct::SortableStruct(std::string name, std::string nameAbbrev, bool hasReference) : Name(name), NameAbbreviation(nameAbbrev), HasReference(hasReference)
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
SortableStruct::SortableStruct(std::string name, std::string nameAbbrev, bool hasReference, std::string displayName) : Name(name), NameAbbreviation(nameAbbrev), HasReference(hasReference), DisplayName(displayName)
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