#include <stdio.h>

/**
 * main - prints the first Fibonacci numbers that fit in a long
 * Return: Always 0 (Success)
 */
int main(void)
{
long i, j, k;

i = 1;
j = 2;

printf("%ld, %ld", i, j);

while (1)
{
k = i + j;

        /* If k < j, then we've had an overflow and we're done */
if (k < j)
{
printf("\n");
return (0);
}
printf(", %ld", k);

i = j;
	j = k;
}

return (0);
}

