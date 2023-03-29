/*2) Faça um programa que leia do usuário 10 números inteiros e armazene os números pares em uma lista ligada
e os números ímpares em uma segunda lista ligada. Mostre o conteúdo das 2 listas;*/

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
    novo = (Lista*)calloc(1,sizeof(Lista));
    return novo;

}

Registro *aloca_registro(){

    Registro *novo;
    novo = (Registro*)calloc(1,sizeof(Registro));
    return novo;

}
void incluir_lista(Lista *lista, int valor){

    Registro *novo;
    novo = aloca_registro();
    novo->valor = valor;

    if(lista->inicio == NULL || lista->fim == NULL){

        lista->inicio = novo;
        lista->fim = novo;

    }else{

        lista->fim->prox = novo;
        novo->ant = lista->fim;
        lista->fim = novo;
    }
    lista->qtd++;
}

void mostrar_lista(Lista *lista){

    Registro *aux;
    if(lista->inicio == NULL || lista->fim == NULL){
        printf("\nLista Vazia");
        return;
    }

    aux = lista->inicio;
    
    while(aux != NULL){
        
        printf("\nValor: %d", aux->valor);
        aux = aux->prox;

    }

    printf("\n");

}

int main(){

    int valor;
    Lista *lista_par, *lista_impar;
    
    lista_par = aloca_lista();
    lista_impar = aloca_lista();

    printf("\nDigite os 10 valores:\n");
    for(int i = 0; i < 10 ; i++){
        printf("Valor %d: ", i+1);
        scanf("%d", &valor);
        if(valor % 2 == 0){
            incluir_lista(lista_par,valor);
        }else{
            incluir_lista(lista_impar,valor);
        }
    }

    printf("\nLista de pares:\n");
    mostrar_lista(lista_par);
    printf("\nLista de impares:\n");
    mostrar_lista(lista_impar);
    printf("\n");
    return 0;
}
