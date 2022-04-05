
ENTRY(_start)

OUTPUT_FORMAT(elf64-x86-64)



INPUT(./obj/library.o ./obj/test.o ./obj/stdLib.o ./obj/testingAlloc.o ./obj/setjump.o ./obj/setjumpAsm.o) 



OUTPUT(./bin/program.out)

SECTIONS
{
    .=0x9000

    .text : ALIGN(0x1000)
    { *(.text) }

    .data : ALIGN(0x1000)
    { *(.data) }

    .bss : ALIGN(0x1000)
    { *(.bss) }
}