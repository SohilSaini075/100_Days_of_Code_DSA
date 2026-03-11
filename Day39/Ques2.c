// Top K Frequent Elements

#include <stdio.h>
#include <stdlib.h>

int cmpInt(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

typedef struct {
    int num;
    int freq;
} Pair;

int cmpPair(const void *a, const void *b) {
    return ((Pair *)b)->freq - ((Pair *)a)->freq;
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    qsort(nums, numsSize, sizeof(int), cmpInt);

    Pair *arr = (Pair *)malloc(numsSize * sizeof(Pair));
    int count = 0;

    int i = 0;
    while (i < numsSize) {
        int f = 1;
        while (i + 1 < numsSize && nums[i] == nums[i + 1]) {
            f++;
            i++;
        }
        arr[count].num = nums[i];
        arr[count].freq = f;
        count++;
        i++;
    }

    qsort(arr, count, sizeof(Pair), cmpPair);

    int *result = (int *)malloc(k * sizeof(int));
    for (int j = 0; j < k; j++) {
        result[j] = arr[j].num;
    }

    *returnSize = k;
    free(arr);
    return result;
}