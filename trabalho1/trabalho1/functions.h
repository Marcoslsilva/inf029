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

void tratmentString(char *str[]){
    int i = 0;

    while (*str[i] != '\0')
    {
        
        if(*str[i] == 'á' || *str[i] == 'â' || *str[i] == 'ã' || *str[i] == 'à' || *str[i] == 'ä' || *str[i] == 'Á' || *str[i] == 'Â' || *str[i] == 'Ã' || *str[i] == 'À' || *str[i] == 'Ä')
        {
            *str[i] = 'A';
        }
        if(*str[i] == 'é' || *str[i] == 'ê' || *str[i] == 'ë' || *str[i] == 'É' || *str[i] == 'Ê' || *str[i] == 'Ë')
        {
            *str[i] = 'E';
        }
        if(*str[i] == 'í'  || *str[i] == 'ï' || *str[i] == 'Í'  || *str[i] == 'Ï')
        {
            *str[i] = 'I';
        }
        if(*str[i] == 'ó' || *str[i] == 'ô' || *str[i] == 'ö' || *str[i] == 'Ó' || *str[i] == 'Ô' || *str[i] == 'Ö')
        {
            *str[i] = 'O';
        }
        if(*str[i] == 'ú' || *str[i] == 'ü' || *str[i] == 'Ú' || *str[i] == 'Ü')
        {
            *str[i] = 'U';
        }
        
        if (*str[i] >= 'a' && str[i] <= "z")
        {
            *str[i] = *str[i] - 'a' + 'A';
        }

        i++;
        
    }
    
    
}

#endif