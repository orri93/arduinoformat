#ifndef _FDS_ARDUINO_LIBRARY_FORMAT_H_
#define _FDS_ARDUINO_LIBRARY_FORMAT_H_

#include <Arduino.h>

#ifndef FORMAT_BUFFER_COUNT
#define FORMAT_BUFFER_COUNT     2
#endif
#ifndef FORMAT_BUFFER_SIZE
#define FORMAT_BUFFER_SIZE     32
#endif

#ifndef FORMAT_FIXED_LENGTH
#define FORMAT_FIXED_LENGTH    12
#endif

#ifndef FORMAT_DOUBLE_WIDTH
#define FORMAT_DOUBLE_WIDTH     6
#endif
#ifndef FORMAT_DOUBLE_PRECISION
#define FORMAT_DOUBLE_PRECISION 2
#endif

#define FWIDTH 0
#define FPRECISION 0

namespace fds {
namespace format {
void setup();
void set(
  const char& idvaluesep,
  const char* unit,
  const uint8_t& unitlength,
  const uint8_t& fixedlength = FORMAT_FIXED_LENGTH,
  const uint8_t& width = FORMAT_DOUBLE_WIDTH,
  const uint8_t& precision = FORMAT_DOUBLE_PRECISION);
void ids(const char* ids, const uint8_t& lenght);
void number(
  const double& value,
  const uint8_t& index = 0,
  const uint8_t& width = FWIDTH,
  const uint8_t& precision = FPRECISION,
  const uint8_t& start = 0);
void integer(
  const int& value,
  const uint8_t& index = 0,
  const uint8_t& width = FWIDTH,
  const uint8_t& start = 0);
char* get(const uint8_t& index = 0);
void error(
  const uint8_t& index,
  const char* message,
  const uint8_t& length,
  const uint8_t& start = 0);
void assign(const uint8_t& index, const char* text, const uint8_t& length);
void free();
}
}

#endif /* _FDS_ARDUINO_LIBRARY_FORMAT_H_ */
