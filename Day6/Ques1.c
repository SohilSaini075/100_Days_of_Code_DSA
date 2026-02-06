/*Problem: Given a sorted array of n integers, remove duplicates in-place. Print only unique elements in order.

Input:
- First line: integer n
- Second line: n space-separated integers (sorted array)

Output:
- Print unique elements only, space-separated */

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    if (n == 0) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int j = 0;

    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[j]) {
            j++;
            arr[j] = arr[i];
        }
    }

    for (int i = 0; i <= j; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}