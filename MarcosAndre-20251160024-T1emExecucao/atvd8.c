#include <stdio.h>
#include <stdlib.h>
#define A 65
#define SQUARES_BOARD 3

int main(){
    char board[4][4];
    int column = A;
    int line = 1;

    board[1][0] = 'A';
    board[2][0] = 'B';
    board[3][0] = 'C';
    
    // board[0][1] = '1';
    // board[0][2] = '2';
    // board[0][3] = '3';
    


    // for (int i = 0; i < SQUARES_BOARD; i++)
    // {
    //     for (int j = 0; j < SQUARES_BOARD; j++)
    //     {
    //         board[i][j] = 'P';

    //         if (i == 0)
    //         {
    //             sprintf(line);
    //             board[i][j] = line;
    //             atoi(line);
    //             line++;
    //         }
    //         if (j == 0)
    //         {
    //             board[i][j] = column;
    //             column++;
    //         }
            
    //     }
        
    // }
    
    for (int i = 0; i < SQUARES_BOARD; i++)
    {
        for (int j = 0; i < SQUARES_BOARD; j++)
        {
            printf("%c |", board[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}