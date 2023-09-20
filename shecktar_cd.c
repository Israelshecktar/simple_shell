#include "shell.h"
/**
* hndl_cd - function chanages user cwd
* @args: command args
* Return: 1 if succesful and -1 on error
*/
int hndl_cd(char **args)
{
	char *dir_to_change_to;

	if (args[1] != NULL)
	{
		dir_to_change_to = args[1];
	}
	else
	{
		dir_to_change_to = getenv("HOME");

		if (!dir_to_change_to)
		{
			shecktar_write("Cannot get home directory\n");
			return (-1);
		}
	}

	if (chdir(dir_to_change_to) == -1)
	{
		shecktar_write("shecktar: ");
		shecktar_write(args[1]);
		shecktar_write(": ");
		shecktar_write(": No such file or directory\n");
		shecktar_write("\n");
		return (-1);
	}

	return (1);
}
