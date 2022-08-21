#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int qtd;
    struct registro * inicio;
    
}lista;

typedef struct registro
{
    int valor;
    struct registro * prox;

}registro;

int main(){

    struct registro *valor;
    struct registro *inicio = valor;
    int qtd_valores;

    printf("Digite a quantidade de valores da lista:  ");
    scanf("%d", &qtd_valores);

    valor = (registro*)malloc(sizeof(registro)*qtd_valores);

    for(int i = 0 ; i < qtd_valores ; i++){
        valor[i].valor = i;
        if(i != qtd_valores){
            valor[i].prox = &valor[i+1]
;
        }else{
            valor[i].prox = (struct registro *)0;
        }
    }

    for(int i = 0 ; i < qtd_valores ; i++){

        printf("%d\n", valor[i].valor);

    }
    /*
    valor1.valor = 1;
    valor2.valor = 2;
    valor3.valor = 3;

    valor1.prox = &valor2;
    valor2.prox = &valor3;
    valor3.prox = (struct registro *)0;
    
    while(inicio != (struct registro*)0){
        printf("%d\n", inicio->valor);
        inicio = inicio ->prox;
    }
    */

    printf("\n");
    return 0;

}