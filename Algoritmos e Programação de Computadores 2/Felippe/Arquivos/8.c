#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cria_arquivo(FILE *arquivo, char nome_arq[300]){

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

void cria2(FILE *arquivo, FILE *arquivo2, char nome_arq[300], char nome_arq2[300]){
    
    arquivo = fopen(nome_arq, "r");
    arquivo2 = fopen(nome_arq2,"w");
    
    char vogal[] = "aeiouAEIOU";
    char linha[300];


    if (arquivo == NULL){
    
        printf("\n Problemas na abertura do arquivo\n");
    
    }else{
        while(!feof(arquivo)){
            fgets(linha,300,arquivo);
            printf("Letra:%s \n", linha);
            for(int i = 0;i < strlen(vogal);i++){
                for(int j = 0;j < strlen(linha);j++){
                    if(linha[j] == vogal[i]){
                        fprintf(arquivo2,"*");
                    }else{
                        fprintf(arquivo2,"%c",linha[i]);
                    }
                }
            }
            
        }
    }
    fclose(arquivo2);
    fclose(arquivo);

}

int main(){
    
    FILE *arq, *arq2;
    char nome[300];
    char nome2[300];
    char caractere;
    char letra;
    int contador = 0;

    cria_arquivo(arq,nome);
    printf("Digite o nome do arquivo 2: ");
    fgets(nome2,300,stdin);
    nome2[strlen(nome2)-1] = '\0';
    strcat(nome2,".txt");

    cria2(arq,arq2,nome,nome2);

    printf("\n");
    return 0;
}