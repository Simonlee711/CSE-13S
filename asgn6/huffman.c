#include "code.h"
#include "defines.h"
#include "node.h"
#include "pq.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

//uint64_t dfs(Node) {
//}

Node *build_tree(uint64_t hist[static ALPHABET]) {
    PriorityQueue *pq = pq_create(ALPHABET);
    for (int i = 0; i < ALPHABET; i++) {
        if (hist[i] != 0) {
            Node *n = node_create((char) i, hist[i]);
            enqueue(pq, n);
        }
    }
    Node *temp;
    while (pq_size(pq) != 1) {
        temp = node_create('$', 0);
        Node *temp2 = node_create('$', 0);
        dequeue(pq, &temp);
        dequeue(pq, &temp2);
        Node *new_node = node_join(temp, temp2);
        enqueue(pq, new_node);
    }
    dequeue(pq, &temp); //freeing memory could lead to leaks check at the end
    return temp;
}
/*
void build_codes(Node *root, Code table[static ALPHABET]) {
}

Node *rebuild_tree(uint16_t nbytes, uint8_t tree[static nbytes]) {
}

void delete_tree(Node **root) {
}
*/
