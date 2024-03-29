#include "gtest/gtest.h"
#include "CSVWriter.h"
#include "OutputCSVData.h"
#include "InputCSVData.h"

const std::string outputFileName = "output.csv";


TEST(CSVWriterTests, writeOutputToFile)
{
    std::string file(outputFileName);
    ImageComparison::CSVWriter writer(file);
    ImageComparison::InputCSVData in("image1.png", "image2.png");
    std::vector<ImageComparison::OutputCSVData> outVec;
    outVec.emplace_back(std::move(in), 1.0, 0.001f);

    EXPECT_NO_THROW(writer.WriteResultsToCSV(outVec));
}
