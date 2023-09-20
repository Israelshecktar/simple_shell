#include "main.h"
/**
 * sj_strlen - finds length of a string
 * @s: string
 * Return: length of string
*/
int sj_strlen(char *s)
{
	char *ptr = s;
	int strlen;

	strlen = 0;

	while (ptr[strlen] != '\0')
	{
		strlen++;
	}
	return (strlen);
}
/**
 * sj_putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int sj_putchar(char c)
{
	return (write(1, &c, 1));
}
/**
* sj_puts- prints a strings
* @str: the string to be printed
* Return: void
*/
void sj_puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
}
/**
 * sj_strcmp - compare string values
 * @s1: input value
 * @s2: input value
 *
 * Return: s1[i] - s2[i]
 */
int sj_strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
	}
	return (0);

}
