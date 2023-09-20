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
		write(STDOUT_FILENO, *current, my_strlen(*current));
		write(STDOUT_FILENO, "\n", 1);
	}
}

/**
 * sj_strdup - Function Duplicates a string
 * @str: The string to duplicate
 *
 * Return: A pointer to the newly allocated duplicate string, or NULL
 */
char *sj_strdup(const char *str)
{
	int length = 0;
	char *dup_str;

	if (str == NULL)
		return (NULL);

	while (str[length])
		length++;

	dup_str = malloc((length + 1) * sizeof(char));

	if (dup_str == NULL)
	{
		perror("Error: Memory allocation failed for sj_strdup");
		return (NULL);
	}

	for (length = 0; str[length]; length++)
		dup_str[length] = str[length];

	dup_str[length] = '\0';

	return (dup_str);
}
