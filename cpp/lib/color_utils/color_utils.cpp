#include <Arduino.h>

uint16_t rgb_to_12bit(float r, float g, float b) {
  return ((uint16_t)(r*15) << 8) | ((uint16_t)(g*15) << 4) | (uint16_t)(b*15);
}

