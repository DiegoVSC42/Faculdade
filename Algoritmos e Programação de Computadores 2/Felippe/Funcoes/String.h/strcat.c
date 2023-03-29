#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char string1[10];
    char string2[10];



    printf("Digite uma palavra de até 10 caracteres:\n");
    scanf("%s", string1);

    printf("Digite uma palavra que se juntará a anterior:\n");
    scanf("%s", string2);

    strcat(string1, string2);

    printf("A frase e: %s\n", string1);

    return 0;
}