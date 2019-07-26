#pragma once

#include "OutputCSVData.h"
#include <string>
#include <vector>
#include <fstream>

namespace ImageComparison
{
    class CSVWriter {
        public:
        CSVWriter(const std::string& outputFile);
        ~CSVWriter();

        bool WriteResultsToCSV(const std::vector<OutputCSVData>& outputData);

        private:
        std::string mOutputFile;
        std::ofstream mFile;
    };
} // namespace ImageComparison
