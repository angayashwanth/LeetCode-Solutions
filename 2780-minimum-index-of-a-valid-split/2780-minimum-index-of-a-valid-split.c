int minimumIndex(int* nums, int numsSize) {
    int candidate = nums[0], count = 0;

    for (int i = 0; i < numsSize; i++) {
        if (count == 0)
            candidate = nums[i];

        if (nums[i] == candidate)
            count++;
        else
            count--;
    }

    int total = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == candidate)
            total++;
    }

    int left = 0;

    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] == candidate)
            left++;

        int right = total - left;

        if (left * 2 > i + 1 &&
            right * 2 > numsSize - i - 1)
            return i;
    }

    return -1;
}
