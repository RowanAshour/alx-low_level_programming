#include "main.h"

/**
 * cap_string - a function that capitalizes all words of a string.
 * @s: a pointer to the string.
 *
 * Return: a pointer to the string with all words capitalized.
 */
char *cap_string(char *s)
{
	int i, j;
	char separators[] = " \t\n,;.!?\"(){}";

	/* Capitalize first character if it's a letter */
	if (s[0] >= 'a' && s[0] <= 'z')
		s[0] = s[0] - 'a' + 'A';

	/* Iterate over each character in the string */
	for (i = 1; s[i] != '\0'; i++)
	{
		/* Check if character is a separator */
		for (j = 0; separators[j] != '\0'; j++)
		{
			if (s[i] == separators[j] && s[i + 1] >= 'a' && s[i + 1] <= 'z')
			{
				/* Capitalize next character if it's a letter */
				s[i + 1] = s[i + 1] - 'a' + 'A';
			}
		}
	}

	return (s);
}
