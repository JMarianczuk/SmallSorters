
#include <ostream>

#include "lib/clara.hpp"
#include "CommandLineOptions.h"

namespace commandline
{

using namespace clara;

detail::Parser GetParser(CommandLineOptions& options)
{
    auto name = ExeName();
    name.set("SmallSortersPerformancing");
    return
        Opt(options.MeasureNormal)
            ["-n"]["--measureNormal"]
            ("Measure sorting individual arrays") |
        Opt(options.MeasureInRow)
            ["-i"]["--measureInRow"]
            ("Measure sorting of list of arrays") |
        Opt(options.MeasureSampleSort)
            ["-s"]["--measureSampleSort"]
            ("Measure sorting of medium size set using register sample sort implementation with special sorters at base case") |
        Opt(options.MeasureQuickSort)
            ["-q"]["--measureQuickSort"]
            ("Measure sorting of large set with special sorters at base case") |
        Opt(options.MeasureIpso)
            ["-4"]["--measureIpso"]
            ("Measure sorting with ipso") |
        Opt(options.VerifyNetworks)
            ["--verifyNetworks"]
            ("Verify correctnes of networks") |
        Opt(options.ExecuteTestMethod)
            ["-t"]["--test"]
            ("Execute test method") |
        Opt(options.HelpRequested)
            ["-h"]["--help"]
            ("Display help information") |
        Opt(options.ReadableNumbers)
            ["-r"]["--readableNumbers"]
            ("Generate only random numbers with less than three digits") |
        Opt(options.DebugToFile)
            ["--debugToFile"]
            ("Write Debug output to file") |
        name;
}

CommandLineOptions ParseOptions(char **arguments, int numberOfArguments)
{
    CommandLineOptions options = {false, false, false, false, false, false, false};
    auto commandLine = GetParser(options);
    
    auto result = commandLine.parse(Args(numberOfArguments, arguments));
    options.ParsingSuccessful = (bool) result;
    return options;
}

void PrintHelpText(std::ostream &stream)
{
    CommandLineOptions options;
    auto commandLine = GetParser(options);
    commandLine.writeToStream(stream);
}

}