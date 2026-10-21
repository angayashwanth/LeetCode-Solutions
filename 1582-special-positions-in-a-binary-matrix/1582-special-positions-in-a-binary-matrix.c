int numSpecial(int** mat, int matSize, int* matColSize) {
    int count = 0;

    for (int i = 0; i < matSize; i++) {
        for (int j = 0; j < matColSize[i]; j++) {

            if (mat[i][j] == 1) {
                int row = 0;
                int col = 0;

                // Check the row
                for (int k = 0; k < matColSize[i]; k++) {
                    if (mat[i][k] == 1)
                        row++;
                }

                // Check the column
                for (int k = 0; k < matSize; k++) {
                    if (mat[k][j] == 1)
                        col++;
                }

                // Special position
                if (row == 1 && col == 1)
                    count++;
            }
        }
    }

    return count;
}