#include "CommandLineArgsParser.h"
#include "CommandLineArgs.h"
#include "mainProgram.h"
#include <iostream>

int main(int argc, char** argv) {
    auto args = ImageComparison::CommandLineArgParser::ParseCommandLineArguments(argc, argv);
    
    ImageComparison::MainProgram program(std::move(args));
    try {
        program.Run();
        return 0;
    }
    catch (const std::exception& ex) {
        std::cerr << ex.what() << std::endl;
        return 1;
    }
}