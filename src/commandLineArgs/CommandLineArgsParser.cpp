#include "CommandLineArgsParser.h"
#include "cxxopts.hpp"

#include<exception>

namespace ImageComparison
{
    CommandLineArgs CommandLineArgParser::ParseCommandLineArguments(int argc, char** argv) {
        // argv[0] is the program name
        auto error = []() {
            std::cerr << "Not enough arguments." << std::endl;
            std::cerr << "Usage: ./ImageComparison -i <PATH TO CSV FILE> -o <PATH TO OUTPUT CSV>" << std::endl;
            exit(1);
        };

        if (argc < 3) {
            error();
        }

        cxxopts::Options options("ImageComparison", "Calculate image simularity.");
        options.add_options()
            ("i,inputFile", "File path with CSV of image pair locations", cxxopts::value<std::string>())
            ("o,outputFile", "File path to output CSV", cxxopts::value<std::string>());
        auto result = options.parse(argc, argv);

        if (result.count("i") < 1 || result.count("o") < 1) {
            error();
        }

        auto inFile = result["i"].as<std::string>();
        auto outFile = result["o"].as<std::string>();

        return CommandLineArgs(std::move(inFile), std::move(outFile));
    }
}
