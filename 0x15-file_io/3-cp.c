#include "main.h"

/**
 * main - copies the content of a file to another file
 * @argc: number of arguments passed to the program
 * @argv: array of arguments
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	int filed_r, filed_w, rea, abt, babt;
	char buffer[BUFSIZ];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	filed_r = open(argv[1], O_RDONLY);
	if (filed_r < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	filed_w = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	while ((rea = read(filed_r, buffer, BUFSIZ)) > 0)
	{
		if (filed_w < 0 || write(filed_w, buffer, rea) != rea)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			close(filed_r);
			exit(99);
		}
	}
	if (rea < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	abt = close(filed_r);
	babt = close(filed_w);
	if (abt < 0 || babt < 0)
	{
		if (abt < 0)
			dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", filed_r);
		if (babt < 0)
			dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", filed_w);
		exit(100);
	}
	return (0);
}
