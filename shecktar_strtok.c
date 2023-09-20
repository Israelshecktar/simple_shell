#include "shell.h"
/**
* sj_strtok - custom version of the strtok()
* @in_str: provided string to be tokenized
* @delim: the delimeter to which tokenization will occur
*
* Return: a ptr to the first token in the str provided
*/

char *sj_strtok(char *in_str, const char *delim)
{
	static char *token_start;
	static char *next_token;

	/* Initializes start of str */
	if (in_str != NULL)
	{
		next_token = in_str;
	}

	if (next_token == NULL)
		return (NULL);

	token_start = next_token;

	while (*next_token != '\0')
	{
		if (sj_strchr(delim, *next_token) != NULL)
		{
			*next_token = '\0';
			next_token += 1;
			return (token_start);
		}
		next_token += 1;
	}

	next_token = NULL;
	return (token_start);
}

