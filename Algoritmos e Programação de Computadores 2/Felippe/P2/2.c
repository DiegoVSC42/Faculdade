#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    FILE *arquivo1;
    char arq1[40],palavra[40];
    char comparador[40];
    int contador1 = 0,contador2 = 0;

    printf("Digite o nome do primeiro arquivo: ");
    fgets(arq1,40,stdin);
    arq1[strlen(arq1)-1] = '\0';
    strcat(arq1, ".txt");
    arquivo1 = fopen(arq1, "r");
    
    printf("Digite a palavra a ser procurada: ");
    fgets(palavra,40,stdin);
    palavra[strlen(arq1)-1] = '\0';

    while(!feof(arquivo1)){
        fgets(comparador,40,arquivo1);

        for(int i = 0;i < strlen(comparador);i++){
            if(comparador[i] == palavra[i]){
                contador1++;
            }
        }
    }

    if(contador1 == strlen(palavra)-1){
        printf("A palavra aparece no arquivo %s", arq1);
    }else{
        printf("A palavra nao aparece no arquivo %s", arq1);
    }

    printf("\n");
    return 0;
}