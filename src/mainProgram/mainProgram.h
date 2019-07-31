#pragma once

#include "../commandLineArgs/CommandLineArgs.h"

namespace ImageComparison
{
    /*
    @brief: Contains all the main program logic. Does not catch exceptions. Those are caught in main and handeled there.
     */
    class MainProgram {
        public:
        MainProgram(CommandLineArgs args);
        void Run();

        private:
        CommandLineArgs mProgramArgs;

    };
} // namespace ImageComparison
