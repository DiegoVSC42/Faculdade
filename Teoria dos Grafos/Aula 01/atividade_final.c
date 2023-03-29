#include <stdio.h>

int main() {
    int N, a, b;
    int matriz_A[10][10];

    for(int j = 0 ; j < 10; j++){
        for(int k = 0; k < 10;k++){
            matriz_A[j][k] = 0;
        }
    }

    printf("Digite a quantidade de pares:");
    scanf("%d", &N);
    printf("Digite os pares:\n");
    int auxA[N], auxB[N];
    for(int i = 0; i < N; i++){
        printf("Par %d: ", i+1);
        scanf("%d %d",&a,&b);
        matriz_A[a-1][b-1] = 1;
        auxA[i] = a;
        auxB[i] = b;
    }

    printf("\nMatriz Adjascente\n");
    for(int j = 0 ; j < 10; j++){
        printf("%d -> ", j + 1);
        for(int k = 0; k < 10;k++){
            int cont = 0;
            printf("%d ", matriz_A[j][k]);
        }
        printf("\n");
    }
    
    // PARTE 2

    int matriz[10][10];
    int cont = 1;
    int aux;

    for(int j = 0 ; j < 10; j++){
        for(int k = 0; k < 10;k++){
            if(k == 0){
                matriz[j][k] = j+1;
            }else{
                matriz[j][k] = 0;
            }
        }
    }

    for(int j = 0; j < 10 ;j++){
        cont = 1;
        aux = 0;
        for(int k = 0 ; k < N; k++){

            if(matriz[j][0] == auxA[k]){

                if(matriz[j][cont] == 0){
                    for(int i = 1;i < 10 ; i++){
                        if(matriz[j][i] == auxB[k]){
                            aux++;            
                        }
                    }
                    if(aux == 0){
                        matriz[j][cont] = auxB[k];
                        cont++;
                    }

                }
            }
            if(matriz[j][0] == auxB[k]){

                if(matriz[j][cont] == 0){
                    for(int i = 1;i < 10 ; i++){
                        if(matriz[j][i] == auxA[k]){
                            aux++;            
                        }
                    }
                    if(aux == 0){
                        matriz[j][cont] = auxA[k];
                        cont++;
                    }

                }
            }
        }
    }
    printf("\nLista Adjascente\n");
    for(int j = 0 ; j < 10; j++){
        
        for(int k = 0; k < 10;k++){
            if(matriz[j][k] != 0 && matriz[j][1] != 0){
                if(matriz[j][k+1] == 0)
                    printf("%d", matriz[j][k]);                
                else{
                    printf("%d -> ", matriz[j][k]);
                }
            }
        }
        printf("\n");
    }

    return 0;
}