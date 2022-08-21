#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Mercadoria{

    char nome[30];
    float valor_total;
    char porc_desc[100];
    float valor_desc;
    float valor_avista;


}   Mercadoria;

int main(){
    
    Mercadoria mercadoria;
    
    printf("Digite o nome da mercadoria \n");
    fgets(mercadoria.nome,30,stdin);
    printf("Digite o valor da mercadoria \n");
    scanf("%f", &mercadoria.valor_total);

    mercadoria.valor_desc = mercadoria.valor_total*0.1;
    mercadoria.valor_avista= mercadoria.valor_total - mercadoria.valor_desc;

    printf("\n");
    printf("Nome da mercadoria: %s\n", mercadoria.nome);
    printf("Valor total da mercadoria: %.2f\n", mercadoria.valor_total);
    printf("O desconto foi de: %.2f\n", mercadoria.valor_desc);
    printf("Valor avista: %.2f\n", mercadoria.valor_avista);


    printf("\n");
    return 0;
}