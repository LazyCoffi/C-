#include "console_print.h"

int kern_entry(){
    console_clean_screen();
    console_print_str("HelloWorld!");
    console_print_colored_str("Color!", rc_red, rc_white);

    for (int i = 1; i <= 100000; i++) {
        console_print_str("0");
    }

    return 0;
}
