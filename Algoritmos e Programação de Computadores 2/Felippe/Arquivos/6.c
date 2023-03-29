#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cria_arquivo(FILE *arquivo, char nome_arq[300],char linha_arq[300]){

    char frase[300];
    int cont = 1;

    printf("Digite o nome do arquivo: ");
    fgets(nome_arq,300,stdin);
    nome_arq[strlen(nome_arq)-1] = '\0';
    strcat(nome_arq,".txt");

    arquivo = fopen(nome_arq,"w");
    
    if (arquivo == NULL){
    
        printf("\n Problemas na abertura do arquivouivo\n");
    
    }else{

        do{
            
            fgets(frase,300,stdin);

            if(frase[0] != '0'){
                fprintf(arquivo,"%s",frase);
            }

        }while(frase[0] != '0');
    }
    fclose(arquivo);

}

int main(){
    
    FILE *arq;
    char linha[300];
    char nome[300];
    char caractere;
    char letra;
    int contador = 0;

    cria_arquivo(arq,nome,linha);

    printf("Digite um caractere: ");
    caractere = fgetc(stdin);

    arq = fopen(nome,"r");

    if (arq == NULL){
    
        printf("\n Problemas na abertura do arquivouivo\n");
    
    }else{

        while(!feof(arq)){

            letra = fgetc(arq);
            if(letra == caractere){
                contador++;
            }
        }
    }

    printf("O caractere %c aparece %d vezes no arquivo %s", caractere, contador, nome);


    printf("\n");
    return 0;
}