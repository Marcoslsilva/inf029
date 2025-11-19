#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
#include <limits.h>
#include "functions.h"

#define TRUE 1
#define FALSE 0
#define CURRENT_YEAR 2025

// Main Screen
void main_screen()
{

    int awnser = -1;
    while (awnser != 29)
    {
        printf("Digite o que você gostaria de fazer: \n");
        printf("\n");
        printf("------------------REGISTROS---------------------- \n");
        printf("1 - Registrar novo aluno \n"); //
        printf("2 - Registrar novo professor \n"); //
        printf("3 - Registrar nova disciplina \n"); //
        printf("4 - Registrar aluno em uma disciplina \n"); //
        printf("\n");
        printf("--------------------BUSCAS---------------------- \n");
        printf("Alunos: \n");
        printf("5 - Listar alunos \n");
        printf("6 - Listar alunos a partir do sexo\n");
        printf("7 - Listar alunos ordenados por nome\n"); //
        printf("8 - Listar alunos ordenados por data de nascimento\n"); // 
        printf("9 - Listar relatório de alunos\n");
        printf("Professores: \n");
        printf("10 - Listar professores \n");
        printf("11 - Listar professores a partir do sexo\n");
        printf("12 - Listar professores ordenados por nome\n"); //
        printf("13 - Listar professores ordenados por data de nascimento\n"); //
        printf("Listar relatório de professores \n");
        printf("Disciplinas: \n");
        printf("14 - Listar disciplinas \n");
        printf("15 - Listar disciplinas e seus respectivos alunos\n");
        printf("16 - Listar alunos matriculados em menos de 3 disciplinas\n"); //
        printf("17 - Listar disciplinas que extrapolam 40 vagas\n");
        printf("Listar relatório de disciplinas\n");
        printf("Geral: \n");
        printf("18 - Buscar aluno ou professor específico \n");
        printf("19 - Listar aniversariantes do mês \n");
        printf("-------------------MODIFICAÇÕES---------------------- \n");
        printf("20 - Atualizar dados de aluno \n");
        printf("21 - Atualizar dados de professor \n");
        printf("22 - Atualizar dados de disciplinas \n");
        printf("--------------------EXCLUSÕES---------------------- \n");
        printf("23 - Excluir aluno \n");
        printf("24 - Excluir professor \n");
        printf("25 - Excluir disciplina \n");
        printf("26 - Excluir aluno de uma disciplina \n");
        printf("27 - Sair \n");

        scanf("%d", &awnser);
        while (getchar() != '\n');

        switch (awnser)
        {
            int registration, day, month, year, code, semester, teacher_registration;
            char name[MAX_STR], sex;
            long long cpf;
        case 1:
            
            printf("Digite o nome do aluno (Apenas letras em ASCII. Não utilize acentos): \n");
            fgets(name, MAX_STR, stdin);
            name[strcspn(name, "\n")] = '\0';
            printf("Digite a Matrícula do aluno (A matrícula deve conter 6 díitos): \n");
            scanf("%d", &registration);
            printf("Digite o dia do nascimento do aluno: \n");
            scanf("%d", &day);
            printf("Digite o mês do aluno: \n");
            scanf("%d", &month);
            printf("Digite o ano do aluno: \n");
            scanf("%d", &year);
            printf("Digite o sexo do aluno: \n");
            scanf(" %c", &sex);
            printf("Digite o cpf do aluno: \n");
            scanf(" %lld", &cpf);

            new_student(student, &count_students, registration, name, sex, day, month, year, cpf);
            main_screen();
            break;
        case 2:

            printf("Digite o nome do  professor: \n");
            fgets(name, MAX_STR, stdin);
            name[strcspn(name, "\n")] = '\0';
            printf("Digite a Matrícula do professor: \n");
            scanf("%d", &registration);
            printf("Digite o dia do nascimento do professor: \n");
            scanf("%d", &day);
            printf("Digite o mês do professor: \n");
            scanf("%d", &month);
            printf("Digite o ano do professor: \n");
            scanf("%d", &year);
            printf("Digite o sexo do professor (M ou F): \n");
            scanf(" %c", &sex);
            printf("Digite o cpf do professor: \n");
            scanf(" %lld", &cpf);

            new_teacher(teacher, &count_teachers, registration, name, sex, day, month, year, cpf);
            Sleep(3);
            main_screen();
            break;
        case 3:

            printf("Digite o Código da disciplina: \n");
            scanf("%d", &code);
            printf("Digite a quantidade de semestres da disciplina: \n");
            scanf("%d", &semester);
            printf("Digite a matrícula do professor responsável pela disciplina: \n");
            scanf("%d", &teacher_registration);
            printf("Digite o nome da disciplina: \n");
            scanf("%s", name);
            new_discipline(discipline, teacher, &count_disciplines, &count_teachers, code, name, semester, teacher_registration);
            Sleep(3);

            main_screen();
            break;
        case 4:

            printf("Digite a matrícula do aluno \n");
            scanf("%d", &registration);
            printf("Digite o código da disciplina \n");
            scanf("%d", &code);
            insert_student(student_in_discipline, student, discipline, registration, code, &count_students_per_disciplines, &count_students, &count_disciplines);
            
            
            main_screen();
            break;
        case 5:
            /* code */
            break;
        case 6:
            /* code */
            break;
        case 7:
            printf("%d \n", count_students);
            alphabetic(student, &count_students);
            main_screen();
            break;
        case 8:
            birthday_order(student, &count_students);
            main_screen();
            break;
        case 9:

            break;
        case 10:
            /* code */
            break;
        case 11:
            /* code */
            break;
        case 12:
            alphabetic(teacher, &count_teachers);
            main_screen();
            break;
        case 13:
            birthday_order(teacher, &count_teachers);
            
            main_screen();
            break;
        case 14:

            break;
        case 15:
            /* code */
            break;
        case 16:
            students_in_three_disciplines(student_in_discipline, student, &count_students_per_disciplines, &count_students);
            main_screen();
            break;
        case 17:
            overcharge_disciplines(student_in_discipline, discipline, teacher, &count_students_per_disciplines, &count_teachers);
            main_screen();
            break;
        case 18:
            char str[MAX_STR];
            printf("Digite a palavra chave: \n");
            scanf("%s", str);
            str_research(teacher, student, str, &count_teachers, &count_students);
            main_screen();
            break;
        case 19:
            /* code */
            break;
        case 20:
            /* code */
            break;
        case 21:
            /* code */
            break;
        case 22:
            /* code */
            break;
        case 23:
            /* code */
            break;
        case 24:
            /* code */
            break;
        case 25:
            /* code */
            break;
        case 26:
            printf("Digite a matricula do aluno que se deseja a exclusão: \n");
            scanf("%d", &registration);
            printf("Digite o código da disciplina:: \n");
            scanf("%d", &code);
            delete_student_in_discipline(student_in_discipline, registration, code, &count_students_per_disciplines);
            main_screen();
            break;
        case 27:
            printf("Obrigado por utilizar o programa!");
            break;
        default:
            printf("Resposta inválida! Digite novamente");
            break;
        }
    }
}

// Crud

void new_student(People student[],
                 int *count,
                 int registration,
                 char name[],
                 char sex,
                 int day,
                 int month,
                 int year,
                 long long cpf)
{
    // validação

    if (*count >= (TAM_VETOR - 1))
    {
        printf("Não foi possível cadastrar o novo aluno devido a falta de armazenamento");
        return;
    }

    for (int i = 0; i < *count; i++)
    {
        if (registration == student[i].registration)
        {
            printf("Esse aluno já existe! Favor inserir outra matrícula.");
            return;
        }
    }

    if(registration > 999999 || registration < 100000)
    {
        printf("A matrícula deve conter 6 dígitos!");
        return;
    }

    int i = 0;

    while (name[i] != '\0')
    {
        if ((name[i] < 'a' || name[i] > 'z') && (name[i] < 'A' || name[i] > 'Z') && name[i] != ' ')
        {
            printf("Por favor, digite apenas letras ao informar o nome!");
            return;
        }

        if (name[i] >= 'a')
        {
            name[i] = name[i] - 'a' + 'A';
        }

        i++;
    }

    if (sex != 'M' && sex != 'm' && sex != 'F' && sex != 'f')
    {
        printf("Sexo inválido!");
        return;
    }

    if (day > 31 || day < 0)
    {
        printf("Dia inválido!");
        return;
    }

    if ((month == 1 || month == 4 || month == 6 || month == 9 || month == 11) && day > 30 || (month == 2 && day > 28))
    {
        printf("Dia inválido");
        return;
    }

    if (year > CURRENT_YEAR)
    {
        printf("Ano inválido");
        return;
    }

    if (cpf > 99999999999 || cpf < 1000000000)
    {
        printf("CPF inválido");
        return;
    }

    // inserção

    student[*count].registration = registration;

    strcpy(student[*count].name, name);

    student[*count].sex = sex;
    student[*count].day = day;
    student[*count].month = month;
    student[*count].year = year;
    student[*count].cpf = cpf;


    printf("Aluno registrado com sucesso!");
    (*count)++;
}
void new_teacher(People teacher[],
                 int *count,
                 int registration,
                 char name[MAX_STR],
                 char sex,
                 int day,
                 int month,
                 int year,
                 long long cpf)
{

    // validação

    if (*count >= 1023)
    {
        printf("Não foi possível cadastrar o novo professor devido a falta de armazenamento");
        return;
    }

    for (int i = 0; i < *count; i++)
    {
        if (registration == teacher[i].registration)
        {
            printf("Esse professor já existe! Favor inserir outra matrícula.");
            return;
        }
    }

    int i = 0;

     while (name[i] != '\0')
    {
        if ((name[i] < 'a' || name[i] > 'z') && (name[i] < 'A' || name[i] > 'Z') && name[i] != ' ')
        {
            printf("Por favor, digite apenas letras ao informar o nome!");
            return;
        }

        if (name[i] >= 'a')
        {
            name[i] = name[i] - 'a' + 'A';
        }

        i++;
    }

    if (sex != 'M' && sex != 'm' && sex != 'F' && sex != 'f')
    {
        printf("Sexo inválido!");
        return;
    }

    if (day > 31 || day < 0)
    {
        printf("Dia inválido!");
        return;
    }

    if ((month == 1 || month == 4 || month == 6 || month == 9 || month == 11 && day > 30 )|| (month == 2 && day > 28))
    {
        printf("Data de nascimento inválida");
        return;
    }

    if (year > CURRENT_YEAR)
    {
        printf("Ano inválido");
        return;
    }

    if (cpf > 99999999999 && cpf < 100000000000)
    {
        printf("CPF inválido");
        return;
    }

    // inserção

    teacher[*count].registration = registration;
    strcpy(teacher[*count].name, name);

    teacher[*count].sex = sex;
    teacher[*count].day = day;
    teacher[*count].month = month;
    teacher[*count].year = year;
    teacher[*count].cpf = cpf;
    (*count)++;

    printf("Professor registrado com sucesso!");
}

void new_discipline(Disciplines discipline[], People teacher[], int *count_disciplines, int *count_teachers, int code, char name[], int semester, int teacher_registration)
{
    // validação

    int control = FALSE;

    if (*count_disciplines >= 1023)
    {
        printf("Não foi possível adicionar a disciplina devido a falta de armazenamento");
        return;
    }

    for (int i = 0; i < *count_disciplines; i++)
    {
        if (code == discipline[i].code)
        {
            printf("Essa disciplina já existe! Favor inserir outro código.");
            return;
        }
    }

    int i = 0;

    while (name[i] != '\0')
    {
        if ((name[i] > 'z' || name[i] < 'a') && (name[i] > 'Z' || name[i] < 'A'))
        {
            printf("Por favor, digite apenas letras ao informar o nome da disciplina!");
            return;
        }

        if (name[i] > 'a')
        {
            name[i] = name[i] - 'a' + 'A';
        }

        i++;
    }

    for (int i = 0; i < *count_teachers; i++)
    {
        if (teacher[i].registration == teacher_registration)
        {
            control = TRUE;
        }
    }

    if (control == FALSE)
    {
        printf("Professor não encontrado! Por favor, corrija a matrícula informada");
        return;
    }

    i = 0;

    discipline[*count_disciplines].code = code;

    strcpy(discipline[*count_disciplines].name, name);

    discipline[*count_disciplines].semester = semester;

    discipline[*count_disciplines].teacher_registration = teacher_registration;

    (*count_disciplines)++;

    printf("Disciplina registrada com sucesso");
}

void alphabetic(People a[], int *count)
{
    int i, j;
    char temp[MAX_STR];
 

    for (i = 0; i < *count; i++)
    {
        for (j = i + 1; j < *count; j++)
        {
            if (strcmp(a[i].name, a[j].name) > 0)
            {
                strcpy(temp,a[j].name);
                strcpy(a[j].name,a[i].name);
                strcpy(a[i].name,temp);
            }
        }
    }

    for (int i = 0; i < *count; i++)
    {
        printf("%s \n", a[i].name);
    }
}

void insert_student(Student_per_discipline s_and_d[], People s[], Disciplines d[], int registration, int code, int *count, int *count_students, int *count_disciplines)
{
    // validação
    int control_d = FALSE;
    int control_s = FALSE;

    for (int i = 0; i < *count_students; i++)
    {
        if (registration == s[i].registration)
        {
            control_s = TRUE;
            break;
        }
    }

    for (int i = 0; i < *count_disciplines; i++)
    {
        if (code == d[i].code)
        {
            control_d = TRUE;
            break;
        }
    }

    if (control_d == FALSE || control_s == FALSE)
    {
        printf("Aluno ou disciplina inexistente!");
        return;
    }

    // processamento

    s_and_d[*count].code = code;
    s_and_d[*count].registration = registration;
    (*count)++;

    printf("Aluno foi registrado na disciplina com sucesso!");
}

void delete_student_in_discipline(Student_per_discipline a[], int registration, int code, int *count)
{
    int control = FALSE;
    int aux;

    for (int i = 0; i < *count; i++)
    {
        if (a[i].code == code && a[i].registration == registration)
        {

            a[*count + 1].code = a[i].code;
            a[*count + 1].registration = a[i].registration;

            aux = *count - i;

            while (aux != 0)
            {
                int j = 0;
                a[i + j].code = a[i + j + 1].code;
                a[i + j].registration = a[i + j + 1].registration;

                j++;
                aux--;
            }

            control = TRUE;
        }
    }

    if (control == FALSE)
    {
        printf("O aluno não está matriculado nessa disciplina, ou ela não existe!");
    }
    else
    {
        printf("Aluno excluído da disciplina com sucesso!");
        (*count)--;
    }
}


void students_in_three_disciplines(Student_per_discipline a[], People s[], int *count_s_p_d, int *count_s)
{

    int disciplines = 0;

    for (int i = 0; i < *count_s_p_d; i++)
    {
        for (int j = 0; j <= *count_s_p_d; j++)
        {

            if (a[i].registration == a[j].registration)
            {
                disciplines++;
            }
        }

        if (disciplines < 3)
        {
            for (int k = 0; k < *count_s; k++)
            {
                if (s[k].registration == a[i].registration)
                {
                    printf("%s, Matrícula: %d, matriculado em %d disciplinas \n", s[k].name, a[i].registration, disciplines);
                }
            }
        }

        disciplines = 0;
    }
}

void overcharge_disciplines(Student_per_discipline s_p_d[], Disciplines d[], People t[], int *count_s_p_d, int *count_t)
{
    int students = 0;

    for (int i = 0; i < *count_s_p_d; i++)
    {
        for (int j = 0; j <= *count_s_p_d; j++)
        {

            if (s_p_d[i].code == s_p_d[j].code)
            {
                students++;
            }
        }

        if (students > 40)
        {
            for (int k = 0; k < *count_t; k++)
            {
                if (d[k].code == d[i].code)
                {
                    int teacher = d[k].teacher_registration;

                    for (int l = 0; l < *count_t; l++)
                    {
                        if (t[l].registration == teacher)
                        {
                            printf("%s, Matrícula: %d, cuja disciplina (%s, código: %d) possui %d vagas \n", t[l].name, t[l].registration, d[k].name, d[k].code, students);
                        }
                    }
                }
            }
        }

        students = 0;
    }
}

void str_research(People t[], People s[], char str[], int *count_t, int *count_s)
{
    // validação
    size_t size = strlen(str);

    if(size > INT_MAX)
    {
        printf("Não foi possível executar a função devido à quantidade excessiva de letras.");
        return;
    }
    
    int checker = (int) size;


    printf("%d \n", checker);

    if (checker < 3)
    {
        printf("É necessário pelo menos 3 palavras para realizar a busca!");
        return;
    }

    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] < 'A' || str[i] > 'Z')
        {
            str[i] = str[i] - 'a' + 'A';
        }
    }

    // função

    int same_char = 0;

    printf("Professores: \n");

    for (int i = 0; i < *count_t; i++)
    {
        int j = 0;
        int k = 0;

        while (t[i].name[j] != '\0' && str[k] != '\0')
        {
            if (t[i].name[j] == str[k])
            {
                k++;
                same_char++;
            }else {
                k = 0;
                same_char = 0;
            }

            j++;
        }

        if (same_char == checker)
        {
            printf("%s \n", t[i].name);
        }

        same_char = 0;
    }

    printf(" \n Alunos: \n");

    for (int i = 0; i < *count_s; i++)
    {
        int j = 0;
        int k = 0;

        while (s[i].name[j] != '\0' && str[k] != '\0')
        {
            if (s[i].name[j] == str[k])
            {
                k++;
                same_char++;
            } else {
                k = 0;
                same_char = 0;
            }

            j++;
        }

        if (same_char == checker)
        {
            printf("%s \n", s[i].name);
        }

        same_char = 0;
    }
}

void birthday_order(People a[], int *count)
{
    for (int i = 0; i < *count - 1; i++) {
        for (int j = i + 1; j < *count; j++) {
            if (a[i].year > a[j].year ||
                (a[i].year == a[j].year && a[i].month > a[j].month) ||
                (a[i].year == a[j].year && a[i].month == a[j].month && a[i].day > a[j].day)) 
            {
                People temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    for (int i = 0; i < *count; i++) {
        printf("%s, CPF: %lld, data de nascimento: %02d/%02d/%d\n",  a[i].name, a[i].cpf, a[i].day, a[i].month, a[i].year);
    }
}