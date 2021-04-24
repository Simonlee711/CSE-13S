//bubble sort algorithm
//SOURCE Darrell Long's Python Pseudocode
#include "bubble.h"

#include <stdbool.h>
#include <stdio.h>
void bubble_sort(uint32_t *A, uint32_t n, uint32_t *moves, uint32_t *compares) {
    uint32_t hold = 0;
    uint32_t c = n;
    bool swapped = true;
    while (swapped == true) {
        swapped = false;
        for (uint32_t i = 1; i < c; i++) {
            (*compares)++;
            if (A[i] < A[i - 1]) {
                hold = A[i - 1];
                (*moves)++;
                A[i - 1] = A[i];
                (*moves)++;
                A[i] = hold;
                (*moves)++;
                swapped = true;
            }
        }
        c -= 1;
    }
}
