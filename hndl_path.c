#include "shell.h"
/**
* find_cmd_path - function searches for a command in path
* @command: sring passsed as command in stdin
* Return: Null
*/
char *find_cmd_path(const char *command)
{
		char *path_copy;
		char *token;
		char *path = getenv("PATH");

		if (path == NULL)
		{
			fprintf(stderr, "Error, PATH enviroment not found\n");
			return (NULL);
		}

		path_copy = strdup(path);
		token = strtok(path_copy, ":");

		while (token != NULL)
		{
			char cmd_path[400];

			snprintf(cmd_path, sizeof(cmd_path), "%s/%s", token, command);
				if (access(cmd_path, X_OK) == 0)
				{
					/* command is present */
					return (strdup(cmd_path));
				}
				token = strtok(NULL, ":");
		}
			/* But if command is still not found */
			return (NULL);
}
