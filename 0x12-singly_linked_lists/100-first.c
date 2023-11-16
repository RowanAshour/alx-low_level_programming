#include <stdio.h>

/**
 * before_main - Function to execute before the main function.
 *
 * Description: This function is executed before the main function and
 * prints a specific message to the standard output.
 */
void __attribute__((constructor)) before_main()
{
	printf("You're beat! and yet, you must allow,
			\nI bore my house upon my back!\n");
}

