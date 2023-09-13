#include "shell.h"
/**
* sj_cd - Function changes current directory
* @args: List of arguments passed from parsing the command line
* Return: void
*/
void sj_cd(char **args)
{
	char *path_dst = NULL;
	char cwd[4096];
/* if cd is used without arguments */
	if (args[1] == NULL)
	{
		path_dst = getenv("HOME");
		if (path_dst == NULL)
		{
			sj_fprintf(stderr, "Error: HOME environment var not set. \n");
			return;
		}
	}
		else if (args[1][0] == '_' && args[1][1] == '\0')
		{
			path_dst = getenv("OLDPWD");
			if (path_dst == NULL)
			{
				sj_fprintf(stderr, "Error: OLDPWD environmnt var not set. \n");
				return;
			}
		}
		else
		{
				path_dst = args[1];
		}
		if (chdir(path_dst))
		{
			perror(args[0]);
			return;
		}
		if (getcwd(cwd, sizeof(cwd)) == NULL)
		{
			perror("Error getting CWD");
			return;
		}
		if (setenv("PWD", cwd, 1) == -1)
		{
			perror("Error setting PWD environ.. variable");
			return;
		}
		if (setenv("OLDPWD", path_dst, 1) == -1)
		{
			perror("Error setting OLDPWD environ.. var");
		}
}
