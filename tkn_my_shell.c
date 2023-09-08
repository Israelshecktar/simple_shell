#include "shell.h"
/**
* tkn_prompt - Function tokinizes arguments on CLI
* @input: set of arguments as stdin
* Return: void
*/
void tkn_prompt(char *input)
{
		pid_t child_pid = fork();

		int argc = 0;
		char *argv[300];
		char *tkn;

		tkn = strtok(input, " ");

		while (tkn != NULL)
		{
			argv[argc] = tkn;
			argc++;
			tkn = strtok(NULL, " ");
		}

		argv[argc] = NULL;

		if (child_pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (child_pid == 0)
		{
			/* while child process is running */
			if (execve(argv[0], argv, environ) == -1)
			{
				write(STDOUT_FILENO, argv[0], strlen(argv[0]));
				shecktar_write(": No such file or directory\n");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			/* parent process must wait */
			wait(NULL);
		}
}
