#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

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
            if ((in = fopen(optarg, "rb")) == NULL) {
                fprintf(stderr, "failed to open infile\n");
                exit(1);
            }

            break;
        case 'o':
            if ((out = fopen(optarg, "w")) == NULL) {
                fprintf(stderr, "failed to write outfile\n");
                exit(1);
            }
            break;
        case 'v':
            verbose = 1;
            break;
        }
    }

