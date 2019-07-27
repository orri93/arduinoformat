add_library(libarduinoformat STATIC src/arduinoformat.cpp src/arduinoformat.h)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_PLATFORM_INDEPENDENT_CODE ON)

include_directories(
  ${CMAKE_SOURCE_DIR}/src/avr-libc/libc/stdlib
  ${CMAKE_SOURCE_DIR}/extern/googletest/googletest/include 
  ${CMAKE_SOURCE_DIR}/extern/googletest/googlemock/include
  ${CMAKE_SOURCE_DIR}/extern/arduinomock)
