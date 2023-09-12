#ifndef SHELL_H
#define SHELL_H



#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdarg.h>
#include <sys/stat.h>

void shecktar_write(const char *input);
void my_prompt(void);
void Ex_prompt(char **input);
char *take_inputs(char *input, size_t insize, FILE *stream);
void tkn_prompt(char *input);
char *find_cmd_path(char *command);
void exe_cmd(const char *cmd_path, char *const argv[]);
char **sj_get_input(char *input);
/********my_getline function******/
char *shecktar_getline(char *buffer, size_t size, FILE *stream);


/**********externs***********/
extern char **environ;
void hndl_env(void);

/**********Utils*********/
int sj_snprintf(char *in_str, size_t n, const char *format, ...);
void sj_fprintf(FILE* folder, const char* format, ...);
int sj_strcmp(const char *in_str1, const char *in_str2);
size_t shecktar_strcspn(const char *in_str1, const char *in_str2);
char *shecktar_strtok(char *in_str, const char *delim);

#endif /* SHELL_H */
