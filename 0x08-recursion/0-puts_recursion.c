#include <stdio.h>
#include "main.h"

/**
 * _puts_recursion - prints a string followed by a new line
 * @s: the string to print
 *
 * Return: void
 */
void _puts_recursion(char *s)
{
	if (*s == '\0')  /* base case: if the current character is null, return */
	{
		printf("\n");
		return;
	}
	else
	{
		printf("%c", *s);  /* print the current character */
		_puts_recursion(s + 1);  /* recursive call with the next character */
	}
}

/**
 * main - main function
 *
 * Return: Always 0.
 */
void test_puts_recursion()
{
_puts_recursion("Puts with recursion");
}
