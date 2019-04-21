#ifndef VGA_H_
#define VGA_H_

enum vga_color
{
	COLOR_BLACK = 0,
	COLOR_BLUE = 1,
	COLOR_GREEN = 2,
	COLOR_CYAN = 3,
	COLOR_RED = 4,
	COLOR_MAGENTA = 5,
	COLOR_BROWN = 6,
	COLOR_LIGHT_GREY = 7,
	COLOR_DARK_GREY = 8,
	COLOR_LIGHT_BLUE = 9,
	COLOR_LIGHT_GREEN = 10,
	COLOR_LIGHT_CYAN = 11,
	COLOR_LIGHT_RED = 12,
	COLOR_LIGHT_MAGENTA = 13,
	COLOR_LIGHT_BROWN = 14,
	COLOR_WHITE = 15,
};

#define FB_ADDRESS              0x000B8000
#define FB_COMMAND_PORT         0x3D4
#define FB_DATA_PORT            0x3D5
#define FB_HIGH_BYTE_COMMAND    0x0E
#define FB_LOW_BYTE_COMMAND     0x0F

void vga_write(unsigned short pos, char ch, unsigned char fg, unsigned char bg);

void vga_move_cursor(unsigned short pos);

void vga_clear_screen( void );

void vga_write_string( unsigned short pos, const char *string );

#endif /* VGA_H_ */
