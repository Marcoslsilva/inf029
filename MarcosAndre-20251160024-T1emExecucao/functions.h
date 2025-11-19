#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#define CURRENT_YEAR 2025
#define MAX_TAM 250

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Response
{
    int exit[3];
} Response;

Response extDate(char date[])
{

    char day_char[3], month_char[3], year_char[5];
    int day, month, year;
    int i = 0;
    Response response;

    int control = 0;
    int j = 0;

    while (date[i] != '\0')
    {

        if (date[i] == '/')
        {
            if (control == 0)
            {
                day_char[j] = '\0';
            }
            if (control == 1)
            {
                month_char[j] = '\0';
            }

            control++;
            j = 0;
        }

        if (control == 0)
        {
            day_char[j] = date[i];
            j++;
        }
        if (control == 1 && date[i] != '/')
        {
            month_char[j] = date[i];
            j++;
        }
        if (control == 2 && date[i] != '/')
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

void tratmentString(char *str[])
{
    int i = 0;

    while (*str[i] != '\0')
    {
        if (*str[i] >= 'a' && str[i] <= "z")
        {
            *str[i] = *str[i] - 'a' + 'A';
        }

        i++;
    }
}

bool isLeapYear(int year)
{

    if (year % 4 == 0 || year % 400 == 0)
    {
        return true;
    }

    return false;
}

int returnExp(int number)
{
    int exp = 1;
    int n = 0;

    do
    {
        n = number / (exp * 10);
        exp *= 10;
    } while (n > 10 || n < 0);

    return exp;
}

int reversingNumber(int exp, int overExp, int leftover)
{

    int n = 0;

    if (overExp < 1)
    {
        return n;
    }

    n = leftover / overExp;
    leftover %= overExp;
    n *= exp / overExp;
    overExp /= 10;

    n += reversingNumber(exp, overExp, leftover);
    // printf("%d \n", n);

    return n;
}

int isDateValid(char date[])
{
    Response r = extDate(date);

    int day = r.exit[0], month = r.exit[1], year = r.exit[2];
    bool isLeapYear = false;

    if (day < 1 || day > 31)
    {
        return 0;
    }

    if (month < 1 || month > 12)
    {
        return 0;
    }

    if (year < 0 || year > CURRENT_YEAR)
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

int *ignoreSpecialCharacters(char strText[], int *intText)
{
    int k = 0;
    for (int j = 0; j < strlen(strText); j++)
    {
        if (strText[j] != -61)
        {
            intText[k] = strText[j];
            k++;
        }
    }
    return intText;
}

int daysInMonth(int month, int year)
{
    if (month == 2)
        return isLeapYear(year) ? 29 : 28;

    if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;

    return 31;
}

int isWordHiddenHere(char game[MAX_TAM][MAX_TAM], char key[], int line, int column, int tam)
{
    // percorrendo na linha
    int k = 1;
    int final, start;

    
    for (int j = column + 1; j < MAX_TAM && k < tam; j++) {
        if (game[line][j] == key[k])
            k++;
        else
            break;
        
    }
    if (k == tam) return 1;

    //percorrendo a coluna

    k = 1;
    for (int i = line + 1; i < MAX_TAM && k < tam; i++) {
        if (game[i][column] == key[k])
            k++;
        else
            break;
    }
    if (k == tam) return 1;

    //achando na diagonal
    k = 1;
    for (int i = line + 1, j = column + 1; i < MAX_TAM && j < MAX_TAM && k < tam; i++, j++) {
        if (game[i][j] == key[k])
            k++;
        else
            break;
    }
    if (k == tam) return 1;
    //diagonal invertida ou secundária

    k = 1;
    for (int i = line + 1, j = column - 1; i < MAX_TAM && j >= 0 && k < tam; i++, j--) {
        if (game[i][j] == key[k])
            k++;
        else
            break;
    }
    if (k == tam) return 1;

    return 0;
}
#endif