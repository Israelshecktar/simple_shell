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
	static char *last_tok;
	static char *return_ptr;

	/* Initializes start of str */
	if (in_str != NULL)
	{
		last_tok = in_str;
	}

	if (last_tok == NULL)
		return ((NULL));

	while (*last_tok != '\0' && sj_strchr(delim, *last_tok) != NULL)
	{
		last_tok++;
	}
	if (*last_tok == '\0')
	{
		last_tok = NULL;
		return ((NULL));
	}

		(return_ptr = last_tok);

	while (*last_tok != '\0' && sj_strchr(delim, *last_tok) == NULL)
	{
		last_tok++;
	}

	if (*last_tok != '0')
	{
		*last_tok = '\0';
		last_tok++;
	}

	return ((return_ptr));
}
