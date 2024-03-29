#pragma once

#include "../csv/InputCSVData.h"
#include "../csv/OutputCSVData.h"
#include <vector>

namespace ImageComparison
{
    /*
    @brief: Image simularity calculation interface.
     */
    class SimularityGenerator {
        public:
        virtual std::vector<OutputCSVData> GenerateSimularity(const std::vector<InputCSVData>& imagePairs) = 0;
    };
} // namespace ImageComparison
