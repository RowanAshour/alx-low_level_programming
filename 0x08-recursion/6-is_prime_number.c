#include "main.h"

/**
 * check_prime - checks for prime numbers
 * @n: integer
 * @i: integer
 *
 * Return: 1 if input integer is a prime number, otherwise return 0
 */
int check_prime(int n, int i)
{
	if (n == i)
		return (1);
	if (n % i == 0)
		return (0);
	return (check_prime(n, i + 1));
}

/**
 * is_prime_number - checks if a number is prime
 * @n: integer
 *
 * Return: 1 if the input integer is a prime number, otherwise return 0
 */
int is_prime_number(int n)
{
	if (n < 2)
		return (0);
	return (check_prime(n, 2));
}
