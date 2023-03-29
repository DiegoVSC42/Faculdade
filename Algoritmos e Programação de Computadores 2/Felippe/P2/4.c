#include <stdio.h>
#include <stdlib.h>

typedef struct Endereco{

    int rua;
    char bairro[100];
    char cidade[40];
    char estado[40];
    long int CEP;
    
}Endereco;

typedef struct Cadastro{

    char nome[40];
    Endereco endereco;
    float salario;
    long int identidade;
    long int cpf;
    char estado_civil[40];
    long int telefone;
    int idade;
    char sexo[30];
} Cadastro;


int main(){


    printf("\n");
    return 0;
}