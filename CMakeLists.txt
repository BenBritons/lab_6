cmake_minimum_required(VERSION 3.20)
project(lab_6)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib/googletest-main)
include_directories(lib/googletest-main/googletest/include)
include_directories(lib/googletest-main/googlemock/include)
add_executable(lab_6 main.cpp Date.cpp Date.h RationalNumber.cpp RationalNumber.h Rectangle.cpp Rectangle.h DateParser.h FileReader.h tests/tests.cpp)
target_link_libraries(lab_6 gtest gtest_main)