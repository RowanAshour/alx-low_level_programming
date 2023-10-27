#include <stdio.h>

/**
 * main - prints the name of the program
 * @argc: number of command line arguments
 * @argv: array of command line arguments
 *
 * Return: 0 if successful
 */
int main(int argc, char *argv[])
{
	(void)argc; /* This line is to avoid unused variable warning */
	printf("%s\n", argv[0]);
	return (0);
}
