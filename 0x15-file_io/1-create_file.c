#include "main.h"
/**
*create_file - create file
*@filename: pointer to file name
*@text_content: pointer to text to write
*Return: -1 or 1
*
*
*
*
*
*/

int create_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t nw = 0;
	mode_t md = S_IRUSR | S_IWUSR;

	if (filename == NULL)
	{
		return (-1);
	}
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, md);
	if (fd == -1)
	{
		return (-1);
	}
	if (text_content != NULL)
	{
		while (text_content[nw] != '\0')
		{
			nw += write(fd, text_content + nw, 1);
		}
	}
	close(fd);
	return (1);
}
