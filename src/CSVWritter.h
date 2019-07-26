#pragma once

#include "OutputCSVData.h"
#include <string>
#include <vector>

namespace ImageComparison
{
    class CSVWritter {
        public:
        CSVWritter(const std::string& outputFile);
        ~CSVWritter() = default;

        bool WriteResultsToCSV(const std::vector<OutputCSVData> outputData);

        private:
        std::string mOutputFile;
    };
} // namespace ImageComparison
