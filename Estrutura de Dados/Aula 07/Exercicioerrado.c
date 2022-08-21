/*
Dada uma pilha de n cartas enumeradas de 1 até n com a carta 1 no topo e a carta n na base.  
A seguinte operação é ralizada enquanto tiver 2 ou mais cartas na pilha.
Jogue fora a carta do topo e mova a próxima carta (a que ficou no topo) para a base da pilha.
Sua tarefa é encontrar a sequência de cartas descartadas e a última carta remanescente.
Cada linha de entrada (com exceção da última) contém um número n ≤ 50. A última linha contém 0 e não deve ser processada. 
Cada número de entrada produz duas linhas de saída. A primeira linha apresenta a sequência de cartas descartadas e a 
segunda linha apresenta a carta remanescente.
Entrada
A entrada consiste em um número indeterminado de linhas contendo cada uma um valor de 1 até 50. 
A última linha contém o valor 0.
Saída
Para cada caso de teste, imprima duas linhas. A primeira linha apresenta a sequência de cartas descartadas, 
cada uma delas separadas por uma vírgula e um espaço. A segunda linha apresenta o número da carta que restou. 
Nenhuma linha tem espaços extras no início ou no final. Veja exemplo para conferir o formato esperado.
Exemplo de entrada:
7
19
10
6
0
Exemplo de saída:
Discarded cards: 1, 3, 5, 7, 4, 2
Remaining card: 6
Discarded cards: 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 4, 8, 12, 16, 2, 10, 18, 14
Remaining card: 6
Discarded cards: 1, 3, 5, 7, 9, 2, 6, 10, 8
Remaining card: 4
Discarded cards: 1, 3, 5, 2, 6
Remaining card: 4
*/

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
void incluir_no_final(Lista *lista, int valor){

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

void incluir_no_inicio(Lista *lista, int valor){

    Registro *novo;
    novo = aloca_registro();
    novo->valor = valor;

    if(lista->inicio == NULL){

        lista->inicio = novo;
        lista->final = novo;
    
    }else{

        novo->prox = lista->inicio;
        lista->inicio = novo;
    }


    lista->qtd++;

}

int remover(Lista *lista, int valor){

    if (lista->inicio == NULL){

        return 0;
    
    }

    Registro *auxiliar = NULL, *anterior = NULL;

    auxiliar = lista->inicio;
    
    while (auxiliar != NULL)
    {
        if (auxiliar->valor == valor)
        {
            
            if (anterior == NULL){
            
                lista->inicio = auxiliar->prox;
            
            }else{
            
                anterior->prox = auxiliar->prox;
            
            }

            lista->qtd--;
            free(auxiliar);
            return 1;

        }

        anterior = auxiliar;
        auxiliar = auxiliar->prox;
    
    }

    return 0;

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
void descarta_topo(Lista *lista1,Lista *lista2){

    Registro *aux;
    int valor;
    printf("\nlista1 inicio: ");
    mostrar_lista(lista1);
    aux = lista1->inicio;
    incluir_no_final(lista2,aux->valor);
    //printf("\nLista 2:");
    //mostrar_lista(lista2);
    remover(lista1,aux->valor);
    aux = lista1->inicio;
    incluir_no_final(lista1,aux->valor);
    remover(lista1,aux->valor);
    printf("\nlista1 final: ");
    mostrar_lista(lista1);
}

int main(){

    Lista *lista1,*lista2;
    lista1 = aloca_lista();
    lista2 = aloca_lista();

    int tam,valor;
    printf("Digite um valor: ");
    scanf("%d", &tam);

    for(int i = tam; i >= 1; i--){
        incluir_no_final(lista1, i);
    }
    printf("\nLista 1 pre descarte:");
    mostrar_lista(lista1);
    printf("\nLista 2 pre descarte:");
    mostrar_lista(lista2);
    do{
        descarta_topo(lista1,lista2);

    }while(lista1->qtd > 1);
    printf("\nLista 1:");
    mostrar_lista(lista1);
    printf("\nLista 2:");
    mostrar_lista(lista2);

    printf("\n");
    return 0;

}
