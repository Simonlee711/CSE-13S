#include "node.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//strdup function - Sabrina's section
char *strdup(char *string) {
    char *pointer; //intializing empty pointer to return
    uint32_t length = strlen(string) + 1; //the goat jloritz from discord helped me here
    pointer = (char *) malloc(length);
    if (!pointer) {
        free(pointer);
        pointer = NULL;
        return NULL;
    }
    strcopy(pointer, string);
    return pointer;
}

Node *node_create(char *oldspeak, char *newspeak) {
    Node *n = (Node *) malloc(sizeof(Node));
    if (n) {
        n->oldspeak = strdup(oldspeak);
        n->newspeak = strdup(newspeak);
        n->next = NULL;
        n->prev = NULL;
    }
}

void node_delete(Node **n) {
    if ((*n) && ((*n)->oldspeak) && ((*n)->newspeak)) {
        free((*n)->newspeak);
        free((*n)->oldspeak);
        free(*n);
        *n = NULL;
    }
    return;
}

void node_print(Node *n) {
    if (n->oldspeak != NULL && n->newspeak != NULL) {
        printf("%s -> %s\n", n->oldspeak, n->newspeak);
    } else {
        printf("%s\n", n->oldspeak);
    }
}
