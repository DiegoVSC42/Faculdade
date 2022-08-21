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

/*void incluir_no_final(Lista *lista, int valor){
    
    Registro *novo;
    novo = aloca_registro();
    novo->valor = valor;

    if(lista->inicio == NULL || lista->fim == NULL){

        lista->inicio = novo;
        lista->fim = novo;

    }else{

        lista->fim->prox = novo;
        novo->ant = lista->fim;
        lista->fim = novo;

    }
    
    lista->qtd++;

}*/

void incluir_ordenado(Lista *lista, int valor){
    
    Registro *novo, *aux = NULL;
    novo = aloca_registro();
    novo->valor = valor;

    if(lista->inicio == NULL || lista->fim == NULL){

        lista->inicio = novo;
        lista->fim = novo;

    }else{

        aux = lista->inicio;
        //Enquanto o aux nao for o ultimo e ele for menor ou igual o novo valor
        while(aux->prox != NULL && aux->valor <= valor){
            //O anterior de aux vai apontar para o valor atual de aux
            aux->ant = aux;
            //aux será incrementado para ver se o proximo valor de aux é menor ou igual ao novo valor
            aux = aux->prox;
        
        }
        //Apos sair do laço ou aux é maior que o novo, ou aux está no final da lista
        //se o valor de aux for maior ou igual que o novo valor 
        if(aux->valor >= valor){
            //verifica se o aux é o primeiro valor da lista
            if(aux->ant == NULL){
                //caso aux seja o primeiro valor da lista, o inicio da lista receberá novo valor
                lista->inicio = novo;

            }else{
                //caso aux nao seja o primeiro valor da lista, o anterior ao valor atual de aux vai apontar para o novo valor
                aux->ant->prox = novo;
            }
            //o proximo do novo valor vai ser aux ja que esse valor é menor que o aux
            novo->prox = aux;
        }else{
            //caso o valor do aux seja o ultimo da lista entao o novo sera adicionado no final
            //ou seja como proximo de aux
            aux->prox = novo;
        
        }
    }

    lista->qtd++;
}
void mostrar_lista(Lista *lista){

    Registro *aux;

    if(lista->inicio == NULL){

        printf("\nLista Vazia");

    }else{
        aux = lista->inicio;

        while (aux != NULL){

            printf("\nValor: %d", aux->valor);
            aux = aux->prox;

        }
    }
    printf("\n");

}

/*int remove_numero(Lista *lista, int valor){

    Registro *aux;

    if(lista->inicio == NULL || lista->fim == NULL){

        printf("\nLista Vazia");
        return 0;
    }
    
    aux = lista->inicio;

    while (aux != NULL){

        if(aux->ant == NULL && aux->prox != NULL && aux->valor == valor){
            
            lista->inicio = aux->prox;
            return 1;

        }
        if(aux->ant != NULL && aux->prox !=NULL && aux->valor == valor){
            
            aux->ant->prox = aux->prox;
            aux->prox->ant = aux->ant;
            return 1;
        }
        if(aux->ant != NULL && aux->prox == NULL && aux->valor == valor){

            aux->ant->prox = NULL;
            return 1;
        }

        aux = aux->prox;
        free(aux);
    }

    return 0;
    
}*/

//Retorna uma terceira lista que contem apenas os valores que as outras duas listas tem em comum
Lista *numeros_comuns(Lista *lista1, Lista *lista2){

    Lista *l;
    l = aloca_lista();
    Registro *aux1 = NULL;
    Registro *aux2 = NULL;
    aux1 = lista1->inicio;
    aux2 = lista2->inicio;

    //enquanto o aux1 nao for o ultimo e aux2 tb nao o laço seguirá
    while (aux1 != NULL && aux2 != NULL){
        
        //se o proximo valor do aux1 nao for o ultimo esse if verificará se a lista ta ordenada
        if (aux1->prox != NULL){
            if (aux1->prox->valor < aux1->valor){

                printf("\n A lista lista1 não esta ordenada");
                return NULL;
            }
        }
        //se o proximo valor do aux2 nao for o ultimo esse if verificará se a lista ta ordenada
        if (aux2->prox != NULL){

            if (aux2->prox->valor < aux2->valor){

                printf("\n A lista lista2 não esta ordenada");
                return NULL;
            
            }
        }
        //se o valor do aux1 for igual ao valor do aux2 entao esse valor sera inserido na 
        //lista 3 e aux1 e aux2 irao para o proximo elemento da lista
        if (aux1->valor == aux2->valor){

            incluir_ordenado(l, aux1->valor);
            aux1 = aux1->prox;
            aux2 = aux2->prox;

        //caso contrario:
        //deve verificar se qual valor é menor
        //caso o valor de aux1 for menor entao aux1 ira para o proximo valor
        //caso o valor de aux2 for menor entao aux2 ira para o proximo valor   
        }else{
    
            if (aux1->valor < aux2->valor)
                aux1 = aux1->prox;
            else
                aux2 = aux2->prox;
        
        }
    }
    return l;
}

//remove todos os valores que sao iguais ao valor inserido
int remover_todos_primos(Lista *lista, int x){

    if (lista->inicio == NULL){

        return 0;
    
    }

    Registro *aux = NULL;

    aux = lista->inicio;
    while (aux != NULL){

        //se o valor de aux for o mesmo do valor inserido
        if (aux->valor == x){

            //verifica se aux é o primeiro valor da lista
            if (aux->ant == NULL){
                
                //caso seja o primeiro da lista entao o inicio da lista "pulará" ele
                lista->inicio = aux->prox;
            
            //caso aux nao seja o primeiro da lista
            }else{
                
                //o anterior a ele apontara para o que vem depois dele, assim fazendo ele ficar fora da lista
                aux->ant->prox = aux->prox;
            
            }
            free(aux);
            lista->qtd--;


            if (aux->ant == NULL)
                aux = lista->inicio;
            else
                aux = aux->ant->prox;
        
        }else{

            aux->ant = aux;
            aux = aux->prox;
        
        }
    }

    return 0;
}

int main(){

    srand(time(NULL));
    int qtd_numero,numero;
    Lista *lista1,*lista2, *lista_comuns;
    Registro *aux;
    
    lista1 = aloca_lista();
    lista2 = aloca_lista(); 

    printf("\nDigite a quantidade de numeros: ");
    scanf("%d", &qtd_numero);
    printf("\n");

    for(int i = 0; i < qtd_numero ; i++){
        numero = rand() % 20;
        printf("\n Incluindo numero %d na lista 1",numero);
        incluir_ordenado(lista1,numero);

    }
    for(int i = 0; i < qtd_numero ; i++){
        numero = rand() % 20;
        printf("\n Incluindo numero %d na lista 2",numero);
        incluir_ordenado(lista2,numero);
    }

    printf("\nLista 1:\n");
    mostrar_lista(lista1);
    printf("\nLista 2:\n");
    mostrar_lista(lista2);
    /*
    lista_comuns = numeros_comuns(lista1,lista2);
    
    printf("\n Numeros em comum: ");
    mostrar_lista(lista_comuns);

    if (lista_comuns!=NULL)
    {
        aux = lista_comuns->inicio;
        while(aux!=NULL)
        {
            remover_todos_primos(lista1,aux->valor);
            remover_todos_primos(lista2,aux->valor);
            aux=aux->prox;
        }
    }

    printf("\nListas apos remocao:\n");
    printf("\nLista 1:\n");
    mostrar_lista(lista1);
    printf("\nLista 2:\n");
    mostrar_lista(lista2);

    */
    printf("\n");
    return 0;
}