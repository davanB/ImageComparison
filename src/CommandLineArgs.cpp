#include "CommandLineArgs.h"

namespace ImageComparison
{
    CommandLineArgs::CommandLineArgs(std::string& fileName) noexcept
    : mFilePath(std::move(fileName))
    {}
}