#include <stdio.h>

float produtorio(int valor_inicial, int valor_final){
    float resultado_numerador = 0, resultado_denominador = 0, resultado_final = 0;
    
    if(valor_inicial == valor_final){
        return 1;
    }else{
        resultado_final = valor_inicial * produtorio(valor_final - 1);
        return resultado_final;
    }
}


int main(int argc, char const *argv[]){

    int valor_inicial, valor_final;
    float resultado_final;
    
    scanf("%d %d",&valor_inicial, &valor_final);

    resultado_final = produtorio(valor_inicial,valor_final);
    printf("%f", resultado_final);

    return 0;
}