#include "main.h"

/**
 * _strncat - a function that concatenates two strings.
 * @dest: a pointer to the destination string.
 * @src: a pointer to the source string.
 * @n: the maximum number of bytes to be used from src.
 *
 * Return: a pointer to the resulting string dest.
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;

	/* Find the end of the dest string */
	for (i = 0; dest[i] != '\0'; i++)
		;

	/* Append at most n bytes from src string to dest string */
	for (j = 0; j < n && src[j] != '\0'; j++)
		dest[i + j] = src[j];

	/* Add terminating null byte */
	dest[i + j] = '\0';

	return (dest);
}
