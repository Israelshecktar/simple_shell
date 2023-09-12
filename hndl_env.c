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

/**
 * sj_strdup - Function Duplicates a string
 * @s: The string to duplicate
 *
 * Return: A pointer to the newly allocated duplicate string, or NULL
 */
char *sj_strdup(const char *s)
{
	size_t len = strlen(s) + 1;
	char *dup = malloc(len);

	if (dup != NULL)
	{
		memcpy(dup, s, len);
	}

	return (dup);
}
