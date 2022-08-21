/*
Implemente uma lista ligada de caracteres em C, ou seja, cada registro da lista deve possui apenas 1 caractere.
Construa uma função chamada "separa_vogais_consoantes". 
Essa função irá receber 3 listas (lista_a, lista_b, lista_c) 
e deverá incluir na lista_b todas as vogais contidas na lista_a e incluir na lista_c 
todas as consoantes contidas na lista_a. Na sua função principal, 
solicite um texto ao usuário e mostre a lista de vogais e consoantes utilizando a função criada.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Lista{

    int qtd;
    struct Registro *inicio;
    struct Registro *fim;

}Lista;

typedef struct Registro{

    char valor;
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
void inserir_valor(Lista *lista,char valor){
    
    Registro *novo;
    novo = aloca_registro();
    novo->valor = valor;

    if(lista->inicio == NULL){
        
        lista->inicio = novo;
        lista->fim = novo;

    }else{

        lista->fim->prox = novo;
        novo->ant = lista->fim;
        lista->fim = novo;

    }
    lista->qtd++;
}
void separa_vogais_consoantes(Lista *lista_a, Lista *lista_b, Lista *lista_c){

    Registro *aux;
    if(lista_a->inicio == NULL){
        printf("\nLista vazia");
    }else{

        aux = lista_a->inicio;
        while(aux != NULL){
            
            if(aux->valor == 'a' ||aux->valor == 'e' ||aux->valor == 'i' ||aux->valor == 'o' ||aux->valor == 'u' || aux->valor == 'A' ||aux->valor == 'E' ||aux->valor == 'I' ||aux->valor == 'O' ||aux->valor == 'U'){
                inserir_valor(lista_b,aux->valor);
            }else{
                if(aux->valor != ' '){
                    inserir_valor(lista_c,aux->valor);
                }
            }
            aux = aux->prox;
        }

    }
}

void mostrar_lista(Lista *lista){

    Registro *aux;
    if(lista->inicio == NULL){
        printf("\nlista vazia");

    }else{

        aux = lista->inicio;
        while(aux != NULL){
            printf("\nValor: %c", aux->valor);
            aux = aux->prox;
        }
    }
}

int main(){

    Lista *lista_a,*lista_b,*lista_c;
    lista_a = aloca_lista();
    lista_b = aloca_lista();
    lista_c = aloca_lista();
    int tam_a, tam_b;
    char letra[30];


    printf("\nDigite o texto: ");
    fflush(stdin);
    fgets(letra,30,stdin);
    letra[strlen(letra)-1] = '\0';

    for(int i = 0; i < strlen(letra); i++){
        inserir_valor(lista_a,letra[i]);
    }
    printf("\nLista");
    mostrar_lista(lista_a);
    printf("\n");
    separa_vogais_consoantes(lista_a,lista_b,lista_c);
    printf("\nLista b");
    mostrar_lista(lista_b);
    printf("\n");
    printf("\nLista c");
    mostrar_lista(lista_c);
    printf("\n");
    return 0;
}