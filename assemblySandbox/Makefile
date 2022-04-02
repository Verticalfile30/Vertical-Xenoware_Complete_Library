CC=gcc
CFLAGS=-g -Wall
ASM=nasm
AFLAGS= -Wall -felf64 -g
TARGET=./bin
PRE=./asm.o ./c.o

$(TARGET): $(PRE)
	$(CC) $(CFLAGS) $^ -o $@

./asm.o: ./stackTest.asm
	$(ASM) $(AFLAGS) $< -o $@

./c.o: ./stackTest.c
	$(CC) $(CFLAGS) -c $< -o $@