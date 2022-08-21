#include <stdio.h>
#include <string.h>

int main() {
    //Variáveis de contagem
    int comecouPalavra = 0, numPalavras = 0, numLinhas = 0, numCaracteres = 0;
    //Variável usada como descritor do arquivo em disco
    FILE *descritor;
    //Variável que irá receber a string de onde está o arquivo
    char arquivo[50];
    //Variável que armazena caracter para processamento
    char *caracter;    
    printf("Digite o arquivo que deseja abrir: ");
    gets(arquivo);
    descritor = fopen(arquivo, "r");
    while (!feof(descritor)) {
          fread(caracter, 1, 1, descritor);
          numCaracteres++;
          if  ((*caracter!=' ') && (*caracter!='\n') && (!comecouPalavra)) {
             comecouPalavra = 1;
          }
          if  (((*caracter==' ') || (*caracter == '\n')) && (comecouPalavra)) {
             comecouPalavra = 0;
             numPalavras++;
          }
          if (*caracter=='\n') {
             numLinhas++;
             }
   
   }           
   printf("\n Numero de palavras do arquivo: %d", numPalavras);
   printf("\n Numero de linhas do arquivo: %d", numLinhas);
   printf("\n Numero de caracteres do arquivo: %d", numCaracteres);
   return 0;
}