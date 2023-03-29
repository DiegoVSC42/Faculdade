#include <stdio.h>

float produtorio(int valor_inicial, int valor_final){
    float resultado_numerador = 0, resultado_denominador = 0, resultado_final = 0;
    for(int i = valor_inicial;i <= valor_final;i++ ){
        for(int i = valor_inicial;i <= valor_final;i++ ){
            resultado_numerador = -1*i*i-4;
            resultado_denominador = i + 3;
            resultado_final = resultado_numerador / resultado_denominador;
        }
    }
    return resultado_final;
}

int main(int argc, char const *argv[]){

    int valor_inicial, valor_final;
    float resultado_final;
    
    scanf("%d %d",&valor_inicial, &valor_final);

    resultado_final = produtorio(valor_inicial,valor_final);
    printf("%f", resultado_final);

    return 0;
}