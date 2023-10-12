#include <stdio.h>
#include "main.h"

/**
 * convert_day - Converts the day of the year to a specific month and day.
 * @year: Year.
 * @day: Day of the year.
 * @month: Pointer to the variable to store the converted month.
 * @dayOfMonth: Pointer to the variable to store the converted day of the month.
 *
 * Return: void
 */
void convert_day(int year, int day, int *month, int *dayOfMonth)
{
	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int i;

	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		daysInMonth[1] = 29;

	for (i = 0; i < 12; i++)
	{
		if (day <= daysInMonth[i])
			break;
		day -= daysInMonth[i];
	}

	*month = i + 1;
	*dayOfMonth = day;
}
