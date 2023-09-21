#include "shell.h"
/**
* Ex_prompt - Function executes my prompt in terminal
* @input: set of instructed as stdin
* Return: void
*/
void Ex_prompt(char **input)
{
	char *cmd_path = find_cmd_path(input[0]);

		if (input[0] == NULL || my_strlen(input[0]) == 0)
		{
			free(cmd_path);
			return;
		}
		if (sj_strcmp(input[0], "cd") == 0)
		{
			hndl_cd(input);
		}
		if (cmd_path != NULL)
		{
			pid_t child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error: fork failed");
			free(cmd_path);
			return;
		}
		else if (child_pid == 0)
		{
			if (execve(cmd_path, input, environ) == -1)
			{
				perror("Error: execve failed");
				_exit(EXIT_FAILURE);
			}
		}
		else
			{
				wait(NULL);

			}
		}
		else
		{
			shecktar_write(input[0]);
			shecktar_write(": No such file or directory\n");
		}

}
