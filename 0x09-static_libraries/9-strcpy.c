/**
*_strcpy - copies string pointed to by src
*@dest: it's destination
*@src: where it's from
*Return: returns value pointer to dest
*
*/
char *_strcpy(char *dest, char *src)
{
	int inc = 0;

	while (*(src + inc) != '\0')
	{
		*(dest + inc) = *(src + inc);
		inc++;
	}
	*(dest + inc) = '\0';

	return (dest);
}
