#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#define MAX_STR 1024
#define TAM_VETOR 1024

// Variáveis globais

typedef struct People
{
    int registration; 
    char name[MAX_STR];
    char sex;
    int day;
    int month;
    int year;
    long long cpf;

}People;



typedef struct d{
    int code;
    char name[MAX_STR];
    int semester;
    int teacher_registration; 
} Disciplines;

typedef struct disciplines_and_students
{
    int registration;
    int code;
}Student_per_discipline;

People student[TAM_VETOR];
People teacher[TAM_VETOR];
Disciplines discipline[TAM_VETOR];  
Student_per_discipline student_in_discipline[TAM_VETOR] ;

 int count_students = 0;    
 int count_teachers = 0;
 int count_disciplines = 0;
 int count_students_per_disciplines = 0;


void main_screen();
void new_student(People student[], 
                int *count, 
                int registration, 
                char name[], 
                char sex,
                int day,
                int month,
                int year,
                long long cpf
);

void new_teacher(People teacher[], 
                int *count, 
                int registration, 
                char name[MAX_STR], 
                char sex,
                int day,
                int month,
                int year,
                long long cpf
);

void new_discipline(Disciplines discipline[], People teacher[], int *count_disciplines, int *count_teachers, int code, char name[], int semester, int teacher_registration);

void alphabetic(People a[], int *count);

void insert_student(Student_per_discipline s_and_d[], People s[], Disciplines d[], int registration, int code, int *count, int *count_students, int *count_disciplines);

void delete_student_in_discipline(Student_per_discipline a[], int registration, int code, int *count);

void students_in_three_disciplines(Student_per_discipline a[], People s[], int *count_s_p_d, int *count_s);

void overcharge_disciplines(Student_per_discipline s_p_d[], Disciplines d[], People t[], int *count_s_p_d, int *count_t);

void str_research(People t[], People s[], char str[], int *count_t, int *count_s);

void birthday_order(People a[], int *count);

#endif