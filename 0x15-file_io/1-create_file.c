#include "main.h"

/**
 * create_file - creates a file and prints the content of text_content into it
 * @filename: is the file to be created
 * @text_content: is the text file to be copied from
 * Return: 1 if success -1 if failure
 */

int create_file(const char *filename, char *text_content)
{
	int ope, wri, l = 0;

	if (filename == NULL)
	{
		return (-1);
	}
	if (text_content != NULL)
	{
		for (l = 0; text_content[l];)
		{
			l++;
		}
	}

	ope = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	wri = write(ope, text_content, l);

	if (ope == -1 || wri == -1)
	{
		return (-1);
	}

	close(ope);

	return (1);
}
