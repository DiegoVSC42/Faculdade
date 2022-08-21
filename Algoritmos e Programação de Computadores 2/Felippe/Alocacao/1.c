#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *uniao(int *x1, int *x2, int n1, int n2, int *qtd){

    int *x3;
    int tam = 0;
    int n3 = 0;
    int n4 = 0;

    for(int i = 0; i < n1; i++){
        for(int j = 0; j < n2; j++){
            if(x1[i] == x2[j]){
                tam++;
            }
        }
    }

    *qtd = ((n1 - tam) + (n2 - tam) + tam);

    x3 = (int*) malloc(*qtd * sizeof(int));
    
    for(int i = 0; i < n1; i++){
        for(int j = 0; j < n2; j++){
            if(x1[i] == x2[j]){
                x3[n3]=x1[i];
                n3++;
            }
        }
    }

    for(int i = 0; i < n1; i++){
        n4 = 0;
        for(int j = 0; j < n2; j++){
            if(x1[i] == x2[j]){
                n4++;
            }
        }
        if(n4 == 0){
            x3[n3] = x1[i];
            n3++;
        }
    }
    for(int i = 0; i < n2; i++){
        n4 = 0;
        for(int j = 0; j < n1; j++){
            if(x2[i] == x1[j]){
                n4++;
            }
        }
        if(n4 == 0){
            x3[n3] = x2[i];
            n3++;
        }
    }


    return x3;
}

int main(){

    int tamanho;
    int *x1;
    int *x2;
    int n1;
    int n2;
    int *x3;
    int qtd;
    int tam;

    //*qtd = (int*)malloc(sizeof(int));
    
    printf("Digite o tamanho de n1: ");
    scanf("%d", &n1);
    
    x1 = (int*) malloc(n1 * sizeof(int));

    for(int i = 0;i < n1;i++){
        
        printf("Digite o valor de n1 no indice %d: ", i+1);
        scanf("%d", &x1[i]);    

    }

    printf("Digite o tamanho de n2: ");
    scanf("%d", &n2);

    x2 = (int*) malloc(n2 * sizeof(int));

    for(int i = 0;i < n2;i++){
        
        printf("Digite o valor de n2 no indice %d: ",i+1);
        
        scanf("%d", &x2[i]);    

    }

    x3 = uniao(x1, x2, n1, n2, &qtd);
    
    /*printf("QTD : %d", qtd);
    printf("X3: ");
    */
	int aux, i, j;

    for(j=qtd-1; j>=1; j--){
		for(i=0; i<j; i++){
			if(x3[i]>x3[i+1]){
				aux=x3[i];
                    x3[i]=x3[i+1];
                    x3[i+1]=aux;
            }
        }
    }
    for(int i = 0; i < qtd;i++){
        printf("%d ", x3[i]);
    }

    printf("\n");
    return 0;
}