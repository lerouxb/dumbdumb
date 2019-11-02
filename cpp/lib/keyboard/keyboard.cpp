#include <Arduino.h>
#include "keyboard.h"
//#include <Wire.h>

// this is slightly inefficient because not all 5 rows have 13 keys each and we could have fit escape in there
unsigned long keys_down[5 * 13 + 1];
// this is inefficient because we only need one bit per key
byte keys_pressed[5 * 13 + 1];

#define KEY_REPEAT 200

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
}

void check_key(uint8_t index, byte value) {
  if (value == HIGH) {
    unsigned long time = millis();

    // TODO: we probably don't even need this check if we only have presses and no keydown events as time - 0 will also be >= KEY_REPEAT
    if (keys_down[index]) {
      // ignore unless it has been long enough to repeat
      if (time - keys_down[index] >= KEY_REPEAT) {
        key_press(index, time);
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
