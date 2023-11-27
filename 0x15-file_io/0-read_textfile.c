#include "main.h"
#include <stdlib.h>  /* Include necessary header for malloc and free */
#include <unistd.h>  /* Include necessary header for write */

/**
 * read_textfile - Reads a text file and prints it to the POSIX standard output.
 * @filename: The name of the file to read.
 * @letters: The number of letters it should read and print.
 *
 * Return: The actual number of letters it could read and print.
 *         If the file can't be opened or read, return 0.
 *         If filename is NULL, return 0.
 *         If write fails or does not write the expected amount of bytes, return 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	FILE *file;
	char *buffer;
	ssize_t read_count, write_count;

	if (filename == NULL)
		return (0);

	file = fopen(filename, "r");
	if (file == NULL)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
	{
		fclose(file);
		return (0);
	}

	read_count = fread(buffer, sizeof(char), letters, file);
	write_count = write(STDOUT_FILENO, buffer, read_count);

	free(buffer);
	fclose(file);

	if (write_count != read_count)
		return (0);

	return (read_count);
}

