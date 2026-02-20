/*Problem: Given an array of integers, count the number of subarrays whose sum is equal to zero.

Input:
- First line: integer n
- Second line: n integers

Output:
- Print the count of subarrays having sum zero */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int prefix_sum = 0;
    long long count = 0;

    int size = 2 * 100000 + 1;
    int offset = 100000; 
    long long freq[size];

    for(int i = 0; i < size; i++)
        freq[i] = 0;

    freq[offset] = 1;

    for(int i = 0; i < n; i++) {
        prefix_sum += arr[i];

        count += freq[prefix_sum + offset];
        freq[prefix_sum + offset]++;
    }

    printf("%lld\n", count);

    return 0;
}