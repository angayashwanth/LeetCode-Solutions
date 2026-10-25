
#include <stdlib.h>
#include <string.h>

char* getPermutation(int n, int k) {
    static char result[10];
    int fact[10];
    int nums[10];

    fact[0] = 1;

    for (int i = 1; i <= n; i++)
        fact[i] = fact[i - 1] * i;

    for (int i = 0; i < n; i++)
        nums[i] = i + 1;

    k--;

    for (int i = 0; i < n; i++) {
        int index = k / fact[n - 1 - i];
        result[i] = nums[index] + '0';

        for (int j = index; j < n - i - 1; j++)
            nums[j] = nums[j + 1];

        k %= fact[n - 1 - i];
    }

    result[n] = '\0';
    return result;
}
