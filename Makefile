
CC=gcc
CFLAGS=-Wall -g
TARGET=./bin/program.out
PRE=./obj/library.o ./obj/test.o ./obj/stdLib.o

$(TARGET): $(PRE)
	$(CC) $(CFLAGS) $^ -o $@

./obj/library.o: vxBits.c
	$(CC) $(CFLAGS) -c $^ -o $@

./obj/test.o: test.c
	$(CC) $(CFLAGS) -c $^ -o $@

./obj/stdLib.o: ./standardLib/vxStdlib.c
	$(CC) $(CFLAGS) -c $^ -o $@