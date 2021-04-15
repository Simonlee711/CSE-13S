\\SOURCE: Sahiti Section. Helped with Makefile.

CC = clang
CFLAGS = -Wall -Wextra -Werror -Wpedantic
LFLAGS = -lm

all: mathlib-test

mathlib-test: mathlib-test.o mathlib.o
	$(CC) $(CFLAGS) -o mathlib-test mathlib-test.o mathlib.o $(LFLAGS)

mathlib-test.o: mathlib-test.c
	$(CC) -c mathlib-test.c

mathlib.o: mathlib.c
	$(CC) -c mathlib.c

clean: 
	rm -f *.o  mathlib-test

clang-format: 
	clang-format -i -style=file mathlib.h mathlib.c mathlib-test.c
