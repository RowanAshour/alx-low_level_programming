#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	unsigned long fib1 = 1, fib2 = 2, fib_next, sum = 0;

	while (fib1 <= 4000000)
	{
		if (fib1 % 2 == 0)
			sum += fib1;

		fib_next = fib1 + fib2;
		fib1 = fib2;
		fib2 = fib_next;
	}

	printf("%lu\n", sum);

	return (0);
}

