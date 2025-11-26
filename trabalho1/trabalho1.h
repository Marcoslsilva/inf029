// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Marcos André Leite Silva
//  email: marcosandre1309@gmail.com
//  Matrícula: 20251160024
//  Semestre: 2025.2

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021

// #################################################
#ifndef TRABALHO1_H
#define TRABALHO1_H

typedef struct Response
  {
    int exit[3];
  } Response;

  Response extDate(char date[])
  {

    char day_char[3], month_char[3], year_char[5];
    int day, month, year;
    int i = 0;
    Response response;

    int control = 0;
    int j = 0;

    while (date[i] != '\0')
    {

      if (date[i] == '/')
      {
        if (control == 0)
        {
          day_char[j] = '\0';
        }
        if (control == 1)
        {
          month_char[j] = '\0';
        }

        control++;
        j = 0;
      }

      if (control == 0)
      {
        day_char[j] = date[i];
        j++;
      }
      if (control == 1 && date[i] != '/')
      {
        month_char[j] = date[i];
        j++;
      }
      if (control == 2 && date[i] != '/')
      {
        year_char[j] = date[i];
        j++;
      }

      i++;
    }

    day = atoi(day_char);
    month = atoi(month_char);
    year = atoi(year_char);

    response.exit[0] = day;
    response.exit[1] = month;
    response.exit[2] = year;

    return response;
  }


bool isLeapYear(int year)
{

    if (year % 4 == 0 || year % 400 == 0)
    {
        return true;
    }

    return false;
}

typedef struct DQ
{
    int iDia; 
    int iMes;
    int iAno;
    int valido; // 0 se inválido, e 1 se válido 

} DataQuebrada;


//para a q2, a função que conta a distância entre as datas, se válidas

int daysInMonth(int month, int year)
{
    if (month == 2)
        return isLeapYear(year) ? 29 : 28;

    if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;

    return 31;
}


typedef struct Qtd
{
    int qtdDias;
    int qtdMeses;
    int qtdAnos;
    int retorno;

} DiasMesesAnos;

//para a q3

void tratmentString(char str[])
{
    int i = 0;

    while (str[i] != '\0')
    {
        if (str[i] >= 'a' && str[i] <= "z")
        {
            str[i] = str[i] - 'a' + 'A';
        }

        i++;
    }
}

// questao 4

//questao 5

int reversingNumber(int exp, int overExp, int leftover)
{

    int n = 0;

    if (overExp < 1)
    {
        return n;
    }

    n = leftover / overExp;
    leftover %= overExp;
    n *= exp / overExp;
    overExp /= 10;

    n += reversingNumber(exp, overExp, leftover);
    // printf("%d \n", n);

    return n;
}

//questao 6

int pot10(int n) {
    int r = 1;
    while (n--) 
      r *= 10;
  
    return r;
}

int countDigits(int n) {
    int d = 0;
    if (n == 0) 
        return 1;
        
        
    while (n > 0) {
        d++;
        n /= 10;
    }
    return d;
}

//questao 7

int isWordHiddenHere(char game[MAX_TAM][MAX_TAM], char key[], int line, int column, int tam)
{
    // percorrendo na linha
    int k = 1;
    int final, start;

    
    for (int j = column + 1; j < MAX_TAM && k < tam; j++) {
        if (game[line][j] == key[k])
            k++;
        else
            break;
        
    }
    if (k == tam) return 1;

    //percorrendo a coluna

    k = 1;
    for (int i = line + 1; i < MAX_TAM && k < tam; i++) {
        if (game[i][column] == key[k])
            k++;
        else
            break;
    }
    if (k == tam) return 1;

  //percorrendo a coluna invertida

    k = 1;
    for (int i = line - 1; i < MAX_TAM && k > 0; i--) {
        if (game[i][column] == key[k])
            k++;
        else
            break;
    }
    if (k == tam) return 1;

    //achando na diagonal
    k = 1;
    for (int i = line + 1, j = column + 1; i < MAX_TAM && j < MAX_TAM && k < tam; i++, j++) {
        if (game[i][j] == key[k])
            k++;
        else
            break;
    }
    if (k == tam) return 1;
    //diagonal invertida ou secundária

    k = 1;
    for (int i = line + 1, j = column - 1; i < MAX_TAM && j >= 0 && k < tam; i++, j--) {
        if (game[i][j] == key[k])
            k++;
        else
            break;
    }
    if (k == tam) return 1;

    return 0;
}
int somar(int x, int y); //função utilizada para testes
int fatorial(int x); //função utilizada para testes
int q1(char data[]);
DiasMesesAnos q2(char datainicial[], char datafinal[]);
int q3(char *texto, char c, int isCaseSensitive);
int q4(char *strTexto, char *strBusca, int posicoes[30]);
int q5(int num);
int q6(int numerobase, int numerobusca);
int q7(char matriz[8][10], char palavra[5]);
DataQuebrada quebraData(char data[]);

#endif //MAIN_H






