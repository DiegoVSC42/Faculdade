#include <stdio.h>

int main(int argc, char const *argv[]){
    
    int m, n, qtd_elementos,i = 0,letorianos = 0;
    char numero;

    scanf("%d%d", &m, &n);
    char matriz[m][n];
    qtd_elementos = m * n;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            scanf(" %c", &numero); 
            matriz[i][j] = numero;
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(matriz[i][j] == '1'){
                letorianos++;
            }
        }
    }
    printf("%d", letorianos);

    return 0;
}