#include "main.h"

/**
 * _print_rev_recursion - prints a string in reverse
 * @s: the string to print
 *
 * Return: void
 */
void _print_rev_recursion(char *s)
{
	if (*s == '\0')  /* base case: if the current character is null, return */
	{
		return;
	}
	else
	{
		_print_rev_recursion(s + 1);  /* recursive call with the next character */
		_putchar(*s);  /* print the current character */
	}
}
