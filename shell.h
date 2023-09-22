#ifndef SHELL_H
#define SHELL_H

#define READ_SIZE 1024


#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdarg.h>
#include <sys/stat.h>
#include <stddef.h>
#include <locale.h>
#include <errno.h>
#include <ctype.h>

void shecktar_write(const char *input);
void my_prompt(void);
void Ex_prompt(char **input);
char *take_inputs(char *input, size_t insize, FILE *stream);
void tkn_prompt(char *input);
char *find_cmd_path(char *command);
void exe_cmd(const char *cmd_path, char *const argv[]);
char **sj_get_input(char *input);
int hndl_cd(char **args);
char *trim_spaces(char *str);
int sj_isspace(int c);

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

/*********Error handlers*********/
void hndl_exit(char **command);

#endif /* SHELL_H */
