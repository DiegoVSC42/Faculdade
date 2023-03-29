#include <stdio.h>
#include <stdlib.h>

typedef struct Lista
{
    int qtd;
    struct Registro *inicio;

}Lista;

typedef struct Registro{

    int valor;
    struct Registro *prox;

}Registro;

Lista *aloca_lista(){

    Lista *novo;
    novo = (Lista *)calloc(1,sizeof(Lista));
    return novo;

}

Registro *aloca_registro(){
    
    Registro *novo;
    novo = (Registro *)calloc(1,sizeof(Registro));
    return novo;

}

void incluir(Lista *lista, int valor){

    Registro *novo, *aux;
    novo = aloca_registro();
    novo->valor = valor;

    if (lista->inicio == NULL){

        lista->inicio = novo;
    
    }else{

        aux = lista->inicio;
        
        while (aux->prox != NULL){

            aux = aux->prox;
        
        }
        aux->prox = novo;
    }

    lista->qtd++;
}

void QuickSort(int *vetor, int inicio, int fim){
        
    int i,j;
    int pivo,aux;
    i = inicio;
    j = fim;
    pivo = vetor [(inicio+fim)/2 ];

    do{
        while(vetor[i] < pivo && i < fim){
            i++;
        }
        while(pivo < vetor[j] && j > inicio){
            j--;
        }
        if(i <= j){
            aux = vetor[i];         
            vetor[i] = vetor[j];
            vetor[j] = aux;
            i++;
            j--; 
        }
    }while(i <= j);

    if(inicio < j ){
    
        QuickSort(vetor, inicio, j);
    
    }
    if(i < fim ){

        QuickSort(vetor, i, fim);
    
    }
    return ;
}
int *vetor_ordenado(Lista *lista){

    Registro *aux;
    aux = lista->inicio;
    int *vetor;
    vetor = (int*)calloc(lista->qtd,sizeof(int));
    
    int i = 0;
    while(aux != NULL){

        vetor[i] = aux->valor;
        i++;
        aux = aux->prox;

    }
    printf("\nVetor antes de ordenar:\n ");
    for(int i = 0;i < lista->qtd; i++){
    
        printf("%d\t",vetor[i]);
    
    }
    QuickSort(vetor,0,lista->qtd-1);
    
    return vetor;

}

int main(){

  Lista *lista;
  lista = aloca_lista();
  int valor,qtd_valores;

  printf("\nDigite a quantidade de valores: ");
  scanf("%d", &qtd_valores);
  printf("\nDigite os valores: ");
  
  int *vetor;

  for(int i = 0; i < qtd_valores; i++){

    printf("\nValor: ");
    scanf("%d", &valor);
    incluir(lista,valor);

  }
  vetor = (int*)calloc(qtd_valores,sizeof(int));
  vetor = vetor_ordenado(lista);
  printf("\nVetor Ordenado:\n ");
  for(int i = 0;i < qtd_valores; i++){
  
    printf("%d\t",vetor[i]);
  
  }
  printf("\n");
  return 0;
}