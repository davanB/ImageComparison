#include "CSVParser.h"
#include "InputCSVData.h"
#include "csv.h"
#include <fstream>
#include <iostream>

namespace ImageComparison
{
    CSVParser::CSVParser(const std::string& filePath)
    : mFilePath(filePath) {}

    std::vector<InputCSVData> CSVParser::ParseCSVFile() const {
        std::vector<InputCSVData> inputData;

        if (FileExists() == false) {
            throw std::invalid_argument("File does not exist");
        }

        io::CSVReader<2> in(mFilePath);
        std::string imageOne; 
        std::string imageTwo; 
        while(in.read_row(imageOne, imageTwo)){
            inputData.emplace_back(imageOne, imageTwo);
        }

        return inputData;
    }

    bool CSVParser::FileExists() const {
        std::ifstream f(mFilePath.c_str());
        std::cout << mFilePath << std::endl;
        return f.good();
    }
}