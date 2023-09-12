#include "shell.h"
/**
* shecktar_strtok - custom version of the strtok()
* @in_str: provided string to be tokenized
* @delim: the delimeter to which tokenization will occur
*
* Return: a ptr to the first token in the str provided
*/

char *shecktar_strtok(char *in_str, const char *delim)
{
	static char *last_tok;
	char *delimMatch;

	/* Initializes start of str */
	if (in_str == NULL)
	{
		in_str = last_tok;
		if (in_str == NULL)
			return (NULL);
	}

	/* Now we find the first token in string */
	delimMatch = strpbrk(in_str, delim);
	if (delimMatch == NULL)
	{
		last_tok = NULL;
	}
	else
	{
		*delimMatch = '\0';
		last_tok = delimMatch + 1;
	}

	return (in_str);
}
