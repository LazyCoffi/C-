#ifndef INCLUDE_DEBUG_H_
#define INCLUDE_DEBUG_H_
#include "console_print.h"
#include "vargs.h"

void printk(const char *format, ...);

void printk_color(real_color_t bg, real_color_t fg, const char *format, ...);

#endif
