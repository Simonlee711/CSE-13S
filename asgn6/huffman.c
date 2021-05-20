#include "code.h"
#include "defines.h"
#include "node.h"
#include "pq.h"
#include "stack.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void Post_traversal(Node *n, Code *c, Code table[ALPHABET]) {
    if (n->left == NULL && n->right == NULL) {
        table[n->symbol] = *c;
        return;
    }
    uint8_t bit;
    code_push_bit(c, 0); //Sahiti said to add &.
    Post_traversal(n->left, c, table);
    code_pop_bit(c, &bit);
    code_push_bit(c, 1);
    Post_traversal(n->right, c, table);
    code_pop_bit(c, &bit);
    return;
}

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
    pq_delete(&pq);
    return temp;
}

void build_codes(Node *root, Code table[static ALPHABET]) {
    Code c = code_init();
    Post_traversal(root, &c, table);
}

Node *rebuild_tree(uint16_t nbytes, uint8_t tree[static nbytes]) {
    Stack *s = stack_create(nbytes);
    for (int i = 0; i < nbytes; i++) {
        if (tree[i] == 'L') {
            Node *n = node_create(tree[i + 1], 0); //how to access frequency and does it even matter anymore?
            stack_push(s, n);
        } else if (tree[i] == 'I') {
            Node *left_child;
            Node *right_child;
            stack_pop(s, &right_child);
            stack_pop(s, &left_child);
            stack_push(s, node_join(left_child, right_child));
        }
    }
    Node *parent;
    stack_pop(s, &parent);
    stack_delete(&s);
    return parent;
}

void delete_tree(Node **root) {
    if (*root == NULL) {
        return;
    }
    delete_tree(&(*root)->left);
    delete_tree(&(*root)->right);
    node_delete(root);
    return;
}
