#include <Wire.h>

#include "time_utils.h"

#define INFINITE_LOOP_ON_FAILURE InfiniteLoopOnFailure(__FUNCTION__, __LINE__)

namespace {

template <typename X>
inline void Log(const X& x) {
  Serial.println(time::Now() + ' ' + x);
}

void InfiniteLoopOnFailure(const char* function, const uint32_t line_number) {
  Log(String(F("entering an infinite loop due to failure in ")) + function + ", at line number: " + line_number);
  while (true) {
    yield();
  }
}

}  // namespace

void setup() {
  Serial.begin(115200);
  Log(F("setup"));
  Wire.begin();
  // do something
  Log(F("setup successful"));
}

void loop() {
  Log(F("loop"));
  delay(500);
}
