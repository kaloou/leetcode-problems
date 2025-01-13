#include "stdio.h"
#include "stdlib.h"

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
	int * result = malloc(sizeof(int) * numsSize);
	int product;
	int end;
	for (int i = 0;i < numsSize;i++)
	{	
		product = 1;
		end = i + numsSize;
		for (int j = i;j < end -1;j++)
		{
			product *= nums[(j+1) % numsSize];		
		}
		result[i] = product;
	}
	*returnSize = numsSize;

	return result;   
}




int main(void)
{
	int nums[] = {1,2,3,4};
	int size = 4;
	int returnsize;
	int *output;

	output = productExceptSelf(nums,size,&returnsize);
	for (int i = 0;i < size;i++)
		printf("%d\n",output[i]);

	free(output);
	return 0;
}
