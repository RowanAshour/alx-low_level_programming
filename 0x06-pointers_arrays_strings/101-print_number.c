#include "main.h"

/**
 * print_number - Prints an integer
 * @n: The integer to be printed
 */
void print_number(unsigned int n)
{
	unsigned int divisor = 1;
	unsigned int i, digit;
	
	if (n == 0)
	{
		_putchar('0');
		return;
	}
	
	for (i = n; i > 0; i /= 10)
		divisor *= 10;
	
	while (divisor > 0)
	{
	      digit = n / divisor;
		_putchar(digit + '0');
		n %= divisor;
		divisor /= 10;
	}
}
