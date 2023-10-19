#include "main.h"

/**
 * print_number - Prints an integer
 * @n: The integer to be printed
 *
 * Description: This function prints an integer using the _putchar function.
 * If the number is negative, it prints a '-' character first.
 * It recursively divides the number by 10 until it becomes 0, then prints each digit.
 */
void print_number(int n)
{
	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}

	if (n / 10 != 0)
	{
		print_number(n / 10);
	}

	_putchar((n % 10) + '0');
}
