#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "trabalho2.h"

// M- garantindo que todas as posicoes sao 0
int *vetorPrincipal[TAM] = {0};

// int * vetorDeAuxiliares[TAM];

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho)
{
    int retorno = 0;
    int *p, *array = malloc((tamanho + 1) * sizeof(int));
    p = &array;
    // auxiliaryStructure a;

    // a.data = malloc(tamanho * sizeof(int));
    // a.limit = tamanho;

    // M- validações:

    // a posicao pode já existir estrutura auxiliar

    if (vetorPrincipal[posicao])
    {
        retorno = JA_TEM_ESTRUTURA_AUXILIAR;
        // se posição é um valor válido {entre 1 e 10}
        if (posicao > 10 || posicao < 1)
        {
            retorno = POSICAO_INVALIDA;
        }
        // o tamanho ser muito grande

        if (array == NULL)
        {
            retorno = SEM_ESPACO_DE_MEMORIA;
        }

        // o tamanho nao pode ser menor que 1

        if (tamanho < 1)
        {
            retorno = TAMANHO_INVALIDO;
        }
    }
    else
    {
        // deu tudo certo, crie

        array[0] = tamanho;

        vetorPrincipal[posicao] = p;

        retorno = SUCESSO;
    }

    return retorno;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor)
{
    int retorno = 0;
    int existeEstruturaAuxiliar = 0;
    int temEspaco = 0;
    int posicao_invalida = 0;

    int qntdElementos = getQuantidadeElementosEstruturaAuxiliar(posicao);
    int *p = vetorPrincipal[posicao];

    existeEstruturaAuxiliar = vetorPrincipal[posicao] ? 1 : 0;
    temEspaco = qntdElementos - *vetorPrincipal[posicao] == 0 ? 0 : 1;
    posicao_invalida = posicao > 10 || posicao < 1 ? 1 : posicao_invalida;

    if (posicao_invalida)
        retorno = POSICAO_INVALIDA;
    else
    {
        // testar se existe a estrutura auxiliar
        if (existeEstruturaAuxiliar)
        {
            if (temEspaco)
            {
                // insere

                p[qntdElementos + 1] = valor;

                retorno = SUCESSO;
            }
            else
            {
                retorno = SEM_ESPACO;
            }
        }
        else
        {
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    }

    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{
    int retorno = SUCESSO;

    int qntdElementos = getQuantidadeElementosEstruturaAuxiliar(posicao);

    if (qntdElementos < 1)
    {
        retorno = ESTRUTURA_AUXILIAR_VAZIA;
    }

    if (vetorPrincipal[posicao] == 0)
    {
        retorno = SEM_ESTRUTURA_AUXILIAR;
    }

    if (posicao > 10 || posicao < 1)
    {
        retorno = POSICAO_INVALIDA;
    }

    int *p = vetorPrincipal[posicao];

    free(p[qntdElementos]);

    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
    int retorno = SUCESSO;
    int control = 0;
    int *p = vetorPrincipal[posicao];
    int isNumberFound = 0;

    if (vetorPrincipal == 0)
    {
        retorno = SEM_ESTRUTURA_AUXILIAR;
    }

    for (size_t i = 1; i < p[0]; i++)
    {
        if (control == 1)
        {
            p[i - 1] = p[i];
            free(p[i]);
        }

        if (p[i] == valor && isNumberFound == 0)
        {
            free(p[i]);
            control = 1;
            isNumberFound = 1;
        }
    }

    if (control == 0)
    {
        retorno = NUMERO_INEXISTENTE;
    }

    if (ehPosicaoValida(posicao))
    {
        retorno = POSICAO_INVALIDA;
    }

    return retorno;
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao)
{
    int retorno = 0;
    if (posicao < 1 || posicao > 10)
    {
        retorno = POSICAO_INVALIDA;
    }
    else
        retorno = SUCESSO;

    return retorno;
}

// M- Uma função que será utilizada para comparar e ordenar os vetores
int compare_ints(const void *a, const void *b)
{
    int x = *(const int *)a;
    int y = *(const int *)b;
    return x - y;
}

/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{

    int retorno = 0;
    int *p = vetorPrincipal[posicao];
    int qntdElementos = getQuantidadeElementosEstruturaAuxiliar(posicao);

    if (vetorPrincipal[posicao] == 0)
    {
        retorno = SEM_ESTRUTURA_AUXILIAR;
    }

    if (ehPosicaoValida(posicao))
    {
        retorno = POSICAO_INVALIDA;
    }

    for (size_t i = 1; i < p[0]; i++)
    {
        vetorAux[i - 1] = p[i];
    }

    return retorno;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{

    int retorno = 0;
    int *p = vetorPrincipal[posicao];
    int qntdElementos = getQuantidadeElementosEstruturaAuxiliar(posicao);

    if (vetorPrincipal[posicao] == 0)
    {
        retorno = SEM_ESTRUTURA_AUXILIAR;
    }

    if (ehPosicaoValida(posicao))
    {
        retorno = POSICAO_INVALIDA;
    }

    for (size_t i = 1; i < p[0]; i++)
    {
        vetorAux[i - 1] = p[i];
    }

    qsort(vetorAux, qntdElementos, sizeof(int), compare_ints);

    return retorno;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{

    int retorno = 0;
    int controll = 0, k = 0;
    

    for (size_t i = 0; i < 10; i++)
    {
        int *p = vetorPrincipal[i];

        if (p[0] == 0)
        {
            controll++;
        }
        else
        {

            for (size_t j = 1; j <= p[0]; j++)
            {
                if (p[j] != 0)
                    vetorAux[k] = p[j];
                    k++;
            }
        }
    }

    if (controll == 10)
    {
        retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    }else{
        
        qsort(vetorAux, k - 1, sizeof(int), compare_ints);

    }


    return retorno;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int retorno = 0;
    int controll = 0, k = 0;

    for (size_t i = 0; i < 10; i++)
    {
        int *p = vetorPrincipal[i];

        if (p[0] == 0)
        {
            controll++;
        }
        else
        {

            for (size_t j = 1; j < p[0]; j++)
            {
                if (p[j] != 0)
                    vetorAux[k] = p[j];
            }
        }

        if (controll == 10)
        {
            retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
        }
    }

    return retorno;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{
    int retorno = 0;

    int *p = vetorPrincipal[posicao];
    int soma = novoTamanho + p[0];

    if (vetorPrincipal[posicao] == 0)
    {
        retorno = SEM_ESTRUTURA_AUXILIAR;
    }

    if (ehPosicaoValida(posicao))
    {
        retorno = SUCESSO;
    }
    else
    {
        retorno = POSICAO_INVALIDA;
    }

    if (soma >= 1)
    {
        realloc(p, soma * sizeof(int));
        if (p == NULL)
        {
            retorno = SEM_ESPACO_DE_MEMORIA;
        }
    }
    else
    {
        retorno = NOVO_TAMANHO_INVALIDO;
    }

    return retorno;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{
    int retorno = 0;

    int *address = vetorPrincipal[posicao];

    while (*address != 0)
    {
        retorno++;
        address++;
    }

    return retorno;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote()
{

    return NULL;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa

*/

void inicializar()
{
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar()
{
    for (size_t i = 0; i < 10; i++)
    {
        int *p = vetorPrincipal[i];

        if(p[0] != 0)
        {
            for (size_t j = 1; j <= p[0]; j++)
            {
                free(p[j]);
            }
            
            free(p[0]);
        }
    }
    
}