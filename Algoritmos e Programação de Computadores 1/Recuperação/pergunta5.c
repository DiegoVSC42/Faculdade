#include <stdio.h>

int main(int argc, char const *argv[]){

    int numero_informado, soma = 0, valor_indice, valor_base_dez;

    scanf("%d", &numero_informado);

    for (int indice = 15; indice >= 0; indice -= 1){
        
        int potencia = 1;
        
        for (int i = 0; i < indice; i += 1){
            potencia *= 2;
        }
        
        valor_base_dez = 0;

        for(valor_indice = 1; valor_indice < 16; valor_indice += 1){
            valor_base_dez = valor_indice * potencia;
            if (valor_base_dez + soma > numero_informado) {
                valor_indice -= 1;
                break;
            }
        }
        if(valor_indice > 2){
            valor_indice -= 1;
        }
        valor_base_dez = valor_indice * potencia;
        soma += valor_base_dez;
        printf("%d", valor_indice);

    }
    printf("\n");

    return 0;
}