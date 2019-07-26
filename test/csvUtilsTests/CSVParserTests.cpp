#include "gtest/gtest.h"
#include "CSVParser.h"
#include "InputCSVData.h"

/*
TEST(CSVParserTests, fileDoesNotExist)
{
    std::string file("some/path.csv");
    ImageComparison::CSVParser parser(file);
    EXPECT_THROW(parser.ParseCSVFile(), std::invalid_argument);
}

TEST(CSVParserTests, fileExists)
{
    std::string file("testFiles/images.csv");
    ImageComparison::CSVParser parser(file);
    EXPECT_NO_THROW(parser.ParseCSVFile());
}

TEST(CSVParserTests, fileMalformed)
{
    std::string file("testFiles/imagesWrong.csv");
    ImageComparison::CSVParser parser(file);
    EXPECT_ANY_THROW(parser.ParseCSVFile());
}

TEST(CSVParserTests, parseCorrectFormatFile)
{
    std::vector<ImageComparison::InputCSVData> expectedInputData = {ImageComparison::InputCSVData("image1.png", "image2.png"), 
                                                                    ImageComparison::InputCSVData("image3.png", "image4.png")};
    std::string file("testFiles/images.csv");
    ImageComparison::CSVParser parser(file);
    auto res = parser.ParseCSVFile();

    EXPECT_EQ(res.size(), expectedInputData.size());

    for (int i = 0; i < res.size(); ++i) {
        EXPECT_EQ(res[i].GetImageOne(), expectedInputData[i].GetImageOne());
        EXPECT_EQ(res[i].GetImageTwo(), expectedInputData[i].GetImageTwo());
    }
}
*/