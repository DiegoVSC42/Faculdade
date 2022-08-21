/*    8. Faça um programa que armazene em um registro de dados (estrutura composta) os da-
dos de um funcionário de uma empresa, compostos de: Nome, Idade, Sexo (M/F), CPF,
Data de Nascimento, Código do Setor onde trabalha (0-99), Cargo que ocupa (string de
até 30 caracteres) e Salário. Os dados devem ser digitados pelo usuário, armazenados
na estrutura e exibidos na tela.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Data_Nas{

    int dia;
    int mes;
    int ano;

} Data_Nas;

typedef struct Funcionario{

    char nome[30];
    int idade;
    char sexo[1];
    long int CPF;
    Data_Nas data_nas;
    int codigo_setor;
    char cargo[30];
    float salario;

} Funcionario;

void mostrar_funcionario(Funcionario funcionario){

    printf("\nNome: %s", funcionario.nome);
    printf("\nIdade: %d", funcionario.idade);
    printf("\nSexo: %s", funcionario.sexo);
    printf("\nCPF: %ld", funcionario.CPF);
    printf("\nData de nascimento: %d/%d/%d", funcionario.data_nas.dia, funcionario.data_nas.mes, funcionario.data_nas.ano);
    printf("\nCodigo de setor: %d", funcionario.codigo_setor);
    printf("\nCargo: %s", funcionario.cargo);
    printf("\nSalario: %.2f", funcionario.salario);
    printf("\n");

}
void receber_funcionario(Funcionario *funcionario){

    printf("\nDigite o nome: \n");
    scanf("%s", funcionario->nome);
    printf("\nDigite a idade: \n");
    scanf("%d", &funcionario->idade);
    printf("\nDigite o sexo: \n");
    scanf("%s", funcionario->sexo);
    printf("\nDigite o CPF: \n");
    scanf("%ld", &funcionario->CPF);
    printf("\nDigite a data de nascimento: \n");
    scanf("%d/%d/%d", &funcionario->data_nas.dia, &funcionario->data_nas.mes, &funcionario->data_nas.ano);
    printf("\nDigite o codigo de setor: \n");
    scanf("%d", &funcionario->codigo_setor);
    printf("\nDigite o cargo: \n");
    scanf("%s", funcionario->cargo);
    printf("\nDigite o salario: \n");
    scanf("%f", &funcionario->salario);
}

int main(){

    Funcionario funcionario;

    receber_funcionario(&funcionario);
    mostrar_funcionario(funcionario);

    return 0;
}