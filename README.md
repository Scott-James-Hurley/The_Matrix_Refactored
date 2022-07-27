# The_Matrix_Refactored
## An attempt to speed up a portion of the ACTS project multiplying matrices

This project requires [Eigen](https://gitlab.com/libeigen/eigen), [ROOT](https://root.cern/install/) and [Google Benchmark](https://github.com/google/benchmark) <br /><br />

To change the dimensions of the marices, use the following build options: `-DM1ROWS` and `-DM1COLUMNSM2ROWSCOLUMNS`.<br /><br />

Compile files using the following commands:<br />
`cmake -B build -S src`<br />
`cmake --build build`<br /><br />

Run with the following command:<br />
./build/benchmarks/benchmarks
