#include "ll.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct LinkedList {
    uint32_t length;
    Node *head; // Head  sentinel  node.
    Node *tail; // Tail  sentinel  node.
    bool mtf;
};

LinkedList *ll_create(bool mtf) {
    LinkedList *ll = (LinkedList *)malloc(sizeof(LinkedList));
    if(ll){
      ll->length = length;
      ll->head = node_create(NULL, NULL);
      ll->tail = node_create(NULL, NULL);
      ll->head->next = ll->tail;
      ll->tail->prev = ll->head;
      ll->mtf = mtf;
    }
    return ll;
}

//Sabrina's section logic
void ll_delete(LinkedList **ll) {
    for(Node *temp = (*ll)->head->next; temp < != NULL; temp = temp->next){
        if(temp != NULL){
           node_delete(&(temp->prev)); //deletes every previous node
        }   
    }
    node_delete(&((*ll)->tail)); //deletes the tail node because it never got freed
    free(*ll);
    *ll = NULL;
}

uint32_t ll_length(LinkedList *ll) {
    return ll->length;
}

//Sabrinas section logic
Node *ll_lookup(LinkedList *ll, char *oldspeak) {
    for(Node *n = ll->head->next; n != n->tail; n->next){
        if(strcmp(n->oldspeak, ll->oldspeak) == 0){
          if(ll->mtf == 1){
            n->prev->next = n->next;
            n->next->prev = n->prev;
            n->next = ll->head->next;
            n->prev = ll->head;
            ll->head->next->prev = n;
            ll->head->next = n;
          }
          return n;
        }
    }
    return NULL;
}

//Sabrina's section logic
void ll_insert(LinkedList *ll, char *oldspeak, char *newspeak) {
      if(ll_lookup(ll, oldspeak) != NULL){
          return NULL;
      }
      Node *nn = node_create(oldspeak, newspeak); //nn stands for new node to insert into the linked list
      
}

void ll_print(LinkedList *ll) {
    printf("LINKED LIST:\n");
    for (Node *i = ll->head->next; i != ll->tail; i = i->next) { //same iteration as delete ll
        node_print(i);
    }
}
