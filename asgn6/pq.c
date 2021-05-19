#include "pq.h"
#include "node.h"

#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct PriorityQueue {
    uint32_t capacity;
    uint32_t size;
    Node **arr;
    uint32_t head;
    uint32_t tail;
};

PriorityQueue *pq_create(uint32_t capacity) {
    PriorityQueue *q = malloc(sizeof(PriorityQueue));
    if (!q) {
        return NULL;
    }
    q->capacity = capacity;
    q->size = 0;
    q->head = 0;
    q->tail = 0;
    q->arr = calloc(capacity, sizeof(Node *));
    if (!q->arr) {
        free(q);
        q = NULL;
    }
    return q;
}
void pq_delete(PriorityQueue **q) {
    if (q) {
        free((*q)->arr);
        free(*q);
        *q = NULL;
    }
}

bool pq_empty(PriorityQueue *q) {
    return q->size == 0;
}

bool pq_full(PriorityQueue *q) {
    return q->size == q->capacity;
}

uint32_t pq_size(PriorityQueue *q) {
    return q->size;
}

bool enqueue(PriorityQueue *q, Node *n) {
    if (pq_full(q)) {
        return false;
    }
    q->size += 1;
    q->arr[q->tail] = n;
    q->tail = (q->tail + 1) % q->capacity;
    for (uint32_t i = q->tail - 2; i > q->head; --i) { //should be comparing with 2nd to last element in the pq
        if ((q->arr[q->tail - 1]->frequency) < (q->arr[i]->frequency)) {
            Node *temp = q->arr[q->tail - 1];
            q->arr[q->tail - 1] = q->arr[i];
            q->arr[i] = temp;
        }
    }
    return true;
}

bool dequeue(PriorityQueue *q, Node **n) { //look this over
    if (q->size == 0) {
        return false;
    }
    q->size -= 1;
    *n = q->arr[q->head];
    q->head = (q->head + 1) % q->capacity;
    return true;
}

void pq_print(PriorityQueue *q) {
    uint32_t index = q->head; //index is head
    while (&(q->arr[index]->frequency) != &(q->arr[q->tail])->frequency) {
        printf("%" PRId64, q->arr[index]->frequency);
        index = (index + 1) % q->capacity;
    }
    printf("%" PRId64, q->arr[q->tail]->frequency); //prints tail
}

int main(void){
printf("about to make pq");
PriorityQueue *pq = pq_create(20);
printf("made pq");
Node *n = node_create('a', 7);
Node *a = node_create('b', 5);
Node *b = node_create('c', 2);
printf("made nodes");
enqueue(pq, n);
enqueue(pq, a);
enqueue(pq, b);
pq_print(pq);
dequeue(pq, &b);
dequeue(pq, &a);
pq_print(pq);
printf("complete");
}
