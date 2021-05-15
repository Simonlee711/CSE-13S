#include "code.h"
#include "defines.h"
#include "io.h"
#include <fcntl.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

extern uint64_t bytes_read;
extern uint64_t bytes_written;
static uint8_t buffer_r[BLOCK];
static int32_t pos;
static uint8_t buffer_w[BLOCK];


int read_bytes(int infile, uint8_t *buf, int nbytes) { //tutor eric covered this
    uint32_t total_bytes = 0;
    int32_t bytes = 0;
    while ((bytes = read(infile, buf, nbytes)) > 0) {
        if (bytes == -1) {
            return 0;
        }
        total_bytes += bytes;
        nbytes -= bytes;
        buf += bytes;
        if (nbytes == 0) {
            break;
        }
    }
    return total_bytes;
}

int write_bytes(int outfile, uint8_t *buf, int nbytes) {
    uint32_t total_bytes = nbytes;
    int32_t bytes = 0;
    while ((bytes = write(outfile, buf, nbytes)) > 0) {
        if (bytes == -1) {
            return 0;
        }
	//bytes_written += bytes;
        total_bytes -= bytes;
        nbytes -= bytes;
        buf += bytes;
        if (nbytes == 0) {
            break;
        }
    }
    return total_bytes;
}

bool read_bit(int infile, uint8_t *bit) {
    int32_t end = -1;
    if (pos == 0 || pos == BLOCK * 8) {
        int num_bytes = read_bytes(infile, buffer_r, BLOCK);
        if (num_bytes < BLOCK) {
            end = num_bytes + 1;
        }
	bytes_read = num_bytes;
    }
    *bit = ((buffer_r[pos / 8] >> (pos % 8)) & 1);
    pos += 1;
    if (pos == end) {
        return false;
    }
    return true;
}

void write_code(int outfile, Code *c) {
   for(uint32_t i = 0; i < c->top; i++){
     buffer_w[pos / 8] |= c->bits[i / 8] & (1 << (i % 8));
     pos += 1;
     if(pos == BLOCK * 8){
       bytes_written += write_bytes(outfile, buffer_w, pos);   
       pos = 0;
     }
   }
     
}

void flush_codes(int outfile) {

}
