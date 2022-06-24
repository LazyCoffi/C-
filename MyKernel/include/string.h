#ifndef INCLUDE_STRING_H_
#define INCLUDE_STRING_H_

#include "types.h"

void memcpy(void *dest, const void *src, uint32_t len);

void memset(void *dest, uint8_t val, uint32_t len);

void bezero(void *dest, uint32_t len);

char *strcpy(char *dest, const char *src);

char *strcat(char *dest, char *src);

char *strlen(char *dest);

#endif
