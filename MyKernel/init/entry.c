#include "console_print.h"

int kern_entry(){
    console_clean_screen();
    console_print_str("Helloworld!");
    console_print_colored_str("Color!", rc_red, rc_yellow);
    return 0;
}