#include <stdlib.h>

int* distinctDifferenceArray(int* nums, int numsSize, int* returnSize) {
    int* diff = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;

    for (int i = 0; i < numsSize; i++) {
        int prefixCount = 0;
        int suffixCount = 0;

        for (int j = 0; j <= i; j++) {
            int unique = 1;
            for (int k = 0; k < j; k++) {
                if (nums[k] == nums[j]) {
                    unique = 0;
                    break;
                }
            }
            if (unique) prefixCount++;
        }

        for (int j = i + 1; j < numsSize; j++) {
            int unique = 1;
            for (int k = i + 1; k < j; k++) {
                if (nums[k] == nums[j]) {
                    unique = 0;
                    break;
                }
            }
            if (unique) suffixCount++;
        }

        diff[i] = prefixCount - suffixCount;
    }

    return diff;
}
