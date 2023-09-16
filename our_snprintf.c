#include "shell.h"
/**
* sj_snprintf - custom implented snprintf
* @in_str: the string to the concatonated
* @n: size of the str
* @format: format of str
* Return: 0 always success
*/
int sj_snprintf(char *in_str, size_t n, const char *format, ...)
{
	int output;

	va_list args;

	va_start(args, format);

	output = vsnprintf(in_str, n, format, args);

	va_end(args);
	return (output);
}

/**
* sj_fprintf - custom implemented fprintf
* @format: format for string
* @folder: format for folder
* Return: null
*/
void sj_fprintf(FILE *folder, const char *format, ...)
{
	va_list args;

	va_start(args, format);
	vfprintf(folder, format, args);
	va_end(args);
}
