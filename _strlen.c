int _strlen(char *s)
{
    char *ptr = s;
    int strlen;

    strlen = 0;
    
    while (ptr[strlen] != '\0')
    {
        strlen++;
    }
    return strlen;

}
