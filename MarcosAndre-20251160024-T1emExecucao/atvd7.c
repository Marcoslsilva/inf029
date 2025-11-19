#include <stdio.h>
#include "functions.h"

#define MAX_TAM 250

int wordSearch(char game[MAX_TAM][MAX_TAM], char key[])
{
    int tam = 0;
    while (key[tam] != '\0')
        tam++;

    for (size_t i = 0; i < MAX_TAM; i++) {
        for (size_t j = 0; j < MAX_TAM; j++) {

            if (game[i][j] == key[0]) {
                if (isWordHiddenHere(game, key, i, j, tam))
                    return 1;
            }

        }
    }
    return 0; 
}