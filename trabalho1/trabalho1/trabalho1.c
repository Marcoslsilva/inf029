#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "functions.h"

#define CURRENT_YEAR 2025

int isDateValid(char date[])
{
    Response r = extDate(date);

    int day = r.exit[0],month = r.exit[1], year = r.exit[2];
    bool isLeapYear;
    
    if (day < 0 || day > 31)
    {
        return 0;
    }

    if (month < 0 || month > 12)
    {
        return 0;
    }

    if (year > CURRENT_YEAR)
    {
        return 0;
    }

    if (year % 400 == 0 || year % 4 == 0)
    {
        isLeapYear = true;
    }

    if ((month == 2 || month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
    {
        return 0;
    }

    if (day == 29 && month == 2 && isLeapYear == false)
    {
        return 0;
    }

    return 1;
}