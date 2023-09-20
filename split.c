#include "shell.h"
#define MAX_COMMANDS 100
/**
* split -  function splits str into multiple strings based on delimeter
* @input: strings entered on the cli
* @delim: delimeter processed
* Return: result of the splited strings
*/
char **split(char *input, const char *delim)
{
	char **result = malloc(MAX_COMMANDS * sizeof(char *));

	char *token;
	int index = 0;

	token = sj_strtok(input, delim);
	while (token != NULL)
	{
		result[index++] = token;
		token = sj_strtok(NULL, delim);
	}
		result[index] = NULL;

		return (result);
}
/**
* sj_strchr - custom version of strchr
* @str: the string searched for
* @c: character to search for
*
* Return: a pointer to the first occurence or NULLi if otherwise
*/
char *sj_strchr(const char *str, int c)
{
	if (str == NULL)
		return (NULL);

	while (*str != '\0')
	{
		if (*str == c)
			return ((char *)str);
		str++;
	}

	return (NULL);
}
