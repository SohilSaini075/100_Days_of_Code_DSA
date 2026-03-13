/*Problem Statement:
Implement a Queue using a linked list supporting enqueue and dequeue operations.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;

    if(front == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue() {
    if(front == NULL) {
        printf("-1\n");
        return;
    }

    struct Node* temp = front;
    printf("%d\n", front->data);
    front = front->next;

    if(front == NULL)
        rear = NULL;

    free(temp);
}

int main() {
    int n, x;
    char op[20];

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%s", op);

        if(strcmp(op, "enqueue") == 0) {
            scanf("%d", &x);
            enqueue(x);
        }
        else if(strcmp(op, "dequeue") == 0) {
            dequeue();
        }
    }

    return 0;
}