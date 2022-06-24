#include "string.h"

void memcpy(void *dest, const void *src, uint32_t len) {
    uint8_t *dst = (char*)dest;
    uint8_t *sr = (char*)src;

    while (len--) {
        *dst++ = *sr++; 
    }
}

void memset(void *dest, uint8_t val, uint32_t len) {
    uint8_t *dst = (char*)dest;
    
    while (len--) {
        *dst++ = val;
    }
}

void bzero(void *dest, uint32_t len) {
    memset(dest, 0, len);
}

char *strcpy(char *dest, const char *src) {
    char *cp = dest;
    while (*cp++ = *src++); 
    return dest;
}

char *strcat(char *dest, const char *src) {
    char *cp = dest;
    while (*cp++);
    while (*cp++ = *src++);
    return dest;
}

int strlen(const char *dest) {
    char *cp = dest;
    while (*cp++);
    return cp - dest - 1;
}
