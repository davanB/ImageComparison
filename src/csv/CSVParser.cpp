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

        if (InputFileExists() == false) {
            throw std::invalid_argument("File does not exist");
        }

        io::CSVReader<2> in(mFilePath);
        std::string imageOne; 
        std::string imageTwo; 
        while(in.read_row(imageOne, imageTwo)){
            if (FileExists(imageOne) == false || FileExists(imageTwo) == false) {
                throw std::invalid_argument("input image does not exist");
            }
            inputData.emplace_back(imageOne, imageTwo);
        }

        return inputData;
    }

    bool CSVParser::FileExists(const std::string& file) const {
        std::ifstream f(file.c_str());
        return f.good();
    }

    bool CSVParser::InputFileExists() const {
        std::ifstream f(mFilePath.c_str());
        return f.good();
    }
}