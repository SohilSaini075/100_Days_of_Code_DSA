//Maximum Sum Circular Subarray

#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int maxSubarraySumCircular(int nums[], int n) {
    int total_sum = nums[0];
    
    int max_current = nums[0];
    int max_global = nums[0];
    
    int min_current = nums[0];
    int min_global = nums[0];
    
    for(int i = 1; i < n; i++) {
        max_current = max(nums[i], max_current + nums[i]);
        max_global = max(max_global, max_current);
        
        min_current = min(nums[i], min_current + nums[i]);
        min_global = min(min_global, min_current);
        
        total_sum += nums[i];
    }
    
    if(max_global < 0)
        return max_global;
    
    return max(max_global, total_sum - min_global);
}

int main() {
    int n;
    scanf("%d", &n);
    
    int nums[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &nums[i]);
    
    printf("%d\n", maxSubarraySumCircular(nums, n));
    
    return 0;
}