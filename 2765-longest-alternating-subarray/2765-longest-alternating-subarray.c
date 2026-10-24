int alternatingSubarray(int* nums, int numsSize) {
    int maxLen = -1;
    int len = 1;

    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i + 1] - nums[i] == 1) {
            len = 2;

            for (int j = i + 1; j < numsSize - 1; j++) {
                if (nums[j + 1] - nums[j] == (len % 2 == 0 ? -1 : 1)) {
                    len++;
                } else {
                    break;
                }
            }

            if (len > maxLen)
                maxLen = len;
        }
    }

    return maxLen;
}
