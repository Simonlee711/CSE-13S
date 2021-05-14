#include "code.h"
#include "defines.h"
#include "node.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint64_t dfs(Node){
  

}

Node *build_tree(uint64_t hist[static ALPHABET]){
  PriotityQueue *pq = pq_create(ALPHABET);
  for(int i = 0; i < ALPHABET; i++){
    if(hist[i] != 0){
      Node *n = node_create((char)i, hist[i]);
        pq_enqueue(pq, n);
    } 
  }
  while(pq_size != 1){
     Node **temp = &node_create('$', 0); 
     Node **temp2 = &node_create('$', 0);
     pq_dequeue(pq, temp);
     pq_dequeue(pq, temp2);
     Node new_node = node_join(temp1, temp2);
     pq_enqueue(pq, new_node);
  }
  dequeue(pq, temp); //freeing memory could lead to leaks check at the end
  return *temp;
}

void build_codes(Node *root, Code table[static ALPHABET]){
  
}

Node *rebuild_tree(uint16_t nbytes, uint8_t tree[static nbytes]){

}

void delete_tree(Node **root){

}

