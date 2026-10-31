int** rotateGrid(int** grid, int gridSize, int* gridColSize,
                 int k, int* returnSize, int** returnColumnSizes) {

    int m = gridSize;
    int n = gridColSize[0];

    int** ans = malloc(m * sizeof(int*));

    *returnSize = m;
    *returnColumnSizes = malloc(m * sizeof(int));

    for (int i = 0; i < m; i++) {
        ans[i] = malloc(n * sizeof(int));
        (*returnColumnSizes)[i] = n;
    }

    int layers = (m < n ? m : n) / 2;

    for (int layer = 0; layer < layers; layer++) {

        int top = layer;
        int left = layer;
        int bottom = m - 1 - layer;
        int right = n - 1 - layer;

        int len = 2 * (bottom - top + right - left);
        int* temp = malloc(len * sizeof(int));

        int idx = 0;

        // Store top row
        for (int j = left; j <= right; j++)
            temp[idx++] = grid[top][j];

        // Store right column
        for (int i = top + 1; i <= bottom; i++)
            temp[idx++] = grid[i][right];

        // Store bottom row
        for (int j = right - 1; j >= left; j--)
            temp[idx++] = grid[bottom][j];

        // Store left column
        for (int i = bottom - 1; i > top; i--)
            temp[idx++] = grid[i][left];

        int shift = k % len;
        idx = 0;

        // Rotate top row
        for (int j = left; j <= right; j++)
            ans[top][j] = temp[(idx++ + shift) % len];

        // Rotate right column
        for (int i = top + 1; i <= bottom; i++)
            ans[i][right] = temp[(idx++ + shift) % len];

        // Rotate bottom row
        for (int j = right - 1; j >= left; j--)
            ans[bottom][j] = temp[(idx++ + shift) % len];

        // Rotate left column
        for (int i = bottom - 1; i > top; i--)
            ans[i][left] = temp[(idx++ + shift) % len];

        free(temp);
    }

    return ans;
}