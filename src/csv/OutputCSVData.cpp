#include "OutputCSVData.h"
#include "InputCSVData.h"
#include <string>

namespace ImageComparison
{
    OutputCSVData::OutputCSVData(InputCSVData imagePair, uint64_t simularityScore, float secondsTaken) noexcept
    : mImagePair(std::move(imagePair))
    , mSimularityScore(simularityScore)
    , mSecondsTaken(secondsTaken) {}

    OutputCSVData::OutputCSVData(OutputCSVData&& other) noexcept
    : mImagePair(std::move(other.mImagePair))
    , mSimularityScore(std::exchange(other.mSimularityScore, 0))
    , mSecondsTaken(std::exchange(other.mSecondsTaken, 0.0)) {}

    OutputCSVData& OutputCSVData::operator=(OutputCSVData&& other) noexcept {
        if (this != &other) {
            mImagePair = std::move(other.mImagePair);
            mSimularityScore = std::exchange(other.mSimularityScore, 0);
            mSecondsTaken = std::exchange(other.mSecondsTaken, 0.0);
        }

        return *this;
    }

    InputCSVData OutputCSVData::GetImagePair() const noexcept {
        return mImagePair;
    }

    uint64_t OutputCSVData::GetSimularityScore() const noexcept {
        return mSimularityScore;
    }

    float OutputCSVData::GetSecondsTaken() const noexcept {
        return mSecondsTaken;
    }
}