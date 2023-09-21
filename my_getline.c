#include "shell.h"
#define READ_SIZE 1024

/**
* shecktar_getline - function reads the entire line from the file stream
* @buffer: buffer in which to store read chars
* @size: buffer size
* @stream: file stream from which to read
* Return: buffer on success, Null on failure or EOF
*/
char *shecktar_getline(char *buffer, size_t size, FILE *stream)
{
	size_t i = 0;
	int ch;

	if (!buffer || size <= 0 || !stream)
		return (NULL);

	while ((ch = fgetc(stream)) != EOF && i < size - 1)
	{
		buffer[i++] = ch;
		if (ch == '\n')
			break;
	}

	if (i == 0 && ch == EOF)
		return (NULL);

	buffer[i] = '\0';

	return (buffer);
}

