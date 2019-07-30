#include "InputCSVData.h"
#include<string>

namespace ImageComparison
{
    InputCSVData::InputCSVData(const std::string& imageOne, const std::string& imageTwo) noexcept
    : mImageOne(imageOne)
    , mImageTwo(imageTwo) {}

    std::string InputCSVData::GetImageOne() const noexcept {
        return mImageOne;
    }

    std::string InputCSVData::GetImageTwo() const noexcept {
        return mImageTwo;
    }
}