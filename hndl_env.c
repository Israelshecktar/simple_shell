#include "shell.h"
/**
* hndl_env - function prints environment global variable
* Return: Void
*/
void hndl_env(void)
{
	char **current;

	for (current = environ; *current; current++)
	{
		write(STDOUT_FILENO, *current, strlen(*current));
		write(STDOUT_FILENO, "\n", 1);
	}
}
