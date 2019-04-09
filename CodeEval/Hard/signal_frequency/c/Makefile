CC = clang
CFLAGS = -O2 -Wall -Wextra
LIBS = -lm

OBJ = sf_main.o

program: $(OBJ)
	$(CC) -o $@ $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) $(LIBS) $<

clean:
	rm ./program
	rm ./output.txt

test_1: program
	./program test.txt > output.txt
	diff correct.txt output.txt

test: test_1

phony: clean test program
