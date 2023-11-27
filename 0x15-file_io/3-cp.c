#include "main.h"

/**
 * main - Entry point
 * @argc: The number of command line arguments
 * @argv: The command line arguments
 *
 * Return: 0 on success, or one of the error codes on failure
 */
int main(int argc, char **argv)
{
	char buffer[BUFFER_SIZE];
	ssize_t bytesRead;
	int file_from, file_to;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	file_from = open(argv[1], O_RDONLY);
	if (file_from < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	file_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (file_to < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}

	while ((bytesRead = read(file_from, buffer, BUFFER_SIZE)) > 0)
	{
		if (write(file_to, buffer, bytesRead) != bytesRead)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			exit(99);
		}
	}

	if (bytesRead < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	if (close(file_from) < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		exit(100);
	}

	if (close(file_to) < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_to);
		exit(100);
	}

	return (0);
}
