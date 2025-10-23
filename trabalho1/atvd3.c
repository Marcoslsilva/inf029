#include <stdio.h>

int howMuchTimes(char str[], char key, int count){
    
    int count_times = 0;
    int i = 0;
    
    tratamentString(*str);

    for (int i = 0; i < count; i++)
    {
        if (key == str[i])
        {
            count_times++;
        }
        
    }

    return count_times;

}

