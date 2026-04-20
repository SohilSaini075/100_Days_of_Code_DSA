/*Problem Statement
Find shortest distances from source vertex in a weighted graph with non-negative weights.

Input Format
n m
u v w
source

Output Format
Distances to all vertices. */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 1000

struct Node {
    int vertex;
    int weight;
    struct Node* next;
};

struct MinHeapNode {
    int vertex;
    int dist;
};

struct Node* createNode(int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct Node* adj[], int u, int v, int w) {
    struct Node* newNode = createNode(v, w);
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = createNode(u, w);
    newNode->next = adj[v];
    adj[v] = newNode;
}

void swap(struct MinHeapNode* a, struct MinHeapNode* b) {
    struct MinHeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(struct MinHeapNode heap[], int size, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < size && heap[left].dist < heap[smallest].dist)
        smallest = left;

    if (right < size && heap[right].dist < heap[smallest].dist)
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(heap, size, smallest);
    }
}

struct MinHeapNode extractMin(struct MinHeapNode heap[], int* size) {
    struct MinHeapNode root = heap[0];
    heap[0] = heap[*size - 1];
    (*size)--;
    heapify(heap, *size, 0);
    return root;
}

void decreaseKey(struct MinHeapNode heap[], int size, int v, int dist) {
    for (int i = 0; i < size; i++) {
        if (heap[i].vertex == v) {
            heap[i].dist = dist;
            while (i && heap[i].dist < heap[(i - 1) / 2].dist) {
                swap(&heap[i], &heap[(i - 1) / 2]);
                i = (i - 1) / 2;
            }
            break;
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[MAX] = {NULL};

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(adj, u, v, w);
    }

    int source;
    scanf("%d", &source);

    int dist[MAX];
    struct MinHeapNode heap[MAX];
    int size = n;

    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
        heap[i - 1].vertex = i;
        heap[i - 1].dist = INT_MAX;
    }

    dist[source] = 0;

    for (int i = 0; i < n; i++) {
        if (heap[i].vertex == source) {
            heap[i].dist = 0;
            break;
        }
    }

    for (int i = (n / 2) - 1; i >= 0; i--)
        heapify(heap, size, i);

    while (size > 0) {
        struct MinHeapNode minNode = extractMin(heap, &size);
        int u = minNode.vertex;

        struct Node* temp = adj[u];
        while (temp != NULL) {
            int v = temp->vertex;
            int weight = temp->weight;

            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                decreaseKey(heap, size, v, dist[v]);
            }
            temp = temp->next;
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }

    return 0;
}