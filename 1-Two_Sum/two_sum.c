#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int *array_sols = (int *)malloc(sizeof(int) * 2);
    if (!array_sols)
        return NULL;

    int i = 0;
    while (i < numsSize - 1) {
        int j = i + 1;
        while (j < numsSize) {
            
            if (nums[i] + nums[j] == target) {
                array_sols[0] = i;
                array_sols[1] = j;
                *returnSize = 2;  
                return array_sols;
            }
            j++;
        }
        i++;
    }

    *returnSize = 0; 
    free(array_sols);  
    return NULL;    
}
