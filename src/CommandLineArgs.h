#pragma once

#include<string>

namespace ImageComparison
{
    class CommandLineArgs {
        public:
        CommandLineArgs(std::string& fileName) noexcept;
        std::string GetFilePath() const;

        private:
        std::string mFilePath;
    };
} // namespace ImageComparison
