#include "shell.h"

/**
* my_strlen - function is a custom strlen
* @str: string passed
* Return: always 0 success
*/
int my_strlen(const char *str)
{
	int counter = 0;

	if (str == NULL)
		return (0);

	while (str[counter] != '\0')
	{
		counter++;
	}

	return (counter);
}
