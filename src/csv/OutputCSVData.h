#pragma once

#include "InputCSVData.h"
#include <string>

namespace ImageComparison
{
    /*
    @brief: Used to package the image simularity calculations to eventually be writen to the output file.
     */
    class OutputCSVData {
        public:
        explicit OutputCSVData(InputCSVData imagePair, double simularityScore, float secondsTaken) noexcept;
        ~OutputCSVData() = default;

        OutputCSVData(OutputCSVData&& other) noexcept;
        OutputCSVData& operator=(OutputCSVData&& other) noexcept;

        InputCSVData GetImagePair() const noexcept;
        double GetSimularityScore() const noexcept;
        float GetSecondsTaken() const noexcept;

        private:
        InputCSVData mImagePair;
        double mSimularityScore;
        float mSecondsTaken;
    };
}