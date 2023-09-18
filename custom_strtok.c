char *customStrtok(char *str, const char *delim) {
    static char *token; // Static variable to store the position between calls
    if (str != NULL) {
        token = str;
    } else if (token == NULL) {
        return NULL; // If no string provided and no previous position, return NULL
    }

    char *start = token;
    token = strpbrk(start, delim); // Find the next delimiter in the remaining string

    if (token != NULL) {
        *token = '\0'; // Replace the delimiter with null terminator
        token++; // Move past the delimiter
    }

    return start;
}
