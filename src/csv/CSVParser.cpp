#include "CSVParser.h"
#include "InputCSVData.h"
#include "csv.h"
#include <fstream>

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
        in.read_header(io::ignore_no_column, "imageOne", "imageTwo");
        std::string imageOne; 
        std::string imageTwo; 
        while(in.read_row(imageOne, imageTwo)){
            // do stuff with the data
            inputData.emplace_back(imageOne, imageTwo);
        }

        return inputData;
    }

    bool CSVParser::FileExists() const {
        std::ifstream f(mFilePath.c_str());
        return f.good();
    }
}