#include <cstdlib>
#include <iostream>

#include <arduinoformat.h>

#define DISPLAY_LENGTH 12

#define TEXT_UNIT "°C"
#define SENSOR_IDS "PK"

char* pointer = nullptr;

int main() {
  fds::format::setup();
  fds::format::set(
    ':',
    TEXT_UNIT,
    sizeof(TEXT_UNIT),
    DISPLAY_LENGTH,
    -(DISPLAY_LENGTH - sizeof(TEXT_UNIT) - 2),
    1);
  fds::format::ids(SENSOR_IDS, sizeof(SENSOR_IDS));
  fds::format::number(93.418);
  pointer = fds::format::get();
  std::cout << "Line #1: " << pointer;
  free(pointer);
  fds::format::number(666.11, 1, FORMAT_DOUBLE_WIDTH, FORMAT_DOUBLE_PRECISION, 2);
  pointer = fds::format::get(1);
  pointer[0] = 'A';
  pointer[1] = ' ';
  std::cout << "Line #2: " << pointer;
  free(pointer);
}
