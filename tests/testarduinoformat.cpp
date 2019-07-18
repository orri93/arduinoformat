#include <arduinoformat.h>
#include <gtest/gtest.h>

static char* pointer = nullptr;

TEST(testarduinoformat, setup_and_get) {
  fds::format::setup();
  pointer = fds::format::get(0);
  ASSERT_NE(pointer, nullptr);
  free(pointer);
  pointer = fds::format::get(1);
  ASSERT_NE(pointer, nullptr);
  free(pointer);
}

TEST(testarduinoformat, number) {
  fds::format::setup();
  fds::format::number(93.418);
  pointer = fds::format::get(0);
  ASSERT_EQ(pointer, "93.42");
  pointer = fds::format::get(1);
  pointer[0] = 'A';
  pointer[1] = ' ';
  fds::format::number(666.11, 1, FORMAT_DOUBLE_WIDTH, FORMAT_DOUBLE_PRECISION, 2);
  ASSERT_EQ(pointer, "A 666.11");
}

