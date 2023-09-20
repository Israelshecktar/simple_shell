#include "shell.h"
/**
* shecktar_write - Function writes to the std output
* @input: set of instructions recieved
* Return: void
*/
void shecktar_write(const char *input)
{
	write(STDOUT_FILENO, input, my_strlen(input));
}

/**
* sj_strcmp - function compares two strings
* @in_str1: The first str to compare
* @in_str2: The second str to compare
* Return: 0 if the string is equal, a negative value if in_str1 is
* less than in_str2
*/
int sj_strcmp(const char *in_str1, const char *in_str2)
{
	if (in_str1 == NULL || in_str2 == NULL)
	{
		return (in_str1 == in_str2 ? 0 : (in_str1 == NULL ? -1 : 1));
	}

	while (*in_str1 && (*in_str1 == *in_str2))
	{
		in_str1++;
		in_str2++;
	}

	return (*(unsigned char *)in_str1 - *(unsigned char *)in_str2);
}

/**
* shecktar_strcspn - function calculates the length of the initial str
* @in_str1: The str to search
* @in_str2: The str containing the char to match
* Return: The lenght of the init segment of in_str1
*/
size_t shecktar_strcspn(const char *in_str1, const char *in_str2)
{
	size_t str_len = 0;
	const char *init;

	while (*in_str1)
	{
		init = in_str2;

		while (*init)
		{
			if (*in_str1 == *init)
			{
				return (str_len);
			}
			init++;

		}
		in_str1++;
		str_len++;
	}
	return (str_len);
}
