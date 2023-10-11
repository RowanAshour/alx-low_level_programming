#include <stdio.h>
#include <limits.h>

/**
 * main - prints the first n Fibonacci numbers, starting with 1 and 2.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    int count;
    unsigned long i = 1, j = 2, t;

    printf("%lu, %lu", i, j);  /* print the first two numbers */

    for (count = 2; count < 98 && j <= ULONG_MAX - i; count++)
    {
        t = i + j;
        printf(", %lu", t);
        i = j;
        j = t;
    }
    printf("\n");

    return (0);
}

