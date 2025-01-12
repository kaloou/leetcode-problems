#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct {
    int num;
    int freq;
} HashStruct;

int compare(const void *a, const void *b) {
    return ((HashStruct *)b)->freq - ((HashStruct *)a)->freq;
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    int hashSize = numsSize;
    HashStruct* hashMap = malloc(hashSize * sizeof(HashStruct));
    int hashCount = 0;

    // initialize ash table
    for (int i = 0; i < hashSize; i++) {
        hashMap[i].num = INT_MIN;
        hashMap[i].freq = 0;
    }

    for (int i = 0; i < numsSize; i++) // loop in nums
    {
        int found = 0;
        for (int j = 0; j < hashCount; j++) // search the num in the ash table
        {
            if (hashMap[j].num == nums[i]) // founded
            {
                hashMap[j].freq++;
                found = 1;
                break;
            }
        }
        if (!found) // not founded so add it
        {
            hashMap[hashCount].num = nums[i];
            hashMap[hashCount].freq = 1;
            hashCount++;
        }
    }
    
    qsort(hashMap, hashCount, sizeof(HashStruct), compare);

    int* result = malloc(k * sizeof(int));
    for (int i = 0; i < k; i++) {
        result[i] = hashMap[i].num;
    }

    *returnSize = k;

    free(hashMap);

    return result;
}

int main(void) {
    int nums[] = {1, 1, 1, 2, 2, 3, 3, 3,4,9,0,34,3,8,34,1,3,};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = 4;
    int returnSize;

    int* output = topKFrequent(nums, numsSize, k, &returnSize);

    printf("top %d frequent elements:\n", k);
    for (int i = 0; i < returnSize; i++) {
        printf("%d\n", output[i]);
    }

    free(output);

    return 0;
}
