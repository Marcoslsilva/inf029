#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdlib.h>

typedef struct Response
{
    int exit[3];
}Response;

Response extDate(char date[])
{

    char day_char[3], month_char[3], year_char[5];
    int day, month, year;
    int i = 0;
    Response response;
    
     while (date[i] != '\0')
    {
        int control = 0;
        int j = 0;

        if (date[i] == '/')
        {
            control++;
            j = 0;
        }

        if (control == 0)
        {
            day_char[j] = date[i];
            j++;
        }
        if (control == 1)
        {
            month_char[j] = date[i];
            j++;
        }
        if (control == 2)
        {
            year_char[j] = date[i];
            j++;
        }
        
        i++;
    }

    day = atoi(day_char);
    month = atoi(month_char);
    year = atoi(year_char);

    response.exit[0] = day;
    response.exit[1] = month;
    response.exit[2] = year;

    return response;
}


#endif