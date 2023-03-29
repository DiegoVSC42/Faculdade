#include <stdio.h>
#include <stdlib.h>

int main(){
    
    FILE *arq;
    int contador_B = 0;
    char B;
    char linha[300];

    arq = fopen("nomes.txt", "r");

    if (arq == NULL){
    
        printf("\n Problemas na abertura do arquivo");
    
    }else{

        while(!feof(arq)){

            fgets(linha,300,arq);

            if(linha[0] == 'B'){
                contador_B++;
            }
        }
    }


    printf("Numero de letras B : %d", contador_B);

    printf("\n");
    return 0;
}