#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char string1[10];
    char string2[10];
    int opcao;


    printf("Digite uma palavra de até 10 caracteres:\n");
    scanf("%s", string1);

    printf("Digite outra palavra de ate 10 caracteres:\n");
    scanf("%s", string2);

    opcao = strcmp(string1, string2);

    if(opcao == 0){
        
        printf("As strings sao iguais\n");
    }else if(opcao > 0){
        printf("A primeira palavra e %d x maior que a segunda\n",opcao);
    }else if(opcao < 0){
        printf("A segunda palavra e %d x menor que a primeira\n", opcao);
    }

    return 0;
}