#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int le_elemento(int *vetor,int qtd_elementos){

    for(int i = 0;i < qtd_elementos;i++){
        printf("Digite o elemento %d do vetor:", i+1);    
        scanf("%d", &vetor[i]);
    }        
}


int main(){

    int *vetor;
    int qtd_elementos;
    int tamanho,tamanho_int;
    char string[100] = "JoaoCusao";

    printf("Digite a quantidade de elementos do vetor: ");
    scanf("%d", &qtd_elementos);
    
    fflush(stdin);

    vetor = (int*) malloc(qtd_elementos * sizeof(int));

    le_elemento(vetor,qtd_elementos);
    
    printf("Vetor = ");
    for(int i = 0;i < qtd_elementos;i++){
        printf("%d ", vetor[i]);
    }

    putchar('\n'); /* == printf("\n");*/

    free(vetor);

    return 0;
}