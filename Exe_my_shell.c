#include "shell.h"
/**
* Ex_prompt - Function executes my prompt in terminal
* @input: set of instructed as stdin
* Return: void
*/
void Ex_prompt(const char *input)
{
	char *cmd_path = find_cmd_path(input);

		if (cmd_path != NULL)
		{
			pid_t child_pid = fork();
			/* function initiates child process */

		if (child_pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (child_pid == 0)
		/* while child process is running */

		{
			/* execute the command with this path */
			char *argv[2];

			argv[0]  = cmd_path;
			argv[1] = NULL;

			if (execve(cmd_path, argv, environ) == -1)
			{
				perror("execve");
				exit(EXIT_FAILURE);
			}
		}
			else
			/* parent process must wait */
			{
				wait(NULL);
			}

			free(cmd_path);
			}
				else
			{
				fprintf(stderr, "%s: Error, command not found\n", input);
			}
}
