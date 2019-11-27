#include <Arduino.h>
#include "keyboard.h"
//#include <Wire.h>

#define R0 PC11
#define R1 PC12
#define R2 PC13
#define R3 PC14
#define R4 PC15
#define C0 PF1
#define C1 PC0
#define C2 PC1
#define C3 PC2
#define C4 PC3
#define C5 PA0
#define C6 PA1
#define C7 PA2
#define C8 PA3
#define C9 PA4
#define C10 PA5
#define C11 PA6
#define C12 PA7
#define ESC PF0

//#define KEY_BACKSPACE 12
//#define KEY_ENTER 25
#define KEY_LEFT_SHIFT 39
#define KEY_RIGHT_SHIFT 51
#define KEY_CONTROL 52
#define KEY_ALT 53
//#define KEY_LEFT_ARROW 55
//#define KEY_RIGHT_ARROW 56
//#define KEY_ESCAPE 65


#define KEY_DEBOUNCE 50
#define KEY_DELAY 1000
#define KEY_REPEAT 150

// this is slightly inefficient because not all 5 rows have 13 keys each and we could have fit escape in there
unsigned long last_down[5 * 13 + 1];
unsigned long keys_down[5 * 13 + 1];

// this is inefficient because we only need one bit per key
bool keys_repeat[5 * 13 + 1];
bool keys_pressed[5 * 13 + 1];

char key_buffer[KEY_BUFFER_SIZE + 1];

const char key_map_normal[] = {
    '1', // 0    1!
    '2', // 1    2@
    '3', // 2    3#
    '4', // 3    4$
    '5', // 4    5%
    '6', // 5    6^
    '7', // 6    7&
    '8', // 7    8*
    '9', // 8    9(
    '0', // 9    0)
    '-', // 10 -=
    '=', // 11 =+
    0x08, // 12 backspace
    'q', // 13 q
    'w', // 14 w
    'e', // 15 e
    'r', // 16 r
    't', // 17 t
    'y', // 18 y
    'u', // 19 u
    'i', // 20 i
    'o', // 21 o
    'p', // 22 p
    '[', // 23 [{
    ']', // 24 ]}
    0x0D, // 25 enter (line-feed)
    'a', // 26 a
    's', // 27 s
    'd', // 28 d
    'f', // 29 f
    'g', // 30 g
    'h', // 31 h
    'j', // 32 j
    'k', // 33 k
    'l', // 34 l
    ';', // 35 ;:
    '\'', // 36 '"
    '\\', // 37 \|
    0, // 38 NOT USED
    0, // 39 left shift TODO
    'z', // 40 z
    'x', // 41 x
    'c', // 42 c
    'v', // 43 v
    'b', // 44 b
    'n', // 45 n
    'm', // 46 m
    ',', // 47 ,<
    '.', // 48 .>
    '/', // 49 /?
    '`', // 50 `~
    0, // 51 right shift TODO
    0, // 52 control TODO
    0, // 53 alt TODO
    ' ', // 54 space
    0x02, // 55 left arrow
    0x06, // 56 right arrow
    0, // 57 NOT USED
    0, // 58 NOT USED
    0, // 59 NOT USED
    0, // 60 NOT USED
    0, // 61 NOT USED
    0, // 62 NOT USED
    0, // 63 NOT USED
    0, // 64 NOT USED
    0    // 65 escape TODO
};

const char key_map_shifted[] = {
    '!', // 0    1!
    '@', // 1    2@
    '#', // 2    3#
    '$', // 3    4$
    '%', // 4    5%
    '^', // 5    6^
    '&', // 6    7&
    '*', // 7    8*
    '(', // 8    9(
    ')', // 9    0)
    '_', // 10 -=
    '+', // 11 =+
    0, // 12 backspace
    'Q', // 13 q
    'W', // 14 w
    'E', // 15 e
    'R', // 16 r
    'T', // 17 t
    'Y', // 18 y
    'U', // 19 u
    'I', // 20 i
    'O', // 21 o
    'P', // 22 p
    '{', // 23 [{
    '}', // 24 ]}
    0, // 25 enter
    'A', // 26 a
    'S', // 27 s
    'D', // 28 d
    'F', // 29 f
    'G', // 30 g
    'H', // 31 h
    'J', // 32 j
    'K', // 33 k
    'L', // 34 l
    ':', // 35 ;:
    '"', // 36 '"
    '|', // 37 \|
    0, // 38 NOT USED
    0, // 39 left shift
    'Z', // 40 z
    'X', // 41 x
    'C', // 42 c
    'V', // 43 v
    'B', // 44 b
    'N', // 45 n
    'M', // 46 m
    '<', // 47 ,<
    '>', // 48 .>
    '?', // 49 /?
    '~', // 50 `~
    0, // 51 right shift
    0, // 52 control
    0, // 53 alt
    0x09, // 54 shift-space == tab
    0x10, // 55 shift left arrow == up
    0x0D, // 56 shift right arrow == down
    0, // 57 NOT USED
    0, // 58 NOT USED
    0, // 59 NOT USED
    0, // 60 NOT USED
    0, // 61 NOT USED
    0, // 62 NOT USED
    0, // 63 NOT USED
    0, // 64 NOT USED
    0    // 65 escape
};


/*
void requestEvent() {
    Wire.write(keys, 8);
    for (int i=0; i<8; ++i) {
        keys[i] = 0;
    }
}
*/

void keyboard_init() {
    pinMode(R0, OUTPUT);
    pinMode(R1, OUTPUT);
    pinMode(R2, OUTPUT);
    pinMode(R3, OUTPUT);
    pinMode(R4, OUTPUT);

    pinMode(C0, INPUT_PULLDOWN);
    pinMode(C1, INPUT_PULLDOWN);
    pinMode(C2, INPUT_PULLDOWN);
    pinMode(C3, INPUT_PULLDOWN);
    pinMode(C4, INPUT_PULLDOWN);
    pinMode(C5, INPUT_PULLDOWN);
    pinMode(C6, INPUT_PULLDOWN);
    pinMode(C7, INPUT_PULLDOWN);
    pinMode(C8, INPUT_PULLDOWN);
    pinMode(C9, INPUT_PULLDOWN);
    pinMode(C10, INPUT_PULLDOWN);
    pinMode(C11, INPUT_PULLDOWN);
    pinMode(C12, INPUT_PULLDOWN);

    pinMode(ESC, INPUT_PULLDOWN);

    //Wire.begin();
    //Wire.begin(8);
    //Wire.onRequest(requestEvent);
}


void key_press(uint8_t index, unsigned long time) {

    last_down[index] = time;
    keys_down[index] = time;
    keys_pressed[index] = true;
}


void key_up(uint8_t index) {

    keys_down[index] = 0;
    keys_repeat[index] = false;
}


bool is_modifier(uint8_t index) {

    if (index == KEY_LEFT_SHIFT || index == KEY_RIGHT_SHIFT || index == KEY_CONTROL ||  index == KEY_ALT) {
        return true;
    }

    return false;
}


bool is_ctrlable(char c) {
    if (c == 'a' || c == 'b' || c == 'c' || c == 'd' || c == 'e' || c == 'f' || c == 'k' || c == 'n' || c == 'p' || c == 'u') {
        return true;
    }

    return false;
}

char ctrlify(char c) {
    return c - 'a' + 1;
}


void check_key(uint8_t index, byte value) {

    unsigned long time = millis();

    // Modifiers need special handling as repeat and delay isn't relevant there. ie. they don't get "pressed", they just go "down". There's also no debounce involved.
    if (is_modifier(index)) {
        if (value == HIGH) {
            keys_down[index] = 1;
        }
        else {
            keys_down[index] = 0;
        }

        return;
    }

    if (value == HIGH) {
        // Minimum debounce to deal with contact bounce.
        if (last_down[index] && (time - last_down[index] < KEY_DEBOUNCE)) {
            return;
        }

        if (keys_down[index]) {
            // The first time a key repeats, there's a longer delay (KEY_DELAY). After that we use the shorter one (KEY_REPEAT).
            if (keys_repeat[index]) {
                if (time - keys_down[index] >= KEY_REPEAT) {
                    key_press(index, time);
                }
            }
            else {
                if (time - keys_down[index] >= KEY_DELAY) {
                    keys_repeat[index] = true;
                    key_press(index, time);
                }
            }
        }
        else {
            // wasn't down before, is now so it is pressed
            key_press(index, time);
        }
    }
    else {
        if (keys_down[index]) {
            key_up(index);
        }
    }
}


void keyboard_poll() {

    int r;
    int pin;

    for (r=0; r<5; r++) {
        // TODO: this can be optimised a lot

        if (r == 0) {
            pin = R0;
        } else if (r == 1) {
            pin = R1;
        } else if (r == 2) {
            pin = R2;
        } else if (r == 3) {
            pin = R3;
        } else {
            pin = R4;
        }

        /*
        digitalWrite(R0, (r == 0) ? HIGH : LOW);
        digitalWrite(R1, (r == 1) ? HIGH : LOW);
        digitalWrite(R2, (r == 2) ? HIGH : LOW);
        digitalWrite(R3, (r == 3) ? HIGH : LOW);
        digitalWrite(R4, (r == 4) ? HIGH : LOW);
        */
        digitalWrite(pin, HIGH);

        delay(1); // TODO: without this it seems like voltages don't settle quickly enough. Maybe we can make this shorter with delayMicroseconds?

        // Might be better to have interrupts on all these pins and do the checking in there?

        check_key(r*13 + 0, digitalRead(C0));
        check_key(r*13 + 1, digitalRead(C1));
        check_key(r*13 + 2, digitalRead(C2));
        check_key(r*13 + 3, digitalRead(C3));
        check_key(r*13 + 4, digitalRead(C4));
        check_key(r*13 + 5, digitalRead(C5));
        check_key(r*13 + 6, digitalRead(C6));
        check_key(r*13 + 7, digitalRead(C7));
        check_key(r*13 + 8, digitalRead(C8));
        check_key(r*13 + 9, digitalRead(C9));
        check_key(r*13 + 10, digitalRead(C10));
        check_key(r*13 + 11, digitalRead(C11));
        check_key(r*13 + 12, digitalRead(C12));

        digitalWrite(pin, LOW);
    }

    check_key(5*13, digitalRead(ESC));
}

bool keyboard_to_vt100() {

    uint8_t i;
    int buffer_index = 0;
    key_buffer[0] = 0;
    char printable;

    bool is_ctrl = keys_down[KEY_CONTROL];
    bool is_alt = keys_down[KEY_ALT];
    bool is_shift = keys_down[KEY_LEFT_SHIFT] || keys_down[KEY_RIGHT_SHIFT];

    // ignore alt-* for now
    if (is_alt) {
        for (i=0; i<5*13+1; i++) {
            keys_pressed[i] = false;
        }
        return true;
    }

    for (i=0; i<5*13+1; i++) {
        if (is_modifier(i)) {
            // you can't press a modifier anyway
            continue;
        }

        if (!keys_pressed[i]) {
            continue;
        }

        // Don't allow more but since we exit before clearing it means we should be able to get it next time.
        if (buffer_index == KEY_BUFFER_SIZE) {
            return false;
        }

        keys_pressed[i] = false;
        printable = is_shift ? key_map_shifted[i] : key_map_normal[i];

        if (!printable) {
            continue;
        }

        if (is_ctrl) {
            if (is_ctrlable(printable)) {
                // control char that we support
                key_buffer[buffer_index] = ctrlify(printable);
                buffer_index += 1;
                key_buffer[buffer_index] = 0;
            }
        }
        else {
            // normal printable character
            key_buffer[buffer_index] = printable;
            buffer_index += 1;
            key_buffer[buffer_index] = 0;
        }
    }

    return true;
}
