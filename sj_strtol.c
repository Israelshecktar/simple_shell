#include "shell.h"
/**
 * sj_strtol - Converts a string to long integer
 * @in_str: The input string to be converted
 * @endptr: A pointer to the character that stops the scan
 * @base: The base of the number system
 * Return: The converted long integer value
 */
long sj_strtol(const char *in_str, char **endptr, int base)
{
	long result = 0;
	int sign = 1;

	if (in_str == NULL)
	{
		return (0);
	}

	if (*in_str == '-')
	{
		sign = -1;
		in_str++;
	}
	while (*in_str)
	{
		int digit;

		if ('0' <= *in_str && *in_str <= '9')
			digit = *in_str - '0';
		else if
			('a' <= *in_str && *in_str <= 'z')
			digit = *in_str - 'a' + 10;
		else if
			('A' <= *in_str && *in_str <= 'Z')
			digit = *in_str - 'A' + 10;
		else
			break;

		if (digit >= base)
			break;

		result = result * base + digit;
		in_str++;
	}
	if (endptr)
		*endptr = (char *)in_str;
	return (sign * result);
}
