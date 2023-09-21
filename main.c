#include "shell.h"
/**
* my_prompt - function displays my prompt to terminal
* Return: void
*/

void my_prompt(void)
	{
		if (isatty(STDIN_FILENO))
			shecktar_write("$ ");
	}

/**
* main - Entry point
*
* Return: 0 success
*/
int main(void)
{
		char input[400];
		char *result = NULL;
		char **commands;

		while (1)
		{
			my_prompt();
			result = shecktar_getline(input, sizeof(input), stdin);
			if (result == NULL)
				break;

			/* we remove new line character */
			input[shecktar_strcspn(input, "\n")] = '\0';

			if (sj_strcmp(input, "exit") == 0)
				break;

			if (sj_strcmp(input, "env") == 0)
			{
				hndl_env();
				continue;
			}

			commands = split(input, ";");

			hndl_mul_cmd(commands);
			free(commands);
		}
		return (0);
}
