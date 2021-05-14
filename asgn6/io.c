#include "code.h"
#include "defines.h"
#include <stdbool.h>
#include <stdint.h>

extern uint64_t bytes_read;
extern uint64_t bytes_written;
extern uint8_t *buffer_r;
extern uint8_t index = 0;
extern uint8_t *buffer_w;


int read_bytes(int infile, uint8_t *buf, int nbytes){ //tutor eric covered this
  uint32_t total_bytes = 0;
  uint32_t bytes = 0;
  while((bytes = read(infile, buf, nbytes)) > 0){
    if(bytes == -1){
      return 0;
  }
  total_bytes += bytes;
  nbytes -= bytes;
  buf += bytes;
  if(nbytes == 0){
    break;
    }
  }
  return total_bytes;
}

int write_bytes(int outfile, uint8_t *buf, int nbytes){
  uint32_t total_bytes = nbytes;
  uint32_t bytes = 0;
  while((bytes = write(outfile, buf, nbytes)) > 0){
    if(bytes == -1){
      return 0;
    }
  total_bytes -= bytes;
  nbytes -= bytes;
  buf += bytes;
  if(nbytes == 0){
    break;
  }   
}
return total_bytes;
}

bool read_bit(int infile, uint8_t *bit){
  uint32_t end = -1;
  if(index == 0 || index == BLOCK){
    num_bytes = read_bytes(infile, buffer_r, BLOCK);
    if(num_bytes < BLOCK){
      end = num_bytes + 1;
    }
  }
  *bit = ((buffer_r[index/8]>>(index % 8)) & 1); 
  index += 1;
  if(index == end){
    return false;
  }
  return true;
}

void write_code(int outfile, Code *c){

}

void flush_codes(int outfile){

}

