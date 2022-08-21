#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void letras_alfa(FILE *arquivo, char nome[300]){

    char letra;
    char alfabeto[] = "abcdefghijklmnopqrstuvwxyz";
    char caractere;
    int contador;
    char aux;
    char stream[300];

    caractere = 'a';

    arquivo = fopen(nome,"r");

    if (arquivo == NULL){
    
        printf("\n Problemas na abertura do arquivo\n");
    
    }else{
        
        letra = fgetc(arquivo);
        
        for(int i = 0;i < 26;i++){
            contador = 0;
            
            for(int j = 0;fgets(stream,300,arquivo)!= NULL; j++){
                
                for(int k = 0;k < strlen(stream);k++){
                    
                    if(stream[k] == caractere){
                        
                       contador++;
                    }   
                }
            }
            rewind(arquivo);
            printf("Quantidade de letras %c: %d \n", caractere, contador);
            caractere++;
        }

    }

    fclose(arquivo);
}
int main(){
    
    FILE *arquivo;
    char nome_arq[300];
    char linha_arq[300];
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

    letras_alfa(arquivo, nome_arq);

    printf("\n");
    return 0;
}