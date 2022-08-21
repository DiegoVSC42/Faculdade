#include <stdio.h>
#include <stdlib.h>

typedef struct funcionario{

    long int matricula;
    float salario_bruto;
    int carga_horaria;


} funcionario;
void mostrar_menu(){
    printf("\n1-Incluir funcionario");
    printf("\n2-Remover funcionario");
    printf("\n3-Mostrar folha de pagamento");
    printf("\n4-Sair");
    printf("\n");

}
void incluir_funcionario(funcionario *funcionarios, int cont){
    
    printf("\nDigite a matricula do funcionario: ");
    scanf("%ld", &funcionarios[cont].matricula);
    printf("\nDigite o salario do funcionario: ");
    scanf("%f", &funcionarios[cont].salario_bruto);
    printf("\nDigite a carga horaria do funcionario: ");
    scanf("%d", &funcionarios[cont].carga_horaria);
    printf("\n");

}
void remover_funcionario(funcionario *funcionarios){
    
    long int matricula;
    int auxiliar;
    
    printf("Digite a matricula da pessoa que sera excluida: ");
    scanf("%d", &matricula);
    auxiliar = 0;
    for(int i= 0; i < 10; i++){
        if(matricula == funcionarios[i].matricula){
            auxiliar++;
            for(;i<10;i++){
                funcionarios[i] = funcionarios[i+1];
            }
        }
    }
    if(auxiliar == 0){
        printf("\nNumero de matricula nao encontrado");
    }
}
void folha_de_pagamento(funcionario *funcionarios, int contador_pessoas){
    
    float salario_total = 0;
    float valor_medio = 0;
    printf("\nLista com todos os funcionarios:\n");
    
    for(int i = 0; i < contador_pessoas;i++){
        printf("\nNumero de matricula: %ld", funcionarios[i].matricula);
        printf("\nSalario: %.2f", funcionarios[i].salario_bruto);
        printf("\nCarga horaria: %d", funcionarios[i].carga_horaria);
        printf("\n");

    }
    printf("\n");

    for(int i = 0; i < contador_pessoas;i++){
        salario_total = salario_total + funcionarios[i].salario_bruto;
    }
    printf("\nSoma de todos os salarios brutos: %.2f\n", salario_total);


    for(int i = 0; i < contador_pessoas; i++){
        valor_medio = valor_medio + funcionarios[i].carga_horaria;
    }
    valor_medio = valor_medio/contador_pessoas;
    printf("\nValor medio de hora da empresa: %.2f\n", valor_medio);

}
int main(){

    int qtd_funcionarios;
    funcionario funcionarios[10];
    int contador_pessoas = 0;
    int escolha;

    do{
        mostrar_menu();
        scanf("%d", &escolha);

        if(escolha == 1){
            incluir_funcionario(funcionarios, contador_pessoas);
            contador_pessoas++;
        }else if(escolha == 2){
            remover_funcionario(funcionarios);
            contador_pessoas--;
        }else if(escolha == 3){
            folha_de_pagamento(funcionarios, contador_pessoas);
            
        }else if(escolha == 4){
            escolha = 0;        

        }else if (escolha < 0 || escolha > 4){
            printf("\nopcao invalida");

        }
        
    }while(escolha != 0);     


    return 0;
}