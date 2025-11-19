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


// Para a q1, uma struct que retorna a data quebrada, e a função que quebra as datas
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

int * count_dates(char dateOne[11], char dateTwo[11])
{

    int current_day, current_month, current_year;
    int count_day = 0, count_month = 0, count_year = 0;
    int final_day, final_month, final_year;
    int * response;

    response = malloc(3 * sizeof(int)); // "Array" que será a saída, resposta, retorno da função

    if (isDateValid(dateOne) == 0 || isDateValid(dateTwo) == 0)
    {
        return 0;
    }
    
    Response rTwo = extDate(dateTwo);
    final_day = rTwo.exit[0];
    final_month = rTwo.exit[1];
    final_year = rTwo.exit[2];

    Response rOne = extDate(dateOne);
    current_day = rOne.exit[0];
    current_month = rOne.exit[1];
    current_year = rOne.exit[2];

    if((current_year > final_year) || 
        (current_year < final_year && current_month > final_month) || 
        (current_year < final_year && current_month > final_month && current_day > final_day))
    {
        return 0;
    }

    while (!(current_day == final_day && current_month == final_month && current_year == final_year))
    {
        
        current_day++;

        if (current_day > daysInMonth(current_month, current_year))
        {
            current_day = 1;
            current_month++;

            if (current_month > 12)
            {
                current_month = 1;
                current_year++;
            }
        }

        count_day++;
        if (count_day > daysInMonth(count_month == 0 ? current_month : count_month,
                                     count_year == 0 ? current_year : count_year))
        {
            count_day = 1;
            count_month++;

            if (count_month >= 12)
            {
                count_month = 1;
                count_year++;
            }
        }
    }

    response[0] = count_day;
    response[1] = count_month;
    response[2] = count_year;

    return response;
}
typedef struct Qtd
{
    int qtdDias;
    int qtdMeses;
    int qtdAnos;
    int retorno;

} DiasMesesAnos;

//para a q3

int howMuchTimes(char str[], char key, int count){
    
    int count_times = 0;

    for (int i = 0; i < count; i++)
    {
        if (key == str[i])
        {
            count_times++;
        }
    }

    return count_times;
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



