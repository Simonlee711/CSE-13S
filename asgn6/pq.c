#include "node.h"
#include "pq.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct PriorityQueue{
  uint32_t capacity;
  uint32_t size;
  Node **arr;
  uint32_t head;
  uint32_t tail;     
};

PriorityQueue *pq_create(uint32_t capacity){
  PriorityQueue *q = (PriorityQueue*)malloc(sizeof(PriorityQueue));
  if(!q){
    return NULL;
  }
  q->capacity = capcity;
  q->size = 0;
  q->head = 0;
  q->tail = 0;
  q->arr = (uint8_t*)calloc(capacity, sizeof(uint8_t));
  if(!q->arr){
    free(q);
    q = NULL;
  }
}
void pq_delete(PriorityQueue **q){
  if(q){
    free((*q)->arr);
    free(*q);
    *q = NULL;
  }
}

bool pq_empty(PriorityQueue *q){
  return q->size == 0;
}

bool pq_full(PriorityQueue *q){
  return q->size == q->capacity;
}

uint32_t pq_size(PriorityQueue *q){
  return q->size;
}

bool enqueue(PriorityQueue *q, Node *n){
  if(pq_full(q)){
    return false;
} 
  q->size += 1;
  q->arr[q->tail] = n;
  q->tail = (q->tail + 1) % q->capacity;
  for(uint32_t i = q->tail - 2; q > q->head; --1){ //should be comparing with 2nd to last element in the pq
    if((q->arr[q->tail -1]->frequency) < (q->arr[i]->frequency)){
      Node *temp = q->arr[q->tail-1];
      q->arr[q->tail - 1] = q->arr[i];
      q->arr[i] = temp;
    }
    
}

bool dequeue(PriorityQueue *q, Node **n){ //look this over
  if (q->size == 0) {
        return false;
    }
    q->size -= 1;
    *n = q->items[q->head];
    q->head = (q->head + 1) % q->capacity;
    return true;

}

void pq_print(PriorityQueue *q){
  uint32_t index = q->head; //index is head
    while (&(q->arr[index]->frequency) != &(q->arr[q->tail])->frequency) { 
        printf("%" PRId64, q->arr[index]); 
        index = (index + 1) % q->capacity; 
    }
    printf("%" PRId64, q->arr[q->tail]); //prints tail
}



