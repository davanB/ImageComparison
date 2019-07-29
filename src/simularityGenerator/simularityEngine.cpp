#include "simularityEngine.h"
#include "../csv/InputCSVData.h"
#include "../csv/OutputCSVData.h"
#include <vector>
#include <future>
#include <thread>
#include <chrono>
#include <iostream>

namespace ImageComparison
{
    std::vector<OutputCSVData> SimularityEngine::GenerateSimularity(const std::vector<InputCSVData>& imagePairs) {
        unsigned long const minPerThread = 5;
        unsigned long const maxThreads = (imagePairs.size() + minPerThread - 1)/minPerThread;
        unsigned long const hardwareThreads = std::thread::hardware_concurrency();
        unsigned long const numThreads = std::min(hardwareThreads != 0 ? hardwareThreads : 2, maxThreads);

        std::vector<OutputCSVData> results;
        std::vector<std::future<std::vector<OutputCSVData>>> tasks;
        auto blockSize = imagePairs.size() / numThreads;
        
        size_t endBlock = 0;
        for (int i = 0; i < numThreads - 1; ++i) {
            size_t startBlock = endBlock;
            endBlock = startBlock + blockSize;

            tasks.emplace_back(std::async(std::launch::async, &SimularityEngine::GenerateSimularitySequential, this, std::cref(imagePairs), startBlock, endBlock));
        }

        auto finalResult = GenerateSimularitySequential(imagePairs, endBlock, imagePairs.size());
        for (auto& task : tasks) {
            std::vector<OutputCSVData> partialResults = task.get();
            results.insert(results.end(), std::make_move_iterator(partialResults.begin()), std::make_move_iterator(partialResults.end()));
        }
        results.insert(results.end(), std::make_move_iterator(finalResult.begin()), std::make_move_iterator(finalResult.end()));

        return results;
    }

    std::vector<OutputCSVData> SimularityEngine::GenerateSimularitySequential(const std::vector<InputCSVData>& imagePairs, size_t start, size_t end) {
        std::vector<OutputCSVData> output;
        for (auto i = start; i < end; ++i) {
            output.push_back(std::move(ImageComparisonCalculation(imagePairs[i])));
        }

        return output;
    }

    OutputCSVData SimularityEngine::ImageComparisonCalculation(const InputCSVData& pair) {
        using namespace std::chrono;
        high_resolution_clock::time_point t1 = high_resolution_clock::now();
        // some func

        high_resolution_clock::time_point t2 = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>( t2 - t1 ).count()/1000;

        //OutputCSVData output(pair, 5, duration);
        OutputCSVData output(pair, 5, 5);
        return output;
    }
}