#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Linhas{

    char linhas1;
    char linhas2;

} Linhas;
int main(){

    FILE *arquivo1,  *arquivo2;
    char arq1[300], arq2[300];
    int cont = 0, cont2 = 0,cont_l1 = 0, cont_l2 = 0 ;
    Linhas linha[300];
    int tam;

    printf("Digite o nome do arquivo 1: ");
    fgets(arq1,300,stdin);
    arq1[strlen(arq1)-1] = '\0';
    strcat(arq1,".txt");
    
    printf("Digite o nome do arquivo 2: ");
    fgets(arq2,300,stdin);
    arq2[strlen(arq2)-1] = '\0';
    strcat(arq2,".txt");
    printf("\n");

    arquivo1 = fopen(arq1, "r");
    arquivo2 = fopen(arq2, "r");


    int i = 0;
    while(!feof(arquivo1)){
        linha[i].linhas1 = fgetc(arquivo1);
        cont_l1++;
        i++;
    }
    int j = 0;
    while(!feof(arquivo2)){
        linha[j].linhas2 = fgetc(arquivo2);
        cont_l2++;
        j++;
    }
    
    if(cont_l1 >= cont_l2){
        tam = cont_l1;
    }
    if(cont_l1 < cont_l2){
        tam = cont_l2;
    }
    if(cont_l1 != cont_l2){
        printf("Conteudo diferente");
        return 0;
    }
    for(int i = 0; i < tam; i++){
        if(linha[i].linhas1 == linha[i].linhas2){
            cont++;
        }
    }
    if(cont == tam){
        printf("Conteudo igual\n");
    }else{
        printf("Conteudo Diferente\n");
    }
    fclose(arquivo1);
    fclose(arquivo2);

    return 0;
}