#include "CommandLineArgParser.h"
#include "cxxopts.hpp"

#include<exception>

namespace ImageComparison
{
    CommandLineArgs CommandLineArgParser::ParseCommandLineArguments(int argc, char** argv) {
        // argv[0] is the program name
        if (argc < 2) {
            throw std::exception();
        }

        cxxopts::Options options("ImageComparison", "Calculate image simularity.");
        options.add_options() 
            ("h,help", "Print help")
            ("f,file", "File path with CSV of image pair locations", cxxopts::value<std::string>());

        auto result = options.parse(argc, argv);

        if (result.count("help"))
        {
        std::cout << "Usage: ./ImageComparison -f <PATH TO CSV FILE>" << std::endl;
        exit(0);
        }

        auto fileName = result["file"].as<std::string>();

        return CommandLineArgs(fileName);
    }
}
