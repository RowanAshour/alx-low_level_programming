#include "function_pointers.h"

/**
 *  * print_name - Prints a name using a function pointer.
 *   * @name: The name to print.
 *    * @f: A pointer to a function that prints a name.
 *     *
 *      * Return: void
 *       */
void print_name(char *name, void (*f)(char *))
{
if (name != NULL && f != NULL)
f(name);
}
