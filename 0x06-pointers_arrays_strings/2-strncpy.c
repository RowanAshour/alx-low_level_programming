#include "main.h"

/**
 * _strncpy - a function that copies a string.
 * @dest: a pointer to the destination string.
 * @src: a pointer to the source string.
 * @n: the maximum number of characters to be copied from src.
 *
 * Return: a pointer to the resulting string dest.
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	/* Copy at most n characters from src string to dest string */
	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];

	/* If src is less than n characters long, pad dest with '\0' */
	for ( ; i < n; i++)
		dest[i] = '\0';

	return (dest);
}
