CC=clang
CFLAGS=-O2 -Wall -Wextra -Werror
#LIBS=-lm

#CFLAGS=-O2 -Wall -Wextra -Werror
#CFLAGS=-O2 -Weverything

program: main.c
	$(CC) $(CFLAGS) $(LIBS) main.c -o program

test_1: program
	./program test.txt > output.txt
	diff correct.txt output.txt

test: test_1

phony: clean

clean:
	rm ./program
	rm ./output.txt
