//Queue implementation
//SOURCES: Darrell Long's slides and assignment doc
//Sources: Eugene's section
//Sources: Sahiti's Section

struct Queue {
  uint32_t head;
  uint32_t tail;
  uint32_t size;
  uint32_t capacity
  int64_t *items;
}

Queue *queue_create(uint32_t capacity){
  queue *q = (queue *)malloc(sizeof(queue));
  if (q){
    q->head = 0;
    q->tail = 0;
    q->size = size;
    q->capacity = capacity
    q->items = (int64_t *)calloc(size, sizeof(int64_t));
    if(!q->items){
      free(q);
      q = NULL;
    }
  }
  return q;
}

void queue_delete(Queue **q){
  if (q){
    free((*q)->items);
    free(*q);
    *q = NULL;
  }

}

bool queue_empty(Queue *q){
  return q->size == 0
}

bool queue_full(Queue *q){
  return q->size == q->capacity
}

uint32_t queue_size(Queue *q){

}

bool enqueue(Queue *q, int64_t x){
  if(q){
    if (full_queue(q)) {
      return false;
    }
    q->size += 1;
    q->items[q->tail] = x;
    q->tail = (q->tail + 1) % q->cap;
    return true;

  }
}

bool dequeue(Queue *q, int64_t *x){
if(q->size == 0){
  return false;
  }
  q->size -= 1;
  *x = q->items[q->head];
  q->head = (q->head + 1) % q->cap;
  return true;
}

void queue_print(Queue *q){

}
