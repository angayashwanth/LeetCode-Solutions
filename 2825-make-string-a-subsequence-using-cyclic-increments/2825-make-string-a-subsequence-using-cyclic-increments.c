bool canMakeSubsequence(char* str1, char* str2) {
    int i = 0, j = 0;

    while (str1[i] != '\0' && str2[j] != '\0') {
        char next = (str1[i] == 'z') ? 'a' : str1[i] + 1;

        if (str1[i] == str2[j] || next == str2[j]) {
            j++;
        }

        i++;
    }

    return str2[j] == '\0';
}