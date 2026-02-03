/* you are given an array arr[] of size n - 1 that contains distinct integers in the range from 1 to n (inclusive).
This array represents a permutation of the integers from 1 to n with one element missing. Your task is to identify and return the missing element */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, actualSum = 0;

    printf("Enter the value of n (total numbers in sequence): ");
    if (scanf("%d", &n) != 1 || n < 2) {
        printf("Invalid input. n must be at least 2.\n");
        return 1;
    }

    long long expectedSum = (long long)n * (n + 1) / 2;

    printf("Enter the %d elements (separated by space):\n", n - 1);
    for (int i = 0; i < n - 1; i++) {
        int temp;
        scanf("%d", &temp);
        actualSum += temp;
    }

    int missingElement = (int)(expectedSum - actualSum);
    printf("\nThe missing element is: %d\n", missingElement);

    return 0;
}