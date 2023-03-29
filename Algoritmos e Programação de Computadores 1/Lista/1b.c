#include<stdio.h>

int main (int argc, char const *argv[]){

    int qtd_dias, qtd_anos = 360,qtd_meses = 30,resultado_1,resultado_2;

    scanf("%d", &qtd_dias);

    resultado_1 = qtd_dias / qtd_anos;
    
    printf("%d ano(s)\t", resultado_1);
    
    resultado_1 = 1;
    
    resultado_2 = qtd_dias / qtd_meses;
    
    printf("%d mes(es)\t",resultado_2);
    
    resultado_2 = 1;
    
    printf("%d dia(s)\t", qtd_dias);
    
    printf("\n");

    return 0;

}