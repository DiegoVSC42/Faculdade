/*
Implemente um programa que possua a função “primos_no_inicio”, 
essa função deve receber uma lista ligada simples e percorrê-la, 
caso encontre um número primo a função deve move-lo para o início da lista. 
Ao fim da execução da função, todos os números primos da lista devem estar nas primeiras posições da mesma. 
Na sua função principal leia N números do usuário e utilizando a função “primos_no_inicio”, 
mostre a lista dos números digitados com os números primos na frente.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Lista{

    int qtd;
    struct Registro *inicio;

}Lista;

typedef struct Registro{

    int valor;
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
    
    Registro *novo, *aux;
    novo = aloca_registro();
    novo->valor = valor;

    if(lista->inicio == NULL){
        
        lista->inicio = novo;

    }else{
        
        aux = lista->inicio;

        while(aux->prox != NULL){

            aux = aux->prox;

        }

        aux->prox = novo;
  
    }
    lista->qtd++;
}

void mostrar_lista(Lista *lista){

    Registro *aux;
    if(lista->inicio == NULL){
        printf("\nLista vazia");
        return;
    }else{

        aux = lista->inicio;
        while(aux != NULL){
            printf("\nValor: %d", aux->valor);
            aux = aux->prox;
        }
    }
}

int verifica_primo(int valor){

    if(valor == 0 || valor == 1){
        return 0;
    }
    if(valor == 3){
        return 1;
    }
    for(int i = 2; i < valor ; i++){
        if(valor % i == 0){
            return 0;
        }
    }

    return 1;

}
Lista *primos_no_inicio(Lista *lista){

    Registro *aux = NULL;
    Registro *ant = NULL;
    Registro *aux2 = NULL;
    Lista *lista_aux;
    lista_aux = aloca_lista();

    if(lista->inicio == NULL){
        printf("\nLista vazia");
    }else{
        aux = lista->inicio;
        
        while(aux != NULL){

            aux2 = aux->prox;
            if(verifica_primo(aux->valor)){
                if(ant == NULL){
                    lista->inicio = aux->prox;
                }else{
                    inserir_valor(lista_aux,aux->valor);
                    ant->prox = aux->prox;
                }
                free(aux);
                lista->qtd--;   
                if(ant == NULL){
                    aux = lista->inicio;
                }else{
                    aux = ant->prox;
                }
            }else{
                ant = aux;
                aux = aux->prox;
            }

        }
    }
    aux = lista->inicio;
    while(aux != NULL){
        inserir_valor(lista_aux,aux->valor);
        aux = aux->prox;
    }
    return lista_aux;
}

int main(){

    Lista *lista_a,*lista_b;
    lista_a = aloca_lista();
    lista_b = aloca_lista();
    int tam_a, tam_b,numero;

    printf("\nDigite o tamanho da lista: ");
    scanf("%d", &tam_a);

    for(int i = 0 ; i < tam_a;i++){
        printf("\nDigite o valor: ");
        scanf("%d", &numero);
        inserir_valor(lista_a,numero);
    }

    printf("\nLista");
    mostrar_lista(lista_a);
    lista_a = primos_no_inicio(lista_a);
    
    printf("\nLista com primos no inicio");
    mostrar_lista(lista_a);
    
    printf("\n");
    return 0;
}