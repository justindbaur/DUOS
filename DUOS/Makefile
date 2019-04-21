	OBJECTS = loader.o dumain.o io_port_driver.o vga.o stdlib.o string.o
	CC = gcc
	CFLAGS = -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector \
        	 -nostartfiles -nodefaultlibs -Wall -Wextra -w -std=c99 -c
	LDFLAGS = -T link.ld -melf_i386 -Map=DUOS.map
	AS = nasm
	ASFLAGS = -f elf

all: kernel

kernel: $(OBJECTS) 
	ld $(LDFLAGS) $(OBJECTS) -o kernel.elf

iso: kernel
	cp kernel.elf iso/boot/kernel.elf

	genisoimage	-R				\
			-b boot/grub/stage2_eltorito	\
			-no-emul-boot			\
			-boot-load-size 4               \
			-A DUOS                         \
			-input-charset utf8             \
			-quiet                          \
			-boot-info-table                \
			-o DUOS.iso                     \
			iso

run: iso
	bochs -f bochsrc.txt -q

%.o: %.c
	$(CC) $(CFLAGS)  $< -o $@

%.o: %.asm
	$(AS) $(ASFLAGS) $< -o $@

clean:
	rm -rf *.o *.*~ kernel.elf DUOS.iso DUOS.map
