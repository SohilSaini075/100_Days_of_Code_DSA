/*Problem Statement:
Implement a Min Heap using an array where the smallest element is always at the root.

Supported Operations:
- insert x
- extractMin
- peek */

#include <stdio.h>

#define MAX 1000

int heap[MAX];
int size = 0;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int i)
{
    while(i > 0 && heap[(i-1)/2] > heap[i])
    {
        swap(&heap[(i-1)/2], &heap[i]);
        i = (i-1)/2;
    }
}

void heapifyDown(int i)
{
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < size && heap[left] < heap[smallest])
        smallest = left;

    if(right < size && heap[right] < heap[smallest])
        smallest = right;

    if(smallest != i)
    {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

void insert(int x)
{
    heap[size] = x;
    heapifyUp(size);
    size++;
}

int extractMin()
{
    if(size == 0)
        return -1;

    int min = heap[0];
    heap[0] = heap[size-1];
    size--;

    heapifyDown(0);
    return min;
}

int peek()
{
    if(size == 0)
        return -1;
    return heap[0];
}

int main()
{
    int n;
    scanf("%d",&n);

    char op[20];
    int x;

    for(int i=0;i<n;i++)
    {
        scanf("%s",op);

        if(op[0]=='i') 
        {
            scanf("%d",&x);
            insert(x);
        }
        else if(op[0]=='e')
        {
            printf("%d\n",extractMin());
        }
        else if(op[0]=='p')
        {
            printf("%d\n",peek());
        }
    }

    return 0;
}