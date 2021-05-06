#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "bv.h"

//SGT Tutoring William Dai helped us make BitVector

struct BitVector BitVector{
  uint32_t length;
  uint8_t *vector;
};

BitVector *bv_create(uint32_t length){
  BitVector *v = (BitVector *)malloc(sizeof(BitVector));
  if(v){
    v->length = bit_len;
    v->vector = (uint8_t *)calloc(((bit_len / 8) + 1), sizeof(uint8_t));
    if(!v->vector){
	exit(0);
	} 
  }
  return v;  
}

void bv_delete(BitVector **v){
  if(*v && (*v)->vectors){
    free((*v)->vectors);
    free(*v);
    *v = NULL;
  }
}

uint32_t bv_length(BitVector *v){
  return bv_length;
}

//Eugene's section, Darrell Long's lecture
void bv_set_bit(BitVector *v, uint32_t i){
  (v->vector[i/8] |= (0x1<<(i%8)));
  return; 
}

//Eugene's section, Darrell Longs lecture
void bv_clr_bit(BitVector *v, uint32_t i){
  (v->vector[i/8] &= ~(0x1 << (i%8)));
  return;
}

void bv_xor_bit(BitVector *v, uint32_t i, uint8_t bit){  
  return (v->vector[i/8] ^= (bit << (i%8))); 
}

uint8_t bv_get_bit(BitVector *v, uint32_t i){
return (v->vector[i/8] &= (0x1 << (i%8)));
}
  
void bv_print(BitVector *v){
   for(int i = v->length, i>= 0; i--){
         
   }
}

