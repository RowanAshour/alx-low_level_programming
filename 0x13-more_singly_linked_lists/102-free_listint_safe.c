#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * free_listint_safe - Frees a listint_t linked list safely.
 * @h: Pointer to the head of the list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *current, *temp;
	size_t count = 0;

	if (h == NULL || *h == NULL)
		return (count);

	current = *h;

	while (current != NULL)
	{
		count++;

		if (current->next >= current)
		{
			temp = current->next;
			current->next = NULL;
			current = temp;
			break;
		}

		temp = current;
		current = current->next;
		free(temp);
	}

	*h = NULL;
	return (count);
}

