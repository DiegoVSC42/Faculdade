#include <stdio.h>
#include <stdlib.h>

typedef struct dados{

    int matricula;
    int idade;
    int sexo; //(1 - M/2 - F)
    long int CPF;
    int codigo_setor; //(0-99)
    float salario;

} dados;

typedef struct data{

    int dia;
    int mes;
    int ano;

} data;

void dados_usuario(dados *usuario, data *nascimento){
    
    printf("Digite a matricula:");
    scanf("%d", &usuario->matricula);
    printf("Digite a idade:");
    scanf("%d", &usuario->idade);
    printf("Digite o sexo:");
    scanf("%d", &usuario->sexo);
    printf("Digite o CPF:");
    scanf("%ld", &usuario->CPF);
    printf("Digite o codigo de setor:");
    scanf("%d", &usuario->codigo_setor);
    printf("Digite o salario:");
    scanf("%f", &usuario->salario);
    printf("Digite o dia de nascimento: ");
    scanf("%d", &nascimento->dia);
    printf("Digite o mes de nascimento: ");
    scanf("%d", &nascimento->mes);
    printf("Digite o ano de nascimento: ");
    scanf("%d", &nascimento->ano);

}

void mostrar_dados(dados usuario, data nascimento){
    printf("\nMatricula: %d", usuario.matricula);
    printf("\nidade: %d", usuario.idade);
    if(usuario.sexo == 1){
        printf("\nsexo: M");
    }
    if(usuario.sexo == 2){
        printf("\nsexo: F");
    }   
    printf("\nCPF: %ld", usuario.CPF);
    printf("\nCodigo de setor: %d", usuario.codigo_setor);
    printf("\nSalario: %.2f", usuario.salario);
    printf("\nData de nascimento : %d/%d/%d", nascimento.dia, nascimento.mes, nascimento.ano);
    printf("\n");
}
int main(){
    dados pessoa;
    data data_nas;

    dados_usuario(&pessoa, &data_nas);
    mostrar_dados(pessoa, data_nas);

}