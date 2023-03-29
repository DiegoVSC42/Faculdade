#include <stdio.h>

int main(void) {
    int N, a, b;
    int matriz[10][10];

    for(int j = 0 ; j < 10; j++){
        for(int k = 0; k < 10;k++){
            matriz[j][k] = 0;
        }
    }

    printf("Digite a quantidade de pares:");
    scanf("%d", &N);
    printf("Digite os pares:\n");

    for(int i = 0; i < N; i++){
        printf("Par %d: ", i+1);
        scanf("%d %d",&a,&b);
        matriz[a-1][b-1] = 1;
    }

    printf("\nMatriz Adjascente\n");
    for(int j = 0 ; j < 10; j++){
        printf("%d -> ", j + 1);
        for(int k = 0; k < 10;k++){
            int cont = 0;
            printf("%d ", matriz[j][k]);
        }
        printf("\n");
    }



    return 0;
}