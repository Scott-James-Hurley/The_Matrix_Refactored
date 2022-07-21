# The_Matrix_Refactored
## An attempt to speed up a portion of the ACTS project multiplying matrices
This project requires [ACTS](https://github.com/acts-project/acts) and its prerequisites.<br /><br />
To change the dimensions of the marices used in `MtxMultTransArbSize.cpp`, change the values of `m1Rows` and `m1ColumnsM2RowsColumns` in `main()`.<br /><br />
To change the dimensions of the marices used in `MtxMultArb.cpp`, change the values of `m1Rows`, `m1ColumnsM2Rows` and `m2Columns ` in `main()`.<br /><br />
Compile files using the following command:<br />
`g++ -std=c++17 -O3 -march=native -Ipath/to/Eigen -Ipath/to/acts/Core/include filename.cpp -o filename.exe`
