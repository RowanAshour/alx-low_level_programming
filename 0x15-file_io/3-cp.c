#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1024

/* Function prototypes */
int open_source_file(const char *filename);
int open_destination_file(const char *filename);
void copy_file(int fd_from, int fd_to);
void close_files(int fd_from, int fd_to);

/**
 * main - Copy the content of a file to another file.
 * @argc: The argument count.
 * @argv: The argument vector.
 *
 * Return: 0 on success, or the corresponding exit code on failure.
 */
int main(int argc, char **argv)
{
	int fd_from, fd_to;

	if (argc != 3)
	{
		dprintf(2, "Usage: %s file_from file_to\n", argv[0]);
		exit(97);
	}

	fd_from = open_source_file(argv[1]);
	fd_to = open_destination_file(argv[2]);

	copy_file(fd_from, fd_to);

	close_files(fd_from, fd_to);

	return (0);
}

/**
 * open_source_file - Open the source file in read-only mode.
 * @filename: The name of the source file.
 *
 * Return: The file descriptor on success,
 * or exit with an error code on failure.
 */
int open_source_file(const char *filename)
{
	int fd_from = open(filename, O_RDONLY);

	if (fd_from == -1)
	{
		dprintf(2, "Error: Can't read from file %s\n", filename);
		exit(98);
	}

	return (fd_from);
}

/**
 * open_destination_file - Open or create the destination file
 * in write-only mode.
 * @filename: The name of the destination file.
 *
 * Return: The file descriptor on success,
 * or exit with an error code on failure.
 */
int open_destination_file(const char *filename)
{
	int fd_to = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0664);

	if (fd_to == -1)
	{
		dprintf(2, "Error: Can't write to %s\n", filename);
		exit(99);
	}

	return (fd_to);
}

/**
 * copy_file - Copy the content of the source file to the destination file.
 * @fd_from: The file descriptor of the source file.
 * @fd_to: The file descriptor of the destination file.
 */
void copy_file(int fd_from, int fd_to)
{
	ssize_t read_count, write_result;
	char buffer[BUF_SIZE];

	while ((read_count = read(fd_from, buffer, BUF_SIZE)) > 0)
	{
		write_result = write(fd_to, buffer, read_count);

		if (write_result == -1 || write_result != read_count)
		{
			dprintf(2, "Error: Can't write to destination file\n");
			close_files(fd_from, fd_to);
			exit(99);
		}
	}

	if (read_count == -1)
	{
		dprintf(2, "Error: Can't read from source file\n");
		close_files(fd_from, fd_to);
		exit(98);
	}
}

/**
 * close_files - Close the file descriptors.
 * @fd_from: The file descriptor of the source file.
 * @fd_to: The file descriptor of the destination file.
 */
void close_files(int fd_from, int fd_to)
{
	int close_result;

	close_result = close(fd_from);
	if (close_result == -1)
	{
		dprintf(2, "Error: Can't close source file descriptor\n");
		exit(100);
	}

	close_result = close(fd_to);
	if (close_result == -1)
	{
		dprintf(2, "Error: Can't close destination file descriptor\n");
		exit(100);
	}
}

