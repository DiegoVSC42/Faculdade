/*
2) Faça um programa que apresente o9 seguinte menu para o usuário:
    1 - incluir carro
    2 - procurar carro
    3 - remover carro pelo chassi
    4 - mostrar carro mais velho
    5 - mostrar carro mais caro
    obs. Informações de um veículo: marca, modelo, chassi, ano, preco;
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

    char marca[30];
    char modelo[30];
    long int chassi;
    int ano;
    double preco;
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

void inserir_carro(Lista *lista){

    Registro *novo;
    novo = aloca_registro();
    /*printf("Digite a marca do carro: ");
    fflush(stdin);
    fgets(novo->marca,29,stdin);
    printf("Digite o modelo do carro: ");
    fflush(stdin);
    fgets(novo->modelo,29,stdin);*/
    printf("Digite o numero de chassi do carro: ");
    scanf("%ld", &novo->chassi);
    printf("Digite o ano do carro: ");
    scanf("%d", &novo->ano);
    printf("Digite o preco do carro: ");
    scanf("%lf", &novo->preco);

    if(lista->inicio == NULL && lista->fim == NULL){

        lista->fim = novo;
        lista->inicio = novo;

    }else{
        lista->fim->prox = novo;
        novo->ant = lista->fim;
        lista->fim = novo;
    }
    lista->qtd++;
}

int remover_carro_chassi(Lista *lista, int valor){

    Registro *aux;

    if(lista->inicio == NULL){
        return 0;
    }
    aux = lista->inicio;
    while(aux != NULL){

        if(aux->chassi == valor){
            
            if(aux->ant == NULL){
               
                lista->inicio = aux->prox;
           
            }else{
                
                aux->ant->prox = aux->prox;

            }
            
        }
        aux = aux->prox;
    }
    free(aux);
    lista->qtd--;
    return 1;

}
void mostrar_carro_antigo(Lista *lista){

    Registro *aux;
    int velho = 3000;
    if(lista->inicio == NULL){
        return;
    }
    aux = lista->inicio;

    while(aux != NULL){

        if(velho > aux->ano){
            velho = aux->ano;
        }

        aux = aux->prox;
    }
    aux = lista->inicio;
    while(aux != NULL){

        if(aux->ano == velho){
            printf("\nCarro mais velho: %d", aux->chassi);
        }
        aux = aux->prox;
    }
}
void mostrar_carro_caro(Lista *lista){

    Registro *aux;
    double caro = 0;
    if(lista->inicio == NULL){
        return;
    }
    aux = lista->inicio;

    while(aux != NULL){

        if(caro < aux->preco){
            caro = aux->preco;
        }

        aux = aux->prox;
    }
    aux = lista->inicio;
    while(aux != NULL){

        if(aux->preco == caro){
            printf("\nCarro mais caro: %d", aux->chassi);
        }
        aux = aux->prox;
    }
}
void mostrar_lista(Lista *lista){

    Registro *aux;
    if(lista->inicio == NULL && lista->fim == NULL){
        printf("\nLista vazia");
        return;
    }
    aux = lista->inicio;

    while(aux != NULL){
        printf("\nValor: %d", aux->chassi);
        aux = aux->prox;
    }
    printf("\n");
}
void menu(Lista *lista){
    
    int opcao,chassi;
    
    do{
        
        printf("\nEscolha uma opcao:");
        printf("\n1 - Incluir carro");
        printf("\n2 - Remover carro pelo chassi");
        printf("\n3 - Mostrar carro mais antigo");
        printf("\n4 - Mostrar carro mais caro");
        printf("\n5 - Sair");
        printf("\nOpcao: ");
        scanf("%d", &opcao);

        switch (opcao){

            case 1:
                printf("\n");
                inserir_carro(lista);
                break;
            case 2:
                printf("\n");
                printf("Digite o numero de chassi do carro que sera removido: ");
                scanf("%d", &chassi);
                if(!remover_carro_chassi(lista,chassi)){
                    printf("\nCarro nao removido ou lista vazia");
                }else{
                    printf("\nCarro removido com sucesso");
                }
                break;
            case 3:
                printf("\n");
                mostrar_carro_antigo(lista);
                break;
            case 4:
                mostrar_carro_caro(lista);
                printf("\n");
                break;
            case 5:
                printf("\nSaindo do programa");
                break;  
            default:
                printf("\nOpcao invalida");
                break;
        }
    }while (opcao != 5);

}

int main(){

    Lista *lista;
    lista = aloca_lista();

    menu(lista);
    printf("\n");
    return 0;
}