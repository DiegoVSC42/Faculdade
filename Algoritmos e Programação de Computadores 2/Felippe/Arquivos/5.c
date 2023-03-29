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
void le_arquivo(FILE *arquivo, char nome_arq[300]){

    int contador = 0;
    int contador2 = 0;
    char vogal[] = "aeiouAEIOU";
    char consoante[] = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";
    char letra;
    arquivo = fopen(nome_arq,"r");
    
    if (arquivo == NULL){
    
        printf("\n Problemas na abertura do arquivo\n");
    
    }else{

        while(!feof(arquivo)){

            letra = fgetc(arquivo);
            for(int j = 0;j < strlen(vogal);j++){
                if(letra == vogal[j]){
                    contador++;
                }
            }
            for(int i = 0;i < strlen(consoante);i++){
                if(letra == consoante[i]){
                    contador2++;
                }
            }
        }
    }
    printf("O arquivo %s possui %d vogais\n", nome_arq, contador);
    printf("O arquivo %s possui %d consoantes", nome_arq, contador2);
    
    fclose(arquivo);

}

int main(){
    
    FILE *arq;
    char linha[300];
    char nome[300];

    cria_arquivo(arq,nome,linha);
    le_arquivo(arq,nome);

    printf("\n");
    return 0;
}