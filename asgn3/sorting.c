//sorting .c
#include "bubble.h"
#include "shell.h"
#include "quick.h"
#include "gaps.h"
#include "stack.h"
#include "queue.h"
#include <stdio.h>
#include <unistd.h>

#define OPTIONS "absqQrnp"

int main(int argc, char **argv) {
    int opt = 0;
    int bubble_sort = 0;
    int shell_sort = 0;
    int quick_sort = 0;
    int QUICK_sort = 0;
    int seed = 0;
    int size = 0;
    int elements = 0;

    while ((opt = getopt(argc, argv, OPTIONS)) != -1) {
        switch (opt) {
        case 'a':
            bubble_sort = 1;
            shell_sort = 1;
            quick_sort = 1;
            Quick_sort = 1;
            break;
        case 'b': bubble_sort = 1; break;
        case 's': shell_sort = 1; break;
        case 'q': quick_Sort = 1; break;
        case 'Q': QUICK_sort = 1; break;
        case 'r': seed = 1; break;
	case 'n': size = 1; break;
	case 'p': elements = 1; break;
        default:
            printf("correct usage %s -[absqQrnp]", argv[0]);
            return 1;
            break;
        }
    }
    
