// Product of array except self

#include <stdio.h>

int main() {
    int n;

    scanf("%d", &n);

    int nums[n];
    int answer[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    answer[0] = 1;
    for(int i = 1; i < n; i++) {
        answer[i] = answer[i - 1] * nums[i - 1];
    }

    int suffix = 1;
    for(int i = n - 1; i >= 0; i--) {
        answer[i] = answer[i] * suffix;
        suffix *= nums[i];
    }

    for(int i = 0; i < n; i++) {
        printf("%d ", answer[i]);
    }

    return 0;
}