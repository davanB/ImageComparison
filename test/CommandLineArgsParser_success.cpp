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
    auto argv = CreateInputArguments({programNameArg, "-f", "/some_path"});
    EXPECT_NO_THROW(auto args = ImageComparison::CommandLineArgParser::ParseCommandLineArguments(argv.size() - 1, argv.data()));
}

TEST(CommandLineArgsParserTests, includeFilePath)
{
    auto argv = CreateInputArguments({programNameArg, "-f", "/some_path"});

    auto args = ImageComparison::CommandLineArgParser::ParseCommandLineArguments(argv.size() - 1, argv.data());
    EXPECT_STREQ(args.GetFilePath().data(), argv[1]);
}

TEST(CommandLineArgsParserTests, ExtraArgumentsNoThrow)
{
    auto argv = CreateInputArguments({programNameArg, "-f", "/some_path", "-a", "not_allowed"});

    EXPECT_THROW(auto args = ImageComparison::CommandLineArgParser::ParseCommandLineArguments(argv.size() - 1, argv.data()), std::exception);
}
