#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1024

/**
 * main - Copy the content of a file to another file.
 * @argc: The argument count.
 * @argv: The argument vector.
 *
 * Return: 0 on success, or the corresponding exit code on failure.
 */
int main(int argc, char **argv)
{
	int fd_from, fd_to, read_count, write_result, close_result;
	char buffer[BUF_SIZE];

	if (argc != 3)
	{
		dprintf(2, "Usage: %s file_from file_to\n", argv[0]);
		exit(97);
	}

	/* Open the source file in read-only mode */
	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(2, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	/* Open or create the destination file in write-only mode, truncate if it exists */
	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		dprintf(2, "Error: Can't write to %s\n", argv[2]);
		close(fd_from);
		exit(99);
	}

	/* Read from source and write to destination in chunks of BUF_SIZE */
	while ((read_count = read(fd_from, buffer, BUF_SIZE)) > 0)
	{
		write_result = write(fd_to, buffer, read_count);
		if (write_result == -1 || write_result != read_count)
		{
			dprintf(2, "Error: Can't write to %s\n", argv[2]);
			close(fd_from);
			close(fd_to);
			exit(99);
		}
	}

	if (read_count == -1)
	{
		dprintf(2, "Error: Can't read from file %s\n", argv[1]);
		close(fd_from);
		close(fd_to);
		exit(98);
	}

	/* Close file descriptors */
	close_result = close(fd_from);
	if (close_result == -1)
	{
		dprintf(2, "Error: Can't close fd %d\n", fd_from);
		close(fd_to);
		exit(100);
	}

	close_result = close(fd_to);
	if (close_result == -1)
	{
		dprintf(2, "Error: Can't close fd %d\n", fd_to);
		exit(100);
	}

	return (0);
}

