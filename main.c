#include "shell.h"
/**
* my_prompt - function displays my prompt to terminal
* Return: void
*/

void my_prompt(void)
	{
		shecktar_write("$ ");
	}

#include "shell.h"
/**
* shecktar_write - Function writes to the std output
* @input: set of instructions recieved
* Return: void
*/
void shecktar_write(const char *input)
{
	write(STDOUT_FILENO, input, strlen(input));
}

/**
* main - Entry point
* Return: 0 success
*/
int main(void)
{
	char command[100];

	while (1)
	{
		my_prompt();
		fgets(command, sizeof(command), stdin);
		system(command);
	}

	return (0);
}
