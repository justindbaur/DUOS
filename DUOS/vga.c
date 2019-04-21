#include "vga.h"
#include "io_port_driver.h"
#include "string.h"

char *framebuffer = (char *) FB_ADDRESS;

void vga_write( unsigned short pos, char ch, unsigned char fg, unsigned char bg )
{
	framebuffer[pos] = ch;
	framebuffer[pos + 1] = fg | bg << 4;
}

void vga_move_cursor( unsigned short pos )
{
     outb(FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);
     outb(FB_DATA_PORT,    ((pos >> 8) & 0x00FF));
     outb(FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);
     outb(FB_DATA_PORT,    pos & 0x00FF);
}

void vga_clear_screen( void )
{
	for( int i = 0; i < 3840; i += 2)
	{
		vga_write(i, '\0', COLOR_BLACK, COLOR_BLACK);
	}
	vga_move_cursor(0);
}

void vga_write_string( unsigned short pos, const char *string )
{

	size_t len = strlen(string);

	for( unsigned int i = 0; i < len; i++ )
	{
		vga_write(pos, string[i], COLOR_GREEN, COLOR_BLACK);
		pos+=2;
	}

}
