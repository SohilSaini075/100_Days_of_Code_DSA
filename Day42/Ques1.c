/*Problem Statement:
Given a queue of integers, reverse the queue using a stack.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers

Output Format:
- Print the reversed queue*/

#include <stdio.h>
#define MAX 100

int queue[MAX], stack[MAX];
int front = 0, rear = -1;
int top = -1;

void enqueue(int x) {
    queue[++rear] = x;
}

int dequeue() {
    return queue[front++];
}

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int isQueueEmpty() {
    return front > rear;
}

int isStackEmpty() {
    return top == -1;
}

int main() {
    int n, i, x;

    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    while(!isQueueEmpty()) {
        push(dequeue());
    }

    front = 0;
    rear = -1;

    while(!isStackEmpty()) {
        enqueue(pop());
    }

    for(i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}