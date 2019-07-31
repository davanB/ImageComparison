[![Build Status](https://travis-ci.com/davanB/ImageComparison.svg?branch=master)](https://travis-ci.com/davanB/ImageComparison/builds)


# Image Comparison

- [Build and test history](https://travis-ci.com/davanB/ImageComparison/builds)
- [Code coverage](https://coveralls.io/github/davanB/ImageComparison)

# Dependencies

OpenCV4:
Instructions for installing on OSX can be found below.
https://www.learnopencv.com/install-opencv-4-on-macos/

Instructions for installing on Windows:
https://www.learnopencv.com/install-opencv3-on-windows/

CMake:
Instructions for installing CMake on Unix, OSX and Windows:
https://cmake.org/install/

For OSX users, it is easiest with `Homebrew`:
Using `Homebrew`
```
brew update
brew install cmake
brew install opencv
```

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

The executable will be found in bin/
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

### CSV input file format
 ```
 No column headers are needed.
 The absolute path to each image must be provided.
 
 example:
 /some/path/imageOne.png,/another/path/imageTwo.png
 ```

# Design Decisions

## Language of choice

The main languages I was considering using were C# on the Mono framework or C++. C++ was a good canidate because it is the language I am strongest in and can be compiled for OSX and Windows. There was also the performance benefit for using the language. The argument for using C# on Mono was that I could make a simple WinForms GUI to make this tool slightly easier to use. Although the algorithm to calculate the image simularity score was left until the very end I knew I could probably use OpenCV making C++ a better canidate. A GUI would be nice but another reason for building a C++ command line tool is I could always make a C# WinForms application to serve was a wrapper for the command line tool if I had time at the end. The design was more flexible that way.

## Use of open source

A few lightweight, header-only libraries were used to speed up development. 

[Cxxopts](https://github.com/jarro2783/cxxopts) was used to easily parse command line arguments. The reason for this is there are always many edge cases to consider when accepting data from a user and this problem is not unique.

[Fast C++ CSV Parser](https://github.com/ben-strasser/fast-cpp-csv-parser) was used to parse the input CSV. The interface for the libary is clean and easy to use. Edge cases with malformed csv files are all handeled. It also has the benefit of using multi-threading to speed up reading large files although not very important since I did not expect the file read to be large.

[GoogleTest](https://github.com/google/googletest) was used to unit test the project. No alternatives were considered since for C++ it is the most popular choice.

[OpenCV](https://opencv.org/) is the library of choice to implement the image simularity algorithm. I really did not want to use something so heavyweight. I looked for the simplest algorithm that could meet the requirement of the same image returning a score of 0. In the end OpenCV has already implemented many algorithms I could use in a single line. It also makes reading images very easy. An alternative would be to use a simple hash. 2 identical images would return the same hash (simularity score = 0), otherwise a score of 1.

## Build system

[CMake](https://cmake.org/) was used to build the project. I have never had to work on a project that could be run on OSX and Windows so this was a challenge. I had a feeling using XCode was not an option so I looked for alternatives. At a previous coop, we used [Bazel](https://bazel.build/). It has been a few years since then so I had forgoten how things are set up. I decided on CMake since it is more widlety used and so I could draw from more examples. It was difficult to learn. Easily the most difficult part of this project.

GoogleTest source code is downloaded from GitHub directly and statically compiled with the project as recommened by Google. The CMakeLists.txt files exist in every directory. You call the file in the root which recursively calls identically named files in lower level directories.

### CI

[Travis-CI](https://travis-ci.org/) helped with setting up CI. Travis-CI also provided a way for me to deploy and test on Windows. I would know if the build would fail due to differences in environments. If another developer looked at this project and saw the "build passes" flag, they would know the project is in good shape. This is also something new I learned, so it was valuable to add. It also made it easy to compile and test with multiple compilers. 

## Design process

### Figuring out components

The first step I took was figuring out what high level components would be needed. I listed out the following:
+ package command line arguments
+ parse csv file
+ write out to csv file
+ image simularity calculator
..* the calculation should be wrapped by a component that splits the work among multiple threads

I wanted to hide the implementation of the simularity calculator behind an interface. The reason being at the start I wanted to leave that detail until the very end. By not depending on the implementation, but the interface I was able to continue to design the program and test each component in isolation.

### Testing

I am a firm believer of unit testing. At the start of the project I thought about using GMock to mock out the simularity algorithm so other parts of the program can be testing. I realized that was not needed since there is no direct dependency among them. 

Test files were created to test parsing of csv files. The command line arguments can be 'faked' in code before being passed to the parsing code. The outputs can be testing against to ensure proper parsing and if exceptions are thrown in the right cases.

Testing the multi-threaded code was not done the best way. The main thing I wanted to ensure was that for a given input:
1. The output record count was the same as input (items were not skipped)
2. The number of threads created were bounded based on hardware.
3. The work among the threads was even, with the main thread taking the final block of images to process.

The function that would do the calculation simply returned a hardcoded response. It was not enough to test all requirements.
* given the same 2 images, no way to know if the score would be zero.
* given 2 different images, no way to know if the score would be non-zero.

I had left it to a final integration test to prove those. I would not prove the OpenCV algorithm worked.

## Other considerations

### Image simularity score algorithm

I had come across a web service that calculated a perceptual hash for 2 images. I had though about simply uploading images to this service and getting the result back to display. I later thought this would be a bad idea if the images are high resolution and the inpput csv file contained many images. The program would take a long time to run and would also require a good internet connection. A fast, offline solution would be much more useful to a user.

### Documentation

Originally I wanted to use [Doxygen](http://www.doxygen.nl/) to build the source code documentation. Personally, I am not a fan of adding comments that dont add useful information just to have complete documentation. For this reason I decided not to use it. The unit tests provide code examples on how to use different parts of the projct and what they do. I also tried my best to write descriptive code. The cmake scripts have been organized so that the pattern is clear if adding new libraries. Comments provide additional insight into whats happening.

### Performance

I wanted to add multi-threading for 2 reasons: the problem is a good canidate for multi-threading since each calculation is independent and because I wanted to show off some skills. The elapsed time output would not change since it would be calculated per-thread but the total runtime of the program could be reduced.

## TODO:

There are a few things I would do to really have a polished project.

### Docker

I had thought about using Docker was a way to easily distribute this command line tool. The argument was that all dependencies would be packaged in the container so the user would not have to worry about installing them. Next, everytime a successful build happens a new image can be published on DockerHub for users. I have never used Docker so I thought this might be a challenge. For this reason I decided not to do it since it could potentially be a time sink.

### GUI

A GUI can be built to serve as a wrapper for the C++ command line tool. This would format the command line arguments and the file explorer could be used to select the input file.

### Code statistics and analysis

Many CI add-ons exist for open source projects. Code coverage and static analysis for complexity can be done after builds with their results uploaded. Once set up their data can be read for every build for the lifetime of the project which can provide insight. I could not get code coverage to work and connecting to any other service was not a priority.

### Testing on Windows

I never got around to testing on windows right. It would error on Travis-CI to difference in setup. Never got around to trying appveyor. Docker might have helped with this.

## Acknowledgments

- Project template taken from https://github.com/bast/gtest-demo

## References

- https://crascit.com/2015/07/25/cmake-gtest/
