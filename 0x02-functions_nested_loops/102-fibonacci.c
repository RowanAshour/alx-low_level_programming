#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i;
	unsigned long fib1 = 1, fib2 = 2, fib_next;

	printf("%lu, %lu", fib1, fib2);

	for (i = 3; i <= 50; i++)
	{
		fib_next = fib1 + fib2;
		printf(", %lu", fib_next);

		fib1 = fib2;
		fib2 = fib_next;
	}

	printf("\n");

	return (0);
}
