#include "shell.h"
/**
* shecktar_write - Function writes to the std output
* @input: set of instructions recieved
* Return: void
*/
void shecktar_write(const char *input)
{
	write(STDOUT_FILENO, input, strlen(input));
}
