#include "function_pointers.h"

/*
*print_name - prints a name
*@name: name of the person
*@f: A pointer to function taking a character pointer
*Return: Nothing.
*/
void print_name(char *name, void (*f)(char *))
{
	/* Check if the function pointer and name is not NULL */
	if (name != NULL && f != NULL)
	{
		/* Call the function */
	f(name);
	}
}
