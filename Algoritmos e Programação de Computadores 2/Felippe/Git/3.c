#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char digito[30];
    int tamanho;
    int cont_dig = 0;


    fgets(digito,30,stdin);
    tamanho = strlen (digito);
    for(int i = 0;i < 30;i++){
        if(digito[i] == '1'){
            cont_dig++;
        }
    }
    printf("%d", cont_dig);

}   