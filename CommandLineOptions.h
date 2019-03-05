
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
    bool MeasureCompleteSort;

    bool ExecuteTestMethod;
    bool HelpRequested;
};

CommandLineOptions ParseOptions(char **arguments, int numberOfArguments);
void PrintHelpText(std::ostream &stream);

}

#endif