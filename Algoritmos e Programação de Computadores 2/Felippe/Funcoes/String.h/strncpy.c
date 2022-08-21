#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char string1[8];
    char string2[6];

    printf("Digite uma palavra de até 8 caracteres:\n");
    scanf("%s", string1);

    //strncpy (string_destino,string_origem, tamanho)
    strncpy(string2,string1, 5);
   
    string2[5] = '\0';

    printf("Os 5 primeiros caracteres são: %s\n", string2);

    return 0;
}