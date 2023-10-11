#include "main.h"

/**
 * print_alphabet_x10 - Prints the alphabet in lowercase, ten times
 *
 * Description: This function prints the alphabet in lowercase,
 *              followed by a new line, ten times, using the _putchar function.
 */
void print_alphabet_x10(void)
{
	char letter;
	int i;

	for (i = 0; i < 10; i++)
	{
		for (letter = 'a'; letter <= 'z'; letter++)
		{
			_putchar(letter);
		}

		_putchar('\n');
	}
}
