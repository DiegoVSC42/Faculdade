#include <stdio.h>

int main(int argc, char const *argv[]){

    int espacos, tamanho;
    char linha[25] = "IESB NOTA CINCO NO MEC";

    printf("aa %d\n", tamanho);
    for(tamanho = 1; tamanho <25; tamanho++){
        if(linha[tamanho] == ' '){
            espacos +=1;
        }
    }
    printf("%d\n", espacos);
    return 0;
}