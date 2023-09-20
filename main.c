#include "shell.h"
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
	size_t z = 0;

	(void)argc; (void)argv;

	while (1)
	{
                print_prompt();
		read_chars = getline(&ln_ptr, &z, stdin);
		if (read_chars == -1)
		{
			sj_puts("exiting shell...");
			return (-1);
		}
                sj_puts(ln_ptr);
		free(ln_ptr);
	}
	return (0);
}
