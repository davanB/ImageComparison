#pragma once

#include "InputCSVData.h"
#include <string>

namespace ImageComparison
{
    class CSVParser {
        public:
        CSVParser(const std::string& fileName);
        ~CSVParser() = default;

        std::vector<InputCSVData> ParseCSVFile() const;

        private:
        bool FileExists() const;

        std::string mFilePath;
    };
}