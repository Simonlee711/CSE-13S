#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "code.h"
#include "defines.h"

Code code_init(void){
  Code c;
  c.top = 0;
  for(uint32_t i = 0; i < MAX_CODE_SIZE; i++){
    c.bits[i] = 0;
  }
  return c;
}

uint32_t code_size(Code *c){
  return c->top;
}

bool code_empty(Code *c){
  return c->top == 0;
}

bool code_full(Code *c){
  return c->top == MAX_CODE_SIZE;
}

bool code_push_bit(Code *c, uint8_t bit){
    if(c->top == MAX_CODE_SIZE){
      return false; 
    }
    s->bits[s->top] = bit;
    s->top += 1;
    return true;
  
}

bool code_pop_bit(Code *c, uint8_t *bit){
  if(c->top == 0){
    return false;
  }
  c->top -1;
  bit = c->bits[c->top];
  return true; 
}

void code_print(Code *c){
  printf("[");
    for (uint32_t i = 0; i < c->top; i += 1) {
        printf("%" PRId64, c->bits[i]);
        if (i + 1 != c->top) {
            printf(", ");
        }
    }
    printf("]\n");
}
