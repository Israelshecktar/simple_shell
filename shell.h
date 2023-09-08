#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void shecktar_write(const char *input);
void my_prompt(void);
void Ex_prompt(const char *command);
char *take_inputs(char *input, size_t insize, FILE *stream);
void tkn_prompt(char *input);
char *find_cmd_path(const char *command);


/**********externs***********/
extern char **environ;
void hndl_env(void);

#endif /* SHELL_H */
