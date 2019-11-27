#include <Arduino.h>
#include <st7789vi.h>
#include <keyboard.h>
#include <pixel_buffer.h>
#include <text_buffer.h>
#include <color_utils.h>

//uint16_t tileColor = 0;
//uint16_t xTile = 0;
//uint16_t yTile = 0;
//uint16_t nextChar = 0;

TextBuffer tb;

HardwareSerial Serial1(PC5, PC4);

void setup() {
    tb_init(&tb);
    tft_init();
    keyboard_init();

    Serial1.begin(115200);
    //Serial1.println("begin");
}


//uint16_t row = 0;
//uint16_t col = 0;

/*
void debug_key_buffer() {

    int i;
    int length;

    length = strlen(key_buffer);

    if (length) {
        //Serial1.write(key_buffer);

        for (i=0; i<length; i++) {
            pixel_buffer_draw_char(col*6, 0, (unsigned char) key_buffer[i], 4095, 0);
            col++;

            if (col > 52) {
                tft_copy_pixel_buffer(row);
                pixel_buffer_clear();
                row++;
                col = 0;
            }
            if (row > 29) {
                row = 0;
            }
        }

        // cursor
        pixel_buffer_draw_cursor(col*6, 0, 4095);
        tft_copy_pixel_buffer(row);
    }
}
*/

void loop() {

    int length;
    int row;
    int col;
    char line[TEXTBUFFER_LENGTH + 1];
    int line_length;
    int num_bytes;

    // prioritise reading the serial buffer above all else
    length = Serial1.available();
    if (length > 0) {
        while (length > 0) {
            num_bytes = Serial1.readBytes(line, length);
            line[num_bytes] = 0;
            tb_write(&tb, line);
            length = Serial1.available();
        }
    }
    else {
        keyboard_poll();
        keyboard_to_vt100();

        length = strlen(key_buffer);
        if (length) {
            Serial1.write(key_buffer);
        }

        for (row=0; row<ROWS; row++) {
            if (!tb.dirty[row]) {
                continue;
            }
            tb.dirty[row] = false;

            pixel_buffer_clear();

            line[0] = 0;
            tb_get_screen_line(&tb, line, row);
            line_length = strlen(line);

            for (col=0; col<line_length; col++) {
                pixel_buffer_draw_char(col*6, 0, (unsigned char) line[col], 4095, 0);
            }

            // draw the cursor if it is on this row
            if (row == tb_y(&tb)) {
                pixel_buffer_draw_cursor(tb_x(&tb)*6, 0, 4095);
            }

            tft_copy_pixel_buffer(row);
        }
    }

    /*
    // debug

    bool is_control = keys_down[KEY_CONTROL];
    bool is_alt = keys_down[KEY_ALT];

    // TODO: deal with these
    if (is_control || is_alt) {
        return;
    }

    bool is_shift = keys_down[KEY_LEFT_SHIFT] || keys_down[KEY_RIGHT_SHIFT];

    int i;
    unsigned char printable;

    for (i=0; i<5*13+1; i++) {
        if (keys_pressed[i]) {
            keys_pressed[i] = 0;
            printable = is_shift ? key_map_shifted[i] : key_map_normal[i];
            if (printable) {
                Serial1.print(is_control);
                Serial1.print(is_alt);
                Serial1.write(printable);
                pixel_buffer_draw_char(col*6, 0, printable, 4095, 0);
                tft_copy_pixel_buffer(row);
            }
            else {
                // shifted non-printable things don't make sense yet. except maybe arrows?
                if (is_shift) {
                    continue;
                }
                Serial1.print("<");
                Serial1.print(i);
                Serial1.print(">");

                pixel_buffer_draw_char(col*6, 0, '?', 4095, 0);
            }

            tft_copy_pixel_buffer(row);

            col++;
            if (col > 52) {
                pixel_buffer_clear();
                row++;
                col = 0;
            }
            if (row > 29) {
                row = 0;
            }

            // TODO: we're most likely still on the same row as before so in most cases we could have just drawn once
            pixel_buffer_draw_cursor(col*6, 0, 4095);
            tft_copy_pixel_buffer(row);
        }
    }
    */

    /*
    for (int r=0; r<5; ++r) {
        Serial1.print(keys[r]);
    }
    Serial1.println("");
    Serial1.print("ESC: ");
    Serial1.println(esc);
    delay(1000);
    */
    /*
    uint16_t i, x, y, row, col;

    if (nextChar > 255) {
        return;
    }

    unsigned long time = micros();
    for (row=0; row<30; row++) {
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
    */

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
        tft_fill_area(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, color);
    }
    */

    /*
    tft_fill_area(xTile, yTile, 16, 16, tileColor);

    xTile += 16;
    if (xTile >= SCREEN_WIDTH) {
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
        tft_fill_area(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, color);
    }
    Serial1.println(micros() - time);
    */

    /*
    uint32_t color = rgbTo12bit(0.0, 0.0, 1.0);
    Serial1.println(color);
    tft_fill_area(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, color);
    */
}
