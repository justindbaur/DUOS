	global loader                    	; the entry symbol for ELF
   	extern dumain						; the kernel

    MAGIC_NUMBER equ 0x1BADB002     	; define the magic number constant
    FLAGS        equ 0x0            	; multiboot flags
    CHECKSUM     equ -MAGIC_NUMBER  	; calculate the checksum
                                    	; (magic number + checksum + flags should equal 0)
    KERNEL_STACK_SIZE equ 4096      	; size of stack in bytes

    section .multibootHeader
    align 4                         	; the code must be 4 byte aligned
    dd MAGIC_NUMBER             		; write the magic number to the machine code,
    dd FLAGS                    		; the flags,
    dd CHECKSUM                 		; and the checksum


    loader:                         	; the loader label (defined as entry point in linker script)
        push EBX						; push the address of the multiboot_info structure
        mov EAX, MAGIC_NUMBER			; put the magic number in EAX (32-bit register) so we can see that the code executed
        finit							; Initialize Floating-Point Unit
        ;mov [0x000B8000], word 0x8241
        ;mov [0x000B8002], word 0x8242
        call dumain						; c function to run the kernel
    .loop:
        jmp .loop                   	; loop forever
