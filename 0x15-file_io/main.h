#include "main.h"
/**
*read_textfile - reads and prints to POSIX stdout
*@filename: pointer to file
*@letters: number of letters
*Return: 0 or bytes to read and print
*
*
*
*
*
*/

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t nread;
	char *buf;

	if (filename == NULL)
	{
		return (0);
	}
	buf = malloc(sizeof(char) * (letters + 1));
	if (buf == NULL)
	{
		return (0);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		free (buf);
		return (0);
	}
	nread = read(fd, buf, letters);
	if (nread == -1)
	{
		free(buf);
		close(fd);
		return (0);
	}
	buf[nread] = '\0';
	if (write(STDOUT_FILENO, buf, nread) != nread)
	{
		free(buf);
		close(fd);
		return (0);
	}
	free(buf);
	close(fd);
	return (nread);
}
