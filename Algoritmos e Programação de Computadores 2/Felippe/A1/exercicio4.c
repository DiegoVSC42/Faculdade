#include<stdio.h>
#include<stdlib.h>

int main (){

    int N1;
    int N2;
    int resultado = 0;

    printf("\nDigite os valores de N1 e N2: ");
    scanf("%d %d", &N1, &N2);

    if(N1 < N2){
        for(int i = N1; i < N2 ; i++){
            resultado = 0; 
            for(int j = 2; j <= i;j++) {
                if(i % j == 0){
                    resultado++;
                }
            }
            if (resultado < 2){
                printf("%d\t", i);
            }
            
        }
    }
    if(N2 < N1){
        for(int i = N2; i < N1 ; i++){
            resultado = 0; 
            for(int j = 2; j <= i;j++) {
                if(i % j == 0){
                    resultado++;
                }
            }
            if (resultado < 2){
                printf("%d\t", i);
            }
            
        }
    }

}