#include <stdlib.h>

int compare(const void* a, const void* b) {
    int x = *(const int*)a;
    int y = *(const int*)b;
    return (x > y) - (x < y);
}

long long makeSubKSumEqual(int* arr, int arrSize, int k) {
    int a = arrSize, b = k;

    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }

    int g = a;
    int visited[arrSize];
    long long ans = 0;

    for (int i = 0; i < arrSize; i++)
        visited[i] = 0;

    for (int i = 0; i < g; i++) {
        int values[arrSize];
        int count = 0;
        int j = i;

        while (!visited[j]) {
            visited[j] = 1;
            values[count++] = arr[j];
            j = (j + k) % arrSize;
        }

        qsort(values, count, sizeof(int), compare);

        int median = values[count / 2];

        for (int x = 0; x < count; x++) {
            long long diff = (long long)values[x] - median;
            ans += diff < 0 ? -diff : diff;
        }
    }

    return ans;
}