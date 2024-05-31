#include <Wire.h>

#include "time_utils.h"

#define INFINITE_LOOP_ON_FAILURE InfiniteLoopOnFailure(__FUNCTION__, __LINE__)

namespace {

void InfiniteLoopOnFailure(const char* function, const uint32_t line_number) {
  Serial.println(String(F("entering an infinite loop due to failure in ")) + function + ", at line number: " + line_number);
  while (true) {
    yield();
  }
}

}  // namespace

void setup() {
  Serial.begin(115200);
  Serial.println(time::Now() + F(" setup"));
  Wire.begin();
  Serial.println(time::Now() + F(" setup successful"));
}

void loop() {
  Serial.println(time::Now() + F(" loop"));
  delay(500);
}
