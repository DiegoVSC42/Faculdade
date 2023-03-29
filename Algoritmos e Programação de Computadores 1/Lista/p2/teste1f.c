//f. Receba uma palavra e mostre-a em ordem inversa.

#include<stdio.h>

int main (int argc, char const *argv[]){

    char palavra[46];
    int qtd_letras = 0;

    scanf("%s", palavra);
    
    while(palavra[qtd_letras] != '\0'){
        qtd_letras++;
    }
    int i = qtd_letras;

    while(i >= 0){
        printf("%c", palavra[i]);
        i--;
    }
    printf("\n");
    return 0;

}