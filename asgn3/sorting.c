#include "bubble.h"
//#include "queue.h"
#include "quick.h"
#include "set.c"
#include "shell.h"
//#include "stack.h"

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef enum Sorts {
    Bubblesort,
    Shellsort,
    quicksort,
    QUICKsort,
} Sorts;

const char *names[] = { "Bubblesort", "Shellsort", "quicksort", "QUICKsort" };

#define OPTIONS "absqQrnp"

int main(int argc, char **argv) {
    int opt = 0;
    int seed = 0;
    int size = 0;
    int elements = 0;

    Set sorts = set_empty();

    while ((opt = getopt(argc, argv, OPTIONS)) != -1) {
        switch (opt) {
        case 'a': break;
        case 'b': sorts = set_insert(sorts, Bubblesort); break;
        case 's': sorts = set_insert(sorts, Shellsort); break;
        case 'q': sorts = set_insert(sorts, quicksort); break;
        case 'Q': sorts = set_insert(sorts, QUICKsort); break;
        case 'r': seed = 1; break;
        case 'n': size = 1; break;
        case 'p': elements = 1; break;
        default:
            printf("correct usage %s -[absqQrnp]", argv[0]);
            return 1;
            break;
        }
    }

    //Eugene's Section
    for (Sorts i = Bubblesort; i <= QUICKsort; i += 1) {
        if (set_member(sorts, i)) {
            uint32_t seeds = 13371453;
            srandom(seeds);
            uint32_t elements = 100;
            //randomize seed if prompted

            if (seed == 1) {

                srandom(seeds);
            }
            //make an if statement that takes user sys argv and put that into elements

            //assigning values to array
            uint32_t A[elements];
            for (uint32_t j = 0; j < elements; j++) {
                A[j] = random();
            }

            //Printing Statements;
            uint32_t moves = 0;
            uint32_t compares = 0;
            uint32_t stack_size = 0;
            uint32_t queue_size = 0;
            if (set_member(sorts, Bubblesort)) {
                bubble_sort(&A[0], elements, &moves, &compares);
                printf("Bubble Sort\n");
                printf("%d elements, %d moves, %d compares ", elements, moves, compares);
                for (uint32_t k = 0; k < elements; k++) {
                    if (k % 5 == 0) {
                        printf("\n");
                    }
                    printf("%13" PRIu32, A[k]);
                }
                printf("\n");
            }
            if (set_member(sorts, Shellsort)) {
                shell_sort(&A[0], elements, &moves, &compares);
                printf("Shell Sort\n");
                printf("%d elements, %d moves, %d compares ", elements, moves, compares);
                for (uint32_t k = 0; k < elements; k++) {
                    if (k % 5 == 0) {
                        printf("\n");
                    }
                    printf("%13" PRIu32, A[k]);
                }
                printf("\n");
            }
            if (set_member(sorts, quicksort)) {
                quick_sort_stack(&A[0], elements, &moves, &compares, &stack_size);
                printf("Quick Sort (Stack)\n");
                printf("%d elements, %d moves, %d compares\n", elements, moves, compares);
                printf("Max stack size: %d", stack_size);
                for (uint32_t k = 0; k < elements; k++) {
                    if (k % 5 == 0) {
                        printf("\n");
                    }
                    printf("%13" PRIu32, A[k]);
                }
                printf("\n");
            }
            if (set_member(sorts, QUICKsort)) {
                quick_sort_queue(&A[0], elements, &moves, &compares, &queue_size);
                printf("Quick Sort (Queue)\n");
                printf("%d elements, %d moves, %d compares\n", elements, moves, compares);
                printf("Max queue size: %d", queue_size);
                for (uint32_t k = 0; k < elements; k++) {
                    if (k % 5 == 0) {
                        printf("\n");
                    }
                    printf("%13" PRIu32, A[k]);
                }
                printf("\n");
            }
        }
    }
}
