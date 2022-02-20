#ifndef _INCLUDE_PORT_IO_H
#define _INCLUDE_PORT_IO_H

#include "type.h"

void outb(uint8_t content, uint16_t port);

uint8_t inb(uint16_t port);

void outw(uint16_t content, uint16_t port);

uint16_t inw(uint16_t port);

#endif
