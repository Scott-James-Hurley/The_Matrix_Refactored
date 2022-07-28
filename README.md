# The_Matrix_Refactored

## An attempt to speed up a portion of the ACTS project multiplying matrices

### Files

[`include/similarityImplementations.hpp`](https://github.com/Scott-James-Hurley/The_Matrix_Refactored/blob/googlebenchmark/include/similarityImplementations.hpp) - Contains the custom implementations of the similarity calculation<br />
[`include/benchmarks/`](https://github.com/Scott-James-Hurley/The_Matrix_Refactored/tree/googlebenchmark/include/benchmarks) - Directory that contains the benchmarks for all the similarity implementations<br />
[`include/benchmarks/similarity.hpp`](https://github.com/Scott-James-Hurley/The_Matrix_Refactored/blob/googlebenchmark/include/benchmarks/similarity.hpp) - Adds the aforementioned benchmarks to the benchmark suite<br />
[`include/benchmarks/similarityHeader.h`](https://github.com/Scott-James-Hurley/The_Matrix_Refactored/blob/googlebenchmark/include/benchmarks/similarityHeader.h) - Contains definitions for constants<br />
[`src/benchmarks/benchmark.cpp`](https://github.com/Scott-James-Hurley/The_Matrix_Refactored/blob/googlebenchmark/src/benchmarks/benchmark.cpp) - Runs the benchmark suite<br />

### Requirements
This project requires [Eigen](https://gitlab.com/libeigen/eigen), [ROOT](https://root.cern/install/) and [Google Benchmark](https://github.com/google/benchmark)

### Set Matrix Sizes
To change the dimensions of the marices, use the following build options: `-DM1ROWS` and `-DM1COLUMNSM2ROWSCOLUMNS`.

### How to Build and Run

Compile files using the following commands:<br />
`cmake -B build -S src`<br />
`cmake --build build`<br /><br />

Run with the following command:<br />
`./build/benchmarks/benchmarks`