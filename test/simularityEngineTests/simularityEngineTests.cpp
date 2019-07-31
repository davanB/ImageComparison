#include "gtest/gtest.h"
#include "simularityEngine.h"
#include "OutputCSVData.h"
#include "InputCSVData.h"

const std::string testImage1 = "image1.png";
const std::string testImage2 = "image2.png";

TEST(SimularityGeneratorTests, dontBlowUp)
{
    ImageComparison::SimularityEngine engine;

    ImageComparison::InputCSVData in(testImage1, testImage2);
    std::vector<ImageComparison::InputCSVData> inVec = {std::move(in)};

    EXPECT_NO_THROW(engine.GenerateSimularity(inVec));
}

static void TestSimularity(const std::string& image1, const std::string& image2,
                                bool expectedSame, int inVecSize) {
    ImageComparison::SimularityEngine engine;

    std::vector<ImageComparison::InputCSVData> inVec;
    for (int i = 0; i < inVecSize; ++i) {
        inVec.emplace_back(image1, image2);
    }

    auto result = engine.GenerateSimularity(inVec);
    EXPECT_EQ(result.size(), inVec.size());

    for (int i = 0; i < result.size(); ++i) {
        auto entry = std::move(result[i]);
        auto ex = inVec[i];
        EXPECT_EQ(entry.GetImagePair().GetImageOne(), ex.GetImageOne());
        EXPECT_EQ(entry.GetImagePair().GetImageTwo(), ex.GetImageTwo());
        if (expectedSame == true) {
            EXPECT_EQ(entry.GetSimularityScore(), 0);
        }
        else {
            EXPECT_NE(entry.GetSimularityScore(), 0);
        }
        EXPECT_NE(entry.GetSecondsTaken(), 0);
    }
}

TEST(SimularityGeneratorTests, GetDifferentSimularity)
{
    TestSimularity(testImage1, testImage2, false, 1);
}

TEST(SimularityGeneratorTests, GetSameSimularityScore)
{
    TestSimularity(testImage1, testImage1, true, 1);
}

TEST(SimularityGeneratorTests, MultiThreadedDifferentSimularity)
{
    TestSimularity(testImage1, testImage2, false, 101);
}

TEST(SimularityGeneratorTests, MultiThreadedSameSimularity)
{
    TestSimularity(testImage1, testImage1, true, 101);
}