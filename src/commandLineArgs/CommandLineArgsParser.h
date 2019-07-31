#pragma once

#include "CommandLineArgs.h"

namespace ImageComparison
{
    /*
    @brief: Parses command line arguments passed into main.
    Uses cxxopts library to easily parse arguments.
     */
    class CommandLineArgParser {
        public:
        static CommandLineArgs ParseCommandLineArguments(int argc, char** argv);

        private:
        CommandLineArgParser() = default;
        ~CommandLineArgParser() = default;
    };
}
