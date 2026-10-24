int longestAlternatingSubarray(int* nums, int numsSize, int threshold) {
    int maxLen = 0;
    int len = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] % 2 == 0 && nums[i] <= threshold) {
            len = 1;

            for (int j = i + 1; j < numsSize; j++) {
                if (nums[j] > threshold ||
                    nums[j] % 2 == nums[j - 1] % 2) {
                    break;
                }
                len++;
            }

            if (len > maxLen)
                maxLen = len;
        }
    }

    return maxLen;
}