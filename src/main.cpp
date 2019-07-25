#include "cxxopts.hpp"
#include "CommandLineArgParser.h"

int main(int argc, char** argv) {
    auto args = ImageComparison::CommandLineArgParser::ParseCommandLineArguments(argc, argv);

    return 0;
}