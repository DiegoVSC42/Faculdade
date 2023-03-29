#include <stdlib.h>
#include <stdio.h>

int main(){

    int N = 0;
    int contador_primeiro = 0;
    int primeiro;
    int contador_segundo =0;
    int segundo;
    do{

        printf("\nDigite um numero natural: ");
        scanf("%d", &N);
    
    }while (N <= 4);


    /*for(int i = 1; i <= N;i++){
        if(N % i == 0){
            contador++;
        }
    }*/
    
    for(int i = 1;i <= primeiro;i++){
        if(primeiro % i == 0){
            contador_primeiro++;
        }
    }
    if(contador_primeiro < 2){
        for(int i = 1;i <= primeiro;i++){
            if(segundo % i == 0){
                contador_segundo++;
            }
        }
    }
    if(primeiro + segundo == N){
        printf("%d + %d = %d", primeiro, segundo, N);
    }
    
    return 0;

}