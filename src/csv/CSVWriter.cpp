#include "CSVWriter.h"
#include "OutputCSVData.h"
#include <string>
#include <fstream>
#include<iostream>

namespace ImageComparison
{
    CSVWriter::CSVWriter(const std::string& outputFile)
    : mOutputFile(outputFile)
    , mFile(mOutputFile)
    {}

    CSVWriter::~CSVWriter() {
        if (mFile.is_open()) {
            mFile.close();
        }
    }

    bool CSVWriter::WriteResultsToCSV(const std::vector<OutputCSVData>& outputData) {
        try {
            if (mFile.good() == false || mFile.is_open() == false) {
                return false;
            }

            for (const auto& record : outputData) {
                mFile << record.GetImagePair().GetImageOne() << ","
                    << record.GetImagePair().GetImageTwo() << ","
                    << record.GetSimularityScore() << ","
                    << record.GetSecondsTaken() << "\n";
            }

            mFile.flush();
            mFile.close();
            return true;
        } catch (...) {
            return false;
        }
    }
} // namespace ImageComparison
