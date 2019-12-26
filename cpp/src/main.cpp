#include <Arduino.h>
#include <st7789vi.h>
#include <keyboard.h>
#include <pixel_buffer.h>
#include <text_buffer.h>
#include <color_utils.h>

TextBuffer tb;

HardwareSerial Serial1(PC5, PC4);

int FG_COLOR;

void setup() {
    //FG_COLOR = rgb_to_12bit(1, 0.75, 0);
    FG_COLOR = 4095; // white

    tb_init(&tb);
    tft_init();
    keyboard_init();

    Serial1.begin(115200);

    // hack so you get a prompt even if the target was up before the terminal
    Serial1.write("\r");
}

void loop() {

    int i;
    int length;
    int row;
    int col;
    char line[TEXTBUFFER_LENGTH + 1];
    int line_length;
    int num_bytes;
    int num_lines;
    unsigned char c;

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
        if (tb_error != NULL) {
            Serial1.write(tb_error);
            tb_error = NULL;
        }

        keyboard_poll();
        keyboard_to_vt100();

        length = strlen(key_buffer);
        if (length) {
            Serial1.write(key_buffer);
        }

        num_lines = tb_num_lines(&tb);

        for (row=0; row<ROWS; row++) {
            if (!tb.dirty[row]) {
                continue;
            }
            tb.dirty[row] = false;

            pixel_buffer_clear();

            line[0] = 0;
            if (row < num_lines) {
                tb_get_screen_line(&tb, line, row);
            }
            line_length = strlen(line);

            for (col=0; col<line_length; col++) {
                c = (unsigned char) line[col];
                if (c == 0) {
                    break;
                }
                pixel_buffer_draw_char(col*6, 0, c, FG_COLOR, 0);
            }

            // draw the cursor if it is on this row
            if (row == tb_y(&tb)) {
                pixel_buffer_draw_cursor(tb_x(&tb)*6, 0, FG_COLOR);
            }

            tft_copy_pixel_buffer(row);
        }
    }
}
