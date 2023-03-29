#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char const *argv[]){
    char nome[50];
    int tamanho;
    scanf("%s", &nome);

    tamanho = strlen(nome);
    printf("%d", tamanho);
    /*for(int i = 0; i < 100000; i++){
        if (palavra[i] == 'a' || palavra[i] == 'e' || palavra[i] == 'i' || palavra[i] == 'o' || palavra[i] == 'u'){
            vogais += 1;
        }
    }*/
    return 0;
}