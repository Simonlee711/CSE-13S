#include "code.h"
#include "defines.h"
#include "header.h"
#include "huffman.h"
#include "io.h"
#include "node.h"
#include "pq.h"
#include "stack.h"

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

void LIpt(Node *root, Stack **s) { //Leaf and Internal Post Traversal
    if (root == NULL) { //->left == NULL && root->right == NULL){
        return;
    }
    LIpt(root->left, s);
    LIpt(root->right, s);
    if (root->left == NULL && root->right == NULL) {
        Node *L = node_create('L', 0);
        stack_push(*s, L);
        stack_push(*s, root);
    }
    if (root->left != NULL && root->right != NULL) {
        Node *I = node_create('I', 0);
        stack_push(*s, I);
    }
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
        case 'o': out = open(optarg, O_WRONLY | O_CREAT | O_TRUNC); break;
        case 'v': verbose = 1; break;
        }
    }

    //make histogram
    //SOURCE: Proffessor Long's example from class to construct histogram
    int length;
    uint8_t buffer[BLOCK] = { 0 };
    while ((length = read(in, buffer, sizeof(BLOCK)) > 0)) {
        bytes += length;
        for (int i = 0; i < length; i++) {
            hist[buffer[i]] += 1;
        }
    }
    hist[0] += 1;
    hist[255] += 1;

    //build tree
    Node *huffman_tree = build_tree(hist);

    //construct codes
    Code table[ALPHABET];
    for (int i = 0; i < ALPHABET; i++) {
        table[i] = code_init();
    }
    build_codes(huffman_tree, table);

    //print code table
    /*for (int i = 0; i < ALPHABET; i++) {
        if (hist[i] != 0) {
            printf("code values!!!! char: %c code: ", (char) i);
            code_print(&table[i]);
        }
    }*/

    //counter for leaf's
    int leaf_counter = 0;
    for (int k = 0; k < ALPHABET; k++) {
        if (hist[k] != 0) {
            leaf_counter += 1;
        }
    }
    //printf("\nleaf count: %u\n", leaf_counter);

    //header
    struct stat statbuf;
    fstat(in, &statbuf);
    fchmod(out, statbuf.st_mode);

    Header h;
    h.magic = MAGIC; //change to -> if dot notation doesn't work
    h.permissions = statbuf.st_mode;
    h.tree_size = ((3 * leaf_counter) - 1);
    h.file_size = statbuf.st_size;
    //printf("tree size: %u\n", h.tree_size);
    //printf("magic number: %u\n", h.magic);
    //printf("file size: %lu\n", h.file_size);
    write_bytes(out, (uint8_t *) &h, sizeof(h));

    //build the Leaf and internal post traversal array
    Stack *s = stack_create(h.tree_size);
    uint8_t arr[h.tree_size];
    LIpt(huffman_tree, &s);
    Node *temp;
    for (int i = h.tree_size - 1; i >= 0; i--) {
        stack_pop(s, &temp);
        arr[i] = temp->symbol;
        node_delete(&temp);
    }
    write_bytes(out, arr, sizeof(arr));

    //write out to outfile
    lseek(in, 0, SEEK_SET);
    uint8_t bit;
    for (uint64_t sym = 0; sym < h.file_size; sym++) {
        read_bytes(in, &bit, 1);
        if (table[bit].top != 0) {
            //code_print(&table[bit]);
            write_code(out, &table[bit]);
        }
    }
    flush_codes(out);
    if (verbose) {
         printf("uncompressed file size: %lu\n", h.file_size);
         printf("compressed file size: \n");
         printf("Space saving\n");
         }
	//close files
         close(in);
         close(out);
}
