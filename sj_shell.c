#include "shell.h"
/**
* my_prompt - function displays my prompt to terminal
* Return: void
*/

void my_prompt(void)
	{
		shecktar_write("shecktar_shell$ ");
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

		while (1)
		{
			shecktar_write("shecktar_shell$ ");
			result = shecktar_getline(input, sizeof(input), stdin);
			if (result == NULL)
				break;

			/* we remove new line character */
			input[strcspn(input, "\n")] = '\0';

			if (strcmp(input, "exit") == 0)
				break;

			if (strcmp(input, "env") == 0)
			{
				hndl_env();
				continue;
			}

			Ex_prompt(input);
		}

		shecktar_write("Goodbye my friend!\n");
		return (0);
}
