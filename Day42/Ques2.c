// Find Median from Data Stream

#include <stdlib.h>

typedef struct {
    int left[50005];   // max heap
    int right[50005];  // min heap
    int leftSize;
    int rightSize;
} MedianFinder;

void maxHeapPush(int heap[], int *size, int val) {
    int i = (*size)++;
    heap[i] = val;

    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[parent] >= heap[i]) break;

        int temp = heap[parent];
        heap[parent] = heap[i];
        heap[i] = temp;
        i = parent;
    }
}

int maxHeapPop(int heap[], int *size) {
    int top = heap[0];
    heap[0] = heap[--(*size)];

    int i = 0;
    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left < *size && heap[left] > heap[largest])
            largest = left;
        if (right < *size && heap[right] > heap[largest])
            largest = right;

        if (largest == i) break;

        int temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;
        i = largest;
    }

    return top;
}

int maxHeapTop(int heap[]) {
    return heap[0];
}

void minHeapPush(int heap[], int *size, int val) {
    int i = (*size)++;
    heap[i] = val;

    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[parent] <= heap[i]) break;

        int temp = heap[parent];
        heap[parent] = heap[i];
        heap[i] = temp;
        i = parent;
    }
}

int minHeapPop(int heap[], int *size) {
    int top = heap[0];
    heap[0] = heap[--(*size)];

    int i = 0;
    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < *size && heap[left] < heap[smallest])
            smallest = left;
        if (right < *size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest == i) break;

        int temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;
        i = smallest;
    }

    return top;
}

int minHeapTop(int heap[]) {
    return heap[0];
}

MedianFinder* medianFinderCreate() {
    MedianFinder* obj = (MedianFinder*)malloc(sizeof(MedianFinder));
    obj->leftSize = 0;
    obj->rightSize = 0;
    return obj;
}

void medianFinderAddNum(MedianFinder* obj, int num) {

    maxHeapPush(obj->left, &obj->leftSize, num);

    int moved = maxHeapPop(obj->left, &obj->leftSize);
    minHeapPush(obj->right, &obj->rightSize, moved);

    if (obj->rightSize > obj->leftSize) {
        int movedBack = minHeapPop(obj->right, &obj->rightSize);
        maxHeapPush(obj->left, &obj->leftSize, movedBack);
    }
}

double medianFinderFindMedian(MedianFinder* obj) {
    if (obj->leftSize > obj->rightSize) {
        return (double)maxHeapTop(obj->left);
    }
    return ((double)maxHeapTop(obj->left) + (double)minHeapTop(obj->right)) / 2.0;
}

void medianFinderFree(MedianFinder* obj) {
    free(obj);
}