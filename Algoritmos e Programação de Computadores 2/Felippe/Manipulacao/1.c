#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    
    FILE *arq;
    char nome[30];
    char aux[30];
    char vogais[] = "aeiouAEIOU";
    char vog;


    fgets(nome,30,stdin);

    for(int i = 0; i < strlen((nome)-1);i++){
        aux[i] = nome[i];
    }

    nome[strlen(nome)-1] = '\0';
    strcat(nome,".txt");
    
    arq = fopen(nome, "w");
    
    if (arq == NULL){
        printf("\n Problemas na abertura do arquivo");
    }else{

        for(int i = 0; i <strlen((aux));i++){
           for(int j = 0; j < strlen(vogais);j++){
               if(aux[i] == vogais[j]){
                    fprintf(arq,"%c",aux[i]);
               }
           }
        }
    }
    
    
    fclose(arq);


    printf("\n");
    return 0;
}