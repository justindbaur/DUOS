#include "multiboot_info.h"
#include "vga.h"
#include "stdlib.h"

// Linker symbols defined in link.ld
//
extern unsigned int KERNEL_HEAP_START;
extern unsigned int KERNEL_HEAP_END;

// global heap addresses for use in kernel heap allocation routines
//
const unsigned int *hstart = (unsigned int *)&KERNEL_HEAP_START,
		           *hend = (unsigned int *)&KERNEL_HEAP_END;

int dumain(multiboot_info_t* mb_info)
{
	// ->mem_lower 0 - 640 (in KB)
	// ->mem_upper 1M - ?  (in KB)

	// check
	/*
	 * string.h
	 *
	 *  Created on: Feb 8, 2017
	 *      Author: developer
	 * to see if the multiboot header is present and valid
	// https://www.gnu.org/software/grub/manual/multiboot/html_node/Boot-information-format.html
	//
	// If bit 0 in the ‘flags’ word is set, then the ‘mem_*’ fields are valid. ‘mem_lower’ and ‘mem_upper’
	// indicate the amount of lower and upper memory, respectively, in kilobytes. Lower memory starts at
	// address 0, and upper memory starts at address 1 megabyte. The maximum possible value for lower memory
	// is 640 kilobytes. The value returned for upper memory is maximally the address of the first upper memory
	// hole minus 1 megabyte. It is not guaranteed to be this value.
	//
	 */

	// is bit 0 in the 'flags' word set and do we have more than 16 MB RAM?
	//
	if( ( (mb_info->flags & 0x01) == 0x01) && mb_info->mem_upper > 16384 )  // GRUB2 reports memory in KB
	{
		vga_clear_screen();
		vga_write_string(0, "DUOS version 1.0 Alpha");

		char memory[9] = { 0 };

		vga_write_string(160, "Lower Memory : ");
		ltoa( mb_info->mem_lower, memory, 16 );
		vga_write_string( 190, memory );

		vga_write_string(320, "Upper Memory : ");
		ltoa( mb_info->mem_upper, memory, 16 );
		vga_write_string( 350, memory );

		vga_write_string(480, "KHeap Start  : ");
		ltoa( (long)hstart, memory, 16);
		vga_write_string(510, memory );

		ltoa( (long)hend, memory, 16);
		vga_write_string(640, "KHeap End    : ");
		vga_write_string(670, memory );

		ltoa( (long)hend - (long)hstart, memory, 16);
		vga_write_string(800, "KHeap Size   : ");
		vga_write_string(830, memory );
	}
	else
	{
		vga_clear_screen();
		vga_write_string(0, "DUOS requires a minimum of 16 MB RAM");
	}

	// TODO: display os_heap_avail here to show the starting heap size

	char *ptr = (char *)malloc(10); // allocate 10 bytes

	// TODO: display os_heap_avail here to show the heap size after the allocation
	if (ptr != NULL)
	{
		memset(ptr, '\0', 10); // initialize the array to '\0'
		char name[10] = "DUOS V1.1"; // create a c-string
		strncpy(ptr, name, strlen(name)); // copy the c-string to the dynamic array
		vga_write_string(0, ptr); // print the dynamic array
		free(ptr); // release the memory
	}
	// TODO: display os_heap_avail here to show the ending heap size

	while(1);  // loop until powered-off...

	return 0;
}


