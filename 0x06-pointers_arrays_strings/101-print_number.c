#include "main.h"

/**
 * print_number - prints an integer
 * @n: integer to print
 *
 * Return: void
 */
void print_number(int n)
{
	if (n / 10 != 0)
	{
		print_number(n / 10);
	}

	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}

	_putchar((n % 10) + '0');
}
