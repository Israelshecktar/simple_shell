#include "shell.h"
#define READ_SIZE 1024
/**
* shecktar_getline - function reads an entire line from the file stream
* @buffer: buffer in which to store read chars
* @size: buffer size
* @stream: file stream from which to read
* Return: buffer on success, Null on failure or EOF
*/
char *shecktar_getline(char *buffer, size_t size, FILE *stream)
{
	static char *line;
	static size_t start, end;
	size_t e, k;

	if (!buffer || size <= 0 || !stream)
		return (NULL);

	if (!line)
		line = malloc(sizeof(char) * READ_SIZE);
	if (!line)
		return (NULL);
	start = 0;
	end = read(fileno(stream), line, READ_SIZE - 1);
	if (end < 1)
	{
		line = NULL;
		return (NULL);
		free(line);
	}
	line[end] = '\0';
	for (e = 0, k = start; e < size - 1 && k < end; e++, k++)
		buffer[e] = line[k];
	buffer[e] = '\0';

	if (k >= end)
	{
		line = NULL;
		free(line);
	}
	else
	{
		start = k;
	}
	return (buffer);
}
