#include <stdio.h>

/**
 * print_rev - prints a string, in reverse, followed by a new line
 * @s: pointer to a string
 *
 * Return: void
 */
void print_rev(char *s)
{
int length = 0;

/* find the length of the string */
while (s[length] != '\0')
{
length++;
}

/* print the string in reverse */
for (int i = length - 1; i >= 0; i--)
{
putchar(s[i]);
}

putchar('\n'); /* print a new line */
}
