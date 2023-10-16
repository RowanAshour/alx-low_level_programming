/**
 * swap_int - swaps the values of two integers
 * @a: pointer to the first integer
 * @b: pointer to the second integer
 *
 * Return: void
 */
void swap_int(int *a, int *b)
{
	int temp;

	temp = *a; /* store the value of *a in temp */
	*a = *b;   /* assign the value of *b to *a */
	*b = temp; /* assign the stored value in temp to *b */
}
