#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char string[100];
    char C;
    int posicao,j;
    int aux;
    
    printf("Digite a string:");
    fgets(string,100,stdin);
    printf("Digite uma letra: ");
    scanf("%c", &C);
    printf("Digite um numero: ");
    scanf("%d", &posicao);

    for(int i = posicao; i < strlen(string);i++){
        if(string[i] == C){
            printf("Indice da posicao: %d\n", i+1);
            break;
        }
    }
    for(j = posicao; j >= 0;j--){
        if(string[j] == C){
            aux = j;
            printf("Indice da posicao: %d\n", j+1);
            break;
        }
    }
    printf("\n");
    return 0;
}