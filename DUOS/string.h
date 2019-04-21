#include "stddef.h"
#ifndef STRING_H_
#define STRING_H_

size_t strlen(const char* str);

void *memset(void *str, int c, size_t n );

char *strncpy(char *dest, const char *src, size_t n );

#endif /* STRING_H_ */
