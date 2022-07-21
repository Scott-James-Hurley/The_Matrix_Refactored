# The_Matrix_Refactored
## An attempt to speed up a portion of the ACTS project multiplying matrices
This project requires [ACTS](https://github.com/acts-project/acts) and its prerequisites as well as [OpenBLAS](https://github.com/xianyi/OpenBLAS).<br /><br />
To change the dimensions of the marices used in `MtxMultTransArbSize.cpp`, change the values of `m1Rows` and `m1ColumnsM2RowsColumns` in `main()`.<br /><br />
To change the dimensions of the marices used in `MtxMultArb.cpp`, change the values of `m1Rows`, `m1ColumnsM2Rows` and `m2Columns ` in `main()`.<br /><br />
Compile files using the following command:<br />
`g++ -O3 -march=native -mavx -mfma -m64 -I/opt/openblas/include -L/opt/openblas/lib -Wl,-rpath,/opt/openblas/lib filename.cpp -lm -lpthread -lgfortran -lopenblas -o filename.exe`
