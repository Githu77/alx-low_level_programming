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
	FILE *file = fopen(filename, "a");

	if (filename == NULL)
	{
		return (-1);
	}

	if (file == NULL)
	{
		return (-1);
	}
	if (text_content != NULL)
	{
		fprintf(file, "%s", text_content);
	}

	fclose(file);
	return (1);
}
