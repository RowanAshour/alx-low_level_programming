#include <stdio.h>

/**
 * print_array - prints n elements of an array of integers,
 * followed by a new line
 * @a: pointer to an array of integers
 * @n: number of elements of the array to be printed
 *
 * Return: void
 */
void print_array(int *a, int n)
{
int i;

/* iterate over the array */
for (i = 0; i < n; i++)
{
printf("%d", a[i]); /* print the current element */

/* print a comma and a space after all but the last element */
if (i < n - 1)
{
printf(", ");
}
}

printf("\n"); /* print a new line */
}
