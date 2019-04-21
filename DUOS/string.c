#include "stddef.h"

size_t strlen( const char* str )
{
	size_t ret = 0;

	while ( str[ret] != 0 )
		ret++;

	return ret;
}

void *memset(void *str, int c, size_t n )
{

}

char *strncpy(char *dest, const char *src, size_t n )
{
	
}
