#include <stdio.h>
#include <stdlib.h>



typedef struct endereco{
        
    int rua;
    char bairro[30];
    char cidade[30];
    char estado[30];
    int cep;

} endereco;

typedef struct Cadastro{
    
    char nome[30];
    endereco endereco;
    float salario;
    int identidade;
    long int cpf;
    char estado_civil[30];
    int telefone;
    int idade;
    int sexo;

} cadastro;

int main(){

    cadastro vetor[5];
    int identidade;
    cadastro velho;
    velho.idade = 0;

    for (int i = 0; i < 5; i++){
        printf("\nDigite o nome: ");
        scanf("%s", vetor[i].nome);
        printf("Digite o endereco: ");
        printf("\nDigite o numero da rua: ");
        scanf("%d", &vetor[i].endereco.rua);
        printf("Digite o bairro: ");
        scanf("%s", vetor[i].endereco.bairro);
        printf("Digite a cidade: ");
        scanf("%s", vetor[i].endereco.cidade);
        printf("Digite o estado: ");
        scanf("%s", vetor[i].endereco.estado);
        printf("Digite o CEP: ");
        scanf("%d", &vetor[i].endereco.cep);
        printf("Digite o salario: ");
        scanf("%f", &vetor[i].salario);
        printf("Digite a identidade: ");
        scanf("%d", &vetor[i].identidade);
        printf("Digite o CPF: ");
        scanf("%ld", &vetor[i].cpf);
        printf("Digite o estado civil: ");
        scanf("%s", vetor[i].estado_civil);
        printf("Digite o telefone: ");
        scanf("%d", &vetor[i].telefone);
        printf("Digite a idade: ");
        scanf("%d", &vetor[i].idade);
        printf("Digite o sexo(1 para masculino ou 2 para feminino): ");
        scanf("%d", &vetor[i].sexo);
    }
    for (int i = 0; i < 5 ; i++){
        if(vetor[i].idade > velho.idade){
            velho = vetor[i];
        }
    }
    printf("\nPessoa mais velha: %s", velho.nome);
    printf("\n");
    printf("\nAs pessoas do sexo masculino sao: ");
    for(int i = 0;i < 5; i++){
        if(vetor[i].sexo == 1){
            printf("\n%s",vetor[i].nome);
        }
    }
    printf("\n");
    printf("\nAs pessoas com salario maior que 1000 sao: ");
    for(int i = 0;i < 5; i++){
        if(vetor[i].salario > 1000){
            printf("\n%s",vetor[i].nome);
        }
    }
    printf("\n");
    printf("\nDigite a identidade desejada para verificar: ");
    scanf("%d", &identidade);
    for(int i = 0; i < 5;i++){
        if(identidade == vetor[i].identidade){
            printf("\n%s possui a mesma identidade que a desejada\n", vetor[i].nome);
            printf("\n");
        }
    }
    if(identidade != vetor[0].identidade && identidade != vetor[1].identidade && identidade != vetor[2].identidade && identidade != vetor[3].identidade && identidade != vetor[4].identidade){ 
        printf("\nNinguem possui identidade igual a desejada\n");
        printf("\n");
    }
}
