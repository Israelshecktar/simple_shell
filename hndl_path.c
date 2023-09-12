#include "shell.h"

/**
* find_cmd_path - function searches for a command in path
* @command: sring passsed as command in stdin
* Return: cmd_path
*/
char *find_cmd_path(char *command)
{
		char *path_copy;
		char *token;
		char *cmd_path = NULL;
		char *path = getenv("PATH");
		struct stat buffer;

		if (path == NULL)
		{
			sj_fprintf(stderr, "Error, PATH enviroment not found\n");
			return (NULL);
		}
		if (stat(command, &buffer) == 0)
		{
			return (command);
		}
		path_copy = strdup(path);
		token = shecktar_strtok(path_copy, ":");

		while (token != NULL)
		{
			char cmd_local[400];

			sj_snprintf(cmd_local, sizeof(cmd_path), "%s/%s", token, command);
				if (access(cmd_local, X_OK) == 0)
				{
					/* command is present */
					cmd_path = strdup(cmd_local);
					break;
				}
				token = shecktar_strtok(NULL, ":");
		}

		if (cmd_path == NULL && access(command, X_OK) == 0)
		{
			cmd_path = strdup(command);
		}
			/* But if command is still not found */

		return (cmd_path);
}
