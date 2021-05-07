#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


#define OPTIONS "hi:o:"

int main(int argc, char **argv) {
  int opt = 0;

  while ((opt = getopt(argc, argv, OPTIONS)) != -1) {
        switch (opt) {
        case 'h':
          printf("SYNOPSIS\n");
	  printf("  A Hamming(8, 4) systematic code generator.\n\n");
	  printf("USAGE\n");
	  printf("  ./encode [-h] [-i infile] [-o outfile]\n\n");
          printf("OPTIONS\n");
	  printf("  -h             Program usage and help.\n");
	  printf("-i infile      Input data to encode.\n");
	  printf("-o outfile     Output of encoded data.");
          return 0;
        case 'i':
	  break;
        case 'o':
	  break;
}
}



}

