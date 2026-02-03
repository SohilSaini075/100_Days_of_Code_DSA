#include <stdio.h>

int main() {
    int n, k, i;
    int comparisons = 0;

    // Input size of array
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input key to search
    scanf("%d", &k);

    // Linear Search
    for(i = 0; i < n; i++) {
        comparisons++;
        if(arr[i] == k) {
            printf("Found at index %d\n", i);
            printf("Comparisons = %d\n", comparisons);
            return 0;
        }
    }

    // If not found
    printf("Not Found\n");
    printf("Comparisons = %d\n", comparisons);

    return 0;
}