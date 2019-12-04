#ifndef BST_H
#define BST_H

typedef struct Node{
    int key;
    struct Node *left, *right;
} Node;

Node *createNode(int key);
Node *search(Node *node, int key);
Node *insert(Node *node, int key);
void pre_order(Node *node);
void pos_order(Node *node);
void in_order(Node *node);
int height(Node *node);
Node *search_parent(Node *node, int key);
Node *successor(Node *node, int key);
Node *predecessor(Node *node, int key);
Node *binary_search(Node* node, int key);
Node *find_maximum(Node *node);
Node *find_minimum(Node *node);
Node *remover(Node *node, int key);

#endif
