//1) utilizando como base a solucao_lista2_exercicio3.c 
//construa as seguintes funções para uma lista duplamente ligada:
//    1 - Remover Primos
//    2 - Remover numeros iguais
//    3 - Buscar por numero
//    4 - Comparar 2 listas ( falar os numeros iguais e quais sao diferentes)
//    5 - incluir de forma ordenada

#include <stdio.h>
#include <stdlib.h>

typedef struct Lista
{
    int qtd;
    struct registro *inicio;
    struct registro *fim;
} Lista;

typedef struct registro
{
    int valor;
    struct registro *prox;
    struct registro *ant;
} registro;

Lista *aloca_Lista();
registro *aloca_registro();
void mostrar(Lista *lista, int inverso);
void incluir_no_inicio(Lista *lista, int x);
void incluir_no_final(Lista *lista, int x);
void menu(Lista *lista);


int main()
{
    Lista *lista1;
    lista1 = aloca_Lista();
    menu(lista1);
    printf("\n");
    return 0;
}

Lista *aloca_Lista()
{
    Lista *novo;
    novo = (Lista *)calloc(1, sizeof(Lista));
    return novo;
}


registro *aloca_registro()
{
    registro *novo;
    novo = (registro *)calloc(1, sizeof(registro));
    return novo;
}

void incluir_no_inicio(Lista *lista, int x)
{
    if (lista == NULL)
    {
        printf("\n Lista nao alocada");
        return;
    }

    registro *novo;
    novo = aloca_registro();
    novo->valor = x;

    if (lista->inicio == NULL && lista->fim == NULL)
    {
        lista->inicio = novo;
        lista->fim = novo;
    }
    else
    {
        novo->prox = lista->inicio;
        lista->inicio->ant = novo;
        lista->inicio = novo;
    }
    lista->qtd++;
}

void incluir_no_final(Lista *lista, int x)
{
    if (lista == NULL)
    {
        printf("\n Lista nao alocada");
        return;
    }

    registro *novo;
    novo = aloca_registro();
    novo->valor = x;

    if (lista->inicio == NULL && lista->fim == NULL)
    {
        lista->inicio = novo;
        lista->fim = novo;
    }
    else
    {
        lista->fim->prox = novo;
        novo->ant = lista->fim;
        lista->fim = novo;
    }
    lista->qtd++;
}

void mostrar(Lista *lista, int inverso)
{
    registro *aux;
    if (lista->inicio == NULL || lista->fim == NULL)
    {
        printf("\n Lista vazia");
        return;
    }

    if (!inverso)
    {
        aux = lista->inicio;
        while (aux != NULL)
        {
            printf("\n %d", aux->valor);
            aux = aux->prox;
        }
    }
    else
    {
        aux = lista->fim;
        while (aux != NULL)
        {
            printf("\n %d", aux->valor);
            aux = aux->ant;
        }
    }
}

int verifica_primo(int valor){

    printf("\nEntrei\n");
    int resultado = 0;

    for (int i = 2 ; i <= valor / 2 ; i++){
        if (valor % i == 0){
            resultado++;
            break;
        }
    }
    if (resultado > 0){
    
        return 0;
    
    }else{
        return 1;
    }

}
int remover_todos(Lista *lista, int valor)
{
    if (lista->inicio == NULL){

        return 0;
    
    }

    registro *aux = NULL, *ant = NULL;

    aux = lista->inicio;
    while (aux != NULL){

        if (aux->valor == valor){

            if (ant == NULL){
                
                lista->inicio = aux->prox;
            
            }else{
                
                ant->prox = aux->prox;
            
            }

            lista->qtd--;
            free(aux);

            if (ant == NULL){
                
                aux = lista->inicio;

            }else{
            
               aux = ant->prox;
            
            }
            
        }else{

            ant = aux;
            aux = aux->prox;
        
        }
    }

    return 0;
}

int remove_primo(Lista *lista){

    if (lista->inicio == NULL){

        return 0;
    
    }

    registro *aux = NULL;
    aux = lista->inicio;
    while (aux != NULL){

        printf("\n Verificando se %d e primo: ", aux->valor);
        printf("%d", verifica_primo(aux->valor));
        
        if (verifica_primo(aux->valor) == 1){


            if (aux->ant == NULL){
                
                lista->inicio = aux->prox;

                        
            }else{
                
                aux->ant->prox = aux->prox;

            
            }

            lista->qtd--;

            if (aux->ant == NULL){
                
                aux = lista->inicio;


            }else{
            
                aux = aux->ant->prox;

            
            }
            
        }else{

            aux->ant = aux;
            aux = aux->prox;
        
        }
        
    }

    return 0;

   /*if (lista->inicio == NULL){

        return 0;
    
    }

    registro *auxiliar = NULL;

    auxiliar = lista->inicio;
    
    while (auxiliar != NULL)
    {
        if (verifica_primo(auxiliar->valor) == 1)
        {
            
            if (auxiliar->ant == NULL){
            
                lista->inicio = auxiliar->prox;
            
            }else{
            
                auxiliar->ant->prox = auxiliar->prox;
            
            }

            lista->qtd--;
            free(auxiliar);
            return 1;

        }

        auxiliar->ant = auxiliar;
        auxiliar = auxiliar->prox;
    
    }

    return 0;*/

}
    

void menu(Lista *lista)
{
    int opcao, numero,valor;
    registro *aux;
    do
    {
        printf("\n1 - Incluir no inicio da Lista");
        printf("\n2 - Incluir no final da Lista");
        printf("\n3 - Mostrar Lista");
        printf("\n4 - Mostrar Lista inversa");
        printf("\n5 - Remover primos da lista");
        printf("\n6 - Remover todos os numeros iguais ao valor");
        printf("\n Digite a opcao desejada:" );
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\n Digite um numero: ");
            scanf("%d", &numero);
            incluir_no_inicio(lista, numero);
            printf("\n");
            break;
        case 2:
            printf("\n Digite um numero: ");
            scanf("%d", &numero);
            incluir_no_final(lista, numero);
            printf("\n");
            break;
        case 3:
            mostrar(lista, 0);
            printf("\n");
            break;
        case 4:
            mostrar(lista, 1);
            printf("\n");
            break;
        case 5:
            remove_primo(lista);
            printf("\n");
            break;
        case 6:
            aux = lista->inicio;
            printf("Digite o valor a ser removido: ");
            scanf("%d", &valor);
            
            while(aux!=NULL){
                if(aux->valor != valor){
                    remover_todos(lista, aux->valor);
                }
                aux = aux->prox;
            }
            printf("\n");
            break;
        case 7:
            printf("\n saindo do programa");
            printf("\n");
            break;
        default:
            printf("\n opcao invalida");
            printf("\n");
            break;
        }
    } while (opcao != 6);
}