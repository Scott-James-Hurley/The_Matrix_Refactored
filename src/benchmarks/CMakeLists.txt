file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS *.cpp)
configure_file (config.h.in config.h @ONLY)
add_executable(benchmarks ${SOURCES})

target_link_libraries(benchmarks PUBLIC benchmark::benchmark)
target_include_directories(benchmarks PUBLIC ../../include)
target_include_directories(benchmarks PUBLIC ../libs/benchmark/include)
target_include_directories(benchmarks PUBLIC ../libs/eigen)
target_include_directories(benchmarks PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
