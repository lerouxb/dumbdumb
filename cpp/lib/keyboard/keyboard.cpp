#include <Arduino.h>
#include "keyboard.h"
//#include <Wire.h>

// this is slightly inefficient because not all 5 rows have 13 keys each and we could have fit escape in there
unsigned long keys_down[5 * 13 + 1];

// this is inefficient because we only need one bit per key
byte keys_repeat[5 * 13 + 1];
byte keys_pressed[5 * 13 + 1];

const unsigned char key_map_normal[] = {
  '1', // 0  1!
  '2', // 1  2@
  '3', // 2  3#
  '4', // 3  4$
  '5', // 4  5%
  '6', // 5  6^
  '7', // 6  7&
  '8', // 7  8*
  '9', // 8  9(
  '0', // 9  0)
  '-', // 10 -=
  '=', // 11 =+
  0, // 12 backspace TODO
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
  0, // 25 enter TODO
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
  0, // 55 left arrow TODO
  0, // 56 right arrow TODO
  0, // 57 NOT USED
  0, // 58 NOT USED
  0, // 59 NOT USED
  0, // 60 NOT USED
  0, // 61 NOT USED
  0, // 62 NOT USED
  0, // 63 NOT USED
  0, // 64 NOT USED
  0  // 65 escape TODO
};

const unsigned char key_map_shifted[] = {
  '!', // 0  1!
  '@', // 1  2@
  '#', // 2  3#
  '$', // 3  4$
  '%', // 4  5%
  '^', // 5  6^
  '&', // 6  7&
  '*', // 7  8*
  '(', // 8  9(
  ')', // 9  0)
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
  0, // 54 space
  0, // 55 left arrow
  0, // 56 right arrow
  0, // 57 NOT USED
  0, // 58 NOT USED
  0, // 59 NOT USED
  0, // 60 NOT USED
  0, // 61 NOT USED
  0, // 62 NOT USED
  0, // 63 NOT USED
  0, // 64 NOT USED
  0  // 65 escape
};

const byte key_modifiers[] = {
  39, // left shift
  51, // right shift
  52, // control
  53  // alt
};

#define KEY_DELAY 1000
#define KEY_REPEAT 250

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
  keys_down[index] = time;
  keys_pressed[index] = 1;
}

void key_up(uint8_t index) {
  keys_down[index] = 0;
  keys_repeat[index] = 0;
}

void check_key(uint8_t index, byte value) {
// TODO: modifiers probably need special handling as repeat and delay isn't relevant there. And we don't want to clear them the moment we first see them later. ie. they don't get "pressed", they just go "down".

  // TODO: this needs a minimum debounce to deal with contact bounce. ie even when the key was released in between.

  if (value == HIGH) {
    unsigned long time = millis();

    if (keys_down[index]) {
      // The first time a key repeats, there's a longer delay (KEY_DELAY). After that we use the shorter one (KEY_REPEAT).
      if (keys_repeat[index]) {
        if (time - keys_down[index] >= KEY_REPEAT) {
          key_press(index, time);
        }
      }
      else {
        if (time - keys_down[index] >= KEY_DELAY) {
          keys_repeat[index] = 1;
          key_press(index, time);
        }
      }
    }
    else {
      // wasn't down before, is now so it is pressed
      // TODO: do we want keydown events too?
      key_press(index, time);
    }
  }
  else {
    // TODO: we don't technically have to check this until we have keyup events
    if (keys_down[index]) {
      key_up(index);
    }
  }
}

void keyboard_poll() {
    for (int r=0; r<5; r++) {
        // TODO: this can be optimised a lot

        digitalWrite(R0, (r == 0) ? HIGH : LOW);
        digitalWrite(R1, (r == 1) ? HIGH : LOW);
        digitalWrite(R2, (r == 2) ? HIGH : LOW);
        digitalWrite(R3, (r == 3) ? HIGH : LOW);
        digitalWrite(R4, (r == 4) ? HIGH : LOW);

        delay(1); // TODO: without this it seems like voltages don't settle quickly enough. Maybe we can make this shorter with delayMicroseconds?

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
    }

    check_key(5*13, digitalRead(ESC));
}
