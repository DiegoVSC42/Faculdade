#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    
    char string[100];
    int tamanho = 0;

    fgets(string,100,stdin);
    tamanho = strlen(string);

    for(int i = 0; i < tamanho;i++){
        if(string[i] == '0'){
            string[i] = '1';
        }
    }
    printf("%s\n", string);
    return 0;
}