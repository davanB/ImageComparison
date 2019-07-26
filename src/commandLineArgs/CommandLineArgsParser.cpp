#include "CommandLineArgsParser.h"
#include "cxxopts.hpp"

#include<exception>

namespace ImageComparison
{
    CommandLineArgs CommandLineArgParser::ParseCommandLineArguments(int argc, char** argv) {
        // argv[0] is the program name
        if (argc < 3) {
            throw std::exception();
        }

        cxxopts::Options options("ImageComparison", "Calculate image simularity.");
        options.add_options()
            ("i,inputFile", "File path with CSV of image pair locations", cxxopts::value<std::string>())
            ("o,outputFile", "File path to output CSV", cxxopts::value<std::string>());
        auto result = options.parse(argc, argv);

        if (result.count("help"))
        {
            std::cout << "Usage: ./ImageComparison -i <PATH TO CSV FILE> -o <PATH TO OUTPUT CSV>" << std::endl;
            exit(0);
        }

        if (result.count("i") < 1 || result.count("o") < 1) {
            //throw std::exception();
        }

        auto inFile = result["i"].as<std::string>();
        auto outFile = result["o"].as<std::string>();
        

        return CommandLineArgs(std::move(inFile), std::move(outFile));
    }
}
