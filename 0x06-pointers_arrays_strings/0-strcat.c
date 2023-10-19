#include "main.h"

/**
 * _strcat - a function that concatenates two strings.
 * @dest: a pointer to the destination string.
 * @src: a pointer to the source string.
 *
 * Return: a pointer to the resulting string dest.
 */
char *_strcat(char *dest, char *src)
{
	int i, j;

	/* Find the end of the dest string */
	for (i = 0; dest[i] != '\0'; i++)
		;

	/* Append src string to dest string */
	for (j = 0; src[j] != '\0'; j++)
		dest[i + j] = src[j];

	/* Add terminating null byte */
	dest[i + j] = '\0';

	return dest;
}
