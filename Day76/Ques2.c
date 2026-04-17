// Clone Graph

#include <stdlib.h>

#define MAX 101

struct Node* visited[MAX];

struct Node* clone(struct Node* node) {
    if (node == NULL)
        return NULL;

    if (visited[node->val] != NULL)
        return visited[node->val];

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = node->val;
    newNode->numNeighbors = node->numNeighbors;

    newNode->neighbors = (struct Node**)malloc(sizeof(struct Node*) * node->numNeighbors);

    visited[node->val] = newNode;

    for (int i = 0; i < node->numNeighbors; i++) {
        newNode->neighbors[i] = clone(node->neighbors[i]);
    }

    return newNode;
}

struct Node *cloneGraph(struct Node *s) {
    if (s == NULL)
        return NULL;

    for (int i = 0; i < MAX; i++)
        visited[i] = NULL;

    return clone(s);
}