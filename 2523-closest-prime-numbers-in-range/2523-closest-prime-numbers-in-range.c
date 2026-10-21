
#include <stdlib.h>

int isPrime(int n) {
    if (n < 2)
        return 0;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return 0;
    }

    return 1;
}

int* closestPrimes(int left, int right, int* returnSize) {
    int* ans = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;

    ans[0] = -1;
    ans[1] = -1;

    int prev = -1;
    int minDiff = right - left + 1;

    for (int i = left; i <= right; i++) {
        if (isPrime(i)) {
            if (prev != -1 && i - prev < minDiff) {
                minDiff = i - prev;
                ans[0] = prev;
                ans[1] = i;

                if (minDiff == 2)
                    break;
            }

            prev = i;
        }
    }

    return ans;
}
