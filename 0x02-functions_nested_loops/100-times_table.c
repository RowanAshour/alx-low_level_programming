#include "main.h"

/**
 * print_times_table - Prints the n times table, starting with 0.
 * @n: The number to print the times table for.
 */
void print_times_table(int n)
{
	int row, column, product;

	if (n < 0 || n > 15)
		return;

	for (row = 0; row <= n; row++)
	{
		for (column = 0; column <= n; column++)
		{
			product = row * column;

			if (column != 0)
			{
				_putchar(',');
				_putchar(' ');
			}

			if (product < 10 && column != 0)
			{
				_putchar(' ');
				_putchar(' ');
			}
			else if (product >= 10 && product < 100)
			{
				_putchar(' ');
				_putchar('0' + (product / 10));
			}
			else if (product >= 100)
			{
				_putchar('0' + (product / 100));
				_putchar('0' + ((product / 10) % 10));
			}

			_putchar('0' + (product % 10));
		}
		_putchar('\n');
	}
}

