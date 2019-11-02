#include <Arduino.h>
#include "st7789vi.h"
#include <pixel_buffer.h>

inline void tft_write_command(uint16_t command) {
  CLR_DC
  SET_RD
  CLR_WR
  GPIOB->ODR = (command << 8) & 0xffff;
  SET_WR
  SET_DC
}

inline void tft_write_data(uint16_t data1) {
  CLR_WR
  GPIOB->ODR = (data1 << 8) & 0xffff;
  SET_WR
}

inline void tft_write_data3(uint16_t data1, uint16_t data2, uint16_t data3) {
  CLR_WR
  GPIOB->ODR = (data1 << 8) & 0xffff;
  SET_WR
  CLR_WR
  GPIOB->ODR = (data2 << 8) & 0xffff;
  SET_WR
  CLR_WR
  GPIOB->ODR = (data3 << 8) & 0xffff;
  SET_WR
}


inline void tft_set_write_area(uint16_t x, uint16_t y, uint16_t xlen, uint16_t ylen) {
  tft_write_command(0x002A);
  tft_write_data((x>>8)&0xFF);
  tft_write_data((x>>0)&0xFF);
  tft_write_data(((x+xlen)>>8)&0xFF);
  tft_write_data(((x+xlen)>>0)&0xFF);

  tft_write_command(0x2B);
  tft_write_data((y>>8)&0xFF);
  tft_write_data((y>>0)&0xFF);
  tft_write_data(((y+ylen)>>8)&0xFF);
  tft_write_data(((y+ylen)>>0)&0xFF);
  }

void tft_fill_area(uint16_t x, uint16_t y, uint16_t xlen, uint16_t ylen, uint32_t back) {
    uint32_t i, total;
    tft_set_write_area(x, y, xlen, ylen);
    tft_write_command(0x2C);

    //FIXME: Why do I need these +1 adjustments. Off-by-one in tft_set_write_area?
    total = (xlen+1) * (ylen+1);

    /*
    for (i=0; i<total; i++) {
      tft_write_data3((back>>16) & 0xFF, (back>>8) & 0xFF, (back>>0) & 0xFF);
      //tft_write_data((back>>16) & 0xFF);
      //tft_write_data((back>>8) & 0xFF);
      //tft_write_data((back>>0) & 0xFF);
    }
    */
    // do two pixels at a time using three bytes because 12 bits times 2 = 24 bits
    for (i=0; i<total; i+=2) {
      /*
      tft_write_data((back >> 4) & 0xFF);
      tft_write_data((back & 0xF) << 4 | (back >> 8) & 0xF);
      tft_write_data(back & 0xFF);
      */
      tft_write_data3(
        (back >> 4) & 0xFF,
        ((back & 0xF) << 4) | ((back >> 8) & 0xF),
        back & 0xFF
      );
    }
}


void tft_init() {
  /*

  IM0: PA8 (0: 16-bit. 1: 8-bit)
  DC: PC8 (1: data, 0: command)
  nWR: PA15 (low: write)
  nRD: PC7 (low: read)
  nRES: PC6 (low: reset)
  DB0-DB15: PB0-PB15 (high byte for 8-bit!)

  */

  // 8 bit mode
  pinMode(IM0, OUTPUT);
  digitalWrite(IM0, HIGH);

  pinMode(nRES, OUTPUT);

  // control pins
  pinMode(DC, OUTPUT);
  pinMode(nWR, OUTPUT);
  pinMode(nRD, OUTPUT);

  // bi-directional data bus
  pinMode(DB0, OUTPUT);
  pinMode(DB1, OUTPUT);
  pinMode(DB2, OUTPUT);
  pinMode(DB3, OUTPUT);
  pinMode(DB4, OUTPUT);
  pinMode(DB5, OUTPUT);
  pinMode(DB6, OUTPUT);
  pinMode(DB7, OUTPUT);
  pinMode(DB8, OUTPUT);
  pinMode(DB9, OUTPUT);
  pinMode(DB10, OUTPUT);
  pinMode(DB11, OUTPUT);
  pinMode(DB12, OUTPUT);
  pinMode(DB13, OUTPUT);
  pinMode(DB14, OUTPUT);
  pinMode(DB15, OUTPUT);

  digitalWrite(nRES, LOW);
  digitalWrite(nRD, HIGH);
  digitalWrite(nWR, HIGH);
  digitalWrite(nRES, HIGH);
  delay(2);

  tft_write_command(0x0029); //exit SLEEP mode

  delay(2);

  // MADCTL: memory data access control
  tft_write_command(0x0036);
  tft_write_data(0x70); //0b01110000
  // page address order: top to bottom (0)
  // column adddress order: right to left (1)
  // page/column order: reverse mode (1)
  // line address order: LEFT refresh bottom to top (1) ML
  // RGB/BGR order: RGB (0)
  // Display data latch data order: LCD refresh left to right (0) MH

  // COLMOD: Interface Pixel format
  tft_write_command(0x003A);
  /*
  tft_write_data(0x0066); // 0b01100110
  // 0
  // 110 262K of RGB interface
  // 0
  // 110 18bit/pixel
  */
  tft_write_data(0x03);

  // PORCTRL: Porch setting
  tft_write_command(0x00B2);
  tft_write_data(0x0C);
  tft_write_data(0x0C);
  tft_write_data(0x00);
  tft_write_data(0x33);
  tft_write_data(0x33);

  // GCTRL: Gate Control
  tft_write_command(0x00B7);
  tft_write_data(0x0035);

  // VCOMS: VCOM setting
  tft_write_command(0x00BB);
  tft_write_data(0x002B);

  // LCMCTRL: LCM Control
  tft_write_command(0x00C0);
  tft_write_data(0x002C);

  // VDVVRHEN: VDV and VRH Command Enable
  tft_write_command(0x00C2);
  tft_write_data(0x0001);
  tft_write_data(0xFF);

  // VRHS: VRH Set
  tft_write_command(0x00C3);
  tft_write_data(0x0011);

  // VDVS: VDV Set[10]
  tft_write_command(0x00C4);
  tft_write_data(0x0020);

  // FRCTRL2: Frame Rate control in normal mode
  tft_write_command(0x00C6);
  //tft_write_data(0x000F); // 39Hz which is the slowest setting
  //tft_write_data(0x00); // 58Hz (fastest)
  tft_write_data(0x05); // 50Hz

  // PWCTRL1: Power Control 1
  tft_write_command(0x00D0);
  tft_write_data(0x00A4);
  tft_write_data(0xA1);

  // PVGAMCTRL: Positive Voltage Gamma control
  tft_write_command(0x00E0);
  tft_write_data(0x00D0);
  tft_write_data(0x0000);
  tft_write_data(0x0005);
  tft_write_data(0x000E);
  tft_write_data(0x0015);
  tft_write_data(0x000D);
  tft_write_data(0x0037);
  tft_write_data(0x0043);
  tft_write_data(0x0047);
  tft_write_data(0x0009);
  tft_write_data(0x0015);
  tft_write_data(0x0012);
  tft_write_data(0x0016);
  tft_write_data(0x0019);

  // NVGAMCTRL: Negative Voltage Gamma control
  tft_write_command(0x00E1);
  tft_write_data(0x00D0);
  tft_write_data(0x0000);
  tft_write_data(0x0005);
  tft_write_data(0x000D);
  tft_write_data(0x000C);
  tft_write_data(0x0006);
  tft_write_data(0x002D);
  tft_write_data(0x0044);
  tft_write_data(0x0040);
  tft_write_data(0x000E);
  tft_write_data(0x001C);
  tft_write_data(0x0018);
  tft_write_data(0x0016);
  tft_write_data(0x0019);

  // X address set
  tft_write_command(0x002A);
  tft_write_data(0x0000);
  tft_write_data(0x0000);
  tft_write_data(0x0001);
  tft_write_data(0x003F);

  // Y address set
  tft_write_command(0x002B);
  tft_write_data(0x0000);
  tft_write_data(0x0000);
  tft_write_data(0x0000);
  tft_write_data(0x00EF);

  // Sleep out
  tft_write_command(0x11);

  // Idle mode off
  tft_write_command(0x38);

  // Normal display mode on
  tft_write_command(0x13);

  delay(100);

  tft_fill_area(0, 0, 320, 240, 0);
}

void tft_copy_pixel_buffer(uint8_t line_offset) {
  tft_set_write_area(0, line_offset * 8, 320, 8);
  tft_write_command(0x2C);

  uint16_t i, total;

  total = 320*8/2*3;

  for (i=0; i<total; i+=3) {
    tft_write_data3(
      pixel_buffer[i],
      pixel_buffer[i+1],
      pixel_buffer[i+2]
    );
  }
}
