/* Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target. */
/*You may assume that each input would have exactly one solution, and you may not use the same element twice. You can return the answer in any order.*/

#include <stdio.h>
#include <stdlib.h> // Required for malloc

/**
 * Function to find the indices of two numbers that sum up to a target.
 * Assumes exactly one solution exists and no element is used twice.
 * 
 * @param nums The input array of integers.
 * @param numsSize The size of the array.
 * @param target The target sum.
 * @param returnSize Pointer to an integer to store the size of the result array (will be 2).
 * @return An array containing the two indices, or NULL if no solution found (though problem guarantees a solution).
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* ans = (int*)malloc(2 * sizeof(int)); // Dynamically allocate memory for the result indices

    if (ans == NULL) {
        // Handle memory allocation failure
        return NULL;
    }

    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                ans[0] = i;
                ans[1] = j;
                return ans; // Return the indices immediately upon finding the solution
            }
        }
    }

    // This part should ideally not be reached given the problem constraints
    // (guaranteed exactly one solution)
    *returnSize = 0;
    free(ans); // Free allocated memory if no solution found
    return NULL;
}

int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    
    // Call the twoSum function
    int* indices = twoSum(nums, numsSize, target, &returnSize);

    if (indices != NULL) {
        printf("Indices of the two numbers are: [%d, %d]\n", indices[0], indices[1]);
        free(indices); // Free the allocated memory after use
    } else {
        printf("No two sum solution found.\n");
    }

    return 0;
}