#include <stdio.h>

/**
 * main - finds and prints the largest prime factor of the number 612852475143
 *
 * Return: Always 0.
 */
int main(void)
{
long num = 612852475143;
long largest_prime;
long i;

for (i = 2; i <= num; i++)
{
if (num % i == 0)
{
num /= i;
largest_prime = i;
i--;
}
}

printf("%ld\n", largest_prime);
return (0);
}
