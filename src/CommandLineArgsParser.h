#pragma once

#include "CommandLineArgs.h"

namespace ImageComparison
{
    class CommandLineArgParser {
        public:
        static CommandLineArgs ParseCommandLineArguments(int argc, char** argv);

        private:
        CommandLineArgParser() = default;
        ~CommandLineArgParser() = default;
    };
}
