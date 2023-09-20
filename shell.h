#ifndef SHELL_H
#define SHELL_H

#define READ_SIZE 1024

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


void shecktar_write(const char *input);
void my_prompt(void);
void Ex_prompt(char **input);
char *take_inputs(char *input, size_t insize, FILE *stream);
void tkn_prompt(char *input);
char *find_cmd_path(char *command);
void exe_cmd(const char *cmd_path, char *const argv[]);
char **sj_get_input(char *input);
int hndl_cd(char **args);
/********my_getline function******/
char *shecktar_getline(char *buffer, size_t size, FILE *stream);
/**********externs***********/
extern char **environ;
void hndl_env(void);
void sj_setenv(char **args);
void sj_unsetenv(char **args);
int hndl_builtins(char **args);
/**********Utils*********/
int sj_snprintf(char *in_str, size_t n, const char *format, ...);
void sj_fprintf(FILE *folder, const char *format, ...);
int sj_strcmp(const char *in_str1, const char *in_str2);
size_t shecktar_strcspn(const char *in_str1, const char *in_str2);
char *sj_strtok(char *in_str, const char *delim);
long sj_strtol(const char *in_str, char **endptr, int base);
char *sj_strdup(const char *str);
char *sj_strchr(const char *str, int c);
/*void free_memories(char* cmd_path, char* path_copy);*/
int my_strlen(const char *str);
void hndl_mul_cmd(char **commands);
char **split(char *input, const char *delim);
void tokenize_args(char *commands);

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

int main(int argc, char **argv);


#endif /* SHELL_H */
