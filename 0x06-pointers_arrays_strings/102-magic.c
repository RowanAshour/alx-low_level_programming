#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Description: This program demonstrates the usage of a pointer to modify
 * the value of an array element indirectly. It assigns the value 98 to a[2]
 * by using a pointer to access the memory location of the variable n.
 * Finally, it prints the value of a[2].
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n;
	int a[5];
	int *p;

	a[2] = 1024;
	p = &n;
	*(p + 5) = 98; /* ...so that this prints 98\n */
	printf("a[2] = %d\n", a[2]);
	return (0);
}
