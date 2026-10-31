char* decodeMessage(char* key, char* message) {
    char map[26];
    int visited[26] = {0};
    int index = 0;

    // Build the substitution table
    for (int i = 0; key[i] != '\0'; i++) {
        if (key[i] == ' ')
            continue;

        int pos = key[i] - 'a';

        if (!visited[pos]) {
            map[pos] = 'a' + index;
            visited[pos] = 1;
            index++;
        }
    }

    // Decode the message
    for (int i = 0; message[i] != '\0'; i++) {
        if (message[i] != ' ') {
            message[i] = map[message[i] - 'a'];
        }
    }

    return message;
}