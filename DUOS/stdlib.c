/*
 * stdlib.c
 *
 *  Created on: Feb 8, 2017
 *      Author: developer
 */

#include "stddef.h"

char *ltoa( long value, char *str, int base )
{
	unsigned char byte = '\0';
	char ch = '\0';
	int index = 7;

	if( base == 16 )
	{
		for ( int i = 0; i <= 24; i+= 8 )
		{
			byte = (unsigned char)(value >> i);

			// extract the first nibble and assign a character
			if ((byte & 0x0F) < 10)
				ch = 48 + (byte & 0x0F); // 0 - 9
			else
				ch = 55 + (byte & 0x0F); // A - F
			str[index] = ch;
			index--;

			// extract the second nibble and assign a character
			byte = (byte >> 4);
			if ((byte & 0x0F) < 10)
				ch = 48 + (byte & 0x0F); // 0 - 9
			else
				ch = 55 + (byte & 0x0F); // A - F
			str[index] = ch;
			index--;
		}
	}

	return NULL;
}

void *malloc(size_t size)
{

}

void free(void *ptr)
{
	
}
