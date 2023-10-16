#include <stdio.h>

/**
 * puts2 - prints every other character of a string, followed by a new line
 * @str: pointer to a string
 *
 * Return: void
 */
void puts2(char *str)
{
int i = 0;

/* iterate over the string until the null character */
while (str[i] != '\0')
{
if (i % 2 == 0) /* if the index is even */
{
putchar(str[i]); /* print the character */
}
i++;
}

putchar('\n'); /* print a new line */
}
