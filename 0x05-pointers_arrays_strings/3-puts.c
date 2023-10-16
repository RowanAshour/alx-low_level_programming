#include <stdio.h>

/**
 * _puts - prints a string, followed by a new line, to stdout
 * @str: pointer to a string
 *
 * Return: void
 */
void _puts(char *str)
{
/* iterate over the string until the null character */
while (*str != '\0')
{
putchar(*str); /* print each character */
str++;
}

putchar('\n'); /* print a new line */
}
