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
* @argc: arguments passed
* @argv: argument line
* Return: 0 success
*/
int main(int argc, char **argv)
{
	ssize_t read_chars;
	char *ln_ptr;
	char *my_prompt = ("$ ");
	size_t z = 0;
	(void)argc;
	(void)argv;

	while (1)
	{
		printf("%s", my_prompt);
		read_chars = getline(&ln_ptr, &z, stdin);

		if (read_chars == -1)
		{
			shecktar_write("Goodbye my friend!..\n");
			return (-1);
		}
		printf("%s\n", ln_ptr);

		free(ln_ptr);
	}

	return (0);
}
