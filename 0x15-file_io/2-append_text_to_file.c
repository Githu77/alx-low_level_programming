#include "main.h"
/**
*append_text_to_file - adds text to file end
*@filename: pointer to file name
*@text_content: string to append
*Return: -1 or 1
*
*
*
*
*
*/

int append_text_to_file(const char *filename, char *text_content)
{
	int fd = open(filename, O_WRONLY | O_APPEND);

	if (filename == NULL)
	{
		return (-1);
	}
	if (fd == -1)
	{
		return (-1);
	}
	if (text_content != NULL)
	{
		int bytes = 0;
		ssize_t bytes_w = write(fd, text_content, bytes);

		while (text_content[bytes] != '\0')
		{
			bytes++;
		}
		if (bytes_w == -1)
		{
			return (-1);
		}
	}
	close(fd);
	return (1);
}
