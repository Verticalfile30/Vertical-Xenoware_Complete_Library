
CC=gcc
ASM=nasm
AFLAGS=-f elf64 -g
CFLAGS=-Wall -g 
TARGET=./bin/program.out
PRE=./obj/library.o ./obj/test.o ./obj/stdLib.o ./obj/testingAlloc.o ./obj/setjump.o ./obj/setjumpAsm.o

$(TARGET): $(PRE)
	$(CC) $(CFLAGS) $^ -o $@

./obj/library.o: ./dataManip/vxBits.c
	$(CC) $(CFLAGS) -c $^ -o $@ 

./obj/test.o: test.c
	$(CC) $(CFLAGS) -c $^ -o $@

./obj/stdLib.o: ./standardLib/vxStdlib.c
	$(CC) $(CFLAGS) -c $^ -o $@

./obj/testingAlloc.o: ./standardLib/testAllocator.asm
	$(ASM) $(AFLAGS) $^ -o $@

./obj/setjump.o: ./setjump/vxSaveExec.c
	$(CC) $(CFLAGS) -c $^ -o $@

./obj/setjumpAsm.o: ./setjump/vxSaveExecAsm.asm
	$(ASM) $(AFLAGS) $^ -o $@

clean:
	rm -rf $(TARGET) $(PRE)