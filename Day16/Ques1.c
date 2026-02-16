/*Problem: Given an array of integers, count the frequency of each distinct element and print the result.

Input:
- First line: integer n (size of array)
- Second line: n integers

Output:
- Print each element followed by its frequency in the format element:count */

#include <stdio.h>

int main() {
    int n;

    
    scanf("%d", &n);

    int arr[n];

    
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    
    for(int i = 0; i < n; i++) {
        int count = 1;

        
        if(arr[i] == -1)
            continue;

        for(int j = i + 1; j < n; j++) {
            if(arr[i] == arr[j]) {
                count++;
                arr[j] = -1; 
            }
        }

        printf("%d:%d ", arr[i], count);
    }

    return 0;
}