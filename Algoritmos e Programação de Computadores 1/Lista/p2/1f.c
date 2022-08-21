//f. Receba uma palavra e mostre-a em ordem inversa.

#include<stdio.h>

int main (int argc, char const *argv[]){

    int qtd_numeros,aux,numero;
    int tamanho = 0;
    char palavra[100];
    char palavra_inv[100];
    int qtd_letras = 0;

    scanf("%s", &palavra);

    while(palavra[qtd_letras] != '\0'){
        qtd_letras++;
    }
    int i = 0;
    while(palavra[i] != '\0'){
        palavra_inv[qtd_letras] = palavra[i];
        qtd_letras--;
        i++;
    }

    printf ("%s", palavra_inv);

    printf("\n");

    
    return 0;

}