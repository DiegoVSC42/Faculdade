#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char string1[20];
    int tamanho;


    printf("Digite uma palavra de até 20 caracteres:\n");
    scanf("%s", string1);

    tamanho = strlen(string1);

    printf("A frase contem %d caracteres\n", tamanho);

    return 0;
}