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
	static char internalBuffer[READ_SIZE];
	static char *ptr;
	static int charsLeft;
	size_t i = 0;

	if (!buffer || size <= 0 || !stream)
		return (NULL);

	while (i < size - 1)
	{
		if (charsLeft <= 0)
		{
			charsLeft = read(fileno(stream), internalBuffer, READ_SIZE);
			if (charsLeft <= 0)
				break;
			ptr = internalBuffer;
		}
		buffer[i++] = *ptr++;
		charsLeft--;

		if (buffer[i - 1] == '\n')
			break;

	}
	if (i == 0)
		return (NULL);

	buffer[i] = '\0';

	return (buffer);
}

