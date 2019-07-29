#include "gtest/gtest.h"
#include "simularityEngine.h"
#include "OutputCSVData.h"
#include "InputCSVData.h"


TEST(SimularityGeneratorTests, dontBlowUp)
{
    ImageComparison::SimularityEngine engine;

    ImageComparison::InputCSVData in("image1.png", "image2.png");
    std::vector<ImageComparison::InputCSVData> inVec = {std::move(in)};

    EXPECT_NO_THROW(engine.GenerateSimularity(inVec));
}

TEST(SimularityGeneratorTests, GetCannedResponse)
{
    ImageComparison::SimularityEngine engine;

    ImageComparison::InputCSVData in("image1.png", "image2.png");
    std::vector<ImageComparison::InputCSVData> inVec = {std::move(in)};

    auto result = engine.GenerateSimularity(inVec);
    EXPECT_EQ(result.size(), inVec.size());

    for (int i = 0; i < result.size(); ++i) {
        auto entry = std::move(result[i]);
        auto ex = inVec[i];
        EXPECT_EQ(entry.GetImagePair().GetImageOne(), ex.GetImageOne());
        EXPECT_EQ(entry.GetImagePair().GetImageTwo(), ex.GetImageTwo());
        EXPECT_EQ(entry.GetSimularityScore(), 5);
        EXPECT_EQ(entry.GetSecondsTaken(), 5);
    }
}

TEST(SimularityGeneratorTests, MultiThreadedResponses)
{
    ImageComparison::SimularityEngine engine;
    std::string image1 = "image1.png";
    std::string image2 = "image2.png";

    std::vector<ImageComparison::InputCSVData> inVec;
    for (int i = 0; i < 101; ++i) {
        inVec.emplace_back(image1, image2);
    }

    auto result = engine.GenerateSimularity(inVec);
    EXPECT_EQ(result.size(), inVec.size());

    for (int i = 0; i < result.size(); ++i) {
        auto entry = std::move(result[i]);
        auto ex = inVec[i];
        EXPECT_EQ(entry.GetImagePair().GetImageOne(), ex.GetImageOne());
        EXPECT_EQ(entry.GetImagePair().GetImageTwo(), ex.GetImageTwo());
        EXPECT_EQ(entry.GetSimularityScore(), 5);
        EXPECT_EQ(entry.GetSecondsTaken(), 5);
    }
}