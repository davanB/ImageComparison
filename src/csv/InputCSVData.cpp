#include "InputCSVData.h"
#include<string>

namespace ImageComparison
{
    InputCSVData::InputCSVData(const std::string& imageOne, const std::string& imageTwo) noexcept
    : mImageOne(imageOne)
    , mImageTwo(imageTwo) {}

    InputCSVData::InputCSVData(InputCSVData&& other) noexcept
    : mImageOne(std::move(other.mImageOne))
    , mImageTwo(std::move(other.mImageTwo)) {}

    InputCSVData& InputCSVData::operator=(InputCSVData&& other) noexcept {
        if (this != &other) {
            mImageOne = std::move(other.mImageOne);
            mImageTwo = std::move(other.mImageTwo);
        }

        return *this;
    }

    std::string InputCSVData::GetImageOne() const noexcept {
        return mImageOne;
    }

    std::string InputCSVData::GetImageTwo() const noexcept {
        return mImageTwo;
    }
}