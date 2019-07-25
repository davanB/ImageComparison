#pragma once

#include "CommandLineArgs.h"

namespace ImageComparison
{
    class CommandLineArgParser {
        public:
        CommandLineArgParser() = delete;
        ~CommandLineArgParser() = delete;

        static CommandLineArgs ParseCommandLineArguments(int argc, char** argv);
    };
}
