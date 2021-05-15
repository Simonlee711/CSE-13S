#include <fcntl.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#define OPTIONS "hi:o:v"
uint64_t bytes_read;
uint64_t bytes_written;

int main(int argc, char **argv) {
    int opt = 0;
    //FILE *in = stdin, *out = stdout;
    int verbose = 0;
    while ((opt = getopt(argc, argv, OPTIONS)) != -1) {
        switch (opt) {
        case 'h': exit(1);
        case 'i':
            //int in = open(optarg, O_RDONLY);
            break;
        case 'o':
            //int out = open(optarg, O_WRONLY|O_CREAT);
            break;
        case 'v': verbose = 1; break;
        }
    }
}
