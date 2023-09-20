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
		free(command);
		i++;
	}
}

