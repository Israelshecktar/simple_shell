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
 * @s: The string to duplicate
 *
 * Return: A pointer to the newly allocated duplicate string, or NULL
 */
char *sj_strdup(const char *s)
{
	size_t len = my_strlen(s) + 1;
	char *dup = malloc(len);

	if (dup != NULL)
	{
		memcpy(dup, s, len);
	}

	return (dup);
}
/**
* free_memories - function frees memory
* @cmd_path: function to free
* @path_copy: function to free
* Return: Nothing
*/
void free_memories(char *cmd_path, char *path_copy)
{
	free(cmd_path);
	free(path_copy);
}
