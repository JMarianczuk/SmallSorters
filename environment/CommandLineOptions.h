
#ifndef COMMAND_LINE_OPTIONS_H
#define COMMAND_LINE_OPTIONS_H

#include <ostream>

namespace commandline
{

struct CommandLineOptions
{
    bool ParsingSuccessful;

    bool MeasureNormal;
    bool MeasureInRow;
    bool MeasureSampleSort;
    bool MeasureQuickSort;
    bool MeasureIpso;

    bool VerifyNetworks;

    bool ExecuteUnitTests;
    bool ExecuteExperimentMethod;
    bool HelpRequested;

    bool ReadableNumbers;
    bool DebugToFile;

    bool MeasureCpuCycles;
    bool MeasureL1InstrCache;
};

CommandLineOptions ParseOptions(char **arguments, int numberOfArguments);
void PrintHelpText(std::ostream &stream);

} // namespace commandline

#endif // COMMAND_LINE_OPTIONS_H