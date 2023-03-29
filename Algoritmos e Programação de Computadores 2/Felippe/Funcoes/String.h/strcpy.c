#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char nome[50];
    char nome_rec[50];

    printf("Digite o nome a ser copiado");
    scanf("%s", nome_rec);

    strcpy(nome, nome_rec);


}