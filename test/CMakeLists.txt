project(testarduinoformat)
enable_testing()

include_directories(${CMAKE_SOURCE_DIR}/src )

add_executable(${PROJECT_NAME} utest.cpp testarduinoformat.cpp)

target_link_libraries(${PROJECT_NAME} libarduinoformat)

add_test(NAME arduinoformattest COMMAND arduinoformatutest)
