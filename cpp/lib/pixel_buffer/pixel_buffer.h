extern byte pixel_buffer[320*8/2*3];

void pixel_buffer_clear();

//void pixel_buffer_draw_pixel(uint16_t x, uint16_t y, uint16_t color);

void pixel_buffer_draw_char(uint16_t x, uint16_t y, unsigned char c, uint16_t color, uint16_t bg);

void pixel_buffer_draw_cursor(uint16_t x, uint16_t y, uint16_t color);
