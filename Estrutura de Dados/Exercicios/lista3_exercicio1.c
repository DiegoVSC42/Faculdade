/*
1) utilizando como base a solucao_lista2_exercicio3.c construa as seguintes funções para uma lista duplamente ligada:
    1 - incluir de forma ordenada
    2 - Remover Primos
    3 - Remover numeros iguais
    4 - Buscar por numero
    5 - Comparar 2 listas ( falar os numeros iguais e quais sao diferentes)
*/


#include <stdio.h>
#include <stdlib.h>

typedef struct Lista{

    int qtd;
    struct Registro *inicio;
    struct Registro *fim;

}Lista;

typedef struct Registro{

    int valor;
    struct Registro *ant;
    struct Registro *prox;

}Registro;

Lista *aloca_lista(){

    Lista *novo;
    novo = (Lista*) malloc(sizeof(Lista));
    novo->qtd = 0;
    novo->inicio = NULL;
    novo->fim = NULL;
    return novo;
}

Registro *aloca_registro(){

    Registro *novo;
    novo = (Registro*)malloc(sizeof(Registro));
    novo->valor = 0;
    novo->ant = NULL;
    novo->prox = NULL;
    return novo;

}


void mostrar_lista(Lista *lista){

    Registro *aux;
    if(lista->inicio == NULL && lista->fim == NULL){
        printf("\nLista vazia");
        return;
    }
    aux = lista->inicio;

    while(aux != NULL){
        printf("\nValor: %d", aux->valor);
        aux = aux->prox;
    }

}

void incluir_ordenado(Lista *lista, int valor){

    Registro *novo, *aux;
    novo = aloca_registro();
    novo->valor = valor;
    
    if(lista->inicio == NULL && lista->fim == NULL){

        lista->fim = novo;
        lista->inicio = novo;

    }else{

        aux = lista->inicio;
        while(aux->prox != NULL && aux->valor < valor){
            aux = aux->prox;
        }
        if(aux->valor < valor){

            aux->prox = novo;
            novo->ant = aux;
            lista->fim = novo;
        
        }else{

            novo->ant = aux->ant;
            novo->prox = aux;
            aux->ant = novo;
            if(novo->ant == NULL){
                lista->inicio = novo;
            }else{
                novo->ant->prox = novo;
            }
        }
    }
    lista->qtd++;
}
int verifica_primo(int valor){

    if(valor == 0 || valor == 1){
        return 0;
    }
    for(int i = 2; i < valor; i++){
        if(valor % i == 0){
            return 0;
        }
    }
    return 1;
}
void remover_primos(Lista *lista){

    Registro *atual = NULL;
    Registro *auxiliar1 = NULL;

    if(lista->inicio == NULL && lista->fim == NULL){
        return;
    }

    atual = lista->inicio;
    while(atual != NULL){
        if(verifica_primo(atual->valor)){
            if(atual->ant == NULL){
                auxiliar1 = lista->inicio;
                lista->inicio = atual->prox;
   
            }else{
                auxiliar1 = atual;
                atual->ant->prox = atual->prox;

            }
            free(auxiliar1);
            lista->qtd--;
        }
        atual = atual->prox;
    }
    free(atual);
    if(lista->qtd == 0){
        lista->inicio = NULL;
        lista->fim = NULL;
    }
    
}
void remover_iguais(Lista *lista1 ,Lista *lista2){

    Registro *atual1 = NULL, * atual2 = NULL;
    Registro *auxiliar1 = NULL, *auxiliar2 = NULL;

    if(lista1->inicio == NULL && lista1->fim == NULL || lista2->inicio == NULL && lista2->fim == NULL){
        printf("\nAlguma das listas está vazia ou nao foi possivel remover");
        return;
    }

    atual1 = lista1->inicio;
    while(atual1 != NULL){

        atual2 = lista2->inicio;
        
        while(atual2 != NULL){    
            
            if(atual1->valor == atual2->valor){
                if(atual1->ant == NULL){
                    auxiliar1 = lista1->inicio;
                    lista1->inicio = atual1->prox;
    
                }else{
                   
                    auxiliar1 = atual1;
                    atual1->ant->prox = atual1->prox;

                }
                
                lista1->qtd--;
                free(auxiliar1);
                
                if(atual2->ant == NULL){
                    auxiliar2 = lista2->inicio;
                    lista2->inicio = atual2->prox;
    
                }else{
                    
                    auxiliar2 = atual2;
                    atual2->ant->prox = atual2->prox;

                }

                lista2->qtd--;
                free(auxiliar2);

            }
            
            atual2 = atual2->prox;
        
        }
        
        atual1 = atual1->prox;
    
    }
    if(lista1->qtd == 0){
        lista1->inicio = NULL;
        lista1->fim = NULL;
    }
    if(lista2->qtd == 0){
        lista2->inicio = NULL;
        lista2->fim = NULL;
    }
}

void remover_repetidos(Lista *lista){

    Registro *atual = NULL;
    Registro *auxiliar = NULL;
    Registro *removedor = NULL;

    if(lista->inicio == NULL && lista->fim == NULL){
        return;
    }

    atual = lista->inicio;

    while(atual != NULL){
        
        auxiliar = atual->prox;
        while(auxiliar != NULL){
            if(atual->valor == auxiliar->valor){
                removedor = atual->prox;
                atual->prox = atual->prox->prox;
            }
            free(removedor);
            auxiliar = auxiliar->prox;
        }
        free(auxiliar);
        atual = atual->prox;
        lista->qtd--;
    }
    free(atual);

    if(lista->qtd == 0){
        lista->inicio = NULL;
        lista->fim = NULL;
    }
    
}

int buscar_por_valor(Lista *lista,int valor){

    Registro *aux;
    if(lista->inicio == NULL){
        return 0;
    }
    aux = lista->inicio;
    
    while(aux != NULL){

        if(aux->valor == valor){
            return 1;
        }
        aux = aux->prox;
    }
    return 0;
}
Lista *compara_lista(Lista *lista1, Lista*lista2){

    Registro *aux1, *aux2;
    Lista *lista3;
    lista3 = aloca_lista();

    if(lista1->inicio == NULL || lista2->inicio == NULL){

        return NULL;
    }

    aux1 = lista1->inicio;
    while(aux1 != NULL){
        
        aux2 = lista2->inicio;
        while(aux2 != NULL){

            if(aux2->valor == aux1->valor){
                incluir_ordenado(lista3,aux2->valor);
            }
            aux2 = aux2->prox;
        }
        aux1 = aux1->prox;
    }
    return lista3;
}

void menu(Lista *lista1, Lista *lista2){

    int opcao;
    int valor;
    int lista;
    Lista *lista_comparadora;

    do{
        printf("\nDigite uma opcao");
        printf("\n1 - Incluir de forma ordenada");
        printf("\n2 - Mostrar listas");
        printf("\n3 - Remover primos");
        printf("\n4 - Remover numeros repetidos");
        printf("\n5 - Remover numeros iguais nas duas listas");
        printf("\n6 - Buscar por numero");
        printf("\n7 - Comparar duas listas: ");
        printf("\n    Opcao desejada : ");
        scanf("%d", &opcao);

        switch (opcao){

        case 1:
            printf("\nDigite em qual lista ele sera inserido: ");
            scanf("%d", &lista);
            printf("\nDigite o valor a ser incluido na lista: ");
            scanf("%d", &valor);
            if(lista == 1){
                
                incluir_ordenado(lista1,valor);

            }else if(lista == 2){

                incluir_ordenado(lista2,valor);

            } 
            break;
        case 2: 
            printf("\nLista 1:");
            mostrar_lista(lista1);
            printf("\n");
            printf("\nLista 2:");
            mostrar_lista(lista2);
            printf("\n");
            break;
        case 3: 
            printf("\nDigite em qual lista serao removidos os valores: ");
            scanf("%d", &lista);
            if(lista == 1){
                
                remover_primos(lista1);

            }else if(lista == 2){

                remover_primos(lista2);

            }
            break;
        case 4:
            printf("\nDigite em qual lista serao removidos os valores: ");
            scanf("%d", &lista);
            if(lista == 1){
                
                remover_repetidos(lista1);

            }else if(lista == 2){

                remover_repetidos(lista2);

            }
            break;
        case 5:
            remover_iguais(lista1, lista2);
            break;
        case 6:
            printf("\nDigite qual valor sera buscado: ");
            scanf("%d", &valor);             
            if(buscar_por_valor(lista1, valor)){
                printf("\nA lista 1 possui o numero %d", valor);
            }else{
                printf("\nA lista 1 nao possui o numero %d", valor);
            }
            if(buscar_por_valor(lista2, valor)){
                printf("\nA lista 2 possui o numero %d", valor);
            }else{
                printf("\nA lista 2 nao possui o numero %d", valor);
            }
            printf("\n");
            break;
        case 7:
            lista_comparadora = compara_lista(lista1, lista2);
            mostrar_lista(lista_comparadora);
            printf("\n");
            break;  
        default: 
            printf("\nOpcao Invalida");
            break;
        }

    
    }while(opcao != 8);
    
}

int main(){

    Lista *lista1, *lista2;
    lista1 = aloca_lista();
    lista2 = aloca_lista();
    
    menu(lista1,lista2);
    printf("\n");
    return 0;
}