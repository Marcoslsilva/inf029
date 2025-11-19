#include <stdio.h>

#include "Functions.h"

int reverse_number(int number)
{

    int exp = 1, leftover;
    int n = 0, overExp = 1;
    int hmt = 0;

    do
    {
        n = number / (exp * 10);
        exp *= 10;
        hmt++;
    } while (n > 9 || n < 0);

    overExp = exp;
    leftover = number;

    return reversingNumber(exp, overExp, leftover);

   
}

int main()
{

    printf("%d", reverse_number(3246));
    return 0;
}