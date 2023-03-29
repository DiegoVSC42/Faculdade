/*
    1 ) Faça um programa que receba do usuário um número N e preencha 2 listas ligadas com N números aleatórios.
    Depois de preenchida as 2 listas, remova os números em comum das 2 listas
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Lista{
    
    int qtd;
    struct Registro *inicio;

}Lista;

typedef struct Registro{

    int valor;
    struct Registro*prox;

}Registro;

Lista *aloca_lista(){

    Lista *novo;
    novo = (Lista *)malloc(sizeof(Lista));
    novo->qtd = 0;
    novo->inicio = NULL;
    return novo;

}

Registro *aloca_registro(){

    Registro *novo;
    novo = (Registro *)malloc(sizeof(Registro));
    novo->valor = 0;
    novo->prox = NULL;
    return novo;

}

void incluir_ordenado(Lista *lista, int valor){

    Registro *aux = NULL, *ant = NULL;
    Registro *novo;
    
    novo = aloca_registro();
    novo->valor = valor;

    if (lista->inicio == NULL){
        
        lista->inicio = novo;

    }else{
        
        aux = lista->inicio;

        while (aux->prox != NULL && aux->valor <= valor){

            ant = aux;
            aux = aux->prox;

        }

        if (aux->valor >= valor){

            if (ant == NULL){

                lista->inicio = novo;

            }else{

                ant->prox = novo;

            }

            novo->prox = aux;
        
        }else{

            aux->prox = novo;
        
        }
    }

    lista->qtd++;
    
}

int remover_todos(Lista *lista, int valor){

    if (lista->inicio == NULL){

        return 0;

    }

    Registro *aux = NULL, *ant = NULL;

    aux = lista->inicio;

    while (aux != NULL){

        if (aux->valor == valor){

            if (ant == NULL){
                
                lista->inicio = aux->prox;
            
            }else{
                
                ant->prox = aux->prox;
            
            }

            lista->qtd--;
            free(aux);

            if (ant == NULL){
                
                aux = lista->inicio;

            }else{
            
               aux = ant->prox;
            
            }

        }else{

            ant = aux;
            aux = aux->prox;
        
        }
    }

    return 0;
}

Lista *elementos_em_comum(Lista * lista1, Lista * lista2){

    Lista *lista3;
    lista3 = aloca_lista();
    Registro *aux1 = NULL;
    Registro *aux2 = NULL;
    aux1 = lista1->inicio;
    aux2 = lista2->inicio;
    while (aux1 != NULL && aux2 != NULL){
        
        if (aux1->prox != NULL){

            if (aux1->prox->valor < aux1->valor){
        
                printf("\n A lista l1 não esta ordenada");
                return NULL;

            }
        }

        if (aux2->prox != NULL){

            if (aux2->prox->valor < aux2->valor){

                printf("\n A lista l2 não esta ordenada");
                return NULL;
            
            }
        }

        if (aux1->valor == aux2->valor){

            incluir_ordenado(lista3, aux1->valor);
            aux1 = aux1->prox;
            aux2 = aux2->prox;
        
        }else{
            
            if (aux1->valor < aux2->valor){
            
                aux1 = aux1->prox;
            
            }else{
             
                aux2 = aux2->prox;
            
            }
        }
    }
    return lista3;
}



void mostrar_lista(Lista * lista){
    
    Registro * auxiliar;

    if (lista->inicio == NULL){

        printf("\n          lista vazia");

    }else{

        auxiliar = lista->inicio;

        while(auxiliar != NULL){

            printf("\n          Valor: %d",auxiliar->valor);
            auxiliar = auxiliar->prox;
        
        }
    }
}


int main(){

    srand(time(NULL));

    int N, Numero_aleatorio;
    Lista *lista1,*lista2, *lista_aux;
    Registro *aux;
    
    lista1 = aloca_lista();
    lista2 = aloca_lista();
    lista_aux = aloca_lista();


    printf("\nDigite um numero: ");
    scanf("%d", &N);

    for(int i = 0 ; i < N ; i++){

        Numero_aleatorio = rand() % 20;
        incluir_ordenado(lista1,Numero_aleatorio);
        
        Numero_aleatorio = rand() % 20;
        incluir_ordenado(lista2,Numero_aleatorio);
    }
    printf("\n  Listas :");
    printf("\n");
    printf("\n      Lista 1\n");
    mostrar_lista(lista1);
    printf("\n");
    printf("\n      Lista 2\n");
    mostrar_lista(lista2);
    printf("\n");
    lista_aux = elementos_em_comum(lista1,lista2);

    printf("\nLista de numeros em comum:\n");
    mostrar_lista(lista_aux);
    printf("\n");

    if(lista_aux != NULL){

        aux = lista_aux->inicio;
        while(aux != NULL){

            remover_todos(lista1,aux->valor);
            remover_todos(lista2,aux->valor);
            aux = aux->prox;

        }
    }

    printf("\nConteudo das listas apos remocao: \n");
    printf("\n      Lista 1\n");
    mostrar_lista(lista1);
    printf("\n");
    printf("\n      Lista 2\n");
    mostrar_lista(lista2);
    printf("\n");
    printf("\n");

    return 0;

}

