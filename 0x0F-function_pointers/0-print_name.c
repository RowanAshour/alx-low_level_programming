#include "function_pointers.h"

/* print_name - A function that prints a name.
* @name: A pointer to a char that contains the name to be printed.
*@f: A function pointer to a function that takes a char pointer (the name) as 
*parameter and returns nothing.
* This function takes as parameters a name (char pointer) and a function 
* pointer 'f'. This function pointer 'f' points to a function that takes a
* char pointer as a parameter and returns nothing. The 'print_name' function 
* checks first if 'name' and the function pointer 'f' are not NULL. If they 
* are not NULL, it calls the function that 'f' points to, using 'name' as the 
* argument for that function
* Return: Nothing.
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
