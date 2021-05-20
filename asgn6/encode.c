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
static uint64_t hist[ALPHABET];

void LIpt(Node *root, uint32_t index, uint8_t *array) { //Leaf and Internal Post Traversal
    if (root->left == NULL && root->right == NULL)
        return;
    LIpt(root->left, index, array);
    LIpt(root->right, index, array);
    if (root->symbol == '$') {
        array[index] = 'I';
        index += 1;
    } else {
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
        case 'h':
            printf("SYNOPSIS\n");
            printf("  A Huffman encoder.\n");
            printf("  Compresses a file using the Huffman coding algorithm.\n\n");
            printf("USAGE\n");
            printf("  ./encode [-h] [-i infile] [-o outfile]\n\n");
            printf("OPTIONS\n");
            printf("  -h             Program usage and help.\n");
            printf("  -v             Print compression statistics.\n");
            printf("  -i infile      Input file to compress.\n");
            printf("  -o outfile     Output of compressed data.\n");
            exit(1);
        case 'i': in = open(optarg, O_RDONLY); break;
        case 'o': out = open(optarg, O_WRONLY | O_CREAT); break;
        case 'v': verbose = 1; break;
        }
    }

    //make histogram
    int length;
    uint8_t buffer[BLOCK] = { 0 }; // analogous to Professor Long's code
    while ((length = read(in, buffer, sizeof(BLOCK)) > 0)) {
        bytes += length;
        for (int i = 0; i < length; i++) {
            hist[buffer[i]] += 1;
            printf("the populated character +1 %c\n", (char)hist[buffer[i]]);
        }
    }
    hist[0] += 1;
    hist[ALPHABET - 1] += 1;
   
    //build tree
    Node *huffman_tree = build_tree(hist);

    //construct codes
    Code table[ALPHABET] = { 0 };
    /*
    for (int j = 0; j < ALPHABET; j++) {
        table[j] = code_init();
    }*/
    build_codes(huffman_tree, table);
    code_print(table);
    printf(" <- code table\n");
    //counter for leaf's
    int leaf_counter = 0;
    for (int k = 0; k < ALPHABET; k++) {
        if (hist[k] != 0) {
            leaf_counter += 1;
        }
    }
    printf("leaf count: %u\n", leaf_counter);    
    //print histogram
    for(int i = 0; i < ALPHABET; i++){
      if(hist[i] != 0){
        printf("%c", hist[(char)i]);
      }
    }
    printf(" <- histogram characters\n");
    //header
    struct stat statbuf;
    fstat(in, &statbuf);
    fchmod(out, statbuf.st_mode);

    Header h;
    h.magic = MAGIC; //change to -> if dot notation doesn't work
    h.permissions = statbuf.st_mode;
    h.tree_size = ((3 * leaf_counter) - 1);
    h.file_size = statbuf.st_size;
    printf("tree size: %u\n", h.tree_size);
    printf("magic number: %u\n", h.magic);
    write_bytes(out, (uint8_t *)&h, sizeof(h.magic)); //how to write out the header to outfile???

    //build the Leaf and internal post traversal array
    uint32_t array_index = 0;
    uint8_t arr[ALPHABET];
    LIpt(huffman_tree, array_index, arr);
    write(out, arr, h.tree_size);    

    for(int i = 0; i < h.tree_size; i++){
      printf("%c", arr[i]);
    }
    printf(" <- printing LIpt array\n");
    
    //write out to outfile
    lseek(in, 0, SEEK_SET);
    for (uint64_t sym = 0; sym < h.file_size; sym++) {
        write_code(out, table);
    }
    flush_codes(out);

    //close files
    close(in);
    close(out);
}
