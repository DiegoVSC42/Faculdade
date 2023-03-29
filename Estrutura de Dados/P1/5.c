#include <stdio.h>
#include <stdlib.h>

typedef struct Lista{

    int qtd;
    struct Registro *inicio;
    struct Registro *fim;

}Lista;


typedef struct Registro{

    int valor;
    struct Registro *prox;
    struct Registro *ant;
    

} Registro;

Lista *aloca_lista(){

    Lista *novo;
    novo = (Lista *)calloc(1,sizeof(Lista));
    novo->qtd = 10;
    return novo;

}

Registro *aloca_registro(){

    Registro *novo;
    novo = (Registro *)calloc(1,sizeof(Registro));
    return novo;

}

int empty(Lista *lista){

    if(lista->inicio == NULL){
       
        return 1;

    }else{

        return 0;
    }
}

int Lista_cheia(Lista *lista){

    Registro *aux;
    int contador = 0;
    aux = lista->inicio;
    while(aux != NULL){

        contador++;
        aux = aux->prox;
    }

    if(contador == lista->qtd){
        
        return 1;
    
    }else{

        return 0;
    }
}
//push
void mostrar_lista(Lista *lista){

    Registro *aux;
    aux = lista->inicio;

    while(aux != NULL){

        printf("\nValor: %d", aux->valor);
        aux = aux->prox;
    }

}

void push(Lista *lista, int valor){

    Registro * novo;
    novo = aloca_registro();
    novo->valor = valor;

    if(Lista_cheia(lista)){
        printf("\nErro: Lista cheia");
    }else{
        if(lista->inicio == NULL){
            lista->inicio = novo;
            lista->fim = novo;
        }else{
            lista->fim->prox = novo;
            novo->ant = lista->fim;
            lista->fim = novo;
        }
        mostrar_lista(lista);
    }

}
//pop
void pop(Lista *lista){


    Registro *aux = NULL;
    Registro *removedor = NULL;

    if(empty(lista)){
        printf("\nErro: Lista vazia");
    }else{
        aux = lista->inicio;
        while(aux->prox != NULL){

            aux = aux->prox;
        }
        if(aux == lista->inicio){
            lista->inicio = NULL;
            printf("\nLista Vazia");
            return;
        }
        if(aux->prox == NULL){
            removedor = aux;
            aux->ant->prox = aux->prox;

        }
        free(removedor);
    }
    mostrar_lista(lista);
}


//stackpop
int stackpop(Lista *lista){
    
    /*Registro *aux;
    aux = lista->inicio;

    while(aux != NULL){

        aux = aux->prox;

    }
    printf("%d", aux->valor);*/

    return lista->fim->valor;
}

int main(){

    int opcao,valor;
    Lista *lista;
    lista = aloca_lista();

    do{
        printf("\nEscolha uma opcao:");
        printf("\n1 - Push:");
        printf("\n2 - Pop:");
        printf("\n3 - Empty:");
        printf("\n4 - Stackpop:");
        printf("\n5 - Sair:");
        printf("\nOpcao desejada: ");
        scanf("%d", &opcao);

        switch (opcao){

            case 1:
                printf("\nDigite o valor que deseja inserir: ");
                scanf("%d", &valor);
                push(lista,valor);
                
                printf("\n");
                break;
            case 2:
                pop(lista);
                printf("\n");
                break;
            case 3:
                if(empty(lista)){
                    printf("\nLista vazia");
                }else{
                    printf("\nLista nao vazia");                }
                printf("\n");
                break;
            case 4:
                printf("\nValor no topo da lista: %d", stackpop(lista));
                mostrar_lista(lista);
                printf("\n");
                break;
            case 5:
                printf("\nSaindo do programa");
                printf("\n");   
                break;  

            default:
                printf("\n");   
                break;  
        }
        

    }while(opcao != 5);

    printf("\n");
    return 0;

}

