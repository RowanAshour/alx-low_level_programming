#include <stdio.h>
#include "main.h"

int main(void)
{
    int month, dayOfMonth;
    int year = 2022;
    int day = 60; /* Assuming it's the 60th day of the year */

    convert_day(year, day, &month, &dayOfMonth);
    printf("Date: %d/%d/%d\n", dayOfMonth, month, year);

    print_remaining_days(month, dayOfMonth, year);

    return 0;
}
