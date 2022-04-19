#include "console_print.h"

static uint8_t cursor_x = 0;
static uint8_t cursor_y = 0;
static uint16_t *screen_content = (uint16_t *)0xB8000;

void console_set_cursor() {
    uint16_t cursor_location = cursor_y * 80 + cursor_x;

    outb(0x3D4, 14);                    // 设置高8位
    outb(0x3D5, cursor_location >> 8);
    outb(0x3D4, 15);                    // 设置底8位
    outb(0x3D5, cursor_location);
}

void console_clean_screen() {
    uint8_t blank_color = rc_white | (rc_black << 4);
    uint16_t blank = 0x20 | (blank_color << 8);

    int i;
    for (i = 0; i < 80 * 25; i++) {
        screen_content[i] = blank;
    }

    cursor_x = 0;
    cursor_y = 0;
    console_set_cursor();
}

void console_scroll() {
    if (cursor_y < 25) {
        return;
    }

    uint8_t blank_color = rc_white | (rc_black << 4);
    uint16_t blank = 0x20 | (blank_color << 8);  // space 是 0x20

    for (int i = 0 * 80; i < 24 * 80; i++) {
        screen_content[i] = screen_content[i+80];
    }

    for (int i = 24 * 80; i < 25 * 80; i++) {
        screen_content[i] = blank;
    }

    cursor_y = 24;
}


void console_print_colored_char(char ori_ch, real_color_t fg, real_color_t bg) {
    uint8_t char_color = fg | (bg << 4);

    uint16_t ch = ori_ch | (char_color << 8);

    if (ch == 0x08 && cursor_x) {
        cursor_x --;
    } else if (ch == 0x09) {
        cursor_x = (cursor_x + 8) & ~(8 - 1);
    } else if (ch == '\r') {
        cursor_x = 0;
    } else if (ch == '\n') {
        cursor_x = 0;
        cursor_y ++;
    } else if (ch >= ' ') {
        screen_content[cursor_y * 80 + cursor_x] = ch;
        cursor_x ++;
    }

    // 每 80 个字符一行，满80就必须换行了
    if (cursor_x >= 79) {
        cursor_x = 0;
        cursor_y ++;
    }

    console_scroll();
    console_set_cursor();
}

void console_print_char(char ch) {
    console_print_colored_char(ch, rc_white, rc_black);
}

void console_print_colored_str(char *str, real_color_t fg, real_color_t bg) {
    while (*str) {
        console_print_colored_char(*str, fg, bg);
        str++;
    }
}

void console_print_str(char *str) {
    console_print_colored_str(str, rc_white, rc_black);
}