#include <stdio.h>

int count_dates(char dateOne[10], char dateTwo[10]){
    
    int current_day = 0, current_month = 0, current_year = 0;
    int count_day = 0, count_month = 0, count_year = 0;
    int final_day, final_month, final_year;

while(current_day != final_day && current_month != final_month && current_year != final_year)
{   
    
    
    current_day++;
    count_day++;

    if((current_month == 1 || current_month == 3 || current_month == 5 || current_month == 7|| current_month == 8 || current_month == 10 || current_month == 12) && current_day == 31)
    {
        current_day = 1;
        current_month++;
    }

    if((count_month == 1 || count_month == 3 || count_month == 5 || count_month == 7|| count_month == 8 || count_month == 10 || count_month == 12) && count_day == 31)
    {
        count_day = 1;
        count_month++;
    }

    if((current_month == 2 || current_month == 4|| current_month == 6 || current_month == 9 || current_month == 11) && current_day == 30)
    {
        current_day = 1;
        current_month++;
    }

    if((count_month == 2 || count_month == 4 || count_month == 6 || count_month == 9|| count_month == 11) && count_day == 30)
    {
        count_day = 1;
        count_month++;
    }

    if((current_month == 2 && current_day == 28 && isLeapYear(current_year) == 0) || (current_month == 2 && current_day == 29 && isLeapYear(current_year) == 1))
    {
        current_day = 1;
        current_month++;
    }
    if((count_month == 2 && count_day == 28 && isLeapYear(current_year) == 0) || (count_month == 2 && count_day == 29 && isLeapYear(current_year) == 1))
    {
        current_day = 1;
        current_month++;
    }

    if(current_month == 12 && current_day == 31)
    {
        current_day = 1;
        current_month = 1;
        current_year++;
    }

    if(count_month == 12 && count_day == 31)
    {
        count_day = 1;
        count_month = 1;
        count_year++;
    }
}

    // RESSALVAS: 
    // - As variáveis de contagem recebem os valores indicados pelo usuário
    // - Criar as funções isLeapYear() e date()

}


