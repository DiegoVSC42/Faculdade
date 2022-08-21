/*
Implemente um programa que possua uma função de nome "inverter_listas".
 Essa função recebe por parâmetro duas listas duplamente ligadas (lista_a, lista_b)
  e troque os valores da lista_a pelos valores invertidos da lista_b e os valores da lista_b 
  pelos valores invertidos da lista_a. 
  Ex: Lista_a: 1,2,3 , Lista_b: 4,5,6. 
  Resultado: Lista_a: 6,5,4 Lista_B: 3,2,1. 
  Na sua função principal leia 2 números N e M que correspondem a 
  quantidade de elementos da lista_a e lista_b respectivamente. 
  Leia N + M números, atribua-os a suas respectivas listas e utilizando a função criada, 
  mostre seus valores invertidos.
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
void inserir_valor(Lista *lista,int valor){
    
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

void mostrar_lista(Lista *lista){

    Registro *aux;
    if(lista->inicio == NULL){
        printf("\nlista vazia");

    }else{

        aux = lista->inicio;
        while(aux != NULL){
            printf("\nValor: %d", aux->valor);
            aux = aux->prox;
        }
    }
}

void inverter_listas(Lista *lista_a, Lista *lista_b){


    Lista *lista_aux,*lista_aux2, *lista_clone;
    lista_clone = aloca_lista();
    lista_aux = aloca_lista();
    lista_aux2 = aloca_lista();
    Registro *aux,*aux_aux, *aux_clone;

    aux_clone = lista_b->inicio;

    while(aux_clone != NULL){

        inserir_valor(lista_clone,aux_clone->valor);
        aux_clone = aux_clone->prox;
    }

    aux = lista_a->fim;

    while(aux->ant != NULL){

        inserir_valor(lista_aux,aux->valor);   
        aux = aux->ant;
    
    }
    aux = lista_a->inicio;
    inserir_valor(lista_aux,aux->valor);
    
    lista_b = aloca_lista();
    aux_aux = lista_aux2->inicio;

    while(aux_aux != NULL){

        inserir_valor(lista_b,aux_aux->valor);
        aux_aux = aux_aux->prox;

    }


    aux = lista_clone->fim;
    
    while(aux->ant != NULL){

        inserir_valor(lista_aux2,aux->valor);   
        aux = aux->ant;
    
    }
    aux = lista_clone->inicio;
    inserir_valor(lista_aux2,aux->valor);
    
    lista_a = aloca_lista();
    
    aux_aux = lista_aux2->inicio;

    while(aux_aux != NULL){

        inserir_valor(lista_a,aux_aux->valor);
        aux_aux = aux_aux->prox;

    }
    
    mostrar_lista(lista_a);
    printf("\nPrimeira Lista Invertida e trocada");
    mostrar_lista(lista_a);
    lista_b = aloca_lista();
    aux = lista_aux->inicio;
    while(aux != NULL){
        inserir_valor(lista_b, aux->valor);
        aux = aux->prox;
    }
    printf("\nSegunda Lista Invertida e trocada");
    mostrar_lista(lista_b);
}

int main(){

    Lista *lista_a,*lista_b;
    lista_a = aloca_lista();
    lista_b = aloca_lista();
    int tam_a, tam_b,numero;

    printf("\nDigite o tamanho da primeira lista: ");
    scanf("%d", &tam_a);

    for(int i = 0 ; i < tam_a;i++){
        printf("\nDigite o valor: ");
        scanf("%d", &numero);
        inserir_valor(lista_a,numero);
    }

    printf("\nPrimeira Lista");
    mostrar_lista(lista_a);
    
    printf("\nDigite o tamanho da segunda lista: ");
    scanf("%d", &tam_b);
    
    for(int i = 0 ; i < tam_b;i++){
        printf("\nDigite o valor: ");
        scanf("%d", &numero);
        inserir_valor(lista_b,numero);
    }
    
    printf("\nSegunda Lista");
    mostrar_lista(lista_b);
    printf("\n");
    
    inverter_listas(lista_a,lista_b);

    printf("\n");
    return 0;
}