/*
Implemente um programa que possua uma função "remove_perfeitos". 
Essa função deve receber por parâmetro uma lista ligada e remover todos números perfeitos que estão dentro da lista. 
Na sua função principal leia do usuário N números e utilizando a função criada remova os números perfeito da lista de N números.
*/

//soma dos divisores é igual ao valor
//ex: 6 = 1+2+3

#include <stdio.h>
#include <stdlib.h>

typedef struct Lista{

    long int qtd;
    struct Registro *inicio;
    struct Registro *fim;

}Lista;

typedef struct Registro{

    long int valor;
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
void inserir_valor(Lista *lista,long int valor){
    
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

        printf("\nLista vazia");

    }else{

        aux = lista->inicio;
        while(aux != NULL){
            printf("\nValor: %ld", aux->valor);
            aux = aux->prox;
        }
    }
}

void remove_perfeitos(Lista *lista){

    Lista *divisores;
    Registro *aux, *aux_div,*aux_div2;
    Registro *removedor;
    long int soma_div = 0;
    long int contador = 0;
    if(lista->inicio == NULL && lista->fim == NULL){
        return;
    }
    aux = lista->inicio;

    do{
        while(aux != NULL){
            
            divisores = aloca_lista();

            for(long int i = 1; i < aux->valor; i++){
                if(aux->valor % i == 0){
                    inserir_valor(divisores,i);
                }
            }
            soma_div = 0;
            aux_div = divisores->inicio;

            while(aux_div != NULL){

                soma_div = soma_div + aux_div->valor;

                aux_div = aux_div->prox;

            }

            if(aux->valor == soma_div){
                if(aux->ant == NULL){
                    removedor = aux;
                    lista->inicio = aux->prox;
                }else{
                    removedor = aux;
                    aux->ant->prox = aux->prox;
                }
                free(removedor);
                lista->qtd--;
            }
            free(aux_div);
            aux = aux->prox;
        }
        if(lista->qtd == 0){
            lista->inicio = NULL;
            lista->fim = NULL;
        }
        free(aux);
        contador++;
    }while(contador <= lista->qtd);

}

void menu(Lista *lista){

    long int opcao,valor;

    do{
        printf("\n1 - Inserir valor");
        printf("\n2 - Remover perfeitos");
        printf("\n3 - Mostrar lista");
        printf("\n0 - Sair");
        printf("\nDigite a opcao desejada: ");
        scanf("%ld", &opcao);

        switch (opcao){
        case 1:
            printf("\nDigite o valor: ");
            scanf("%ld", &valor);
            inserir_valor(lista,valor);
            break;
        case 2:
            remove_perfeitos(lista);
            break;
        case 3:
            mostrar_lista(lista);
            break;
        case 0:
            printf("\nSaindo do programa");
            break;
        default:
            printf("\nopcao invalida");
            break;
        }


    }while(opcao != 0);
}

long int main(){

    Lista *lista;
    lista = aloca_lista();

    menu(lista);

    printf("\n");
    return 0;
}