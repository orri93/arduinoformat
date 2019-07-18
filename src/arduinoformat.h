#ifndef _FDS_ARDUINO_LIBRARY_FORMAT_H_
#define _FDS_ARDUINO_LIBRARY_FORMAT_H_

#include <Arduino.h>

#ifndef FORMAT_BUFFER_COUNT
#define FORMAT_BUFFER_COUNT     2
#endif
#ifndef FORMAT_BUFFER_SIZE
#define FORMAT_BUFFER_SIZE     32
#endif

#ifndef FORMAT_DOUBLE_WIDTH
#define FORMAT_DOUBLE_WIDTH     6
#endif
#ifndef FORMAT_DOUBLE_PRECISION
#define FORMAT_DOUBLE_PRECISION 2
#endif

namespace fds {
namespace format {
void setup();
void number(
  const double& value,
  const uint8_t& index = 0,
  const uint8_t& width = FORMAT_DOUBLE_WIDTH,
  const uint8_t& precision = FORMAT_DOUBLE_PRECISION,
  const uint8_t& start = 0);
char* get(const uint8_t& index = 0);
}
}

#endif /* _FDS_ARDUINO_LIBRARY_FORMAT_H_ */
