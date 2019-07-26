#include "CommandLineArgsParser.h"
#include "cxxopts.hpp"

#include<exception>

namespace ImageComparison
{
    CommandLineArgs CommandLineArgParser::ParseCommandLineArguments(int argc, char** argv) {
        // argv[0] is the program name
        if (argc < 5) {
            throw std::exception();
        }

        cxxopts::Options options("ImageComparison", "Calculate image simularity.");
        options.add_options() 
            ("h,help", "Print help")
            ("in,inputFile", "File path with CSV of image pair locations", cxxopts::value<std::string>())
            ("out,outputFile", "File path to output CSV", cxxopts::value<std::string>());

        auto result = options.parse(argc, argv);

        if (result.count("help"))
        {
        std::cout << "Usage: ./ImageComparison -in <PATH TO CSV FILE> -out <PATH TO OUTPUT CSV>" << std::endl;
        exit(0);
        }

        auto inFile = result["in"].as<std::string>();
        auto outFile = result["out"].as<std::string>();

        return CommandLineArgs(std::move(inFile), std::move(outFile));
    }
}
