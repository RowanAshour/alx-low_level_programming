#include "main.h"

/**
 * leet - encodes a string into 1337
 * @s: string to encode
 *
 * Return: pointer to the encoded string
 */
char *leet(char *s)
{
	int i, j;
	char normal[] = "aeotlAEOTL";
	char leet[] = "4307143071";

	for (i = 0; s[i]; i++)
	{
		for (j = 0; normal[j]; j++)
		{
			if (s[i] == normal[j])
			{
				s[i] = leet[j];
				break;
			}
		}
	}

	return (s);
}
