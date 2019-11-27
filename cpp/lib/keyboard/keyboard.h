//extern unsigned long last_down[5 * 13 + 1];
//extern unsigned long keys_down[5 * 13 + 1];
//extern byte keys_repeat[5 * 13 + 1];
//extern byte keys_pressed[5 * 13 + 1];

#define KEY_BUFFER_SIZE 10
extern char key_buffer[KEY_BUFFER_SIZE + 1];

//extern const char key_map_normal[66];
//extern const char key_map_shifted[66];

void keyboard_init();
void keyboard_poll();
bool keyboard_to_vt100();
