char *customStrtok(char *str, const char *delim) {
    static char *token;
    if (str != NULL) {
        token = str;
    } else if (token == NULL) {
        return NULL;
    }

    char *start = token;
    token = strpbrk(start, delim);

    if (token != NULL) {
        *token = '\0'; /*Replace the delimiter with null terminator*/
        token++; /* Move past the delimiter*/
    }

    return start;
}
