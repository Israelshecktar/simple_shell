#include "shell.h"
/**
* hndl_mul_cmd - function handles multiple commands
* @commands: set of commands
* Return: Nothing
*/
void hndl_mul_cmd(char **commands)
{
	int i = 0;

	while (commands[i] != NULL)
	{
		char **command = sj_get_input(commands[i]);

		Ex_prompt(command);
		/*free(command);*/
		i++;
	}
}
/**
 * tokenize_args -tokenize inputs into arguments
 * @commands: input commands
 * Return: void
 */
void tokenize_args(char *commands)
{
	char *args[200];
        char *token = strtok(commands, " ");
        int argCount = 0;

	(void)*args[200];

        while (token != NULL) {
            args[argCount++] = token;
            token = strtok(NULL, " ");
        }
	args[argCount] = NULL;
	Ex_prompt(token);
}
