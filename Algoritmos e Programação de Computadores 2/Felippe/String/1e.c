#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char string[100];
    int contador = 0;

    fgets(string,100,stdin);
    for(int i = 0; i < strlen(string);i++){
        if(string[i] == ' '){
            contador++;
        }
    }
    printf("%d", contador);
    printf("\n");
    return 0;
}