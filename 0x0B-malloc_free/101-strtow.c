#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * word_count - Counts the number of words in a string
 * @str: The string to count
 *
 * Return: The number of words in the string
 */
int word_count(char *str)
{
	int i, count = 0;

	for (i = 0; str[i]; i++)
	{
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			count++;
	}
	return (count);
}

/**
 * strtow - Splits a string into words
 * @str: The string to split
 *
 * Return: A pointer to an array of strings (words)
 */
char **strtow(char *str)
{
	char **words;
	int i, j, k, l, wc;

	if (str == NULL || str[0] == '\0')
		return (NULL);

	wc = word_count(str);
	if (wc == 0)
		return (NULL);

	words = malloc((wc + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);

	for (i = 0, j = 0; i < wc; i++)
	{
		while (str[j] == ' ')
			j++;

		for (k = j; str[k] != ' ' && str[k] != '\0'; k++)
			;

		words[i] = malloc((k - j + 1) * sizeof(char));
		if (words[i] == NULL)
		{
			while (i >= 0)
				free(words[--i]);
			free(words);
			return (NULL);
		}

		for (l = 0; j < k; j++, l++)
			words[i][l] = str[j];
		words[i][l] = '\0';
	}
	words[i] = NULL;

	return (words);
}
