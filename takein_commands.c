#include "shell.h"

/**
* take_inputs - Function takes in user inputs
* @input: set of inputs recieves
* @insize: length of input recieved
* @stream: pointer to the exec file for auto-arguments
* Return: input
*/
char *take_inputs(char *input, size_t insize, FILE *stream)
{
	/* if standardinput is empty */
	if (fgets(input, insize, stream) == NULL)
	{
		if (feof(stream))
		{
			/* print a new_line and return new prompt */
			shecktar_write("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			shecktar_write("Error, unable to read inputs.\n");
			exit(EXIT_FAILURE);
		}
	}
	/* Remove new_line in the string */
	input[strcspn(input, "\n")] = '\0';

	return (input);
}
