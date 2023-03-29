/*
    3) Faça um programa que leia do usuário um número N inteiro positivo e solicite ao usuário N números para serem armazenados.
    a primeira metade dos N números, deverá ser armazenada em uma lista ligada e a segunda metade dos N números deverá ser 
    armazenado em uma segunda lista.
    Mostre na tela quais valores são comuns entre as 2 listas ligadas.
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
    novo = (Lista*)calloc(1,sizeof(Lista));
    return novo;

}

Registro *aloca_registro(){

    Registro *novo;
    novo = (Registro*)calloc(1,sizeof(Registro));
    return novo;

}
void incluir_no_final(Lista *lista, int valor){

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

int busca_na_lista(Lista*lista, int valor){

    Registro *aux;
    
    aux = lista->inicio;

    while (aux != NULL){
        
        if(aux->valor == valor){
            return 1;
        }else{
            aux = aux->prox;
        }
    }

    return 0;

}

void mostrar_comuns(Lista *lista1, Lista *lista2){

    if(lista1->inicio == NULL || lista1->fim == NULL){
        printf("\nA primeira lista está vazia");
        return;
    }
    if(lista2->inicio == NULL || lista2->fim == NULL){
        printf("\nA segunda lista está vazia");
        return;
    }
    Registro *aux;

    aux = lista1->inicio;

    while(aux != NULL){
        
        if(busca_na_lista(lista2,aux->valor)){
            printf("%d ", aux->valor);
        }
        aux = aux->prox;
    
    }
    printf("\n");
}

int main(){

    Lista *lista1, *lista2;
    int qtd_num,valor;

    lista1 = aloca_lista();
    lista2 = aloca_lista();
    printf("\nDigite a quantidade de numeros desejada: ");
    scanf("%d", &qtd_num);

    printf("\nDigite os valores desejados: ");
    for(int i = 1; i <= qtd_num ; i++){
        printf("\nValor: ");
        scanf("%d", &valor);
        if(i <= qtd_num/2){
            incluir_no_final(lista1,valor);
        }else{
            incluir_no_final(lista2,valor);
        }
    }

    printf("\nLista 1:");
    mostrar_lista(lista1);
    printf("\nLista 2:");
    mostrar_lista(lista2);
    printf("\nNumeros em comum:\n");
    mostrar_comuns(lista1,lista2);
    printf("\n");
    return 0;
}