#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Description: Prints the name of the file it was compiled from
 *
 * Return: 0 if successful, other value otherwise
 */
int main(void)
{
	/* Print the name of the file */
	printf("%s\n", __FILE__);
	
	/* End program successfully */
	return (0);
}
