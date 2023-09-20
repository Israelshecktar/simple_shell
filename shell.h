#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define READ_SIZE 1024
int sj_strlen(char *str);
int sj_putchar(char c);
void sj_puts(char *str);
int sj_strcmp(char *s1, char *s2);

/*Line functions*/
void print_prompt(void);
char *Sj_custom_getline(char *buffer, size_t size, FILE *stream);
/*under_review*/
void my_prompt(void);
void shecktar_write(const char *input);

#endif /* SHELL_H */
