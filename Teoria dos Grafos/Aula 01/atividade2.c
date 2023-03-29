#include <stdio.h>

int main(void) {
    int N, a, b;
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

    printf("Digite a quantidade de pares:");
    scanf("%d", &N);
    int auxA[N], auxB[N];
    printf("Digite os pares:\n");
    for(int i = 0; i < N; i++){
        printf("Par %d: ", i+1);
        scanf("%d %d",&a,&b);
        auxA[i] = a;
        auxB[i] = b;
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
        printf("\n");
        for(int k = 0; k < 10;k++){
            if(matriz[j][k] != 0 && matriz[j][1] != 0){
                if(matriz[j][k+1] == 0)
                    printf("%d", matriz[j][k]);                
                else{
                    printf("%d -> ", matriz[j][k]);
                }
            }
        }
        
    }

    return 0;
}