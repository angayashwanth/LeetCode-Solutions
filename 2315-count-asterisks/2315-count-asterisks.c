int countAsterisks(char* s) {
    int count = 0;
    int bars = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '|')
            bars++;
        else if (s[i] == '*' && bars % 2 == 0)
            count++;
    }

    return count;
}