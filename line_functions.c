#include "shell.h"
/**
 * print_prompt - print shell prompt
 *
 * Return: void
 */
void print_prompt(void)
{
	char *shellPrompt = "SJ_shell~$ ";

	write(1, shellPrompt, sj_strlen(shellPrompt));
}
/**
 * sj_custom_getline - Read a line from the file stream
 * @buffer: Buffer in which to store read characters
 * @size: Size of the buffer
 * @stream: File stream from which to read
 * Return: Pointer to buffer on success, NULL on failure or EOF
 */
char *sj_custom_getline(char *buffer, size_t size, FILE *stream)
{
	static char *line;
	static size_t start, end;
	size_t e, k;

	if (!buffer || size == 0 || !stream)
		return (NULL);
	if (!line)
	{
		line = malloc(sizeof(char) * READ_SIZE);
		if (!line)
		{
			perror("Error: Memory allocation failed for custom_getline");
			exit(EXIT_FAILURE);
		}
	}
	if (start >= end)
	{
		end = read(fileno(stream), line, READ_SIZE - 1);
		if (end == 0)
		{
			free(line);
			line = NULL;
			return (NULL);
		}
		line[end] = '\0';
		start = 0;
	}
	for (e = 0, k = start; e < size - 1 && start < end; e++, k++)
	{
		buffer[e] = line[start];
	}
	buffer[e] = '\0';
	if (start >= end)
	{
		free(line);
		line = NULL;
	}
	return (buffer);
}
