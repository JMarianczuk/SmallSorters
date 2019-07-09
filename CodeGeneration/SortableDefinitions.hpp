
#ifndef SORTABLE_DEFINITIONS_H
#define SORTABLE_DEFINITIONS_H

#include <string>
#include <vector>
#include <iostream>

#include "VectorHelpers.hpp"

namespace codegeneration 
{

class SortableStruct
{
private:
    bool IsInsertionSortOnly();
public:
    std::string Implementation; 
    std::string Name;
    std::string NameAbbreviation;
    std::string DisplayName;
    bool HasReference;

    SortableStruct(std::string implementation, std::string name, std::string nameAbbrev, bool hasReference);
    SortableStruct(std::string implementation, std::string name, std::string nameAbbrev, bool hasReference, std::string displayName);

    std::string FullName();
    std::string CSName();
    bool UseForNetworkSort();
    bool UseForInsertionSort();
    bool WillBeShownInResults();
    bool InsertionsortSkipIpso();
};

std::vector<SortableStruct*>* sortableStructs();

}

#endif