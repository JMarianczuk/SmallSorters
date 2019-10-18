
#ifndef GEMERATE_MEASUREMENT_HELPERS_HPP
#define GEMERATE_MEASUREMENT_HELPERS_HPP

#include "GenerateMeasurements.hpp"
#include "../Enumerations.h"

namespace codegeneration
{

SortableStruct* DefSortable()
{
    return (*sortableStructs())[0];
}
SortableStruct* FourCSSortable()
{
    return (*sortableStructs())[5];
}
SortableStruct* POpSortable()
{
    return (*sortableStructs())[12];
}

std::string BuildNetworkName(NetworkType networkType, BoseNelsonNetworkType boseNelsonNetworkType, bool withSpaces = true)
{
    std::string result = "";
    switch (networkType)
    {
        case NetworkType::Best:
            result += "Best";
            break;
        case NetworkType::BoseNelson:
            result += "BN";
            break;
        case NetworkType::Batcher:
            result += "Batc";
            break;
        case NetworkType::None:
            result += withSpaces ? "    " : "";
            break;
    }
    switch (boseNelsonNetworkType)
    {
        case BoseNelsonNetworkType::Locality:
            result += "Loc";
            break;
        case BoseNelsonNetworkType::Parallelism:
            result += withSpaces ? "PL " : "PL";
            break;
        case BoseNelsonNetworkType::Parameter:
            result += withSpaces ? "PM " : "PM";
            break;
        case BoseNelsonNetworkType::Recursive:
            result += "Rec";
            break;
        case BoseNelsonNetworkType::Constexpr:
            result += "CEx";
            break;
        case BoseNelsonNetworkType::None:
            result += withSpaces ? " " : "";
            break;
    }
    return result;
}

std::string BuildSorterName(
    Sorter sorter, 
    NetworkType networkType, 
    MeasureType measureType, 
    BoseNelsonNetworkType boseNelsonNetworkType = BoseNelsonNetworkType::None, 
    Sorter subSorter = Sorter::InsertionSort, 
    int sampleSortSplits = 0, 
    int sampleSortOversample = 0, 
    int sampleSortBlockSize = 0, 
    int ipsoBaseCaseSize = 0, 
    bool isInsertionPlusNetwork = false,
    IpsoBaseCaseType bcType = IpsoBaseCaseType::BEST_NETWORKS)
{
    std::string result = "";
    switch (sorter)
    {
        case Sorter::InsertionSort:
            result += "I";
            if (isInsertionPlusNetwork)
            {
                result += " + N ";
                switch (bcType)
                {
                    case IpsoBaseCaseType::BEST_NETWORKS:
                        result += "Best  ";
                        break;
                    case IpsoBaseCaseType::BOSE_NELSON_RECURSIVE:
                        result += "BN Rec";
                        break;
                    default:
                        throw std::logic_error("BuildSorterName - I+N not implemented for this N");
                }
            }
            break;
        case Sorter::SortNetwork:
            result += "N";
            break;
        case Sorter::StdSort:
            result += "StdSort ";
            switch (measureType)
            {
                case MeasureType::Complete:
                    result += "-Q ";
                    break;
                case MeasureType::SampleSort:
                    result += "-S000 ";
                    break;
                case MeasureType::Ipso:
                    result += "-4 ";
                    break;
            }
            return result;
        case Sorter::QuicksortCopy:
            result += "QSort   -Q ";
            return result;
        case Sorter::QuicksortCopyMsvc:
            result += "QSortMs -Q ";
            return result;
        case Sorter::RadixSortThrill:
            result += "RadixT  -Q ";
            switch (subSorter)
            {
                case Sorter::SampleSort:
                    result += "RSS";
                    break;
                case Sorter::StdSort:
                    result += "Std";
                    break;
            }
            return result;
        case Sorter::SkaSort:
            result += "SkaSort -Q ";
            switch (subSorter)
            {
                case Sorter::SampleSort:
                    result += "RSS";
                    break;
                case Sorter::StdSort:
                    result += "Std";
                    break;
            }
            return result;
        case Sorter::SampleSort:
            result += "S+";
            switch (subSorter)
            {
                case Sorter::InsertionSort:
                    result += "I";
                    break;
                case Sorter::SortNetwork:
                    result += "N";
            }
            break;
    }
    result += " ";
    result += BuildNetworkName(networkType, boseNelsonNetworkType, !isInsertionPlusNetwork);
    result += " ";
    switch (measureType)
    {
        case MeasureType::Normal:
            result += "-N";
            break;
        case MeasureType::InRow:
            result += "-I";
            break;
        case MeasureType::Complete:
            result += "-Q";
            break;
        case MeasureType::Complete2:
            result += "-c";
            break;
        case MeasureType::SampleSort:
            result += "-S";
            result += std::to_string(sampleSortSplits);
            result += std::to_string(sampleSortOversample);
            result += std::to_string(sampleSortBlockSize);
            break;
        case MeasureType::SampleSort2:
            result += "-s";
            result += std::to_string(sampleSortSplits);
            result += std::to_string(sampleSortOversample);
            result += std::to_string(sampleSortBlockSize);
            break;
        case MeasureType::Ipso:
            result += "-4 " + std::to_string(ipsoBaseCaseSize) + "_";
            result += std::to_string(sampleSortSplits);
            result += std::to_string(sampleSortOversample);
            result += std::to_string(sampleSortBlockSize);
            break;
    }
    result += " ";
    return result;
}

std::string AddStructName(const std::string& sorter, SortableStruct* sortableStruct)
{
    std::string result(sorter);
    result += "K";
    result += sortableStruct->HasReference ? "R" : " ";
    result += " ";

    result += sortableStruct->NameAbbreviation;

    return result;
}

}

#endif