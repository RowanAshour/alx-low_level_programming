#include "main.h"
#include <stddef.h>  /* Include the stddef.h header file */

/**
 * _strpbrk - locates the first occurrence in the string s of any of the bytes
 * in the string accept
 * @s: string to be searched
 * @accept: string containing bytes to match
 *
 * Return: a pointer to the byte in s that matches one of the bytes in accept,
 * or NULL if no such byte is found
 */
char *_strpbrk(char *s, char *accept)
{
int i;

while (*s)
{
for (i = 0; accept[i]; i++)
{
if (*s == accept[i])
return (s);
}
s++;
}

return (NULL);
}
