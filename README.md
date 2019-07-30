[![Build Status](https://travis-ci.com/davanB/ImageComparison.svg?branch=master)](https://travis-ci.com/davanB/ImageComparison/builds)
[![Coverage Status](https://coveralls.io/repos/github/davanB/ImageComparison/badge.svg?branch=master)](https://coveralls.io/github/davanB/ImageComparison?branch=master)


# Image Comparison

- [Build and test history](https://travis-ci.com/davanB/ImageComparison/builds)
- [Code coverage](https://coveralls.io/github/davanB/ImageComparison)

# Dependencies

OpenCV:
Instructions for installing on OSX can be found below.
https://www.learnopencv.com/install-opencv-4-on-macos/

Instructions for installing on Windows:
https://www.learnopencv.com/install-opencv3-on-windows/

CMake:
Instructions for installing CMake on Unix, OSX and Windows:
https://cmake.org/install/

GoogleTest:
This project pulls source code from gtest directly from Github as recommended by Google.


## How to build this project

```bash
git clone https://github.com/davanB/ImageComparison.git
cd ImageComparison
mkdir build
cd build
cmake ..
cmake --build .
```

## Running the tests

Using `ctest`:
```
$ ctest

You can get detailed output by using the --verbose flag.

$ ctest --verbose
```

## Usage

```
-i, --inputFile: Absolute path to the input CSV file.
-o, --outputFile: Absolute path to where the output results csv file will be written to.

Examples: The following are all accepted

./ImageComparison -i ~/Documents/in.csv -o ~/Documents/in.cs
./ImageComparison -i=~/Documents/in.csv -o=~/Documents/in.cs
./ImageComparison --inputFile ~/Documents/in.csv --outputFile ~/Documents/in.cs
./ImageComparison --inputFile=~/Documents/in.csv=--outputFile ~/Documents/in.cs
```

# Design Decisions

## Language of choice

The main languages I was considering using were C# on the Mono framework or C++. C++ was a good canidate because it is the language I am strongest in and can be compiled for OSX and Windows. There was also the performance benefit for using the language. The argument for using C# on Mono was that I could make a simple WinForms GUI to make this tool slightly easier to use. Although the algorithm to calculate the image simularity score was left until the very end I knew I could probably use OpenCV making C++ a better canidate. A GUI would be nice but another reason for building a C++ command line tool is I could always make a C# WinForms application to serve was a wrapper for the command line tool if I had time at the end. The design was more flexible that way.

## Use of open source

A few lightweight, header-only libraries were used to speed up development. 

[Cxxopts](https://github.com/jarro2783/cxxopts) was used to easily parse command line arguments. The reason for this is there are always many edge cases to consider when accepting data from a user and this problem is not unique.

[Fast C++ CSV Parser](https://github.com/ben-strasser/fast-cpp-csv-parser) was used to parse the input CSV. The interface for the libary is clean and easy to use. Edge cases with malformed csv files are all handeled. It also has the benefit of using multi-threading to speed up reading large files although not very important since I did not expect the file read to be large.

[GoogleTest](https://github.com/google/googletest) was used to unit test the project. No alternatives were considered since for C++ it is the most popular choice.

[OpenCV](https://opencv.org/) is the library of choice to implement the image simularity algorithm. I really did not want to use something so heavyweight. I looked for the simplest algorithm that could meet the requirement of the same image returning a score of 0. In the end OpenCV has already implemented many algorithms I could use in a single line. It also makes reading images very easy.

## Build system

[CMake](https://cmake.org/) was used to build the project. I have never had to work on a project that could be run on OSX and Windows so this was a challenge. I had a feeling using XCode was not an option so I looked for alternatives. At a previous coop, we used [Bazel](https://bazel.build/). It has been a few years since then so I had forgoten how things are set up. I decided on CMake since it is more widlety used and so I could draw from more examples. It was difficult to learn. Easily the most difficult part of this project.

GoogleTest source code is downloaded from GitHub directly and statically compiled with the projext as recommened by Google. The CMakeLists.txt files exist in every directory. You call the file in the root which recursively calls identically named files in lower level directories.

### CI

[Travis-CI](https://travis-ci.org/) helped with setting up CI. Travis-CI also provided a way for me to deploy and test on Windows. I would know if the build would fail due to differences in environments. If another developer looked at this project and saw the "build passes" flag, they would know the project is in good shape. This is also something new I learned, so it was valuable to add. It also made it easy to compile and test with multiple compilers. 

I tried to use Coveralls to get test coverage but I could not get it to work.

## Other considerations


### Documentation

Originally I wanted to use [Doxygen](http://www.doxygen.nl/) to build the source code documentation. Personally, I am not a fan of adding comments that dont add useful information just to have complete documentation. For this reason I decided not to use it. The unit tests provide code examples on how to use different parts of the projct and what they do. I also tried my best to write descriptive code.

### Performance

I wanted to add multi-threading for 2 reasons: the problem is a good canidate for multi-threading since each calculation is independent and because I wanted to show off some skills. The elapsed time output would not change since it would be calculated per-thread but the total runtime of the program could be reduced.

## TODO:

There are a few things I would do to really have a polished project.

### Docker

I had thought about using Docker was a way to easily distribute this command line tool. The argument was that all dependencies would be packaged in the container so the user would not have to worry about installing them. Next, everytime a successful build happens a new image can be published on DockerHub for users. I have never used Docker so I thought this might be a challenge. For this reason I decided not to do it since it could potentially be a time sink.

### GUI

A GUI can be built to serve as a wrapper for the C++ command line tool. This would format the command line arguments and the file explorer could be used to select the input file.

## Acknowledgments

- Project template taken from https://github.com/bast/gtest-demo

## References

- https://crascit.com/2015/07/25/cmake-gtest/
