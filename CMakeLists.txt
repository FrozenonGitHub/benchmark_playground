cmake_minimum_required(VERSION 3.10)
project(cacheBench)
set(CMAKE_CXX_STANDARD 11)

# Find Google Benchmark package
find_package(benchmark REQUIRED)

# Add executable
add_executable(cacheBench cacheBench.cpp)

# Link Google Benchmark package
target_link_libraries(cacheBench benchmark::benchmark)

# Set CXX Flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native -O3 -mavx2")
target_compile_definitions(cacheBench PRIVATE CMAKE_CXX_FLAGS)
