#pragma once

#include <Arduino.h>

namespace time {
String Now() {
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
}  // namespace time