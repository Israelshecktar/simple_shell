char *customGetline() {
    char *line = NULL;
    char c;
    size_t len = 0;
    size_t capacity = 0;

    while (1) {
        c = getchar();

        if (c == '\n' || c == EOF) {
            if (len > 0) {
                break; /* Stop reading when a newline or EOF is encountered*/
            } else if (c == EOF) {
                free(line);
                return NULL; /* Return NULL if no input was read before EOF*/
            }
        }

        if (len + 1 >= capacity) {
            capacity += 10; /*Increase capacity in chunks*/
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

    /* Null-terminate the string*/
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
