#define ROWS 30
#define COLS 53
#define TEXTBUFFER_LENGTH ROWS*COLS

#define ESCAPE 0x1b
#define BACKSPACE 0x08 //'\b'
#define CR 0x0D //'\r'
#define LF 0x0A //'\n'
#define VT100_SINGLE_CHARS "=>NODME78Hc"
#define MAX_ESCAPE_STRING 10

extern const char * tb_error;

typedef struct {
    char past[ROWS-1][COLS + 1];
    char current[ROWS*COLS + 1];
    bool dirty[ROWS];
    int length;
    int offset;
    bool is_escape;
    char escape_string[MAX_ESCAPE_STRING + 1];
    // error_code?
} TextBuffer;

typedef struct {
    TextBuffer * tb;
    int before_length;
    int before_y;
    int before_lines_current;
    bool scrolled;
} Mark;

// utils

bool is_letter(char c);
bool is_number(char c);
bool is_escape_end(const char * escape_string);

bool insert_at(char * current, int offset, char c);

int find_x_in_line(int offset, const char * line);
int find_y_in_line(int offset, const char * line);

// TextBuffer

void tb_init(TextBuffer * tb);

bool tb_write(TextBuffer * tb, const char * str);
bool tb_write_char(TextBuffer * tb, char c);

bool tb_handle_escape_string(TextBuffer * tb);
void tb_handle_backspace(TextBuffer * tb);
void tb_handle_cr(TextBuffer * tb);
void tb_handle_lf(TextBuffer * tb);
bool tb_handle_visible_char(TextBuffer * tb, char c);

void tb_clear_line_from_cursor(TextBuffer * tb);
void tb_move_cursor_left(TextBuffer * tb, int num_chars);

int tb_x(TextBuffer * tb);
int tb_y(TextBuffer * tb);

int tb_y_current(TextBuffer * tb);

int tb_num_lines_current(TextBuffer * tb);
int tb_num_lines(TextBuffer * tb);

void tb_clear(TextBuffer * tb);

bool tb_get_line_from_current(TextBuffer * tb, char * destination, int y);
bool tb_get_line_from_past_end(TextBuffer * tb, char * destination, int delta);
bool tb_get_screen_line(TextBuffer * tb, char * destination, int y);

void tb_set_dirty(TextBuffer * tb);
void tb_reset_dirty(TextBuffer * tb);

// Mark

void mark_init(Mark * mark, TextBuffer * tb);
void mark_apply(Mark * mark, TextBuffer * tb);



