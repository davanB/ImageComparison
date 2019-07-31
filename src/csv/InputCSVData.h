#pragma once

#include<string>

namespace ImageComparison
{
    /*
    @brief: Used to package data read from the input CSV file.
     */
    class InputCSVData {
        public:
        explicit InputCSVData(const std::string& imageOne, const std::string& imageTwo) noexcept;
        ~InputCSVData() = default;

        InputCSVData(const InputCSVData& other) = default;
        InputCSVData& operator=(const InputCSVData& other) = default;

        InputCSVData(InputCSVData&& other) noexcept = default;
        InputCSVData& operator=(InputCSVData&& other) noexcept = default;

        std::string GetImageOne() const noexcept;
        std::string GetImageTwo() const noexcept;

        private:
        std::string mImageOne;
        std::string mImageTwo;
    };
}