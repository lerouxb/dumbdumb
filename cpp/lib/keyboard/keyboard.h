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

extern unsigned long keys_down[5 * 13 + 1];
extern byte keys_repeat[5 * 13 + 1];
extern byte keys_pressed[5 * 13 + 1];

extern const unsigned char key_map_normal[66];
extern const unsigned char key_map_shifted[66];
extern const byte key_modifiers[4];

void keyboard_init();
void keyboard_poll();
