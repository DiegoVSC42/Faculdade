#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char nome1[30];
    char nome2[30];
    int tam1;
    int cont1 = 0;
    int tam2;
    int cont2;

    fgets(nome1,30,stdin);
    fgets(nome2,30,stdin);
    tam1 = strlen(nome1);
    tam2 = strlen(nome2);
    for(int i = 0; i < tam1;i++){
        if(tam1 == tam2){
            if(nome1[i] == nome2[i]){
                cont1++;
            }
        }
    }

    if(cont1 == tam2){
        printf("iguais\n");
    }
}