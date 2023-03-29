#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*faça um programa que leia o nome, sexo e a idade do usuario. se o sexo for feminino e a idade menor que 25 imprimir: "ACEITA" caso contrario imprimir "NAO ACEITA"*/

typedef struct Usuario{

    char nome[30];
    char sexo[9];
    int idade;
} Usuario;

int main(){

    Usuario usuario;
    fgets(usuario.nome,30,stdin);
    fgets(usuario.sexo,30,stdin);
    usuario.sexo[strlen(usuario.sexo)-1] = '\0';
    scanf("%d", &usuario.idade);
   
    if(strcmp(usuario.sexo, "feminino") == 0 && usuario.idade < 25){
        printf("ACEITA\n");
    }else{
        printf("NAO ACEITA\n");
    }
    
}