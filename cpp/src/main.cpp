#include <Arduino.h>
#include <st7789vi.h>
#include <keyboard.h>
#include <pixel_buffer.h>
#include <color_utils.h>

//uint16_t tileColor = 0;
//uint16_t xTile = 0;
//uint16_t yTile = 0;
uint16_t nextChar = 0;

HardwareSerial Serial1(PC5, PC4);

void setup() {
  tft_init();
  keyboard_init();

  Serial1.begin(115200);
  Serial1.println("begin");
}

void loop() {
  /*
  keyboard_poll();

  // debug
  for (int r=0; r<5; ++r) {
    Serial1.print(keys[r]);
  }
  Serial1.println("");
  Serial1.print("ESC: ");
  Serial1.println(esc);
  delay(1000);
  */
  uint16_t i, x, y, row, col;

  if (nextChar > 255) {
    return;
  }

  unsigned long time = micros();
  for (row=0; row<30; row++) {
    /*
    for (i=0; i<320*8/2*3; i++) {
      pixel_buffer[i] = 0;
    }
    */

    /*
    for (x=0; x<320; x++) {
      for (y=0; y<8; y++) {
        pixel_buffer_draw_pixel(x, y, rgb_to_12bit(x/320.0, x/320.0, 0));
      }
    }
    */
    for (col=0; col<53; col++) {
      pixel_buffer_draw_char(col*6, 0, nextChar, 4095, 0);
      nextChar++;

      if (nextChar > 255) {
        //nextChar = 0;

        Serial1.println(micros() - time);
        return;
      }
    }

    tft_copy_pixel_buffer(row);
  }

/*
  Serial1.print("DC: ");
  Serial1.print(digitalRead(DC));
  Serial1.print(' ');

  Serial1.print("nRD: ");
  Serial1.print(digitalRead(nRD));
  Serial1.print(' ');

  Serial1.print("nWR: ");
  Serial1.print(digitalRead(nWR));
  Serial1.print(' ');

  Serial1.println();
  delay(1000);
  */
  /*
  uint32_t color = 0;
  for (int i=0; i<255; i++) {
    color = i;
    color |= i << 8;
    color |= i << 16;
    tft_fill_area(0, 0, 320, 240, color);
  }
  */

  /*
  tft_fill_area(xTile, yTile, 16, 16, tileColor);

  xTile += 16;
  if (xTile >= 320) {
    xTile = 0;
    yTile += 16;
    if (yTile >= 240) {
      yTile = 0;
    }
  }
  */

  /*
  tileColor++;
  if (tileColor >= 4096) {
    tileColor = 0;
  }
  */

  /*
  unsigned long time;
  uint32_t color = 0;
  time = micros();
  for (uint32_t i=0; i<16; i++) {
    color = i;
    color |= i << 4;
    color |= i << 8;
    tft_fill_area(0, 0, 320, 240, color);
  }
  Serial1.println(micros() - time);
  */

  /*
  uint32_t color = rgbTo12bit(0.0, 0.0, 1.0);
  Serial1.println(color);
  tft_fill_area(0, 0, 320, 240, color);
  */
}
