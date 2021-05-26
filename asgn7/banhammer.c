#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#define OPTIONS "ht:f:ms"

int main(int argc, char **argv) {
    int opt = 0;
    FILE *in = stdin, *out = stdout;
    uint64_t ht_size = 10000;
    uint64_t bf_size = 1048576;
    int statistics = 0;
    int mtf = 0;
    while ((opt = getopt(argc, argv, OPTIONS)) != -1) {
        switch (opt) {
        case 'h':
		printf("SYNOPSIS\n");
		printf("  A word filtering program for the GPRSC.\n");
		printf("  Filters out and reports bad words parsed from stdin.\n\n");
		printf("USAGE\n");
		printf("  ./banhammer [-hsm] [-t size] [-f size]\n\n");
		printf("OPTIONS\n");
		printf("  -h           Program usage and help.\n");
		printf("  -s           Print program statistics.\n");
		printf("  -m           Enable move-to-front rule.\n");
		printf("  -t size      Specify hash table size (default: 10000).\n");
		printf("  -f size      Specify Bloom filter size (default: 2^20).\n");
		return 0;
        case 't':
		ht_size = atoi(optarg); //from asgn3
            	break;
        case 'f':
		bf_size = atoi(optarg); //from asgn3
            	break;
	case 'm':
		mtf = 1;
		break;
	case 's':
		statistics = 1;
		break;
        }
    }

