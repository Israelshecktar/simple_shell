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

		while (1)
		{
			shecktar_write("shecktar_shell$ ");
			if (fgets(input, sizeof(input), stdin) == NULL)
			{
				break;
			}

			/* we remove new line character */

			input[strcspn(input, "\n")] = '\0';

			if (strcmp(input, "exit") == 0)
			{
				break; /* exit the loop if 'exit' is entered */
			}

			Ex_prompt(input);
		}

		shecktar_write("Goodbye my friend!\n");
		return (0);
}
