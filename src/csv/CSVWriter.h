#pragma once

#include "OutputCSVData.h"
#include <string>
#include <vector>
#include <fstream>

namespace ImageComparison
{
    /*
    @brief: Used to write out final results to csv file.
    This class will create the output file if it does not already exist.
     */
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
