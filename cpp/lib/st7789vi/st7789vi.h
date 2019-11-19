#define IM0 PA8 // (0: 16-bit. 1: 8-bit)
#define nRES PC6 // (low: reset)
#define DC PC8 // (1: data, 0: command)
#define nWR PA15 // (low: write)
#define nRD PC7 // (low: read)

// will probably just use this as Port B in one go
#define DB0 PB0
#define DB1 PB1
#define DB2 PB2
#define DB3 PB3
#define DB4 PB4
#define DB5 PB5
#define DB6 PB6
#define DB7 PB7
#define DB8 PB8
#define DB9 PB9
#define DB10 PB10
#define DB11 PB11
#define DB12 PB12
#define DB13 PB13
#define DB14 PB14
#define DB15 PB15

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240
#define FONT_HEIGHT 8

// TODO: there are memory locations where you can just specify the bits you want to set, so no reason to read the current values and do bitwise operations
#define CLR_DC GPIOC->ODR &= ~(1 << 8);
#define SET_DC GPIOC->ODR |=  (1 << 8);

#define CLR_RD GPIOC->ODR &= ~(1 << 7);
#define SET_RD GPIOC->ODR |=  (1 << 7);

#define CLR_WR GPIOA->ODR &= ~(1 << 15);
#define SET_WR GPIOA->ODR |=  (1 << 15);

inline void tft_write_command(uint16_t command);
inline void tft_write_data(uint16_t data1);
inline void tft_write_data3(uint16_t data1, uint16_t data2, uint16_t data3);
inline void tft_set_write_area (uint16_t x, uint16_t y, uint16_t xlen, uint16_t ylen);
void tft_fill_area(uint16_t x, uint16_t y, uint16_t xlen, uint16_t ylen, uint32_t back);
void tft_init();
void tft_copy_pixel_buffer(uint8_t line_offset);


