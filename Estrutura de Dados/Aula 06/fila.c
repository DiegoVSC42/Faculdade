
/*
Utilizando as seguintes estruturas, construa um programa que implemente as seguintes funções:
insert ou enqueue - insere itens numa fila (ao final).
remove ou dequeue - retira itens de uma fila (primeiro item).
empty - veriica se a fila está vazia.
size - retorna o tamanho da fila.
front - retorna o próximo item da fila sem retirar o mesmo da fila
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Fila
{
    int tamanho;
    struct Elemento * inicio;
    struct Elemento * final;

}Fila;

typedef struct Elemento
{
    int valor;
    struct Elemento * prox;

}Elemento;

Fila *aloca_fila(){

    Fila *novo;
    novo = (Fila *)calloc(1,sizeof(Fila));
    return novo;

}

Elemento *aloca_elemento(){

    Elemento *novo;
    novo = (Elemento *)calloc(1,sizeof(Elemento));
    return novo;

}
void insert(Fila *fila, int valor){

    Elemento *novo, *auxiliar;
    novo = aloca_elemento();
    novo->valor = valor;

    if (fila->inicio == NULL){
        
        fila->inicio = novo;
    
    }else{

        auxiliar = fila->inicio;

        while(auxiliar->prox != NULL){

            auxiliar = auxiliar->prox;

        }

        auxiliar->prox = novo;
        
    }
    fila->tamanho++;
}

void remove_valor(Fila *fila){

    Elemento *aux;
    aux = fila->inicio;

    fila->final = aux;
    fila->inicio = aux->prox;

    fila->tamanho--;
}
void mostrar_fila(Fila *fila){

    Elemento *auxiliar;

    if (fila->inicio == NULL){

        printf("\n fila vazia");
    
    }else{

        auxiliar = fila->inicio;

        while (auxiliar != NULL){
            
            printf("\n Valor: %d", auxiliar->valor);
            auxiliar = auxiliar->prox;
        
        }
    }
}

int empty(Fila *fila){

    if(fila->inicio == NULL){
        return 1;
    }else{
        return 0;
    }
}

void front(Fila *fila){

    Elemento *aux;
    aux = fila->inicio;

    printf("\nPrimeiro valor da fila: %d", aux->valor);
}

void size(Fila *fila){

    printf("\nTamanho da fila: %d", fila->tamanho);


}
void menu(Fila *fila){

    int opcao,valor;


    do{
        printf("\nSelecione uma opcao: ");
        printf("\n1 - Insert ou enqueue - insere itens numa fila (ao final).");
        printf("\n2 - Remove ou dequeue - retira itens de uma fila (primeiro item).");
        printf("\n3 - Empty - verifica se a fila esta vazia.");
        printf("\n4 - Size - retorna o tamanho da fila.");
        printf("\n5 - Front - retorna o proximo item da fila sem retirar o mesmo da fila");
        printf("\n6 - Mostrar fila");
        printf("\n0 - Sair");
        printf("\nOpcao desejada: ");
        scanf("%d", &opcao);
        
        printf("\n");

        switch (opcao){

        case 1:
            printf("\nDigite o valor que deseja inserir: ");
            scanf("%d", &valor);
            insert(fila,valor);
            break;
        case 2:
            remove_valor(fila);
            break;
        case 3:
            if(empty(fila)){
                printf("\nFila Vazia");
            }else{
                printf("\nFila nao esta vazia");
            }
            break;
        case 4:
            size(fila);

            break;
        case 5:
            front(fila);
            break;
        case 6:
            mostrar_fila(fila);
            break;
        case 0:
            printf("\n Saindo do programa");
            break;
        default:
            printf("\n opcao invalida");
            break;
        }
    } while (opcao != 0);
}

int main(){

    Fila *fila;
    fila = aloca_fila();

    menu(fila);
}
