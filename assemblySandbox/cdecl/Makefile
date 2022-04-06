CC=gcc
CFLAGS=-g -Wall
ASM=nasm
AFLAGS= -Wall -f elf64 -g
TARGET=./bin
PRE=./asm.o ./c.o

$(TARGET): $(PRE)
	$(CC) $(CFLAGS) $^ -o $@

./asm.o: ./cdecl.asm
	$(ASM) $(AFLAGS) $< -o $@

./c.o: ./cdecl.c
	$(CC) $(CFLAGS) -c $< -o $@