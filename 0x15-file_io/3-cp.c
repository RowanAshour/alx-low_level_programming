#include "main.h"

/**
 * copy_file_content - Copy content from source file to destination file.
 * @file_from: Source file descriptor
 * @file_to: Destination file descriptor
 *
 * Return: 0 on success, or one of the error codes on failure
 */
int copy_file_content(int file_from, int file_to)
{
    char buffer[BUFFER_SIZE];
    ssize_t bytesRead;

    while ((bytesRead = read(file_from, buffer, BUFFER_SIZE)) > 0)
    {
        if (write(file_to, buffer, bytesRead) != bytesRead)
        {
            dprintf(STDERR_FILENO, "Error: Can't write to file\n");
            return 99;
        }
    }

    if (bytesRead < 0)
    {
        dprintf(STDERR_FILENO, "Error: Can't read from file\n");
        return 98;
    }

    return 0;
}

/**
 * close_file - Close file descriptor.
 * @fd: File descriptor to close
 *
 * Return: 0 on success, or 100 on failure
 */
int close_file(int fd)
{
    if (close(fd) < 0)
    {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
        return 100;
    }

    return 0;
}

int main(int argc, char **argv)
{
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

    if (copy_file_content(file_from, file_to) != 0)
        exit(1);

    if (close_file(file_from) != 0)
        exit(1);

    if (close_file(file_to) != 0)
        exit(1);

    return 0;
}
