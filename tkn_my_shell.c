#include "shell.h"
/**
* tkn_prompt - Function that tokinizes arguments on CLI
* @input: set of arguments as stdin
* Return: void
*/
void tkn_prompt(char *input)
{
		pid_t child_pid = fork();

		char **argv = sj_get_input(input);

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
				write(STDOUT_FILENO, argv[0], my_strlen(argv[0]));
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
