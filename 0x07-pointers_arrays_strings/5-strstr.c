#include "main.h"
#include <stddef.h>

/**
 * _strstr - locates a substring
 * @haystack: string in which to search
 * @needle: substring to locate
 *
 * Return: pointer to the beginning of the located substring, or NULL if the
 * substring is not found
 */
char *_strstr(char *haystack, char *needle)
{
char *h;
char *n;

while (*haystack)
{
h = haystack;
n = needle;

while (*haystack && *n && *haystack == *n)
{
haystack++;
n++;
}

if (!*n)
return (h);

haystack = h + 1;
}
return (NULL);
}
