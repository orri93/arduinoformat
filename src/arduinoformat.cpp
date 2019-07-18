#include "arduinoformat.h"

namespace fds {
namespace format {

static char* formated[FORMAT_BUFFER_COUNT];
void setup() {
  for(uint8_t i = 0; i < FORMAT_BUFFER_COUNT; i++) {
    formated[i] = (char*)(malloc(FORMAT_BUFFER_SIZE));
  }
}

void number(const double& value,
  const uint8_t& index,
  const uint8_t& width,
  const uint8_t& precision,
  const uint8_t& start) {
  if(FORMAT_BUFFER_SIZE - start - width > 0) {
    dtostrf(value, width, precision, (formated[index]) + start);
  }
}

char* get(const uint8_t& index){
  return formated[index];
}

}
}
