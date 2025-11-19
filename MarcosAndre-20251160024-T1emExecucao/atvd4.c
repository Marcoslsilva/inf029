#include <stdio.h>
#include "functions.h"

#define MAX_STR 250

int * strPosition(char str[], char key[]){
    
    int i = 0, k = 0, j = 1, start, final, count, *intText;

    int * response;
    response = malloc(250 * sizeof(int));
    intText = malloc(250 * sizeof(int));
    
    ignoreSpecialCharacters(str, intText);
    

    for (count = 0; key[count] != '\0'; count++);
    
    while (intText[i] != '\0')
    {
        if(k == count - 1)
        {
            final = i;
            response[j] = start;
            response[j + 1] = final;
            j += 2;
            k = 0;
        }

        if (key[k] == intText[i] && k == 0)
        {
            start = i;
        }
        
        if(key[k] == intText[i])
        {
            k++;
        }else {
            k = 0;
        }
        
        i++;
    }
    response[0] = j;
    return response;
}


int main(){
    char str[MAX_STR] = {'a', 'n', 'a', ' ', 'b','a','n','a', 'n', 'a', '\0'};
    char key[MAX_STR] = {'a','n','a','\0'};

    strPosition(str, key);

    for (int i = 1; i < strPosition(str, key)[0]; i+=2)
    {
        printf("%d %d \n", strPosition(str, key)[i], strPosition(str, key)[i + 1]);
    }
    
    return 0;
}