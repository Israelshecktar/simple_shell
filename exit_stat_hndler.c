#include "shell.h"
/**
* hndl_exit - function handles exit status
* @command: status of input to handle
* Return: void
*/
void hndl_exit(char **command)
{
	if (command[1] != NULL)
	{
		char *endptr;
		long status = sj_strtol(command[1], &endptr, 10);

		if (*endptr != '\0')
		{
			shecktar_write("Invalid integer argument for exit status\n");
			return;
		}
		exit((int)status);
	}

}
