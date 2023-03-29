#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    
    FILE *arq1, *arq2;
    int contador_B = 0;
    char B;
    char linha[300];
    char nome1[300],nome2[300];
    int contador1 = 0, contador2 = 0;

    printf("Digite o nome do arquivo 1: ");
    fgets(nome1,300,stdin);
    nome1[strlen(nome1)-1] = '\0';
    strcat(nome1,".txt");
    printf("Digite o nome do arquivo 2: ");
    fgets(nome2,300,stdin);
    nome2[strlen(nome2)-1] = '\0';
    strcat(nome2,".txt");

    arq1 = fopen(nome1, "r");

    if (arq1 == NULL){
    
        printf("\n Problemas na abertura do arquivo");
    
    }else{

        while(!feof(arq1)){

            fgets(linha,300,arq1);
            contador1++;
        }  
    }

    arq2 = fopen(nome2, "r");

    if (arq2 == NULL){
    
        printf("\n Problemas na abertura do arquivo");
    
    }else{

        while(!feof(arq2)){

            fgets(linha,300,arq2);
            contador2++;
        }  
    }

    if(contador1 > contador2){
        printf("O arq1 e maior que o arq2");
    }
    if(contador2 > contador1){
        printf("O arq2 e maior que o arq1");
    }
    if(contador1 == contador2){
        printf("O arq1 possui a mesma quantidade de linhas de arq2");
    }

    printf("\n");
    return 0;
}