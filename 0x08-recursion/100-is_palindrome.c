#include "main.h"

/**
 * str_length - returns the length of a string
 * @s: string
 *
 * Return: length of string
 */
int str_length(char *s)
{
	if (*s == '\0')
		return (0);
	return (1 + str_length(s + 1));
}

/**
 * check_palindrome - checks if a string is a palindrome
 * @s: string
 * @n: length of string
 *
 * Return: 1 if a string is a palindrome and 0 if not
 */
int check_palindrome(char *s, int n)
{
	if (n <= 1)
		return (1);
	else if (*s != s[n - 1])
		return (0);
	else
		return (check_palindrome(s + 1, n - 2));
}

/**
 * is_palindrome - checks if a string is a palindrome
 * @s: string
 *
 * Return: 1 if a string is a palindrome and 0 if not
 */
int is_palindrome(char *s)
{
	int n = str_length(s);

	return (check_palindrome(s, n));
}
