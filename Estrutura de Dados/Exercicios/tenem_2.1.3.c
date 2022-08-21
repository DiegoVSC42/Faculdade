/*
Escreva um algoritmo para determinar se uma string de caracteres de
entrada é da forma:
xCy
onde x é uma string consistindo nas letras 'A' e 'B', e y é o inverso de
x (isto é, se x = "ABABBA", y deve equivaler a "ABBABA"). Em cada
ponto, você só poderá ler o próximo caractere da string.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 100

typedef struct Pilha {

    char valor[TAM];
    int topo;

}Pilha;

Pilha *inicia_pilha(){

    Pilha *novo;
    novo = (Pilha*)calloc(1,sizeof(Pilha));
    novo->topo = -1;
    
    return novo;

}

int empty(Pilha *pilha){

    if(pilha->topo == -1){
        return 1;
    }
    return 0;
}

int full(Pilha *pilha){

    if(pilha->topo == TAM-1){
        return 1;
    }
    return 0;
}

int stacktop(Pilha *pilha){

    int aux;
    aux = pilha->valor[pilha->topo];
    return aux;

}

void push(Pilha *pilha, char valor){

    if(full(pilha)){
        printf("\nErro: Pilha cheia");
    }else{
        pilha->topo++;
        pilha->valor[pilha->topo] = valor;
    }
}

char pop(Pilha *pilha){

    char aux;

    if(empty(pilha)){
        printf("\nErro: Pilha vazia");
    }else{
        aux = pilha->valor[pilha->topo];
        pilha->topo--;
    }
    return aux;
}
void show(Pilha *pilha){

    for(int i = pilha->topo ; i >= 0 ; i--){
        printf("\nValor: %c", pilha->valor[i]);
    }
    printf("\n");

}

Pilha *inverte_pilha(Pilha *pilha){

    Pilha *pilha_aux;
    pilha = inicia_pilha();
    for(int i = pilha->topo ; i >= 0 ; i--){
        push(pilha_aux,pilha->valor[i]);
        pop(pilha);
    }
    show(pilha_aux);
    
    return pilha_aux;
}
int main(){

    Pilha *pilha;
    pilha = inicia_pilha();
    char nome[10];
    printf("Digite a palavra para ser invertida: ");
    fflush(stdin);
    fgets(nome,TAM,stdin);
    nome[strlen(nome) - 1] = '\0';
    printf("Tamanho do nome: %d", strlen(nome));
    for(int i = 0; i <= strlen(nome)-1; i++){
        push(pilha,nome[i]);
    }
    show(pilha);
    if(empty(pilha)){
        printf("\nPilha vazia");
    }else{
        pilha = inverte_pilha(pilha);
        show(pilha);
    }

    printf("\n");
    return 0;

}