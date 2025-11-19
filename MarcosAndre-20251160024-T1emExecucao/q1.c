#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "functions.h"

#define CURRENT_YEAR 2025

int main(){
    char date[11];

    printf("Digite a data \n");
    fgets(date, 11, stdin);

    if(isDateValid(date) == 1)
    {
        printf("Data válida!");
    }else{
        printf("Data inválida");
    }

    return 0;
}