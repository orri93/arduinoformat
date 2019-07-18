cmake_minimum_required (VERSION 2.8.8)
project (testarduinoformat)

add_executable(testarduinoformat testarduinoformat.cpp utest.cpp)

enable_testing()
add_test(testarduinoformat testarduinoformat)
