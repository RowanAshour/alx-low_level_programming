#include <stdlib.h>
#include <string.h>

/**
 * _realloc - Reallocates a memory block using malloc and free.
 * @ptr: A pointer to the memory previously allocated.
 * @old_size: The size of the allocated space for ptr.
 * @new_size: The size of the new memory block.
 *
 * Return: If new_size > old_size, the added memory is not initialized.
 *         If new_size == old_size, returns ptr.
 *         If ptr is NULL, returns a call to malloc(new_size).
 *         If new_size == 0 and ptr is not NULL, returns NULL.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *mem;
	char *ptr_copy, *filler;
	unsigned int index;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		mem = malloc(new_size);
		if (mem == NULL)
			return (NULL);

		return (mem);
	}

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	mem = malloc(new_size);
	if (mem == NULL)
	{
		free(ptr);
		return (NULL);
	}

	ptr_copy = ptr;
	filler = mem;

	for (index = 0; index < old_size && index < new_size; index++)
		filler[index] = *ptr_copy++;

	free(ptr);

	return (mem);
}
