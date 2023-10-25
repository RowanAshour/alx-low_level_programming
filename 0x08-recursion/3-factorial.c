#include "main.h"

/**
 * factorial - returns the factorial of a given number
 * @n: the number to find the factorial of
 *
 * Return: the factorial of the number, or -1 if the number is less than 0
 */
int factorial(int n)
{
	if (n < 0)  /* if n is less than 0, return -1 to indicate an error */
	{
		return (-1);
	}
	else if (n == 0)  /* base case: if n is 0, return 1 */
	{
		return (1);
	}
	else
	{
		/* recursive call with n - 1 and multiply the result by n */
		return (n * factorial(n - 1));
	}
}
