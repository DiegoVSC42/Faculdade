#include <stdio.h>
#include <stdlib.h>

typedef struct Lista
{
    int qtd;
    struct Registro * inicio;
    
}Lista;

typedef struct Registro{

    int valor;
    struct Registro * proximo;

}Registro;

Lista *aloca_lista(){

    Lista *novo;
    novo = (Lista*)malloc(sizeof(Lista));
    novo->qtd = 0;
    novo->inicio = NULL;
    return novo;

}
Registro * aloca_registro(){
    
    Registro *novo;
    novo = (Registro*)malloc(sizeof(Registro));
    novo->valor = 0;
    novo->proximo = NULL;
    return novo;

}

void incluir_na_lista(Lista *lista, int valor){
    
    Registro *novo,*auxiliar;
    novo = aloca_registro();
    novo->valor = valor;

    if(lista->inicio == NULL){
        lista->inicio = novo;
    }else{
        auxiliar = lista->inicio;
        while(auxiliar->proximo != NULL){
            auxiliar = auxiliar->proximo;
        }
        auxiliar->proximo = novo;
    }
    
    lista->qtd++;

}
void mostrar_lista(Lista * lista)
{
    Registro * auxiliar;

    if (lista->inicio==NULL)
    {
        printf("\n lista vazia");
    }  
    else
    {
        auxiliar = lista->inicio;

        while(auxiliar != NULL)
        {
            printf("\n Valor: %d",auxiliar->valor);
            auxiliar = auxiliar->proximo;
        }
    }
    printf("\n");
}


int main(){ 

    int opcao,valor;
    Lista *lista;
    lista = aloca_lista();



    do{
        
        printf("\nEscolha uma das opcoes \n");
        printf("1 - Incluir na lista\n");
        printf("2 - Mostrar lista\n");
        printf("3 - Mostrar pares da lista\n");
        printf("0 - Finalizar programa\n");

        scanf("%d", &opcao);

        if(opcao == 1){
            printf("Digite um valor que sera incluido na lista: ");
            scanf("%d", &valor);
            incluir_na_lista(lista,valor);
        }
        if(opcao == 2){
            mostrar_lista(lista);
        }
        if(opcao == 3){
            for(int i = 0; i < lista->qtd ; i++){
                printf("\nEntrei\n");
                if(lista[i].inicio->valor % 2 == 0){
                    printf("Valores pares: %d", &lista[i].inicio->valor);
                }
            }
        }

    }while (opcao != 0);    

    printf("\n");
    return 0;
}