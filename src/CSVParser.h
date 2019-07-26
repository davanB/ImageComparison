#pragma once

#include "InputCSVData"
#include<string>

namespace ImageComparison
{
    class CSVParser {
        public:
        CSVParser(std::string& fileName);
        std::vector<CSVInputData> ParseCSVFile() const;
    }
}