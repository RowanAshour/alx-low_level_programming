#include "main.h"

/**
 * _strlen_recursion - returns the length of a string
 * @s: the string to find the length of
 *
 * Return: the length of the string
 */
int _strlen_recursion(char *s)
{
	if (*s == '\0')  /* base case: if the current character is null, return 0 */
	{
		return (0);
	}
	else
	{
		/* recursive call with the next character and add 1 to the length */
		return (1 + _strlen_recursion(s + 1));
	}
}
