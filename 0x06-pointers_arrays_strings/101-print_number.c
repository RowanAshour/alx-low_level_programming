#include "main.h"

/**
 * print_number - Prints an unsigned integer.
 *
 * @n: The unsigned integer to print.
 */
void print_number(unsigned int n)
{
	if (n / 10)
	print_number(n / 10);

	_putchar('0' + n % 10);
}
