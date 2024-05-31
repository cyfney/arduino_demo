#include <Wire.h>

#define INFINITE_LOOP_ON_FAILURE InfiniteLoopOnFailure(__FUNCTION__, __LINE__)

namespace {

void InfiniteLoopOnFailure(const char* function, const uint32_t line_number) {
  Serial.println(String(F("entering an infinite loop due to failure in ")) + function + ", at line number: " + line_number);
  while (true) {
    yield();
  }
}

String Time() {
  const auto now = millis();
  const uint16_t millis = now % 1000;
  const uint16_t seconds = now / 1000 % 60;
  const uint16_t minutes = now / 60000 % 60;
  const uint16_t hours = now / 3600000 % 100;

  static const String s_format(F("%02" PRIu16 ":%02" PRIu16 ":%02" PRIu16 ".%03" PRIu16));
  char buffer[13];
  snprintf(buffer, sizeof(buffer), s_format.c_str(), hours, minutes, seconds, millis);
  return String(buffer);
}

}  // namespace

void setup() {
  Serial.begin(115200);
  Serial.println(Time() + F(" setup"));
  Wire.begin();
  Serial.println(Time() + F(" setup successful"));
}

void loop() {
  Serial.println(Time() + F(" loop"));
  delay(500);
}
