#include "CommandLineArgs.h"

namespace ImageComparison
{
    CommandLineArgs::CommandLineArgs(std::string&& inputFile, std::string&& outputFile) noexcept
    : mInputFilePath(std::forward<std::string>(inputFile))
    , mOutputFilePath(std::forward<std::string>(outputFile))
    {}

    std::string CommandLineArgs::GetInputFilePath() const noexcept{
        return mInputFilePath;
    }

    std::string CommandLineArgs::GetOutputFilePath() const noexcept{
        return mOutputFilePath;
    }
}