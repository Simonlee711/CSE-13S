//Stack implementation
//Sources: Darrell Long's Lecture Slides and Assignment Document
//Sources: Eugene's Section
//Sources: Sahiti's Section

#include "stack.h"

#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct Stack {
    uint32_t top;
    uint32_t capacity;
    uint32_t *items;
};

Stack *stack_create(uint32_t capacity) {
    Stack *s = (Stack *) malloc(sizeof(Stack));
    if (s) {
        s->top = 0;
        s->capacity = capacity;
        s->items = (uint32_t *) malloc(capacity * sizeof(uint32_t));
        if (!s->items) {
            free(s);
            s = NULL;
        }
    }
    return s;
}

void stack_delete(Stack **s) {
    if (*s && (*s)->items) {
        free((*s)->items);
        free(*s);
        *s = NULL;
    }
    return;
}

uint32_t stack_size(Stack *s) {
    printf("%d\n", s->top);
    return s->top;
}

bool stack_empty(Stack *s) {
    return s->top == 0;
}

bool stack_full(Stack *s) {
    return s->top == s->capacity;
}

bool stack_push(Stack *s, uint32_t x) {
    s->items[s->top] = x;
    s->top += 1;
    return true;
}

bool stack_pop(Stack *s, uint32_t *x) {
    s->top -= 1;
    *x = s->items[s->top];
    return true;
}

bool stack_peek(Stack *s, uint32_t *x){

}

void stack_copy(Stack *dst, Stack *src){

}

void stack_print(Stack *s, FILE *outfile, char *cities[]) {
    for(uint32_t i = 0; i < s->top; i += 1) {
	    fprintf(outfile,"%s", cities[s->items[i]]);
	    if( i+ 1 != s->top) {
		    fprintf(outfile,"->");
	    }
    }
    fprintf(outfile,"\n");
}
