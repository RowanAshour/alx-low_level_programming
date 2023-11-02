#include <stdio.h>
#include "main.h"
/**
 * is_digit - checks if a string contains a non-digit char
 * @s: string to be evaluated
 *
 * Return: 0 if a non-digit is found, 1 otherwise
 */
int is_digit(char *s)
{
	int i = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * The function _strlen takes a single argument s which is a pointer to a char type.
 * It initializes an integer variable i to 0.
 * It uses a while loop that continues till the ith element of the string is not equal to null character \0, 
 * inside the loop we increment the value of i.
 * Returns: i which is equal to the length of the string.
 * _strlen - returns the length of a string
 * @s: string to evaluate
 *
 * Return: the length of the string
 */

int _strlen(char *s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return (i);
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * errors - haddles errors for main
 * errors - handles errors for main
 
void errors(void)
{
@@ -53,7 +52,7 @@ void errors(void)
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: always 0 (success)
 * Return: always 0 (Success)
 */
int main(int argc, char *argv[])
{
@@ -68,7 +67,7 @@ int main(int argc, char *argv[])
	len = len1 + len2 + 1;
	result = malloc(sizeof(int) * len);
	if (!result)
	return (1);
		return (1);
	for (i = 0; i <= len1 + len2; i++)
		result[i] = 0;
	for (len1 = len1 - 1; len1 >= 0; len1--)
@@ -90,10 +89,10 @@ int main(int argc, char *argv[])
		if (result[i])
			a = 1;
		if (a)
		_putchar(result[i] + '0');
			_putchar(result[i] + '0');
	}
	if (!a)
	_putchar('0');
		_putchar('0');
	_putchar('\n');
	free(result);
	return (0);
}
