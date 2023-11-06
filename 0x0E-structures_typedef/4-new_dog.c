#include "dog.h"
#include <stdlib.h>
#include <string.h>

/**
 * _strdup - returns a pointer to a new string which is a duplicate of the string str
 * @str: string to duplicate
 * Return: pointer to duplicated string in memory, NULL if insufficient memory
 */
char *_strdup(char *str)
{
    char *duplicate_str;
    int i = 0, len = 0;

    if (str == NULL) /* validate str input */
        return (NULL);

    while (*(str + len))
        len++;
    duplicate_str = malloc(sizeof(char) * (len + 1)); /* allocate memory */

    if (duplicate_str == NULL) /* validate memory */
        return (NULL);

    while (i < len)
    {
        *(duplicate_str + i) = *(str + i);
        i++;
    }

    duplicate_str[i] = '\0'; /* null terminate the string */

    return (duplicate_str);
}

/**
 * new_dog - creates a new dog
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 *
 * Return: pointer to new dog_t
 */
dog_t *new_dog(char *name, float age, char *owner)
{
    dog_t *doggo;

    doggo = malloc(sizeof(dog_t)); /* allocate memory for new dog */
    if (doggo == NULL) /* validate memory */
        return (NULL);

    doggo->name = _strdup(name); /* duplicate name and assign to dog name */
    if (doggo->name == NULL) /* validate name */
    {
        free(doggo); /* prevent memory leak */
        return (NULL);
    }

    doggo->age = age; /* assign age */

    doggo->owner = _strdup(owner); /* duplicate owner and assign to dog owner */
    if (doggo->owner == NULL) /* validate owner */
    {
        free(doggo->name); /* prevent memory leak */
        free(doggo); /* prevent memory leak */
        return (NULL);
    }

    return (doggo);
}

