#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "node.h"

Node *node_create(char *oldspeak, char *newspeak){

}
 
void node_delete(Node **n){

}
 
void node_print(Node *n){
  printf("%s -> %s\n", n->oldspeak , n->newspeak);
  printf("%s\n", n->oldspeak);
}

