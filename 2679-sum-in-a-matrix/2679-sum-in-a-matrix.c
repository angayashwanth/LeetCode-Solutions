int compare(const void *a, const void *b) {
    return (*(int *)a > *(int *)b) - (*(int *)a < *(int *)b);
}

int matrixSum(int** nums, int numsSize, int* numsColSize) {
    int cols = numsColSize[0];
    int score = 0;

    for (int i = 0; i < numsSize; i++) {
        qsort(nums[i], cols, sizeof(int), compare);
    }

    for (int j = 0; j < cols; j++) {
        int max = 0;

        for (int i = 0; i < numsSize; i++) {
            if (nums[i][j] > max) {
                max = nums[i][j];
            }
        }

        score += max;
    }

    return score;
}