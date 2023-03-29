#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char string1[20];
    char string2[10];



    printf("Digite uma palavra de até 20 caracteres:\n");
    scanf("%s", string1);

    printf("Digite uma palavra que se juntará a anterior:\n");
    scanf("%s", string2);

    strncat(string1, string2, 5);

    printf("A frase e: %s\n", string1);

    return 0;
}