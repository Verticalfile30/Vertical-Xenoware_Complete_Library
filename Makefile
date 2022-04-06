
CC=gcc
CPP=g++
LD=ld
ASM=nasm
AFLAGS=-f elf64 -g
CFLAGS=-Wall -g
CPPFLAGS=-Wall -g -fpermissive -lstdc++
TARGET=./bin/program.out
PRE=./obj/library.o ./obj/test.o ./obj/stdLib.o ./obj/stdLibCPP.o ./obj/testingAlloc.o ./obj/setjump.o ./obj/setjumpAsm.o

$(TARGET): $(PRE)
	$(CC) $(CPPFLAGS) $^ -o $@ 

./obj/expTester.so: ./standardLib/vxStdlib.c
	$(CC) $(CFLAGS) -fPIC -c $^ -o expTester.o
	$(CC) -shared expTester.o -o $@

./obj/library.o: ./dataManip/vxBits.c
	$(CC) $(CFLAGS) -c $^ -o $@ 

./obj/test.o: test.C
	$(CC) $(CPPFLAGS) -c $^ -o $@

./obj/stdLib.o: ./standardLib/vxStdlib.c
	$(CC) $(CFLAGS) -c $^ -o $@

./obj/stdLibCPP.o: ./standardLib/vxStdlibCPP.cpp
	$(CC) $(CPPFLAGS) -c $^ -o $@

./obj/testingAlloc.o: ./standardLib/testAllocator.asm
	$(ASM) $(AFLAGS) $^ -o $@

./obj/setjump.o: ./setjump/vxSaveExec.c
	$(CC) $(CFLAGS) -c $^ -o $@

./obj/setjumpAsm.o: ./setjump/vxSaveExecAsm.asm
	$(ASM) $(AFLAGS) $^ -o $@

clean:
	rm -rf $(TARGET) $(PRE)