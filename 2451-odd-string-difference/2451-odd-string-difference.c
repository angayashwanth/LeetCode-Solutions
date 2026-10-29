char* oddString(char** words, int wordsSize) {
    int n = strlen(words[0]);
    int diff[wordsSize][n - 1];

    for (int i = 0; i < wordsSize; i++) {
        for (int j = 0; j < n - 1; j++) {
            diff[i][j] = words[i][j + 1] - words[i][j];
        }
    }

    for (int i = 0; i < wordsSize; i++) {
        int count = 0;

        for (int k = 0; k < wordsSize; k++) {
            if (i == k)
                continue;

            int same = 1;

            for (int j = 0; j < n - 1; j++) {
                if (diff[i][j] != diff[k][j]) {
                    same = 0;
                    break;
                }
            }

            if (same)
                count++;
        }

        if (count == 0)
            return words[i];
    }

    return words[0];
}