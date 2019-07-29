[![Build Status](https://travis-ci.com/davanB/ImageComparison.svg?branch=master)](https://travis-ci.com/davanB/ImageComparison/builds)
[![Coverage Status](https://coveralls.io/repos/github/davanB/ImageComparison/badge.svg?branch=master)](https://coveralls.io/github/davanB/ImageComparison?branch=master)


# Image Comparison

- [Build and test history](https://travis-ci.com/davanB/ImageComparison/builds)
- [Code coverage](https://coveralls.io/github/davanB/ImageComparison)

This demo uses the approach presented by Craig Scott in https://crascit.com/2015/07/25/cmake-gtest/.


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

You can get detailed output by using the `--verbose` flag.

$ ctest --verbose


## Acknowledgments

- Project template taken from https://github.com/bast/gtest-demo


## References

- https://crascit.com/2015/07/25/cmake-gtest/
