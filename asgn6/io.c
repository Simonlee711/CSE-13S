#include "io.h"

#include "code.h"
#include "defines.h"

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

//Sabrina's sections method
/*int read_bytes(int infile, uint8_t *buf, int nbytes) {
    int total_bytes = 0;
    int32_t bytes = 0;
    do {
        bytes = read(infile, (buf + total_bytes), (nbytes - total_bytes));
        total_bytes += bytes;
        buf += bytes;
        nbytes -= bytes;
    } while (total_bytes != nbytes && bytes > -1);
    bytes_read = total_bytes;
    return total_bytes;
}*/

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
        bytes_read += bytes;
        if (nbytes == 0) {
            break;
        }
    }
    bytes_read = total_bytes;
    return total_bytes;
}


// Sabrina's section method 
/*int write_bytes(int outfile, uint8_t *buf, int nbytes) {
    int total_bytes = 0;
    int32_t bytes = 0;
    do {
        bytes = write(outfile, (buf + total_bytes), (nbytes - total_bytes));
        total_bytes += bytes;
        buf += bytes;
        nbytes -= bytes;
    	printf("tot: %u, nbytes: %u bytes: %u\n", total_bytes, nbytes, bytes);
    } while (total_bytes != nbytes && bytes > -1);
    bytes_written = total_bytes;
    return total_bytes;
}*/

int write_bytes(int outfile, uint8_t *buf, int nbytes) {
    uint32_t total_bytes = 0;
    int32_t bytes = 0;
    while ((bytes = write(outfile, buf, nbytes)) > 0) {
        if (bytes == -1) {
            return 0;
        }
        total_bytes += bytes;
        nbytes -= bytes;
        buf += bytes;
        printf("tot: %u, nbytes: %u bytes: %u\n", total_bytes, nbytes, bytes);
        if (nbytes == 0) {
            break;
        }
    }
    bytes_written = total_bytes;
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
    *bit = (buffer_r[pos / 8] >> (pos % 8)) & 1;
    pos += 1;
    if (pos == end * 8) {
        return false;
    }
    return true;
}

void write_code(int outfile, Code *c) {
    for (uint32_t i = 0; i < code_size(c); i++) {
        if (((c->bits[i / 8] >> (i % 8)) & 1) == 1) {
            buffer_w[i / 8] |= (1 << (i % 8));
            pos += 1;
        }
        if (((c->bits[i / 8] >> (i % 8)) & 1) == 0) {
            (buffer_w[i / 8] &= ~(1 << (i % 8)));
            pos += 1;
        }
        if (pos == BLOCK * 8) {
            write_bytes(outfile, buffer_w, (pos / 8));
            pos = 0;
        }
    }
}

void flush_codes(int outfile) {
    if (pos > 0) {
        if (pos % 8 == 0) {
            write_bytes(outfile, buffer_w, (pos / 8));
        } else {
            write_bytes(outfile, buffer_w, ((pos / 8) + 1));
        }
    }
}
