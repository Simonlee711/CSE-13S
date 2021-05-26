#include "bf.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct  BloomFilter {
    uint64_t  primary [2];    //  Primary  hash  function  salt.
    uint64_t  secondary [2]; //  Secondary  hash  function  salt.
    uint64_t  tertiary [2];   //  Tertiary  hash  function  salt.
    BitVector *filter;
 };

BloomFilter *bf_create(uint32_t  size) {
    BloomFilter *bf = (BloomFilter  *)  malloc(sizeof(BloomFilter));
    if (bf) {     
      //  Grimm's Fairy  Tales
      bf ->primary [0] = 0x5adf08ae86d36f21;
      bf ->primary [1] = 0xa267bbd3116f3957;
      // The  Adventures  of  Sherlock  Holmes
      bf ->secondary [0] = 0x419d292ea2ffd49e;
      bf ->secondary [1] = 0x09601433057d5786;
      // The  Strange  Case of Dr. Jekyll  and Mr. Hyde
      bf ->tertiary [0] = 0x50d8bb08de3818df;
      bf ->tertiary [1] = 0x4deaae187c16ae1d;
      bf ->filter = bv_create(size);
      if (!bf->filter) {
         free(bf);
         bf = NULL;
      }
    }
    return  bf;
}

void bf_delete(BloomFilter **bf){

}
 
uint32_t bf_size(BloomFilter *bf){

}
 
void bf_insert(BloomFilter *bf, char *oldspeak){

}
 
bool bf_probe(BloomFilter *bf, char *oldspeak){

}
 
uint32_t bf_count(BloomFilter *bf){

}
 
void bf_print(BloomFilter *bf){

}

