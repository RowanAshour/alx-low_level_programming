#include <stdio.h>

/**
 * _atoi - converts a string to an integer
 * @s: pointer to the string to be converted
 *
 * Return: the converted integer
 */
int _atoi(char *s)
{
int sign = 1; /* sign of the number */
int result = 0; /* final result */
int i = 0; /* index for iterating through the string */

/* handle the sign */
if (s[0] == '-')
{
sign = -1;
i++;
}
else if (s[0] == '+')
{
i++;
}

/* convert the string to an integer */
while (s[i] != '\0')
{
if (s[i] >= '0' && s[i] <= '9')
{
result = result * 10 + (s[i] - '0');
}
else
{
break; /* stop conversion if non-digit character encountered */
}
i++;
}

return result * sign;
}
