#include <stdlib.h>
#include <stdio.h>

/**
 * main - Multiplies two positive numbers.
 * @argc: The number of arguments passed to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: If the number of arguments is incorrect or one of the numbers
 *         contains non-digits - 98. Otherwise - 0.
 */
int main(int argc, char *argv[])
{
	int num1, num2, product;

	if (argc != 3)
	{
		printf("Error\n");
		return (98);
	}

	num1 = atoi(argv[1]);
	num2 = atoi(argv[2]);

	if (num1 == 0 || num2 == 0)
	{
		printf("Error\n");
		return (98);
	}

	product = num1 * num2;
	printf("%d\n", product);

	return (0);
}
