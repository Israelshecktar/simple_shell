/**
 * _strcpy - copies string to a variable
 * @src: source variable
 * @dest: destination variable
 * Return: void
*/
char *_strcpy(char *dest, char *src)
{
	int i;
	
	/*Copy characters from src to dest*/
	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	
	}
	/*Add the null terminator to the destination string*/
	dest[i++] = '\0';
	
	return (dest);
}
