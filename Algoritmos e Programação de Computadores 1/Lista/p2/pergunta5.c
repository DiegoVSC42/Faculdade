#include<stdio.h>

int main (int argc, char const *argv[]){

    int qtd_produtos;
    float valor_produto;
    float produto_invertido[1000];

    scanf("%d", &qtd_produtos);

    for(int i = 0;i < qtd_produtos;i++){
        scanf("%f", &valor_produto);
    }
    for(int i = 0; i < qtd_produtos ;i++){
        produto_invertido[i] = valor_produto;
        printf("%.2f", produto_invertido[i]);
    }
    return 0;
}