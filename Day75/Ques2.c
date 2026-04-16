// Is Graph Bipartite?


#include <stdbool.h>
#include <stdlib.h>

#define MAX 100

// Queue structure
typedef struct {
    int data[MAX];
    int front, rear;
} Queue;

void initQueue(Queue* q) {
    q->front = q->rear = 0;
}

bool isEmpty(Queue* q) {
    return q->front == q->rear;
}

void enqueue(Queue* q, int val) {
    q->data[q->rear++] = val;
}

int dequeue(Queue* q) {
    return q->data[q->front++];
}

bool isBipartite(int** graph, int graphSize, int* graphColSize) {
    int color[MAX];

    for (int i = 0; i < graphSize; i++) {
        color[i] = -1;
    }

    Queue q;

    for (int i = 0; i < graphSize; i++) {
        if (color[i] == -1) {
            initQueue(&q);
            enqueue(&q, i);
            color[i] = 0;

            while (!isEmpty(&q)) {
                int node = dequeue(&q);

                for (int j = 0; j < graphColSize[node]; j++) {
                    int neighbor = graph[node][j];

                    if (color[neighbor] == -1) {
                        color[neighbor] = 1 - color[node];
                        enqueue(&q, neighbor);
                    }
                    else if (color[neighbor] == color[node]) {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}