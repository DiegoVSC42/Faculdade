#include <stdio.h>
#include <stdlib.h>

int main(){

    int aux, i, j;
    int tamanho;
    int *vetor;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    vetor = (int*) malloc(tamanho * sizeof(int)); 

    for(int i = 0;i < tamanho;i++){
        
        printf("Digite o vetor no indice %d: ", i+1);
        scanf("%d", &vetor[i]);

    }
    for(j=tamanho-1; j>=1; j--){
		for(i=0; i<j; i++){
			if(vetor[i]>vetor[i+1]){
				aux=vetor[i];
                    vetor[i]=vetor[i+1];
                    vetor[i+1]=aux;
            }
        }
    }
    
    for(int i = 0;i < tamanho;i++){
        printf("%d ", vetor[i]);
    }

    printf("\n");
    return 0;
}