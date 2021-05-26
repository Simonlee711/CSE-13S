#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "ll.h"

struct  LinkedList {
    uint32_t  length;
    Node *head; // Head  sentinel  node.
    Node *tail; // Tail  sentinel  node.
    bool  mtf;
};

LinkedList *ll_create(bool mtf){

}
 
void ll_delete(LinkedList **ll){

}
 
uint32_t ll_length(LinkedList *ll){

}
 
Node *ll_lookup(LinkedList *ll, char *oldspeak){

}
 
void ll_insert(LinkedList *ll, char *oldspeak, char *newspeak){

}
 
void ll_print(LinkedList *ll){

}

