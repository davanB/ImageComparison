#include "gtest/gtest.h"
#include "CommandLineArgsParser.h"

TEST(CommandLineArgsParserTests, NoThrow)
{
    char  arg0[] = "programName";
    char  arg1[] = "-i";
    char  arg2[] = "some_path";
    char  arg3[] = "-o";
    char  arg4[] = "anotherPath";
    char* argv[] = { &arg0[0], &arg1[0], &arg2[0], &arg3[0], &arg4[0], NULL };
    int   argc   = (int)(sizeof(argv) / sizeof(argv[0])) - 1;

    EXPECT_NO_THROW(auto args = ImageComparison::CommandLineArgParser::ParseCommandLineArguments(argc, &argv[0]));
}

TEST(CommandLineArgsParserTests, validArgs)
{
    char  arg0[] = "programName";
    char  arg1[] = "-i";
    char  arg2[] = "some_path";
    char  arg3[] = "-o";
    char  arg4[] = "anotherPath";
    char* argv[] = { &arg0[0], &arg1[0], &arg2[0], &arg3[0], &arg4[0], NULL };
    int   argc   = (int)(sizeof(argv) / sizeof(argv[0])) - 1;

    auto args = ImageComparison::CommandLineArgParser::ParseCommandLineArguments(argc, &argv[0]);
    EXPECT_STREQ(args.GetInputFilePath().data(), argv[2]);
    EXPECT_STREQ(args.GetOutputFilePath().data(), argv[4]);
}

TEST(CommandLineArgsParserTests, ExtraArgumentsThrow)
{
    char  arg0[] = "programName";
    char  arg1[] = "-i";
    char  arg2[] = "some_path";
    char  arg3[] = "-o";
    char  arg4[] = "anotherPath";
    char  arg5[] = "-a";
    char  arg6[] = "anotherPathWrong";
    char* argv[] = { &arg0[0], &arg1[0], &arg2[0], &arg3[0], &arg4[0], &arg5[0], &arg6[0], NULL };
    int   argc   = (int)(sizeof(argv) / sizeof(argv[0])) - 1;

    EXPECT_THROW(auto args = ImageComparison::CommandLineArgParser::ParseCommandLineArguments(argc, &argv[0]), std::exception);
}

