#include "shell.h"
/**
* my_prompt - function displays my prompt to terminal
* Return: void
*/

void my_prompt(void)
	{
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
		char **command = NULL;

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

			command = sj_get_input(input);
			Ex_prompt(command);
		}
		free(command);
		shecktar_write("Exiting shell...\n");
		return (0);
}
