CC = gcc
MAIN_FILE = main_np1.c
MAIN_EXEC = main_np1

all: main

llist:
	cd llist && make

main: llist $(MAIN_FILE)
	$(CC) $(MAIN_FILE) -o $(MAIN_EXEC) llist/llist.o -Wall

clean:
	rm $(MAIN_EXEC)
	cd llist && make clean

debug:
	valgrind ./$(MAIN_EXEC)

.PHONY: llist
