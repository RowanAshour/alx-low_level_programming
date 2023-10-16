/**
 * _strlen - returns the length of a string
 * @s: pointer to a string
 *
 * Return: length of the string
 */
int _strlen(char *s)
{
	int length = 0;

/* iterate over the string until the null character */
	while (*s != '\0')
	{
	length++;
	s++;
	}

	return length;
}
