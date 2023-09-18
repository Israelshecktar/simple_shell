char *customGetline() {
    char *line = NULL;
    char c;
    size_t len = 0;
    size_t capacity = 0;

    while (1) {
        c = getchar();

        if (c == '\n' || c == EOF) {
            if (len > 0) {
                break;
            } else if (c == EOF) {
                free(line);
                return NULL;
            }
        }

        if (len + 1 >= capacity) {
            capacity += 10;
            char *newLine = realloc(line, capacity);
            if (newLine == NULL) {
                perror("Error (realloc)");
                free(line);
                return NULL;
            }
            line = newLine;
        }

        line[len++] = c;
    }

    if (len + 1 >= capacity) {
        capacity += 1;
        char *newLine = realloc(line, capacity);
        if (newLine == NULL) {
            perror("Error (realloc)");
            free(line);
            return NULL;
        }
        line = newLine;
    }
    line[len] = '\0';

    return line;
}
