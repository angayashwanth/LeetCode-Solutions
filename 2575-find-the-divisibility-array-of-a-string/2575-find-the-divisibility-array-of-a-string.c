/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int* divisibilityArray(char* word, int m, int* returnSize) {
    int n = 0;

    while (word[n] != '\0')
        n++;

    int* div = (int*)malloc(n * sizeof(int));
    long long rem = 0;

    *returnSize = n;

    for (int i = 0; i < n; i++) {
        rem = (rem * 10 + (word[i] - '0')) % m;

        if (rem == 0)
            div[i] = 1;
        else
            div[i] = 0;
    }

    return div;
}