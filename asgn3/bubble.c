//bubble sort algorithm
//SOURCE Darrell Long's Python Pseudocode
#include <stdio.h>

void bubble_sort(uint32_t *A, uint32_t n){	
  bool swapped = true;
  while (swapped == true){
	  swapped = false;
	  for(i = 1; i < n; i++){
		  if *A[i] < *A[i-1]{
			  hold = *A[i-1];
			  *A[i-1] = *A[i];
			  *A[i] = hold;
			  swapped = true;
		  }		  
	  }
	  n -= 1;
  
  }


}
