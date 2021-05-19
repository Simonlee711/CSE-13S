#include "code.h"
#include "header.h"
#include "huffman.h"
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
#define OPTIONS "hi:o:v"
uint64_t bytes_read;
uint64_t bytes_written;
static uint8_t bytes = 0;
static uint8_t hist[ALPHABET];

void LIpt(Node *root, uint32_t index, uint8_t *array) { //Leaf and Internal Post Traversal
    if (root == NULL)
        return;
    LIpt(root->left, index, array);
    LIpt(root->right, index, array);
    if(root->symbol == '$'){
      array[index] ='I';
      index += 1;
    }
    else{
      array[index] = 'L';
      index += 1;
      array[index] = root->symbol;
      index += 1;
    }
    return;
}

int main(int argc, char **argv) {
    int opt = 0;
    int in = STDIN_FILENO, out = STDOUT_FILENO;
    int verbose = 0;
    while ((opt = getopt(argc, argv, OPTIONS)) != -1) {
        switch (opt) {
        case 'h': exit(1);
        case 'i': in = open(optarg, O_RDONLY); break;
        case 'o': out = open(optarg, O_WRONLY | O_CREAT); break;
        case 'v': verbose = 1; break;
        }
    }

    //make histogram
    int length;
    uint8_t buffer[BLOCK] = {0}; // analogous to Professor Long's code
    while ((length = read(in, buffer, sizeof(BLOCK)) > 0)) {
        bytes += length;
        for (int i = 0; i < length; i++) {
            hist[buffer[i]] += 1;
        }
    }
    hist[0] += 1;
    hist[ALPHABET - 1] += 1;

    //build tree
    Node *huffman_tree = build_tree(hist);

    //construct codes
    Code table[ALPHABET];
    for (int j = 0; j < ALPHABET; j++) {
        table[j] = code_init();
    }
    build_codes(huffman_tree, table);

    //counter for leaf's
    int leaf_counter;
    for (int k = 0; k < ALPHABET; k++) {
        if (hist[k] != 0) {
            leaf_counter += 1;
        }
    }
    //header
    struct stat statbuf;
    fstat(fileno(in), &statbuf);
    fchmod(fileno(out), statbuf.st_mode);

    Header *h;
    h->magic = MAGIC;
    h->permissions = statbuf.st_mode;
    h->tree_size = ((3 * leaf_counter) - 1);
    h->file_size = statbuf.st_size;
 
    //write(outfile, buffer, sizeof(BLOCK)) //how to write out the header to outfile???

//build the Leaf and internal post traversal array
    uint32_t array_index = 0;
    uint8_t arr[ALPHABET];
    LIpt(huffman_tree, array_index, arr);
    write(out, arr, h->tree_size);
   
//write out to outfile
    lseek(in, 0, SEEK_SET);
    for(uint64_t sym = 0; sym < h->file_size; sym++){
      write_code(out, table);
    }
    flush_codes(out);

//close files
    close(in);
    close(out);
}
