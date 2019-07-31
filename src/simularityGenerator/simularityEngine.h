#pragma once

#include "simularityGenerator.h"

namespace ImageComparison
{
    /*
    @brief: Contains logic to take in png files and calculate image simularity score using Average Hashing Algorithm defined in OpenCV.
    Uses multiple threads to speed up the computations. The number of threads is at least 2 and at most depends on the hardware.
    This number is determined at runtime.
     */
    class SimularityEngine : public SimularityGenerator {
        public:
        SimularityEngine() = default;
        ~SimularityEngine() = default;
        
        /*
        @brief: Splits up the work among multiple threads and calls GenerateSimularitySequential() with the right chunks.
         */
        std::vector<OutputCSVData> GenerateSimularity(const std::vector<InputCSVData>& imagePairs);

        private:
        /*
        @brief: Loops through a portion of the input vector. This function is called in another thread seperate from the main thread.
         */
        std::vector<OutputCSVData> GenerateSimularitySequential(const std::vector<InputCSVData>& imagePairs, size_t start, size_t end);

        /*
        @brief: Calls the Average Hash Algorithm in OpenCV while timing the results done in each respective thread.
         */
        OutputCSVData ImageComparisonCalculation(const InputCSVData& pair);

        /*
        @brief: Wrapper function around OpenCV functions to do Average Hash Calculations.
        Reads the images into memory and calls OpenCV functions.
         */
        double AverageHashCalc(const std::string& imageOne, const std::string& imageTwo);
    };
} // namespace ImageComparison
