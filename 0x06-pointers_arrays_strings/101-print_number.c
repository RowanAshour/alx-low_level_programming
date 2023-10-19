#include "main.h"

/**
 * print_number - Prints an integer.
 *
 * @n: The integer to print.
 */
void print_number(int n)
{
/* Handle negative numbers */
if (n < 0)
{
_putchar('-');
n = -n;
}

/* Recursively print digits */
if (n / 10)
print_number(n / 10);

/* Print the last digit */
_putchar('0' + n % 10);
}
