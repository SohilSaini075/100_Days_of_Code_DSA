//Intersection of Two Arrays II problem

#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n1, n2;

    scanf("%d", &n1);
    int nums1[n1];

    for (int i = 0; i < n1; i++) {
        scanf("%d", &nums1[i]);
    }

    scanf("%d", &n2);
    int nums2[n2];

    for (int i = 0; i < n2; i++) {
        scanf("%d", &nums2[i]);
    }

    qsort(nums1, n1, sizeof(int), cmp);
    qsort(nums2, n2, sizeof(int), cmp);

    int i = 0, j = 0;
    int result[1000], k = 0;

    while (i < n1 && j < n2) {
        if (nums1[i] == nums2[j]) {
            result[k++] = nums1[i];
            i++;
            j++;
        } else if (nums1[i] < nums2[j]) {
            i++;
        } else {
            j++;
        }
    }

    for (int x = 0; x < k; x++) {
        printf("%d ", result[x]);
    }

    return 0;
}