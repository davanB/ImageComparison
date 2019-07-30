#pragma once

#include "../commandLineArgs/CommandLineArgs.h"

namespace ImageComparison
{
    class Program {
        public:
        Program(CommandLineArgs args);
        void Run();

        private:
        CommandLineArgs mProgramArgs;

    };
} // namespace ImageComparison
