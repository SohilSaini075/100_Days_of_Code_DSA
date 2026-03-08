/*Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements to enqueue)
- Second line: n space-separated integers
- Third line: integer m (number of dequeue operations)

Output:
- Print queue elements from front to rear after operations, space-separated

*/

#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int val)
{
    if((rear + 1) % MAX == front)
        return;

    if(front == -1)
        front = 0;

    rear = (rear + 1) % MAX;
    queue[rear] = val;
}

void dequeue()
{
    if(front == -1)
        return;

    if(front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX;
}

void display()
{
    int i = front;

    while(1)
    {
        printf("%d ", queue[i]);

        if(i == rear)
            break;

        i = (i + 1) % MAX;
    }
}

int main()
{
    int n, m, x, i;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &x);
        enqueue(x);
    }

    scanf("%d", &m);

    for(i = 0; i < m; i++)
        dequeue();

    display();

    return 0;
}