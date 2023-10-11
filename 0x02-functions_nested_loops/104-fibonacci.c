#include <stdio.h>

/**
 * main - prints the first 48 Fibonacci numbers,
 * starting with 1 and 2, followed by a new line.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
int i;
double prev = 1, curr = 2, next;

printf("%.0f, %.0f", prev, curr); /* print the first two numbers */

for (i = 3; i <= 96; i++) /* print the next 96 numbers */
{
next = prev + curr;
printf(", %.0f", next);
prev = curr;
curr = next;
}

printf("\n"); /* print a new line at the end */

return (0);
}
