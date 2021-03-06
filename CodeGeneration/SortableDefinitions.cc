
#include "SortableDefinitions.hpp"

namespace codegeneration
{

std::vector<SortableStruct*> structs =
{
    new SortableStruct("conditional_swap::CS_", "IfSwap", "ISwp", true, "KR-Default"),       //0
    new SortableStruct("conditional_swap::CS_", "JumpXchg", "JXhg", false),
    new SortableStruct("conditional_swap::CS_", "JumpXchg_Ref", "JXhg", true),                //2
    new SortableStruct("conditional_swap::CS_", "TwoCmovTemp", "2Cm", false),
    new SortableStruct("conditional_swap::CS_", "FourCmovTemp", "4Cm ", true),                //4
    new SortableStruct("conditional_swap::CS_", "FourCmovTemp_Split", "4CmS", true),
    new SortableStruct("conditional_swap::CS_", "ThreeCmovTemp", "3Cm", false),              //6
    new SortableStruct("conditional_swap::CS_", "TwoConditionalPointerMove", "2CPm", true),
    new SortableStruct("conditional_swap::CS_", "TwoConditionalPointerMovePredicate", "2CPp", true), //8
    new SortableStruct("conditional_swap::CS_", "Tie", "Tie ", true),
    new SortableStruct("insertionsort::InsertionSort_", "Default", "Def ", true),                     //10
    new SortableStruct("insertionsort::InsertionSort_", "StlVersion", "STL ", true),                  
    new SortableStruct("insertionsort::InsertionSort_", "PointerOptimized", "POp ", true),            //12
    new SortableStruct("insertionsort::InsertionSort_", "ArrayIndex_FirstCheck", "AIF ", true),
    new SortableStruct("conditional_swap::CS_", "CmovXor", "CmX ", true),

    //new SortableStruct("conditional_swap::CS_", "SixCmovTemp", "6Cm", true),
    //new SortableStruct("conditional_swap::CS_", "TernaryConditionalOperator", "TCOp", true),

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

SortableStruct::SortableStruct(std::string implementation, std::string name, std::string nameAbbrev, bool hasReference) : Implementation(implementation), Name(name), NameAbbreviation(nameAbbrev), HasReference(hasReference)
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
SortableStruct::SortableStruct(std::string implementation, std::string name, std::string nameAbbrev, bool hasReference, std::string displayName) : Implementation(implementation), Name(name), NameAbbreviation(nameAbbrev), DisplayName(displayName), HasReference(hasReference)
{

}

std::string SortableStruct::FullName()
{
    std::string result = "Sortable";
    if (HasReference)
    {
        result += "Ref";
    }
    return result;
}
std::string SortableStruct::CSName()
{
    return Implementation + Name;
}

bool SortableStruct::UseForNetworkSort()
{
    return HasReference && Implementation == "conditional_swap::CS_";
}
bool SortableStruct::UseForInsertionSort()
{
    return Implementation == "insertionsort::InsertionSort_";
}
bool SortableStruct::IsInsertionSortOnly()
{
    auto cs_name = Name;
    return VectorAny<std::string>(
        insertionSortOnlyNames, 
        [cs_name](std::string name){
            return cs_name.find(name) != std::string::npos;
        });
}
bool SortableStruct::WillBeShownInResults()
{
    return !(NameAbbreviation == "6Cm" || NameAbbreviation == "TCOp" || NameAbbreviation == "JXhg" || NameAbbreviation == "ISwp" || NameAbbreviation == "Def" || NameAbbreviation == "Tie ");
}
bool SortableStruct::InsertionsortSkipIpso()
{
    return NameAbbreviation == "STL" || NameAbbreviation == "AIF";
}

}