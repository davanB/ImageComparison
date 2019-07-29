#pragma once

#include "simularityGenerator.h"

namespace ImageComparison
{
    class SimularityEngine : public SimularityGenerator {
        public:
        std::vector<OutputCSVData> GenerateSimularity(const std::vector<InputCSVData>& imagePairs);

        private:
        std::vector<OutputCSVData> GenerateSimularitySequential(const std::vector<InputCSVData>& imagePairs, size_t start, size_t end);
        OutputCSVData ImageComparisonCalculation(const InputCSVData& pair);
    };
} // namespace ImageComparison
