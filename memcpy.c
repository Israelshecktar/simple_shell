/**
 * _memcpy - fill memory with a constant byte
 * @dest: pointer to the address of the memory to store the copied data 
 * @src: pointer to the  address of the memory from which the data will be copied.
 * @n: number of characters to copy
 * Return: a pointer to the memory area.
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	int i;
	
	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
