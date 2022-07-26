# The_Matrix_Refactored

## An attempt to speed up a portion of the ACTS project multiplying matrices

This project requires [ACTS](https://github.com/acts-project/acts) and its prerequisites as well as [OpenBLAS](https://github.com/xianyi/OpenBLAS).<br /><br />

Compile files using the following command:<br />

`g++ -std=c++17 -O3 -march=native -mavx -mfma -m64 -I/path/to/eigen -I/path/to/SMatrix -I/path/to/acts/Core/include filename.cpp -lm -o filename.exe`<br /><br />
Example:<br />
`g++ -std=c++17 -O3 -march=native -mavx -mfma -m64 -I/usr/local/include/eigen3 -I/usr/local/include -I/acts/Core/include MtxMultArb.cpp -lm -o MtxMultArb.exe`<br /><br />

MtxMultTrans.cpp requires the openblas library for one of the similarity functions implemented and so requires the following command to compile:
`g++ -std=c++17 -O3 -march=native -mavx -mfma -m64 -I/path/to/openblas/include -L/path/to/openblas/lib -I/path/to/eigen -I/path/to/SMatrix -I/path/to/acts/Core/include -Wl,-rpath,/opt/openblas/lib filename.cpp -lm -lpthread -lgfortran -lopenblas -o filename.exe`<br /><br />
Example:<br />
`g++ -std=c++17 -O3 -march=native -mavx -mfma -m64 -I/opt/openblas/include -L/opt/openblas/lib -I/usr/local/include/eigen3 -I/usr/local/include -I/acts/Core/include -Wl,-rpath,/opt/openblas/lib MtxMultTrans.cpp -lm -lpthread -lgfortran -lopenblas -o MtxMultTrans.exe`<br /><br />

To change the dimensions of the marices used in `MtxMultTransArbSize.cpp`, define the following macros when compiling: `M1ROWS` and `M1COLUMNSM2ROWSCOLUMNS`.<br /><br />

To change the dimensions of the marices used in `MtxMultArb.cpp`, define the following macros when compiling: `M1ROWS`, `M1COLUMNSM2ROWS` and `M2COLUMNS`.<br /><br />

Like so:<br />
`g++ -std=c++17 -DM1ROWS=8 -DM1COLUMNSM2ROWS=8 -DM2COLUMNS=8 -std=c++17 -O3 -march=native -mavx -mfma -m64 -I/usr/local/include/eigen3 -I/usr/local/include -I/acts/Core/include MtxMultArb.cpp -lm -o MtxMultArb.exe`<br />
