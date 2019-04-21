ENTRY(loader)                /* the name of the entry label */

KERNEL_HEAP_SIZE = 0x8000;	 /* 32 kb */

SECTIONS {

    . = 0x00100000;          /* the code should be loaded at 1 MB */

    .multibootHeader : 	     /* GRUB requires the multiboot header to be aligned on a 4 byte boundary within the first 8KB of the kernel executable file. */
    {
      *(.multibootHeader)
    }

    .text ALIGN (0x1000) :   /* align at 4 KB */
    {
        *(.text)             /* all text sections from all files */
    }

    .rodata ALIGN (0x1000) : /* align at 4 KB */
    {
        *(.rodata*)          /* all read-only data sections from all files */
    }

    .data ALIGN (0x1000) :   /* align at 4 KB */
    {
        *(.data)             /* all data sections from all files */
    }

    .bss ALIGN (0x1000) :    /* align at 4 KB */
    {
        *(COMMON)            /* all COMMON sections from all files */
        *(.bss)              /* all bss sections from all files */
    }
    
	/* Read-write data (uninitialized) and stack */
	KERNEL_HEAP ALIGN(4K) :
	{
		KERNEL_HEAP_START = .;
		KERNEL_HEAP_END = . + KERNEL_HEAP_SIZE;
	}    

}

