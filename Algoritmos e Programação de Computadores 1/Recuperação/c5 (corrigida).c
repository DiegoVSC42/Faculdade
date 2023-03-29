#include<stdio.h>

int main(int argc, char const *argv[]){
    
    int numero, soma = 0;

    scanf("%d", &numero);

    for(int algarismo = 2; algarismo >= 0; algarismo--){
        int potencia = 1;
        
        for(int i = 0; i < algarismo; i++){
            potencia *= 3;
        }
        
        int valor_decimal = 0, valor_algarismo;

        for(valor_algarismo = 1; valor_algarismo < 3; valor_algarismo++){
            valor_decimal = valor_algarismo * potencia;
            if(valor_decimal + soma > numero){
                valor_algarismo -= 1;
                break;
            }
        }
    
        if(valor_algarismo > 2){
            valor_algarismo -= 1;
    
        }
    
        valor_decimal = valor_algarismo * potencia;soma += valor_decimal;
    
        printf("%d", valor_algarismo);
    
    }
    
    printf("\n");
    
    return 0;
}
