#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "bm.h"

struct  BitMatrix {
     uint32_t  rows;
     uint32_t  cols;
     BitVector *vector;
};

BitMatrix *bm_create(uint32_t rows, uint32_t cols){
  BitMatrix *m = (*BitMatrix)malloc(sizeof(BitVector));
  if(m){
    m->rows = rows;
    m->cols = cols;
    m->vector = bv_create(m->row * m->cols);
  }
}

void bm_delete(BitMatrix **m){
  if(*m){
    free(*m);
    *m = NULL;
  }
}
uint32_t bm_rows(BitMatrix *m){
  return m->rows;
}
uint32_t bm_cols(BitMatrix *m){
  return m->cols;
}
//Sahiti's sections pseudo code inspired
void bm_set_bit(BitMatrix *m, uint32_t r, uint32_t c){
  bv_set_bit(m->vector, r * (m->cols - 1) + c);
}

//Sahiti's sections pseudo code inspired
void bm_clr_bit(BitMatrix *m, uint32_t r, uint32_t c){
  bv_clr_bit(m->vector, r * (m->cols -1) + c);
}

//Sahiti's sections pseudo code inspired
uint8_t bm_get_bit(BitMatrix *m, uint32_t r, uint32_t c){
  bv_get_bit(m->vector, (m->cols - 1) + c);
}

//Sahiti's section pseudo code inspired
BitMatrix *bm_from_data(uint8_t byte, uint32_t length){
  BitMatrix *bm = bm_create(1, m->length);
  for(uint32_t i = 0; i < m->length; i++){
    if(byte & (1 << i)){
      bm_set_bit(m->vector, i);
    }
    else{
      bm_clr_bit(m->vector, i);
    }


} 
}  
}

//tutor Eric helped me out here
uint8_t bm_to_data(BitMatrix *m){
  data = 0;
  for(int i = 0; i <

}
  //reading matrix putting it back in uint_8

//Sahiti's section logic 
BitMatrix *bm_multiply(BitMatrix *A, BitMatrix *B){
  BitMatrix *new_matrix = bm_create(A->rows, B->cols);
  for(uint32_t i = 0; i < A->rows; i++){
    for(uint32_t j = 0; j < B->cols; j ++){
      for(uint32_t k = 0; k < A->cols; k++){
        product[i][j] = A[i][k] & B[k][j];
	bv_xor_bit(product, ) 
}
}
} 
}
void bm_print(BitMatrix *m){
  
}

