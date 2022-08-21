#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char string[100];
    int tamanho_s,tamanho_v,i,j;
    char vogal[] = "aeiouAEIOU";


    tamanho_v = strlen(vogal);
    fgets(string,100,stdin);
    tamanho_s = strlen (string) - 2;

    for(i = 0;i < tamanho_s;i++){
        
        for(j = 0;j < tamanho_v;j++){
            
            if(string[i] == vogal[j]){
                break;
            }

        }
        if (j == tamanho_v){
            printf("%c", string[i]);
        }


    }
    printf("\n");
    return 0;
}