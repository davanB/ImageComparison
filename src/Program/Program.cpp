#include "Program.h"
#include "../csv/CSVParser.h"
#include "../csv/InputCSVData.h"
#include "../csv/OutputCSVData.h"
#include "../simularityGenerator/simularityEngine.h"
#include "../csv/CSVWriter.h"
#include <vector>

namespace ImageComparison
{
    Program::Program(CommandLineArgs args)
    : mProgramArgs(std::move(args))
    {}

    void Program::Run() {
        CSVParser parser(mProgramArgs.GetInputFilePath());
        std::vector<InputCSVData> inputImages = parser.ParseCSVFile();

        SimularityEngine imageCalculationEngine;
        std::vector<OutputCSVData> outputData = imageCalculationEngine.GenerateSimularity(inputImages);

        CSVWriter writer(mProgramArgs.GetOutputFilePath());
        bool written = writer.WriteResultsToCSV(outputData);

        if (written == false) {
            throw std::runtime_error("Failed to write to output file!");
        }
    }

} // namespace ImageCompatison
