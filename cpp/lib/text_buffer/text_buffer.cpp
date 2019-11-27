#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "text_buffer.h"

const char * tb_error;

const char UNKNOWN_ESCAPE_END[] = "unknown escape end";
const char ESCAPE_STRING_TOO_LONG[] = "escape string too long";
const char UNKNOWN_ESCAPE_SEQUENCE[] = "unknown escape sequence";
const char TEXT_BUFFER_OVERFLOW[] = "text buffer overflow";
const char UNKNOWN_CHARACTER[] = "unknown character";
const char ROW_OVERFLOW[] = "row overflow";

bool is_letter(char c) {
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
        return true;
    } else {
        return false;
    }
}

bool is_number(char c) {
    if (c >= '0' && c <= '9') {
        return true;
    } else {
        return false;
    }
}

bool is_escape_end(const char * escape_string) {
    int escape_length = strlen(escape_string);

    if (escape_length == 0) {
        return false;
    }

    char first = escape_string[0];
    char last = escape_string[escape_length - 1];

    if (escape_length == 1) {
        if (strchr(VT100_SINGLE_CHARS, first) == NULL) {
            return false;
        } else {
            return true;
        }
    } else if (first == '[') {
        return is_letter(last);
    } else if (first == '(' || first == ')') {
        return is_letter(last) || is_number(last);
    } else if (first == '#') {
        if (escape_length == 2) {
            return true;
        } else {
            return false;
        }
    } else if (is_number(first)) {
        return is_letter(last);
    } else {
        tb_error = UNKNOWN_ESCAPE_END;
        return false;
    }
}

bool insert_at(char * current, int offset, char c) {
    int length = strlen(current);

    if (length == TEXTBUFFER_LENGTH) {
        tb_error = TEXT_BUFFER_OVERFLOW;
        return false;
    }

    if (offset == length) {
        current[offset] = c;
        current[offset+1] = 0;
        return true;
    }

    memcpy(&current[offset+1], &current[offset], length - offset);

    current[offset] = c;
    current[length + 1] = 0;

    return true;
}

void tb_init(TextBuffer * tb) {
    int i;

    tb->length = 0;
    tb->offset = 0;
    tb->current[0] = 0;
    tb->is_escape = false;
    tb->escape_string[0] = 0;

    for (i=0; i<ROWS; i++) {
        tb->past[i][0] = 0;
        tb->dirty[i] = false;
    }
}

bool tb_write(TextBuffer * tb, const char * str) {

    int i;
    int str_length = strlen(str);

    for (i=0; i<str_length; i++) {
        if (!tb_write_char(tb, str[i])) {
            return false;
        }
    }

    return true;
}

bool tb_write_char(TextBuffer * tb, char c) {
    int escape_string_length;

    if (tb->is_escape) {
        escape_string_length = strlen(tb->escape_string);

        if (escape_string_length == MAX_ESCAPE_STRING) {
            tb_error = ESCAPE_STRING_TOO_LONG;
            return false;
        }

        tb->escape_string[escape_string_length] = c;
        tb->escape_string[escape_string_length + 1] = 0;

        if (is_escape_end(tb->escape_string)) {
            bool result = tb_handle_escape_string(tb);

            tb->is_escape = false;
            tb->escape_string[0] = 0;
            return result;
        }

    } else if (c == ESCAPE) {
        tb->is_escape = true;

    } else if (c == BACKSPACE) {
        tb_handle_backspace(tb);

    } else if (c == CR) {
        tb_handle_cr(tb);

    } else if (c == LF) {
        tb_handle_lf(tb);

    } else if (c < 32 || c > 126) {
        // unknown character
        tb_error = UNKNOWN_CHARACTER;
        return false;

    } else {
        return tb_handle_visible_char(tb, c);
    }

    return true;
}

bool tb_handle_escape_string(TextBuffer * tb) {

    char first = tb->escape_string[0];
    int length = strlen(tb->escape_string);
    char last = tb->escape_string[length - 1];

    if (first == '[') {
        if (length == 2 && last == 'K') {
            tb_clear_line_from_cursor(tb);
            return true;
        }
        if (last == 'D') {
            int num_chars = atoi(&tb->escape_string[1]);
            tb_move_cursor_left(tb, num_chars);
            return true;
        }
    }

    // nothing else is handled yet
    tb_error = UNKNOWN_ESCAPE_SEQUENCE;
    return false;
}

void tb_handle_backspace(TextBuffer * tb) {
    tb_move_cursor_left(tb, 1);
}

void tb_handle_cr(TextBuffer * tb) {
    // we don't handle CR outside of CRLF for now
}

void tb_handle_lf(TextBuffer * tb) {
    int i;

    Mark mark;
    mark_init(&mark, tb);

    // could be CRLF or LF
    int num_lines = tb_num_lines(tb);

    for (i=0; i<num_lines; i++) {
        tb_get_screen_line(tb, tb->past[i], i);
    }

    tb->length = num_lines;
    tb->offset = 0;
    tb->current[0] = 0;

    mark_apply(&mark, tb);
}

bool tb_handle_visible_char(TextBuffer * tb, char c) {
    Mark mark;
    mark_init(&mark, tb);

    if (!insert_at(tb->current, tb->offset, c)) {
        return false;
    }

    tb->offset += 1;
    mark_apply(&mark, tb);

    return true;
}

void tb_clear_line_from_cursor(TextBuffer * tb) {
    Mark mark;
    mark_init(&mark, tb);

    tb->current[tb->offset] = 0;

    mark_apply(&mark, tb);
}

void tb_move_cursor_left(TextBuffer * tb, int num_chars) {
    if (tb->offset < 1) {
        return;
    }

    Mark mark;
    mark_init(&mark, tb);

    tb->offset = tb->offset - num_chars;

    if (tb->offset < 0) {
        tb->offset = 0;
    }

    mark_apply(&mark, tb);
}

int tb_x(TextBuffer * tb) {
    return tb->offset % COLS;
}

int tb_y(TextBuffer * tb) {
    int current_y = tb_y_current(tb);
    int current_num_lines = tb_num_lines_current(tb);
    int lines_from_end = current_num_lines - current_y - 1;
    int num_lines = tb_num_lines(tb);

    return num_lines - lines_from_end - 1;
}

int tb_y_current(TextBuffer * tb) {
    return tb->offset / COLS;
}

int tb_num_lines_current(TextBuffer * tb) {

    int length = strlen(tb->current);
    int total = ceil((double) length / COLS);

    // if the cursor is alone on a line, add one
    if (tb->offset == length && tb->offset % COLS == 0) {
        total++;
    }

    return total;
}

int tb_num_lines(TextBuffer * tb) {
    // first add the hard-wrapped lines in the current one
    int total = tb_num_lines_current(tb);

    // then add the number of buffered lines
    total += tb->length;

    // there can't be more lines on the screen than what will fit
    if (total > ROWS) {
        return ROWS;
    }

    return total;
}

void tb_clear(TextBuffer * tb) {
    int i;

    tb_init(tb);

    for (i=0; i<ROWS; i++) {
        tb->dirty[i] = true;
    }

    tb_error = NULL;
}

bool tb_get_line_from_current(TextBuffer * tb, char * destination, int y) {
    // copy up to COLS from y*COLS
    int length = strlen(tb->current);

    if (y*COLS > length) {
        tb_error = ROW_OVERFLOW;
        return false;
    }

    int amount;

    if (y*COLS + COLS >= length) {
        amount = length - y*COLS;
    } else {
        amount = COLS;
    }

    memcpy(destination, &tb->current[y*COLS], amount);
    destination[amount] = 0;

    return true;
}

bool tb_get_line_from_past_end(TextBuffer * tb, char * destination, int delta) {
    // copy the delta'th last line. so zero is the last one, 1 is the second last one and so on.
    int index = tb->length - delta - 1;
    int length = strlen(tb->past[index]);

    if (index < 0 || index >= tb->length) {
        tb_error = ROW_OVERFLOW;
        return false;
    }

    memcpy(destination, tb->past[index], length + 1);

    return true;
}

bool tb_get_screen_line(TextBuffer * tb, char * destination, int y) {
    // do nothing if it isn't on screen
    int num_lines = tb_num_lines(tb);

    if (y >= num_lines) {
        tb_error = ROW_OVERFLOW;
        return false;
    }

    int current_num_lines = tb_num_lines_current(tb);

    // figure out if it falls inside current
    int current_start = num_lines - current_num_lines;
    if (y >= current_start) {
        // the line is in current
        tb_get_line_from_current(tb, destination, y - current_start);
    }
    else {
        // the line is in the past lines
        tb_get_line_from_past_end(tb, destination, current_start - y - 1);
    }

    return true;
}

void tb_reset_dirty(TextBuffer * tb) {
    int i;

    for (i=0; i<ROWS; i++) {
        tb->dirty[i] = false;
    }
}

void mark_init(Mark * mark, TextBuffer * tb) {
    mark->before_length = tb_num_lines(tb);
    mark->before_y = tb_y(tb);
}

void mark_apply(Mark * mark, TextBuffer * tb) {
    int i;
    int after_length = tb_num_lines(tb);
    int after_y;

    if (after_length == mark->before_length) {
        after_y = tb_y(tb);
        tb->dirty[mark->before_y] = true;
        tb->dirty[after_y] = true;
    } else {
        // This can be optimised so it doesn't redraw the entire screen every
        // time a new line appears, but that will only help in cases where it
        // doesn't scroll yet.
        for (i=0; i<ROWS; i++) {
            tb->dirty[i] = true;
        }
    }
}
