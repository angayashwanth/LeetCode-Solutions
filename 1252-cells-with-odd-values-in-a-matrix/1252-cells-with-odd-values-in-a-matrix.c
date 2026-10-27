
int oddCells(int m, int n, int** indices, int indicesSize, int* indicesColSize) {
    int row[ m ];
    int col[ n ];
    int count = 0;

    for (int i = 0; i < m; i++)
        row[i] = 0;

    for (int j = 0; j < n; j++)
        col[j] = 0;

    for (int i = 0; i < indicesSize; i++) {
        row[indices[i][0]]++;
        col[indices[i][1]]++;
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if ((row[i] + col[j]) % 2 != 0)
                count++;
        }
    }

    return count;
}
