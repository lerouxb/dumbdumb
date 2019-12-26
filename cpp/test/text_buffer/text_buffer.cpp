#include <stdio.h>
#include <string.h>
#include <unity.h>
#include <text_buffer.h>

const char * KNOWN_ESCAPE_SEQUENCES[93] = {

    // special vars Line, Value, Column are all positive ints

    "Esc[20h", // Set new line mode
    "Esc[?1h", // Set cursor key to application
    //"none", // Set ANSI (versus VT52)
    "Esc[?3h", // Set number of columns to 132
    "Esc[?4h", // Set smooth scrolling
    "Esc[?5h", // Set reverse video on tb
    "Esc[?6h", // Set origin to relative
    "Esc[?7h", // Set auto-wrap mode
    "Esc[?8h", // Set auto-repeat mode
    "Esc[?9h", // Set interlacing mode

    "Esc[20l", // Set line feed mode
    "Esc[?1l", // Set cursor key to cursor
    "Esc[?2l", // Set VT52 (versus ANSI)
    "Esc[?3l", // Set number of columns to 80
    "Esc[?4l", // Set jump scrolling
    "Esc[?5l", // Set normal video on tb
    "Esc[?6l", // Set origin to absolute
    "Esc[?7l", // Reset auto-wrap mode
    "Esc[?8l", // Reset auto-repeat mode
    "Esc[?9l", // Reset interlacing mode

    "Esc=", // Set alternate keypad mode
    "Esc>", // Set numeric keypad mode

    "Esc(A", // Set United Kingdom G0 character set
    "Esc)A", // Set United Kingdom G1 character set
    "Esc(B", // Set United States G0 character set
    "Esc)B", // Set United States G1 character set
    "Esc(0", // Set G0 special chars. & line set
    "Esc)0", // Set G1 special chars. & line set
    "Esc(1", // Set G0 alternate character ROM
    "Esc)1", // Set G1 alternate character ROM
    "Esc(2", // Set G0 alt char ROM and spec. graphics
    "Esc)2", // Set G1 alt char ROM and spec. graphics

    "EscN", // Set single shift 2
    "EscO", // Set single shift 3

    "Esc[m", // Turn off character attributes
    "Esc[0m", // Turn off character attributes
    "Esc[1m", // Turn bold mode on
    "Esc[2m", // Turn low intensity mode on
    "Esc[4m", // Turn underline mode on
    "Esc[5m", // Turn blinking mode on
    "Esc[7m", // Turn reverse video on
    "Esc[8m", // Turn invisible text mode on

    "Esc[222;222r", // Set top and bottom lines of a window

    "Esc[111A", // Move cursor up n lines
    "Esc[111B", // Move cursor down n lines
    "Esc[111C", // Move cursor right n lines
    "Esc[111D", // Move cursor left n lines
    "Esc[H", // Move cursor to upper left corner
    "Esc[;H", // Move cursor to upper left corner
    "Esc[222;333H", // Move cursor to tb location v,h
    "Esc[f", // Move cursor to upper left corner
    "Esc[;f", // Move cursor to upper left corner
    "Esc[222;333f", // Move cursor to tb location v,h
    "EscD", // Move/scroll window up one line
    "EscM", // Move/scroll window down one line
    "EscE", // Move to next line
    "Esc7", // Save cursor position and attributes
    "Esc8", // Restore cursor position and attributes

    "EscH", // Set a tab at the current column
    "Esc[g", // Clear a tab at the current column
    "Esc[0g", // Clear a tab at the current column
    "Esc[3g", // Clear all tabs

    "Esc#3", // Double-height letters, top half
    "Esc#4", // Double-height letters, bottom half
    "Esc#5", // Single width, single height letters
    "Esc#6", // Double width, single height letters

    "Esc[K", // Clear line from cursor right
    "Esc[0K", // Clear line from cursor right
    "Esc[1K", // Clear line from cursor left
    "Esc[2K", // Clear entire line

    "Esc[J", // Clear tb from cursor down
    "Esc[0J", // Clear tb from cursor down
    "Esc[1J", // Clear tb from cursor up
    "Esc[2J", // Clear entire tb

    "Esc5n", // Device status report
    "Esc0n", // Response: terminal is OK
    "Esc3n", // Response: terminal is not OK

    "Esc6n", // Get cursor position
    "Esc222;333R", // Response: cursor is at v,h

    "Esc[c", // Identify what terminal type
    "Esc[0c", // Identify what terminal type (another)
    "Esc[?1;1110c", // Response: terminal type code n

    "Escc", // Reset terminal to initial state

    "Esc#8", // TextBuffer alignment display
    "Esc[2;1y", // Confidence power up test
    "Esc[2;2y", // Confidence loopback test
    "Esc[2;9y", // Repeat power up test
    "Esc[2;10y", // Repeat loopback test

    "Esc[0q", // Turn off all four leds
    "Esc[1q", // Turn on LED #1
    "Esc[2q", // Turn on LED #2
    "Esc[3q", // Turn on LED #3
    "Esc[4q"  // Turn on LED #4
};


void setlength(char * string, int length, char c) {
    int i;

    for (i=0; i<length; i++) {
        string[i] = c;
    }
    string[length] = 0;
    TEST_ASSERT_EQUAL(length, strlen(string));
}

void setlength(char * string, int length) {
    setlength(string, length, 'x');
}

void test_tb_init() {
    int i;

    TextBuffer tb;

    tb_init(&tb);
    TEST_ASSERT_EQUAL(0, tb.length);
    TEST_ASSERT_EQUAL(0, tb.offset);
    TEST_ASSERT_EQUAL(0, strlen(tb.current));
    TEST_ASSERT_EQUAL(0, tb.is_escape);
    TEST_ASSERT_EQUAL(0, strlen(tb.escape_string));

    for (i=0; i<ROWS; i++) {
        if (i<ROWS-1) {
            TEST_ASSERT_EQUAL(0, strlen(tb.past[i]));
        }
        TEST_ASSERT_EQUAL(0, tb.dirty[i]);
    }
}

void test_is_letter() {

    TEST_ASSERT_TRUE(is_letter('a'));
    TEST_ASSERT_TRUE(is_letter('z'));
    TEST_ASSERT_TRUE(is_letter('A'));
    TEST_ASSERT_TRUE(is_letter('Z'));

    TEST_ASSERT_FALSE(is_letter('0'));
    TEST_ASSERT_FALSE(is_letter('9'));
    TEST_ASSERT_FALSE(is_letter('-'));
}

void test_is_number() {

    TEST_ASSERT_TRUE(is_number('0'));
    TEST_ASSERT_TRUE(is_number('9'));

    TEST_ASSERT_FALSE(is_number('a'));
    TEST_ASSERT_FALSE(is_number('z'));
    TEST_ASSERT_FALSE(is_number('A'));
    TEST_ASSERT_FALSE(is_number('Z'));
    TEST_ASSERT_FALSE(is_number('-'));
}

void test_is_escape_end() {

    int i;
    const char * sequence;
    int sequence_length;
    char substring[100];

    for (i=0; i<92; i++) {
        sequence = KNOWN_ESCAPE_SEQUENCES[i] + 3; // skip Esc
        //printf("%s (full)\n", sequence);
        sequence_length = strlen(sequence);
        TEST_ASSERT_TRUE(is_escape_end(sequence));

        if (sequence_length > 1) {
            // make an incomplete one by making a sequence one char shorter
            memcpy(substring, sequence, sequence_length - 1);
            substring[sequence_length - 1] = 0;

            //printf("%s (substr)\n", substring);
            TEST_ASSERT_FALSE(is_escape_end(substring));
        }
    }
}

void test_insert_at() {

    char string[TEXTBUFFER_LENGTH + 1];

    insert_at(string, 0, 'a');
    TEST_ASSERT_EQUAL_STRING("a", string);

    insert_at(string, 0, 'b');
    TEST_ASSERT_EQUAL_STRING("b", string);

    insert_at(string, 1, 'c');
    TEST_ASSERT_EQUAL_STRING("bc", string);

    insert_at(string, 1, '1');
    TEST_ASSERT_EQUAL_STRING("b1", string);

    // TODO: what if the buffer is full?
}

void test_tb_num_lines() {
    int i;

    TextBuffer tb;

    tb_init(&tb);
    TEST_ASSERT_EQUAL(1, tb_num_lines(&tb));

    tb.length = 4;
    TEST_ASSERT_EQUAL(5, tb_num_lines(&tb));

    tb.length = ROWS;
    TEST_ASSERT_EQUAL(ROWS, tb_num_lines(&tb));

    setlength(tb.current, TEXTBUFFER_LENGTH);
    TEST_ASSERT_EQUAL(ROWS, tb_num_lines(&tb));

    tb.length = 0;
    TEST_ASSERT_EQUAL(ROWS, tb_num_lines(&tb));

    setlength(tb.current, COLS);
    TEST_ASSERT_EQUAL(1, tb_num_lines(&tb));

    setlength(tb.current, COLS);
    tb.offset = COLS;
    TEST_ASSERT_EQUAL(2, tb_num_lines(&tb));
}

void test_tb_x() {
    TextBuffer tb;

    tb_init(&tb);
    TEST_ASSERT_EQUAL(0, tb_x(&tb));

    setlength(tb.current, 1);
    tb.offset = 1;
    TEST_ASSERT_EQUAL(1, tb_x(&tb));

    setlength(tb.current, COLS);
    tb.offset = COLS;
    TEST_ASSERT_EQUAL(0, tb_x(&tb));
}

void test_tb_y() {
    TextBuffer tb;

    tb_init(&tb);
    TEST_ASSERT_EQUAL(0, tb_y(&tb));

    setlength(tb.current, COLS);
    tb.offset = COLS;
    TEST_ASSERT_EQUAL(1, tb_y(&tb));

    tb.length = ROWS;
    TEST_ASSERT_EQUAL(ROWS-1, tb_y(&tb));
}

void test_tb_get_line_from_current() {

    int i;

    TextBuffer tb;
    tb_init(&tb);
    char target[COLS + 1];
    char expected[COLS + 1];

    for (i=0; i<COLS+1; i++) {
        target[i] = 'x';
    }

    tb_get_line_from_current(&tb, target, 0);
    TEST_ASSERT_EQUAL_STRING("", target);

    setlength(tb.current, COLS);
    tb_get_line_from_current(&tb, target, 0);
    TEST_ASSERT_EQUAL_STRING(tb.current, target);

    setlength(tb.current, COLS*2);
    tb_get_line_from_current(&tb, target, 1);
    setlength(expected, COLS);
    TEST_ASSERT_EQUAL_STRING(expected, target);

    setlength(tb.current, COLS+10);
    tb_get_line_from_current(&tb, target, 1);
    setlength(expected, 10);
    TEST_ASSERT_EQUAL_STRING(expected, target);

    // when there is less then one full line:
    setlength(tb.current, 5);
    tb_get_line_from_current(&tb, target, 0);
    setlength(expected, 5);
    TEST_ASSERT_EQUAL_STRING(expected, target);
    //printf("target: %s\n", target);
}

void test_tb_get_line_from_past_end() {

    TextBuffer tb;
    tb_init(&tb);
    char target[COLS + 1];
    char expected[COLS + 1];

    setlength(tb.past[0], 5, 'a');
    setlength(tb.past[1], 10, 'b');
    tb.length = 2;

    tb_get_line_from_past_end(&tb, target, 0);
    TEST_ASSERT_EQUAL_STRING("bbbbbbbbbb", target);

    tb_get_line_from_past_end(&tb, target, 1);
    TEST_ASSERT_EQUAL_STRING("aaaaa", target);
}

void test_tb_get_screen_line() {

    int i;

    TextBuffer tb;
    tb_init(&tb);

    char target[COLS + 1];
    char expected[COLS + 1];

    // this is actually one more than will be used due to the current line
    for (i=0; i<ROWS-1; i++) {
        setlength(tb.past[i], i+1, '!'+i);
    }
    tb.length = ROWS;

    setlength(tb.current, ROWS, '!'+ROWS);

    for (i=0; i<ROWS; i++) {
        tb_get_screen_line(&tb, target, i);
        //printf("%d: %s\n", i, target);
    }

    tb.offset = 3;
    tb_clear_line_from_cursor(&tb);
    tb_get_screen_line(&tb, target, ROWS-1);
    //printf("%s\n", target);
}

void test_handle_lf() {
    int i;

    TextBuffer tb;
    tb_init(&tb);

    char line[TEXTBUFFER_LENGTH + 1];

    tb_handle_visible_char(&tb, 'a');

    for (i=0; i<ROWS; i++) {
        if (i == 0) {
            TEST_ASSERT_EQUAL(true, tb.dirty[i]);
        } else {
            TEST_ASSERT_EQUAL(false, tb.dirty[i]);
        }
    }

    tb_handle_lf(&tb);

    // the moment we wrap it will set the whole screen dirty
    for (i=0; i<ROWS; i++) {
        TEST_ASSERT_EQUAL(true, tb.dirty[i]);
    }

    TEST_ASSERT_EQUAL_STRING("a", tb.past[0]);
    TEST_ASSERT_EQUAL(1, tb.length);

    tb_handle_visible_char(&tb, 'b');
    tb_handle_lf(&tb);
    TEST_ASSERT_EQUAL_STRING("b", tb.past[1]);
    TEST_ASSERT_EQUAL(2, tb.length);

    tb_reset_dirty(&tb);

    for (i=0; i<ROWS; i++) {
        TEST_ASSERT_EQUAL(false, tb.dirty[i]);
    }

    // scroll one line

    for (i=0; i<ROWS; i++) {
        sprintf(line, "%d\n", i);
        tb_write(&tb, line);
    }

    TEST_ASSERT_EQUAL(ROWS-1, tb.length);
    for (i=0; i<ROWS-1; i++) {
        sprintf(line, "%d", i+1);
        TEST_ASSERT_EQUAL_STRING(line, tb.past[i]);
    }

    for (i=0; i<ROWS; i++) {
        TEST_ASSERT_EQUAL(true, tb.dirty[i]);
    }
}

void test_clear_line_from_cursor() {
    TextBuffer tb;

    tb_init(&tb);

    tb_write(&tb, "hello");
    tb_write_char(&tb, BACKSPACE);

    tb_write_char(&tb, ESCAPE);
    tb_write(&tb, "[K");

    TEST_ASSERT_EQUAL_STRING("hell", tb.current);

    tb.offset = 0;
    tb_write_char(&tb, ESCAPE);
    tb_write(&tb, "[K");

    TEST_ASSERT_EQUAL_STRING("", tb.current);
}

void test_tb_move_cursor_left() {
    TextBuffer tb;

    tb_init(&tb);

    tb_write(&tb, "hello");
    TEST_ASSERT_EQUAL(5, tb.offset);

    tb_write_char(&tb, BACKSPACE);
    TEST_ASSERT_EQUAL(4, tb.offset);

    tb_write_char(&tb, ESCAPE);
    tb_write(&tb, "[3D");
    TEST_ASSERT_EQUAL(1, tb.offset);

    tb_write_char(&tb, ESCAPE);
    tb_write(&tb, "[3D");

    TEST_ASSERT_EQUAL(0, tb.offset);
}

void test_errors() {

    int i;
    char line[TEXTBUFFER_LENGTH + 1];

    TextBuffer tb;
    tb_init(&tb);

    tb_write_char(&tb, ESCAPE);
    tb_write(&tb, "[12345678901");
    TEST_ASSERT_EQUAL_STRING("escape string too long", tb_error);

    tb_clear(&tb);

    tb_write_char(&tb, ESCAPE);
    tb_write(&tb, "aa");
    TEST_ASSERT_EQUAL_STRING("unknown escape end", tb_error);

    tb_clear(&tb);

    tb_write_char(&tb, ESCAPE);
    tb_write(&tb, "=");
    TEST_ASSERT_EQUAL_STRING("unknown escape sequence", tb_error);

    tb_clear(&tb);

    for (i=0; i<=TEXTBUFFER_LENGTH; i++) {
        tb_write_char(&tb, 'x');
    }
    TEST_ASSERT_EQUAL_STRING("text buffer overflow", tb_error);

    tb_clear(&tb);

    tb_write_char(&tb, 0);
    TEST_ASSERT_EQUAL_STRING("unknown character", tb_error);

    tb_clear(&tb);

    tb_get_line_from_current(&tb, line, 1);
    TEST_ASSERT_EQUAL_STRING("row overflow", tb_error);

    tb_clear(&tb);

    tb_get_line_from_past_end(&tb, line, 0);
    TEST_ASSERT_EQUAL_STRING("row overflow", tb_error);

    tb_clear(&tb);

    tb_get_screen_line(&tb, line, 1);
    TEST_ASSERT_EQUAL_STRING("row overflow", tb_error);
}

int main() {
    UNITY_BEGIN();

    /*
    RUN_TEST(test_tb_init);
    RUN_TEST(test_is_letter);
    RUN_TEST(test_is_number);
    RUN_TEST(test_is_escape_end);
    RUN_TEST(test_insert_at);
    RUN_TEST(test_tb_num_lines);
    RUN_TEST(test_tb_x);
    RUN_TEST(test_tb_y);
    RUN_TEST(test_tb_get_line_from_current);
    RUN_TEST(test_tb_get_line_from_past_end);
    RUN_TEST(test_tb_get_screen_line);
    */
    RUN_TEST(test_handle_lf);
    /*
    RUN_TEST(test_clear_line_from_cursor);
    RUN_TEST(test_tb_move_cursor_left);
    RUN_TEST(test_errors);
    */

    UNITY_END();
    return 0;
}
