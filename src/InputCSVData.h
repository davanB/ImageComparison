#pragma once

#include<string>

namespace ImageComparison
{
    class InputCSVData {
        public:
        explicit InputCSVData(std::string& imageOne, std::string& imageTwo) noexcept;
        ~InputCSVData() = default;

        InputCSVData(InputCSVData&& other) noexcept;
        InputCSVData& operator=(InputCSVData&& other) = delete;

        std::string GetImageOne() const noexcept;
        std::string GetImageTwo() const noexcept;

        private:
        std::string mImageOne;
        std::string mImageTwo;
    }
}