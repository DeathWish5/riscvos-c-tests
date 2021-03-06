OUTPUT_ARCH(riscv)
ENTRY(_start)

SECTIONS {
    .startup : {
        *crt.S.o(.text)
    }

    .text : { *(.text) }
    .data : { *(.data .rodata) }

    /DISCARD/ : { *(.eh_*) }
}