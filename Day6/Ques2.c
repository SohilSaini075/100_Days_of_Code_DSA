/* Problem: Given an array of integers, move all 0's to the end of it while maintaining the relative order of the non-zero elements.*/

#include <stdio.h>

void moveZeroes(int nums[], int n) {
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] != 0) {
            nums[k++] = nums[i];
        }
    }
    while (k < n) {
        nums[k++] = 0;
    }
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter elements (comma-separated):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d,", &nums[i]);
    }

    moveZeroes(nums, n);

    printf("Array after moving zeros to end:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}