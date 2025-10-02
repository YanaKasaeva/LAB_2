cmake_minimum_required(VERSION 3.12)
project(lab_2)

set(CMAKE_CXX_STANDARD 17)

add_executable(bitstring_program src/main.cpp src/bitstring.cpp)
target_include_directories(bitstring_program PUBLIC include)

set(GTEST_INCLUDE_DIR "/opt/homebrew/include")
set(GTEST_LIB_DIR "/opt/homebrew/lib")

add_executable(bitstring_tests test/test_bitstring.cpp src/bitstring.cpp)
target_include_directories(bitstring_tests PUBLIC include ${GTEST_INCLUDE_DIR})
target_link_directories(bitstring_tests PUBLIC ${GTEST_LIB_DIR})
target_link_libraries(bitstring_tests gtest gtest_main pthread)