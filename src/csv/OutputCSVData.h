#pragma once

#include "InputCSVData.h"
#include <string>

namespace ImageComparison
{
    class OutputCSVData {
        public:
        explicit OutputCSVData(InputCSVData imagePair, uint64_t simularityScore, float secondsTaken) noexcept;
        ~OutputCSVData() = default;

        OutputCSVData(OutputCSVData&& other) noexcept;
        OutputCSVData& operator=(OutputCSVData&& other) noexcept;

        InputCSVData GetImagePair() const noexcept;
        uint64_t GetSimularityScore() const noexcept;
        float GetSecondsTaken() const noexcept;

        private:
        InputCSVData mImagePair;
        uint64_t mSimularityScore;
        float mSecondsTaken;
    };
}