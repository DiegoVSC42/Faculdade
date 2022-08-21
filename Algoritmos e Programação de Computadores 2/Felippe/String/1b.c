#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char string[10];
    int tamanho;
    char aux;

    fgets(string,10,stdin);

    tamanho = strlen (string);
    for(int i = tamanho - 2;i >= 0; i--){
        printf("%c", string[i]);
    }

    printf("\n");
    return 0;
}