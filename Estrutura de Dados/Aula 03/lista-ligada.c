#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int qtd;
    struct registro *inicio;
} lista;

typedef struct registro
{
    int valor;
    struct registro *prox;
} registro;

lista *aloca_lista();
registro *aloca_registro();
void incluir_no_final(lista *l, int x);
void mostrar_lista(lista *l);
void mostrar_pares(lista *l);
void menu(lista *l);
int remover(lista *l, int x);

int main()
{
    lista **listas;

    int n = 30;
    int i;

    listas =  (lista**)malloc(sizeof(lista*) * n);

    for(i=0;i<n;i++)
    {
        listas[i] = aloca_lista();
    }


    menu(listas[0]);
    printf("\n");
    return 0;
}

lista *aloca_lista()
{
    lista *novo;
    novo = (lista *)malloc(sizeof(lista));
    novo->qtd = 0;
    novo->inicio = NULL;
    return novo;
}

registro *aloca_registro()
{
    registro *novo;
    novo = (registro *)malloc(sizeof(registro));
    novo->valor = 0;
    novo->prox = NULL;
    return novo;
}

void incluir_no_final(lista *l, int x)
{
    registro *novo, *aux;
    novo = aloca_registro();
    novo->valor = x;

    if (l->inicio == NULL)
    {
        l->inicio = novo;
    }
    else
    {
        aux = l->inicio;
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = novo;
    }

    l->qtd++;
}

void mostrar_lista(lista *l)
{
    registro *aux;

    if (l->inicio == NULL)
    {
        printf("\n lista vazia");
    }
    else
    {
        aux = l->inicio;

        while (aux != NULL)
        {
            printf("\n Valor: %d", aux->valor);
            aux = aux->prox;
        }
    }
}

void mostrar_pares(lista *l)
{
    if (l->inicio == NULL)
    {
        printf("\n Lista vazia");
    }
    else
    {
        registro *aux;
        aux = l->inicio;

        while (aux != NULL)
        {
            if (aux->valor % 2 == 0)
                printf("\n%d", aux->valor);
            aux = aux->prox;
        }
    }
}

void menu(lista *l)
{
    int opcao, numero;

    do
    {
        printf("\n 1 - Inserir na lista");
        printf("\n 2 - Mostrar lista");
        printf("\n 3 - Mostrar pares da lista");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\n Digite o numero que deseja incluir na lista: ");
            scanf("%d", &numero);
            incluir_no_final(l, numero);
            break;
        case 2:
            mostrar_lista(l);
            break;
        case 3:
            mostrar_pares(l);
            break;
        case 4:
            printf("\n Digite o numero que deseja remover na lista: ");
            scanf("%d", &numero);
            if(remover(l, numero))
            {
                printf("\n numero removido com sucesso");
            }
            else
            {
                printf("\n Lista vazia ou numero nao esta na lista");
            }

        case 5:
            printf("\n Saindo do programa");
            break;
        default:
            printf("\n opcao invalida");
            break;
        }
    } while (opcao != 5);
}

int remover(lista *l, int x)
{
    if (l->inicio == NULL)
    {
        return 0;
    }

    registro *aux = NULL, *ant = NULL;

    aux = l->inicio;
    while (aux != NULL)
    {
        if (aux->valor == x)
        {
            if (ant == NULL)
            {
                l->inicio = aux->prox;
            }
            else
            {
                ant->prox = aux->prox;
            }
            l->qtd--;
            free(aux);
            return 1;
        }
        ant = aux;
        aux = aux->prox;
    }

    return 0;
}