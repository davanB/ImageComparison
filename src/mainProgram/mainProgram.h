#pragma once

#include "../commandLineArgs/CommandLineArgs.h"

namespace ImageComparison
{
    class MainProgram {
        public:
        MainProgram(CommandLineArgs args);
        void Run();

        private:
        CommandLineArgs mProgramArgs;

    };
} // namespace ImageComparison
