#include <stdio.h>

int main(int argc, char const *argv[]){

    char amigos_serginho[100000];
    
    scanf("%s", amigos_serginho);

    int qtd_letras = 0;
    while(amigos_serginho[qtd_letras] !='\0'){
        qtd_letras++;
    }
    printf("%d", qtd_letras);

    return 0;
}