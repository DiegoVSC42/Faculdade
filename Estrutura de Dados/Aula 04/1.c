//1) utilizando como base a solucao_lista2_exercicio3.c 
//construa as seguintes funções para uma lista duplamente ligada:
//    1 - Remover Primos
//    2 - Remover numeros iguais
//    3 - Buscar por numero
//    4 - Comparar 2 listas ( falar os numeros iguais e quais sao diferentes)
//    5 - incluir de forma ordenada

#include <stdio.h>
#include <stdlib.h>

typedef struct Lista{
    
    int qtd;
    struct Registro *inicio;
    struct Registro *final;

}Lista;

typedef struct Registro{

    int valor;
    struct Registro*prox;
    struct Registro*ant;

}Registro;

Lista *aloca_lista(){

    Lista *novo;
    novo = (Lista *)malloc(sizeof(Lista));
    novo->qtd = 0;
    novo->inicio = NULL;
    novo->final = NULL;
    return novo;

}

Registro *aloca_registro(){

    Registro *novo;
    novo = (Registro *)malloc(sizeof(Registro));
    novo->valor = 0;
    novo->prox = NULL;
    novo->ant = NULL;
    return novo;

}


void incluir_ordenado(Lista *lista, int valor){

    Registro *aux = NULL;
    Registro *novo;
    novo = aloca_registro();
    novo->valor = valor;

    if (lista->inicio == NULL){
        
        lista->inicio = novo;

    }else{
   
        aux = lista->inicio;
        while (aux->prox != NULL && aux->valor <= valor){
            
            aux->ant = aux;
            aux = aux->prox;
        
        }

        if (aux->valor >= valor){

            if (aux->ant == NULL)
                lista->inicio = novo;
            else
                aux->ant->prox = novo;

            novo->prox = aux;
        
        }else{
            
            aux->prox = novo;
        
        }
    }

    lista->qtd++;

}




int remover_todos(Lista *lista, int valor){

    if (lista->inicio == NULL){

        return 0;
    
    }

    Registro *aux = NULL, *ant = NULL;

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

void remove_primo(Lista *lista){

    int resultado = 0;

    if (lista->inicio==NULL){

        printf("Lista vazia\n");
    
    }

    Registro * auxiliar;

    auxiliar = lista->inicio;

    while(auxiliar!=NULL){

        for (int i = 2 ; i <= auxiliar->valor / 2 ; i++) {
            if (auxiliar->valor % i == 0) {
                resultado++;
                break;
            }
        }
        if (resultado > 0){
        
            remover_todos(lista, auxiliar->valor);
        
        }else{
         
            auxiliar = auxiliar->prox;
        
        }
    }
 

}

void menu(Lista *lista){

    int opcao;
    int primo;
    int valor;

    do{

        printf("1 - Incluir de forma ordenada\n");
        printf("2 - Remover primos");
        printf("\n");
        scanf("%d", &opcao);

        switch (opcao){

        case 1:
            printf("Digite o valor que deseja incluir: ");
            scanf("%d", &valor);
            incluir_ordenado(lista,valor);
            break;
        case 2:
            remove_primo(lista);
            break;
        case 3:

            break;
        case 4:
            printf("\n Saindo do programa");
            break;
        default:
            printf("\n opcao invalida");
            break;
        }
    } while (opcao != 4);
}

int main();

    Lista *l1;

    l1 = aloca_lista();

    menu(lista);
    printf("\n");
    return 0;

}