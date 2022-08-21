#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char string[100];
    char vogal[] = "aeiou";
    char vog_cont[100];
    int qtd_vog = 0;
    char letra;

    printf("Digite uma palavra: \n");
    fgets(string,100,stdin);
    
    for(int i = 0;i < strlen(string);i++){
        for (int j = 0;j < strlen(vogal);j++){
            if(string[i] == vogal[j]){
                qtd_vog++;
            }
        }
    }
    printf("A palavra tem %d vogais \n", qtd_vog);

    printf("Digite uma letra:\n");
    scanf("%c", &letra);
    
    for(int i = 0;i < strlen(string);i++){
        for (int j = 0;j < strlen(vogal);j++){
            if(string[i] == vogal[j]){
                string[i] = letra;
            }
        }
    }
    printf("Palavra modificada: %s", string);

    printf("\n");
    return 0;
}