#include <stdio.h>

void wordSearch(char game[512][512], char key[], int count)
{
    int i, j, k, control = 0, countLines, countColumns;
    int startLine, startColumn, finalLine, finalColumn;
    i = j = k = 0;

    while (control == 0)
    {
        i++;

        if (game[i][j] == '\0')
        {
            control = 1;
        }

        countLines++;
        countColumns++;
    }

    for (i = 0; i <= countLines; i++)
    {
        for (j = 0; j <= countColumns; j++)
        {
            if (k == count - 1)
            {
                finalLine = i;
                finalColumn = j;
                printf("%d %d, %d %d\n", startLine, startColumn, finalLine, finalColumn);
                k = 0;
            }

            if (key[k] == game[i][j] && k == 0)
            {
                startLine = i;
                startColumn = j;
            }

            if (key[k] == game[i][j])
            {
                k++;
            }
            else
            {
                k = 0;
            }

            i++;
        }

        k = 0;
    }

    for (j = 0; j < countColumns; j++)
    {
        for (i = 0; i < countLines; i++)
        {
             if (k == count - 1)
            {
                finalLine = i;
                finalColumn = j;
                printf("%d %d, %d %d\n", startLine, startColumn, finalLine, finalColumn);
                k = 0;
            }

            if (key[k] == game[i][j] && k == 0)
            {
                startLine = i;
                startColumn = j;
            }

            if (key[k] == game[i][j])
            {
                k++;
            }
            else
            {
                k = 0;
            }

            i++;
        }

        k = 0;
    }
}

// A distancia entre duas diagonais no sentido da esquerda para a direita é sempre constante
//O valor da soma do i e do j entre duas diagonais no sentido da direita para a esquerda é sempre constante

// Dúvidas

// A matriz deve ser perfeita? (i == j)?
// Eu posso perguntar o tamanho da matriz? (Quantidade de linhas e colunas)?
// A palavra bsucada em questão pode estar invertida? (vida - adiv)?