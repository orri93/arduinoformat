cmake_minimum_required (VERSION 2.8.8)

project (arduinoformat)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})

find_package(ArduinoMock)

add_subdirectory(src)
add_subdirectory(tests)
