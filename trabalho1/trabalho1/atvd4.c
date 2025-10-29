#include <stdio.h>
#include "functions.h"

#define MAX_STR 1024

// typedef struct returnPositionStr{
//     int array[250];
// }returnPositonsStr;

void strPosition(char str[], char key[], int count){
    
    int i = 0, k = 0, start, final;
    // returnPositonsStr r;
    
    while (str[i] != '\0')
    {
        if(k == count - 1)
        {
            final = i;
            printf("%d, %d \n", start, final);
            k = 0;
        }

        if (key[k] == str[i] && k == 0)
        {
            start = i;
        }
        
        if(key[k] == str[i])
        {
            k++;
        }else {
            k = 0;
        }
        
        i++;
    }
    
    // return r.array;
}


int main(){
    char str[MAX_STR] = {'a', 'n', 'a', ' ', 'b','a','n','a', 'n', 'a', '\0'};
    char key[MAX_STR] = {'a','n','a','\0'};
    int count;

    strPosition(str, key, count);

    //for (count = 0; key[count] != '\0'; count++);
   
    

    return 0;
}