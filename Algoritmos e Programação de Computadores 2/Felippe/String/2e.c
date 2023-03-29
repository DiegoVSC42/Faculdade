#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char string1[100];
    char string2[100];
    int retorno = 0;

    printf("Digite a string 1:");
    fgets(string1,100,stdin);
    printf("Digite a string 2:");
    fgets(string2,100,stdin);

    retorno = strcmp(string1, string2);

    if(retorno > 0){
        printf("A string 2 vem primeiro\n");
    }
    if(retorno <0){
        printf("A string 1 vem primeiro\n");
    }
    if(retorno == 0){
        printf("As strings sao iguais\n");
    }

    printf("\n");
    return 0;
}