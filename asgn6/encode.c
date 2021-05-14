#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#define OPTIONS "hi:o:v"

int main(int argc, char **argv) {
    int opt = 0;
    FILE *in = stdin, *out = stdout;
    int verbose = 0;
    while ((opt = getopt(argc, argv, OPTIONS)) != -1) {
        switch (opt) {
        case 'h':
            exit(1);
        case 'i':
            int in = open(optarg, O_RDONLY);
            }

            break;
        case 'o':
            int out = open(optarg, O_WRONLY|O_CREAT);
            }
            break;
        case 'v':
            verbose = 1;
            break;
        }
    }

