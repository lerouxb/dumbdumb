#include <Arduino.h>
#include "font.cpp"

byte pixel_buffer[320*8/2*3];

inline void pixel_buffer_draw_pixel(uint16_t x, uint16_t y, uint16_t color) {

  // TODO: a version of this function that can draw two pixels at a time, starting at an even x position could make pixel_buffer_draw_char a lot faster

  // color is a 12-bit color

  uint16_t pixel_offset = y*320 + x;
  uint16_t byte_offset = (int)((float)pixel_offset * 1.5);

  if (pixel_offset % 2 == 0) {
    pixel_buffer[byte_offset] = (color >> 4) & 0xff;// bits 5 to 12 of color

    // bits 1 to 4 of next byte plus bits 1 to 4 of color
    pixel_buffer[byte_offset + 1] = (pixel_buffer[byte_offset + 1] & 0xf) | ((color & 0xf) << 4);
  }
  else {
    // bits 9 to 12 of color plus bits 5 to 8 of current byte
    pixel_buffer[byte_offset] = ((color >> 8) & 0xf) | (((pixel_buffer[byte_offset] >> 4) & 0xf) << 4);
    pixel_buffer[byte_offset + 1] = color & 0xff;// bits 1 to 8 of color
  }
}

void pixel_buffer_draw_char(uint16_t x, uint16_t y, byte c, uint16_t color, uint16_t bg) {

  for (int8_t i=0; i<5; i++ ) { // Char bitmap = 5 columns
    uint8_t line = font[c * 5 + i];

    for (int8_t j=0; j<8; j++, line >>= 1) {
        if (line & 1) {
          pixel_buffer_draw_pixel(x+i, y+j, color);
        }
        else if (bg != color) {
          pixel_buffer_draw_pixel(x+i, y+j, bg);
        }
    }
  }
}
