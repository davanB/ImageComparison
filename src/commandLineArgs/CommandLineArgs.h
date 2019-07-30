#pragma once

#include<string>

namespace ImageComparison
{
    class CommandLineArgs {
        public:
        explicit CommandLineArgs(std::string&& inputFile, std::string&& outputFile) noexcept;
        CommandLineArgs(CommandLineArgs&& other) noexcept = default;
        CommandLineArgs& operator=(CommandLineArgs&& other) noexcept = default;

        std::string GetInputFilePath() const noexcept;
        std::string GetOutputFilePath() const noexcept;

        private:
        std::string mInputFilePath;
        std::string mOutputFilePath;
    };
} // namespace ImageComparison
