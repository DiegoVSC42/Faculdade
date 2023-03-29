#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Cidade{

    char nome_cidade[40];
    long int habitantes;

} Cidade;

int main(){

    FILE *arquivo1, *arquivo2;
    char arq1[300], arq2[300];
    Cidade cidade, aux;

    printf("Digite o nome do arquivo 1: ");
    fgets(arq1,300,stdin);
    arq1[strlen(arq1)-1] = '\0';
    strcat(arq1,".txt");
    
    printf("Digite o nome do arquivo 2: ");
    fgets(arq2,300,stdin);
    arq2[strlen(arq2)-1] = '\0';
    strcat(arq2,".txt");

    arquivo1 = fopen(arq1, "r");
    arquivo2 = fopen(arq2, "w");
    
    cidade.habitantes = 0;
    
    while(!feof(arquivo1)){
        
        fscanf(arquivo1,"%s %ld", aux.nome_cidade, &aux.habitantes);
        
        if(aux.habitantes > cidade.habitantes){
            cidade = aux;
        }
    }

    fprintf(arquivo2,"%s %ld",cidade.nome_cidade, cidade.habitantes);

    fclose(arquivo1);
    fclose(arquivo2);
    
    printf("\n");
    return 0;
}