#include <stdio.h>

/**
 *  * array_iterator - Executes a given action on each element of an array
 *   * @array: The array to iterate through
 *    * @size: The size of the array
 *     * @action: The function to execute on each array element
 *      */
void array_iterator(int *array, size_t size, void (*action)(int))
{
		if (array && action)
				{
							size_t i;

									for (i = 0; i < size; i++)
												{
																action(array[i]);
																		}
										}
}

/**
 *  * print_elem - Prints an integer element
 *   * @elem: The element to print
 *    */
void print_elem(int elem)
{
		printf("%d\n", elem);
}

/**
 *  * print_elem_hex - Prints an integer element in hexadecimal format
 *   * @elem: The element to print
 *    */
void print_elem_hex(int elem)
{
		printf("0x%x\n", elem);
}

/**
 *  * main - Entry point of the program
 *   *
 *    * Return: 0 on success
 *     */
int main(void)
{
		int array[5] = {0, 98, 402, 1024, 4096};

			array_iterator(array, 5, &print_elem);
				array_iterator(array, 5, &print_elem_hex);
					return (0);
}
