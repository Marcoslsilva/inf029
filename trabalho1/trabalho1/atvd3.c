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

int main(){
    char str[250], key;
    int count = 0;

    fgets(str, 250, stdin);
    str[strcspn(str, "\n")] = '\0';

    scanf("%c", key);

    while (str[count] != 0)
    {
        count++;
    }
    

    printf("%d" , howMuchTimes(str, key, count));
    return 0;
}