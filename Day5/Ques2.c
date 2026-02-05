/* Merge Sorted Arrays*/

#include <stdio.h>

int main() {
    int m, n;

    printf("Enter m (number of elements in nums1): ");
    scanf("%d", &m);

    printf("Enter n (number of elements in nums2): ");
    scanf("%d", &n);

    int nums1[m + n], nums2[n];

    printf("Enter %d elements of nums1 (sorted):\n", m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &nums1[i]);
    }

    for (int i = m; i < m + n; i++) {
        nums1[i] = 0;
    }

    printf("Enter %d elements of nums2 (sorted):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums2[i]);
    }

    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k--] = nums1[i--];
        } else {
            nums1[k--] = nums2[j--];
        }
    }

    while (j >= 0) {
        nums1[k--] = nums2[j--];
    }

    printf("Merged array:\n");
    for (int i = 0; i < m + n; i++) {
        printf("%d ", nums1[i]);
    }

    return 0;
}