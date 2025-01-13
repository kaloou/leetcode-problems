#include <stdio.h>
#include <stdlib.h>

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int* res = (int*)malloc(numsSize * sizeof(int));
    if (!res) return NULL;

    int* pref = (int*)malloc(numsSize * sizeof(int));
    int* suff = (int*)malloc(numsSize * sizeof(int));
    if (!pref || !suff) {
        free(res);
        return NULL;
    }

    pref[0] = 1;
    suff[numsSize - 1] = 1;

    for (int i = 1; i < numsSize; i++) {
        pref[i] = nums[i - 1] * pref[i - 1];
    }

    for (int i = numsSize - 2; i >= 0; i--) {
        suff[i] = nums[i + 1] * suff[i + 1];
    }

    for (int i = 0; i < numsSize; i++) {
        res[i] = pref[i] * suff[i];
    }

    free(pref);
    free(suff);

    *returnSize = numsSize;
    return res;
}


int main() {
    int nums[] = {1, 2, 3, 4};
    int size = 4;
    int returnSize;

    int* result = productExceptSelf(nums, size, &returnSize);

    if (result) {
        printf("Résultat : ");
        for (int i = 0; i < returnSize; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
        free(result);
    }

    return 0;
}
