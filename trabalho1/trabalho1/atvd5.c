#include <stdio.h>

int reverse_number(int number, int amount){
    
    int exp = 1, exit[512], position = 0, leftover, store;

    for (int i = 0; i < amount - 1; i++)
    {   
        exp *= 10;
    }

    
    
    exit[amount] = number / exp;
    leftover = number % exp;
    
    for (int i = 1; i <= amount - 1; i++)
    {
        exp /= 10;
        exit[amount - i] = leftover / exp;
        leftover %= exp;
    }
    

    

    //se não puder pedir a quantidade como parâmetro, transformar o número em uma string, contar a quantidade de caracteres e transformar em número de novo
}