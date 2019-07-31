#include <Arduino.h>

#ifdef GOS_ARDUINO_UNIT_TESTING
#include <dtostrf.h>
#endif

#include "arduinoformat.h"

namespace fds {
namespace format {

typedef char* TextPointer;

static TextPointer unit_ = nullptr;
static TextPointer ids_ = nullptr;
static uint8_t idslenght_ = 0;
static uint8_t unitlenght_ = 0;
static uint8_t fixedlenght_ = FORMAT_FIXED_LENGTH;
static uint8_t width_ = FORMAT_DOUBLE_WIDTH;
static uint8_t precision_ = FORMAT_DOUBLE_PRECISION;
static uint8_t widthtouse, precisiontouse;
static uint8_t size;
static char idvaluesep_ = ' ';

static char* formated[FORMAT_BUFFER_COUNT];
static char* pointer = nullptr;

static bool prepair(const uint8_t& index, const uint8_t& width, const uint8_t& start);
static void finalize(const uint8_t& index);
static void assignbuffer(
  TextPointer& destination,
  const char* source,
  uint8_t& length,
  const uint8_t& sourcelength);

void setup() {
  for(uint8_t i = 0; i < FORMAT_BUFFER_COUNT; i++) {
    formated[i] = (char*)(malloc(FORMAT_BUFFER_SIZE));
    memset(formated[i], 0, FORMAT_BUFFER_SIZE);
  }
}

void set(
  const char& idvaluesep,
  const char* unit,
  const uint8_t& unitlenght,
  const uint8_t& fixedlength,
  const uint8_t& width,
  const uint8_t& precision) {
  assignbuffer(unit_, unit, unitlenght_, unitlenght);
  if (fixedlength < FORMAT_BUFFER_SIZE) {
    fixedlenght_ = fixedlength;
  }
  idvaluesep_ = idvaluesep;
  width_= width;
  precision_ = precision;
}

void ids(const char* ids, const uint8_t& lenght) {
  assignbuffer(ids_, ids, idslenght_, lenght);
}

void number(
  const double& value,
  const uint8_t& index,
  const uint8_t& width,
  const uint8_t& precision,
  const uint8_t& start) {
  if(prepair(index, width, start)) {
    precisiontouse = precision == FPRECISION ? precision_ : precision;
    dtostrf(value, widthtouse, precisiontouse, pointer);
    finalize(index);
  }
}

void integer(
  const int& value,
  const uint8_t& index,
  const uint8_t& width,
  const uint8_t& start) {
  if(prepair(index, width, start)) {
    sprintf(pointer, "%d", value);
    finalize(index);
  }
}

char* get(const uint8_t& index) {
  return formated[index];
}

void error(
  const uint8_t& index,
  const char* message,
  const uint8_t& length,
  const uint8_t& start) {
  size = FORMAT_BUFFER_SIZE - start - length;
  if(idslenght_ > 0) {
    size -= 2;
  }
  if(size > 0) {
    pointer = formated[index];
    pointer += start;
    if(idslenght_ > 0) {
      pointer += 2;
    }
    memcpy(pointer, message, length);
  }
}

void assign(const uint8_t& index, const char* text, const uint8_t& length) {
  memcpy(formated[index], text, min(length, FORMAT_BUFFER_SIZE));
}

void free() {
  for (uint8_t i = 0; i < FORMAT_BUFFER_COUNT; i++) {
    ::free(formated[i]);
    formated[i] = nullptr;
  }
}

bool prepair(const uint8_t& index, const uint8_t& width, const uint8_t& start) {
  widthtouse = width == FWIDTH ? width_ : width;
  if(unitlenght_ > 0 && unit_ != nullptr) {
    memset(formated[index], 32, fixedlenght_);
  }
  size = FORMAT_BUFFER_SIZE - start - widthtouse - unitlenght_;
  if(idslenght_ > 0) {
    size -= 2;
  }
  if(size > 0) {
    pointer = formated[index];
    pointer += start;
    if(idslenght_ > 0) {
      pointer += 2;
    }
    return true;
  } else {
    return false;
  }
}

void finalize(const uint8_t& index) {
  if(idslenght_ > 0) {
      pointer = formated[index];
      pointer[0] = ids_[index];
      pointer[1] = idvaluesep_;
    }
    if(unitlenght_ > 0 && unit_ != nullptr) {
      pointer = formated[index] + fixedlenght_ - unitlenght_;
      memcpy(pointer, unit_, unitlenght_);
    }
}

void assignbuffer(TextPointer& destination, const char* source, uint8_t& length, const uint8_t& sourcelength) {
  length = sourcelength;
  if(length > 0) {
    if(destination != nullptr) {
      ::free(destination);
    }
    destination = (char*)(malloc(length));
    memcpy(destination, source, length);
  } else {
    if(destination != nullptr) {
      ::free(destination);
      destination = nullptr;
    }
  }
}

}
}
