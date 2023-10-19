#include "main.h"

/**
 * string_toupper - a function that changes all lowercase
 * letters of a string to uppercase.
 * @s: a pointer to the string.
 *
 * Return: a pointer to the string with all lowercase
 *letters changed to uppercase.
 */
char *string_toupper(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] = s[i] - 'a' + 'A';
	}

	return (s);
}
