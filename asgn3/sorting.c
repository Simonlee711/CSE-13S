#include "bubble.h"
#include "shell.h"
#include "quick.h"
#include "stack.h"
#include "queue.h"
#include "set.c"
#include <stdio.h>
#include <unistd.h>
#include <inttypes.h>
#include <stdlib.h>

typedef enum Sorts{
  Bubblesort,
  Shellsort,
  quicksort,
  QUICKsort,
} Sorts;

const char *names[] = {"Bubblesort", "Shellsort", "quicksort", "QUICKsort"};

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
	case 'b':
	  sorts = set_insert(sorts, Bubblesort); break;
	case 's':
	  sorts = set_insert(sorts, Shellsort); break;
	case 'q':
	  sorts = set_insert(sorts, quicksort); break;
	case 'Q':
	  sorts = set_insert(sorts, QUICKsort); break;
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
    for(Sorts i = Bubblesort; i <= QUICKsort; i += 1){
      if(set_member(sorts, i)){
	uint32_t seeds = 13371453;
	srandom(seeds);
	uint32_t elements = 100;
	//randomize seed if prompted
	
	if(seed == 1){
	  
	  srandom(seeds);
	}
	//make an if statement that takes user sys argv and put that into elements
	//assigning values to array
	uint32_t A[elements];
	for(uint32_t j = 0; j < elements; j++){
	  A[j] = random();
	}
	for(uint32_t k=0; k < elements; k++){
	  printf("%d: %d\n",k,A[k]);
	}
	uint32_t moves = 0;
	uint32_t compares = 0;
	shell_sort(&A[0], elements, &moves, &compares);
        
        printf("Shell Sort \n");
	printf("%d elements, %d moves, %d compares " , elements, moves, compares); 
	for(uint32_t k=0; k < elements; k++){
          if (k % 5 == 0){
            printf("\n");
	  }
          printf("%13" PRIu32 , A[k]);
	}
	printf("\n");
      }
    }
} 
