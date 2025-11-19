#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

int * count_dates(char dateOne[11], char dateTwo[11])
{

    int current_day, current_month, current_year;
    int count_day = 0, count_month = 0, count_year = 0;
    int final_day, final_month, final_year;
    int * response;

    response = malloc(3 * sizeof(int)); // "Array" que será a saída, resposta, retorno da função

    if (isDateValid(dateOne) == 0 || isDateValid(dateTwo) == 0)
    {
        return 0;
    }
    
    Response rTwo = extDate(dateTwo);
    final_day = rTwo.exit[0];
    final_month = rTwo.exit[1];
    final_year = rTwo.exit[2];

    Response rOne = extDate(dateOne);
    current_day = rOne.exit[0];
    current_month = rOne.exit[1];
    current_year = rOne.exit[2];

    if((current_year > final_year) || 
        (current_year < final_year && current_month > final_month) || 
        (current_year < final_year && current_month > final_month && current_day > final_day))
    {
        return 0;
    }

    while (!(current_day == final_day && current_month == final_month && current_year == final_year))
    {
        
        current_day++;

        if (current_day > daysInMonth(current_month, current_year))
        {
            current_day = 1;
            current_month++;

            if (current_month > 12)
            {
                current_month = 1;
                current_year++;
            }
        }

        count_day++;
        if (count_day > daysInMonth(count_month == 0 ? current_month : count_month,
                                     count_year == 0 ? current_year : count_year))
        {
            count_day = 1;
            count_month++;

            if (count_month >= 12)
            {
                count_month = 1;
                count_year++;
            }
        }
    }

    response[0] = count_day;
    response[1] = count_month;
    response[2] = count_year;

    return response;
}

int main()
{

    char dateOne[11] = {"30/11/2005"};
    char dateTwo[11] = {"21/12/1998"};
    

    if(count_dates(dateOne, dateTwo) == 0){
        printf("Data(s) inválida(s)");
    }

    for (int i = 0; i < 3; i++)
    {
        printf("%d ", count_dates(dateOne, dateTwo)[i]);
    }
    

    return 0;
}