cmake_minimum_required(VERSION 3.4)

# Google Benchmark build flags
set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "" FORCE)
set(BENCHMARK_ENABLE_INSTALL OFF CACHE BOOL "" FORCE)
set(BENCHMARK_INSTALL_DOCS OFF CACHE BOOL "" FORCE)
set(BENCHMARK_ENABLE_GTEST_TESTS OFF CACHE BOOL "" FORCE)


# add Google Bencmark
add_subdirectory(libs/benchmark)

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native -O3")
endif()

set(BUILD_TESTS OFF CACHE BOOL "" FORCE)

add_subdirectory(libs/eigen)
add_subdirectory(benchmarks)
