#include "main.h"

/**
 * print_number - prints an integer
 * @n: integer to print
 *
 * Return: void
 */
void print_number(int n)
{
	if (n < 0)
	{
		_putchar('-');
		n = -1 * (n % 10);
		print_number(n / -10);
		_putchar('0' - n);
	}
	else
	{
		if (n / 10)
		{
			print_number(n / 10);
		}
		_putchar((n % 10) + '0');
	}
}
