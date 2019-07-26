#include "gtest/gtest.h"
#include "CommandLineArgsParser.h"

static std::vector<char*> CreateInputArguments(std::vector<std::string> args) {
    std::vector<std::string> arguments = args;

    std::vector<char*> argv;
    for (const auto& arg : arguments) {
        argv.push_back((char*)arg.data());
    }
    argv.push_back(nullptr);

    return argv;
}

const std::string programNameArg = "test";

TEST(CommandLineArgsParserTests, TestFunction)
{
    auto argv = CreateInputArguments({"-f", "/some_path"});
    EXPECT_STREQ(argv[0], "-f");
    EXPECT_STREQ(argv[1], "/some_path");
}

TEST(CommandLineArgsParserTests, NoThrow)
{
    auto argv = CreateInputArguments({programNameArg, "-in", "/some_path", "-out", "/anotherPath"});
    EXPECT_NO_THROW(auto args = ImageComparison::CommandLineArgParser::ParseCommandLineArguments(argv.size() - 1, argv.data()));
}

TEST(CommandLineArgsParserTests, ThrowNotEnoughArgs)
{
    auto argv = CreateInputArguments({programNameArg, "-in", "/some_path"});
    EXPECT_THROW(auto args = ImageComparison::CommandLineArgParser::ParseCommandLineArguments(argv.size() - 1, argv.data(), std::exception));
}

TEST(CommandLineArgsParserTests, validArgs)
{
    auto argv = CreateInputArguments({programNameArg, "-in", "/some_path", "-out", "/anotherPath"});

    auto args = ImageComparison::CommandLineArgParser::ParseCommandLineArguments(argv.size() - 1, argv.data());
    EXPECT_STREQ(args.GetInputFilePath().data(), argv[2]);
    EXPECT_STREQ(args.GetOutputFilePath().data(), argv[4]);
}

TEST(CommandLineArgsParserTests, ExtraArgumentsThrow)
{
    auto argv = CreateInputArguments({programNameArg, "-in", "/some_path", "-out", "/anotherPath", "-a", "not_allowed"});

    EXPECT_THROW(auto args = ImageComparison::CommandLineArgParser::ParseCommandLineArguments(argv.size() - 1, argv.data()), std::exception);
}
