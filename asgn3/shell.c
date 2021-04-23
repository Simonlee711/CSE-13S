//shell sorting algorithm
// SOURCES: Darrell Long's Python Pseudocode
#include <stdio.h>
#include <stdbool.h>
#include "shell.h"
#include "gaps.h"

void shell_sort(uint32_t *A, uint32_t n, uint32_t* moves, uint32_t *compares){
  for (uint32_t gap = 0; gap < n; gap++){
    if (gaps[gap] > sizeof(gaps)){
      continue;
    }
    for(uint32_t i = gaps[gap]; i < sizeof(gaps); i++){
      uint32_t j = i;
      uint32_t temp = A[i];
      *compares += 2;
      while(j >= gaps[gap] && temp < A[j - (gaps[gap])]){
	*compares += 2;
	A[j] = A[j - (gaps[gap])];
        j -= gaps[gap];
        A[j] = temp;
	*moves += 3;
      }
    }
  }  
}

