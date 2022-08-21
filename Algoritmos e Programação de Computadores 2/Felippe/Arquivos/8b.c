#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    
    FILE *arq1, *arq2;
    char caractere;
    char vogal[] = "aeiouAEIOU";
    char string[30000];

    arq1 = fopen("teste.txt","r");
    arq2 = fopen("teste2.txt","w");

    if(arq1 == NULL){
        printf("Deu ruim \n");
        return 0;
    }

    while(fgets(string,30000,arq1)!= NULL){
        
        for(int j = 0; j < strlen(string);j++){
            for(int i = 0;i < strlen(vogal);i++){
                if(string[j] == vogal[i]){
                    string[j] = '*';
                }
            }
        }
        fprintf(arq2,string);
    }
    fclose(arq1);
    fclose(arq2);

    printf("\n");
    return 0;
}