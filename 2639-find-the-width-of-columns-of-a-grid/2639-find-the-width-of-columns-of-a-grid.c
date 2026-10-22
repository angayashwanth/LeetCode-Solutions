#include <stdlib.h>
int getLength(int x) {
    int len = 0;

    if (x <= 0)
        len++;

    while (x != 0) {
        len++;
        x /= 10;
    }

    return len;
}

int* findColumnWidth(int** grid, int gridSize, int* gridColSize, int* returnSize) {
    int n = gridColSize[0];
    int* ans = (int*)malloc(n * sizeof(int));

    *returnSize = n;

    for (int j = 0; j < n; j++) {
        int maxWidth = 0;

        for (int i = 0; i < gridSize; i++) {
            int len = getLength(grid[i][j]);

            if (len > maxWidth)
                maxWidth = len;
        }

        ans[j] = maxWidth;
    }

    return ans;
}