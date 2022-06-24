#ifndef _INCLUDE_SCREEN_PRINT_H_
#define _INCLUDE_SCREEN_PRINT_H_

#include "type.h"
#include "port_io.h"

typedef
enum real_color {
    rc_black = 0,
    rc_blue = 1,
    rc_green = 2,
    rc_cyan = 3,
    rc_red = 4,
    rc_magenta = 5,
    rc_brown = 6,
    rc_light_grey = 7,
    rc_dark_grey = 8,
    rc_light_blue = 9,
    rc_light_green = 10,
    rc_light_cyan = 11,
    rc_light_red = 12,
    rc_light_magenta = 13,
    rc_light_brown  = 14,
    rc_white = 15
} real_color_t;

void console_set_cursor();

void console_clean_screen();

void console_scroll();

void console_print_char(char ch);

void console_print_colored_char(char ch, real_color_t fg, real_color_t bg);

void console_print_str(char *str);

void console_colored_print_str(char *str, real_color_t fg, real_color_t bg);

#endif
