CC = clang
CFLAGS = -Wall -Wextra -Werror -Wpedantic
LFLAGS = -lm

all: decode encode

decode: decode.o bm.o bv.o hamming.o
	$(CC) $(CFLAGS) -o decode decode.o bm.o bv.o hamming.o $(LFLAGS)

encode: encode.o bm.o bv.o hamming.o
	$(CC) $(CFLAGS) -o encode encode.o bm.o bv.o hamming.o $(LFLAGS)

bm.o: bm.c
	$(CC) $(CFLAGS) -c bm.c

bv.o: bv.c
	$(CC) $(CFLAGS) -c bv.c

hamming.o: hamming.c
	$(CC) $(CFLAGS) -c hamming.c

clean:
	rm -f *.o decode encode

format:
	clang-format -i -style=file decode.c encode.c bm.c bv.c hamming.c hamming.h bv.h bm.c entropy.c error.c

