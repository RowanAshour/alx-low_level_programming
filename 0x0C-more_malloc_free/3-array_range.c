#include <stdlib.h>

/**
 * array_range - Creates an array of integers ordered from min to max.
 * @min: The first value of the array.
 * @max: The last value of the array.
 *
 * Return: If min > max or the function fails - NULL.
 *         Otherwise - a pointer to the newly created array.
 */
int *array_range(int min, int max)
{
	int *array;
	int index;

	if (min > max)
		return (NULL);

	array = malloc(sizeof(int) * (max - min + 1));

	if (array == NULL)
		return (NULL);

	for (index = 0; min <= max; index++, min++)
		array[index] = min;

	return (array);
}
