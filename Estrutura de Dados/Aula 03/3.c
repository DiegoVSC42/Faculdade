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

void incluir_no_final_2(Lista *lista, int valor){

    Registro *novo;
    novo = aloca_registro();
    novo->valor = valor;

    if(lista->inicio == NULL){

        lista->inicio = novo;
        lista->final = novo;
    
    }else{

        lista->final->prox = novo;
        novo->ant = lista->final;
        lista->final = novo;

    }

    lista->qtd++;

}

void mostrar_lista(Lista *lista){

    Registro *auxiliar;

    if (lista->inicio == NULL){

        printf("\n lista vazia");
    
    }else{

        auxiliar = lista->inicio;

        while (auxiliar != NULL){
            
            printf("\n Valor: %d", auxiliar->valor);
            auxiliar = auxiliar->prox;
        
        }
    }
}

void menu(Lista *lista){

    int opcao, numero;

    do{
        printf("\n");
        printf("\n 1 - Inserir na lista");
        printf("\n 2 - Mostrar lista");
        printf("\n 3 - Finalizar o programa");
        printf("\n ");
        scanf("%d", &opcao);

        switch (opcao){

        case 1:
            printf("\n Digite o numero que deseja incluir na lista: ");
            scanf("%d", &numero);
            incluir_no_final_2(lista, numero);
            break;
        case 2:
            mostrar_lista(lista);
            break;
        case 3:
            printf("\n Saindo do programa");
            break;
        default:
            printf("\n opcao invalida");
            break;
        }
    } while (opcao != 3);
}

int main(){

    int valor;
    Lista *lista;
    lista = aloca_lista();

    menu(lista);

    printf("\n");
    return 0;

}
