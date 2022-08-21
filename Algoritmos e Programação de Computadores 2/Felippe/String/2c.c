#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    
    char string[100];
    int N, M;    
    printf("Digite a string: ");
    fgets(string,100,stdin);
    printf("Digite o primeiro numero: ");
    scanf("%d", &N);
    printf("Digite o segundo numero: ");
    scanf("%d", &M);


    for(int i = 0; i < strlen(string);i++){
        if(i >= N-1 && i <= M-1){
            printf("%c", string[i]);
        }
    }
    printf("\n");
    return 0;
}