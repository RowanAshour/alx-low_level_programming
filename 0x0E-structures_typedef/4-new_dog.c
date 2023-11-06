#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dog.h"

/**
 * new_dog - creates a new dog
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 *
 * Description: Creates a new dog and stores a copy of name and owner.
 * Return: Pointer to the new dog, or NULL if it fails.
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *new_dog;
	char *name_copy, *owner_copy;
	int name_len, owner_len;

	/* Calculate the length of name and owner */
	name_len = strlen(name);
	owner_len = strlen(owner);

	/* Allocate memory for the new dog */
	new_dog = malloc(sizeof(dog_t));
	if (new_dog == NULL)
		return (NULL);

	/* Allocate memory for the name and owner copies */
	name_copy = malloc((name_len + 1) * sizeof(char));
	owner_copy = malloc((owner_len + 1) * sizeof(char));

	/* Check if memory allocation fails */
	if (name_copy == NULL || owner_copy == NULL)
	{
		free(new_dog);
		free(name_copy);
		free(owner_copy);
		return (NULL);
	}

	/* Copy the name and owner to the allocated memory */
	strcpy(name_copy, name);
	strcpy(owner_copy, owner);

	/* Assign the values to the new dog */
	new_dog->name = name_copy;
	new_dog->age = age;
	new_dog->owner = owner_copy;

	return (new_dog);
}

int main(void)
{
	dog_t *my_dog;

	my_dog = new_dog("Poppy", 3.5, "Bob");
	if (my_dog == NULL)
	{
		printf("Failed to create a new dog.\n");
		return (1);
	}

	printf("My name is %s, and I am %.1f :) - Woof!\n", my_dog->name, my_dog->age);

	free(my_dog->name);
	free(my_dog->owner);
	free(my_dog);

	return (0);
}
