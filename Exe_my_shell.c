#include "shell.h"
/**
* Ex_prompt - Function executes my prompt in terminal
* @input: set of instructed as stdin
* Return: void
*/
void Ex_prompt(const char *input)
{
	char *cmd_path = find_cmd_path(input);

		if (input == NULL || strlen(input) == 0)
		{
			shecktar_write("Command invalid or empty, please provide a command.\n");
			return;
		}
			if (cmd_path != NULL)
			{
			pid_t child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error: fork failed");
			return;
		}
		else if (child_pid == 0)
		{
			char *argv[2];

			argv[0]  = cmd_path;
			argv[1] = NULL;

			if (execve(cmd_path, argv, environ) == -1)
			{
				perror("Error: execve failed");
				exit(EXIT_FAILURE);
			}
		}
			else
			{
				wait(NULL);
			}

			free(cmd_path);
			}
				else
			{
				shecktar_write(input);
				shecktar_write(": Error, command not found\n");
			}
}
