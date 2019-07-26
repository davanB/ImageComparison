#pragma once

#include<string>

namespace ImageComparison
{
    class InputCSVData {
        public:
        explicit InputCSVData(const std::string& imageOne, const std::string& imageTwo) noexcept;
        ~InputCSVData() = default;

        InputCSVData(const InputCSVData& other) = default;
        InputCSVData& operator=(const InputCSVData& other) = default;

        InputCSVData(InputCSVData&& other) noexcept;
        InputCSVData& operator=(InputCSVData&& other) noexcept;

        std::string GetImageOne() const noexcept;
        std::string GetImageTwo() const noexcept;

        private:
        std::string mImageOne;
        std::string mImageTwo;
    };
}