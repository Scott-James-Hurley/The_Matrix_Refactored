cmake_minimum_required(VERSION 3.10)
project(TheMatrixRefactored)

set(IN_FILE "${CMAKE_SOURCE_DIR}/support_macros.h.in")
set(GENERATED_FILE_PATH "${CMAKE_BINARY_DIR}/GeneratedFiles")  

target_include_directories(main PRIVATE "${GENERATED_FILE_PATH}")

set(CMAKE_CXX_STANDARD 17)

find_package(Threads REQUIRED)

add_subdirectory(src)
