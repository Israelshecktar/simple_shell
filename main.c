#include "shell.h"

/**
* my_prompt - function displays my prompt to terminal
* Return: void
*/
void my_prompt(void)
{
	if (isatty(STDIN_FILENO))
		shecktar_write("$ ");
}

/**
* trim_spaces - leading and trailing spaces
* @str: string to trim
* Return: trimmed string
*/
char *trim_spaces(char *str)
{
	char *end;
	/* Remove leading spaces */
	while (*str != '\0' && sj_isspace((unsigned char)*str))
	{
		str++;
	}

    /* Remove trailing spaces */
	end = str + my_strlen(str) - 1;

	while (end > str && sj_isspace((unsigned char)*end))
	{
		end--;
	}

    /* Write new null terminator */
	*(end + 1) = '\0';

	return (str);
}

/**
* main - Entry point
*
* Return: 0 success
*/
int main(void)
{
	char input[400];
	char *result = NULL;
	char **commands;

	while (1)
	{
		char *trimmed_input;

		my_prompt();
		result = shecktar_getline(input, sizeof(input), stdin);
		if (result == NULL)
			break;

		/* Trim leading and trailing spaces */
		trimmed_input = trim_spaces(input);

		/* we remove new line character */
		trimmed_input[shecktar_strcspn(trimmed_input, "\n")] = '\0';

		if (sj_strcmp(trimmed_input, "exit") == 0)
			break;

		if (sj_strcmp(trimmed_input, "env") == 0)
		{
			hndl_env();
			continue;
		}

		commands = split(trimmed_input, ";");

		hndl_mul_cmd(commands);
		free(commands);
	}
	return (0);
}

/**
* sj_isspace - function removes trailing spaces from code
* @c: trailing characters
* Return: 0 success
*/
int sj_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n' ||
	c == '\v' || c == '\f' || c == '\r');
}

