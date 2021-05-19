#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include "defines.h"

#define OPTIONS "hi:o:v"

int main(int argc, char **argv) {
    int opt = 0;
    int *in = stdin, *out = stdout; // fix later WRONG
    int verbose = 0;

    while ((opt = getopt(argc, argv, OPTIONS)) != -1) {
        switch (opt) {
        case 'h': return 0;
        case 'i':
            
            break;
        case 'o':
           
            break;
        case 'v': verbose = 1; break;
        }
    }
    //read in header
    
    uint8_t dump[h->tree_size] = {0};
    read(in, dump, h->tree_size);
    Node *root = rebuild_tree(h->tree_size, dump);
    uint8_t bit = 0;
    Node *curr = root; 
    while(read_bit(in, &bit)){
      if(bit == 0){
        if(curr->left == NULL){
          write(out, &(curr->symbol), 1);
	  curr = root;
	}
	else{
          curr =  curr->left;  
        }
      }
      else{
        if(curr->right == NULL){
          write(out, &(curr->symbol), 1);
          curr = root;
        }
        else{
          curr = curr->right;
        }
      }
 
    }
    close(in);
    close(out);
}
