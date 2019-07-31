#pragma once

#include "InputCSVData.h"
#include <string>

namespace ImageComparison
{
    /*
    @brief: Parses the input csv file passed through the command line.
    @precondition:
    The assumption is the file is already created or an exception will be thrown.
    The absolute path to the file must be passed in.
    The paths to the images the input file contains must also exist and be 
    the absolute path or an exception will be thrown.
    @info: This class uses the Fast C++ CSV Parser library and may use multiple threads if
    input file is large enough.
     */
    class CSVParser {
        public:
        CSVParser(const std::string& fileName);
        ~CSVParser() = default;

        std::vector<InputCSVData> ParseCSVFile() const;

        private:
        bool FileExists(const std::string& file) const;
        bool InputFileExists() const;

        std::string mFilePath;
    };
}