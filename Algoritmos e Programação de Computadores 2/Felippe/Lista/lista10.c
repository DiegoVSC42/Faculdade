    /*10. Utilizando uma estrutura, faça um programa que permita a entrada de nome, endereço e
telefone de 5 pessoas e os imprima em ordem alfabética.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Endereco{

    int quadra;
    int mr;
    int lote;
    char setor[10];

} Endereco;

typedef struct Pessoa{

    char nome[30];
    Endereco endereco;
    long int telefone;

} Pessoa;

void le_pessoa(Pessoa *pessoa){
    
    for(int i = 0; i < 5; i++){
    
    printf("\nDigite o nome da pessoa: ");
    scanf("%s", pessoa[i].nome);
    /*printf("\nDigite o endereco da pessoa: ");
    scanf("%d %d %d %s", &pessoa[i].endereco.quadra, &pessoa[i].endereco.mr, &pessoa[i].endereco.lote, pessoa[i].endereco.setor);
    printf("\nDigite o telefone da pessoa: ");
    scanf("%ld", &pessoa->telefone);*/
    
    }

}

void organiza_pessoa(Pessoa *pessoa){

    Pessoa auxiliar;
    char *aux, *aux2;

    for(int i = 0;i<5;i++){
        aux = pessoa[i].nome;
        for(int j = i+1; j < 5; j++){
            aux2 = pessoa[j].nome;
            if(strcmp(aux, aux2) > 0){
                auxiliar = pessoa[i];
                pessoa[i] = pessoa[j];
                pessoa[j] = auxiliar;
            }
        }
    }

}


void imprime_pessoa(Pessoa *pessoa){
    
    for(int i = 0; i < 5;i++){
        printf("\nNome: %s", pessoa[i].nome);
        /*printf("\nEndereco: %d %d %d %s",pessoa[i].endereco.quadra, pessoa[i].endereco.mr, pessoa[i].endereco.lote, pessoa[i].endereco.setor);
        printf("\nTelefone: %ld", pessoa[i].telefone);
        */
    }
    printf("\n");
}

int main(){

    Pessoa pessoa;

    le_pessoa(&pessoa);
    organiza_pessoa(&pessoa);
    imprime_pessoa(&pessoa);
    
    return 0;

}