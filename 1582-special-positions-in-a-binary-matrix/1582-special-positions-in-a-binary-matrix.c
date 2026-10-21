int numSpecial(int** mat, int matSize, int* matColSize) {
    
    int m = matSize;
    int n = matColSize[0];
    
    int rowCount[100] = {0};
    int colCount[100] = {0};
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(mat[i][j] == 1) {
                rowCount[i]++;
                colCount[j]++;
            }
        }
    }
    
    int special = 0;
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(mat[i][j] == 1 && rowCount[i] == 1 && colCount[j] == 1) {
                special++;
            }
        }
    }
    
    return special;
}