#include "main.h"
#include <stdlib.h>

/**
 * strtow - splits a string into words
 * @str: the string to split
 *
 * Return: pointer to an array of words
 */
char **strtow(char *str)
{
	int i, j, words = 0, length;
	char **s;

	if (str == NULL || *str == '\0')
		return (NULL);

	for (i = 0; str[i]; i++)
		words += (str[i] == ' ' && str[i + 1] != ' ' && str[i + 1] != '\0');

	s = malloc((words + 1) * sizeof(char *));
	if (s == NULL)
		return (NULL);

	for (i = 0; *str;)
	{
		while (*str == ' ')
			str++;

		if (*str == '\0')
			break;

		for (length = 0; str[length] != ' ' && str[length]; length++)
			;

		s[i] = malloc((length + 1) * sizeof(char));
		if (s[i] == NULL)
		{
			while (i >= 0)
				free(s[i--]);
			free(s);
			return (NULL);
		}

		for (j = 0; j < length; j++)
			s[i][j] = *str++;
		s[i++][j] = '\0';
	}
	s[i] = NULL;

	return (s);
}
