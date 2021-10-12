cmake_minimum_required(VERSION 3.17)
project(AutoGrad)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -march=native -O3 -fopenmp")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/")
find_package(MKL)

include_directories(./include ${MKL_INCLUDE_DIR})
file(GLOB_RECURSE SOURCE_FILES ./src/*)
add_executable(AutoGrad main.cpp ${SOURCE_FILES})
target_link_libraries(AutoGrad ${MKL_LIBRARIES})
