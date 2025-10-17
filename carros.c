#include <stdio.h>
#include <time.h>
#include <string.h>

#define TAM_STR 1024
#define TAM_INT 512
#define OPTIONS 5

// struct
typedef struct c
{

    int id;
    char color[TAM_STR];
    char plate[8];
    int chassi;
    int year;
} Cars;

// functions

int main_screen(Cars amountCars[], int cont)
{

    int resposta = -1;
    int id, param;

    while (resposta == -1)
    {

        printf("Digite o que você gostaria de fazer: \n");
        printf("0 - Sair \n");
        printf("1 - Inserir um novo carro \n");
        printf("2 - Listar todos os carros \n");
        printf("3 - Atualizar um carro \n");
        printf("4 - Excluir um carro \n");
        scanf("%d", &resposta);

        switch (resposta)
        {

        case 0:
            printf("Obrigado por usar o programa! ");
            break;

        case 1:
            newCar(amountCars, cont);
            cont++;
            printf("Carro registrado com sucesso!");
            sleep(2);
            system("cls");
            main_screen(amountCars, cont);
            break;

        case 2:
            findCars(amountCars, cont);
            main_screen(amountCars, cont);
            break;

        case 3:

            printf("Digite o id do automóvel que você deseja atualizar: ");
            scanf("%d", &id);

            printf("Digite qual é o parâmetro que você quer mudar: \n");
            printf("1 - Cor \n");
            printf("2 - Placa \n");
            printf("3 - Chassi \n");
            printf("3 - Ano \n");
            scanf("%d", &param);

            UpdateCars(amountCars, id, param);

            system("cls");
            main_screen(amountCars, cont);
            break;

        case 4:
            findCars(amountCars, cont);
            printf("\n");
            printf("Digite o id do automóvel que você deseja excluir: ");
            scanf("%d", &id);

            DeleteCars(amountCars, id, cont);
            main_screen(amountCars, cont);
            break;

        default:
            printf("Resposta inválida");
            resposta = -1;
            break;
        }
    }

    return resposta;
}

// Crud

void newCar(Cars amountCars[], int cont)
{

    int i = 0;

    char color[TAM_STR];
    char plate[TAM_STR];
    int chassi, year;

    printf("Digite a cor do carro: \n");
    scanf("%s", color);
    fflush(stdin);

    printf("Digite sua placa: \n");
    scanf("%s", plate);
    fflush(stdin);

    printf("Digite seu chassi: \n");
    scanf("%d", &chassi);
    fflush(stdin);

    printf("Digite o ano do veículo: \n");
    scanf("%d", &year);

    while (color[i] != '\0')
    {
        amountCars[cont].color[i] = color[i];
        i++;
    }

    while (plate[i] != '\0')
    {
        amountCars[cont].plate[i] = plate[i];
        i++;
    }

    amountCars[cont].id = cont;
    amountCars[cont].chassi = chassi;
    amountCars[cont].year = year;
}

// cRud

void findCars(Cars amountCars[], int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("-------------------------------------- \n");
        printf("%d \n", amountCars[i].id);
        printf("%s \n", amountCars[i].color);
        printf("%s \n", amountCars[i].plate);
        printf("%d \n", amountCars[i].chassi);
        printf("%d \n", amountCars[i].year);
        printf("-------------------------------------- \n");
    }
}

// crUd

void UpdateCars(Cars amountCars[], int id, int param)
{

    char newColor[TAM_STR];
    int i = 0;
    char newPlate[TAM_STR];
    int newChassi;
    int newYear;

    switch (param)
    {
    case 1:

        printf("Digite a nova cor desse carro: ");
        scanf("%s", newColor);

        while (newColor[i] != '\0')
        {
            amountCars[id].color[i] = newColor[i];
            i++;
        }

        printf("Registro modificado com sucesso! ");
        sleep(2);
        break;

    case 2:
        
         i = 0;

        printf("Digite a nova placa desse carro: ");
        scanf("%s", newPlate);

        while (newPlate[i] != '\0')
        {
            amountCars[id].plate[i] = newPlate[i];
            i++;
        }

        printf("Registro modificado com sucesso! ");
        sleep(2);
        break;

    case 3:
        
        printf("Digite o novo chassi desse carro: ");
        scanf("%d", &newChassi);

        amountCars[id].chassi = newChassi;
        printf("Registro modificado com sucesso! ");
        sleep(2);
        break;

    case 4:
        
        printf("Digite o novo ano desse carro: ");
        scanf("%d", &newYear);

        amountCars[id].year = newYear;
        printf("Registro modificado com sucesso! ");
        sleep(2);
        break;

    default:
        printf("Opção inválida!");
        break;
    }
}

// cruD

void DeleteCars(Cars amountCars[], int id, int cont)
{

    amountCars[cont + 1] = amountCars[id];
    cont--;
}

int main()
{
    int cont = 0;
    Cars amountCars[TAM_INT];

    main_screen(amountCars, cont);

    return 0;
}