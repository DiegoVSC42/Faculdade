#include <stdio.h>
#include <stdlib.h>

typedef struct Agenda{

    char nome[15];
    char e_mail[30];
    int telefone;
    char observacao[50];

} Agenda;

typedef struct Endereco{

    char rua[30];
    int numero;
    char complemento[30];
    char bairro[30];
    int cep;
    char cidade[30];
    char estado[30];
    char pais[30];

} Endereco;

typedef struct data{

    int dia;
    int mes;
    int ano;

} data;

void define_estrutura(){
    
    printf("A extrutura é composta por nome, e-mail, endereco, telefone, data de nascimento e observacoes");
    
}
void bloco_mes_niver(Agenda pessoa, data mes, Endereco individuo){

    data mes_escolhido;
    data mes_verificado[100];
    Agenda pessoa_verificada[100];
    Endereco individuo_verificado[100];

    printf("Digite o mes de aniversario desejado:");
    scanf("%d", &mes_escolhido.mes);

    for (int i = 0; i < 100;i++){
        if( mes_escolhido.mes == mes_verificado[i].mes){
            printf("\nNome: %s", pessoa_verificada[i].nome);
            printf("\nE-mail: %s", pessoa_verificada[i].e_mail);
            printf("\nTelefone: %d", pessoa_verificada[i].telefone);
            printf("\nObservacao: %s", pessoa_verificada[i].observacao);
            printf("\nEndereco: ");
            printf("\nNumero da casa: %d", individuo_verificado[i].numero);
            printf("\nComplemento: %s", individuo_verificado[i].complemento);
            printf("\nBairro: %s", individuo_verificado[i].bairro);
            printf("\nCEP: %d", individuo_verificado[i].cep);
            printf("\nCidade: %s", individuo_verificado[i].cidade);
            printf("\nEstado: %s", individuo_verificado[i].estado);
            printf("\nPais: %s", individuo_verificado[i].pais);
            printf("\nData de nascimento: %d/%d/%d ", mes_verificado[i].dia, mes_verificado[i].mes, mes_verificado[i].ano);
        }
    }
}
void bloco_dia_e_mes_niver(Agenda pessoa, data mes, data dia, Endereco individuo){

    data dia_escolhido;
    data mes_escolhido;
    data mes_verificado[100];
    data dia_verificado[100];
    Agenda pessoa_verificada[100];
    Endereco individuo_verificado[100];

    printf("Digite o dia e o mes de aniversario desejado:");
    scanf("%d/%d", &dia_escolhido.dia, &mes_escolhido.mes);

    for (int i = 0; i < 100;i++){
        if(dia_escolhido.dia == dia_verificado[i].dia && mes_escolhido.mes == mes_verificado[i].mes){
            printf("\nNome: %s", pessoa_verificada[i].nome);
            printf("\nE-mail: %s", pessoa_verificada[i].e_mail);
            printf("\nTelefone: %d", pessoa_verificada[i].telefone);
            printf("\nObservacao: %s", pessoa_verificada[i].observacao);
            printf("\nEndereco: ");
            printf("\nNumero da casa: %d", individuo_verificado[i].numero);
            printf("\nComplemento: %s", individuo_verificado[i].complemento);
            printf("\nBairro: %s", individuo_verificado[i].bairro);
            printf("\nCEP: %d", individuo_verificado[i].cep);
            printf("\nCidade: %s", individuo_verificado[i].cidade);
            printf("\nEstado: %s", individuo_verificado[i].estado);
            printf("\nPais: %s", individuo_verificado[i].pais);
            printf("\nData de nascimento: %d/%d/%d ", mes_verificado[i].dia, mes_verificado[i].mes, mes_verificado[i].ano);
        }
    }
}
void insere_pessoas(Agenda *Pessoa, Endereco *Local, data *Aniversario){
    
    Agenda pessoa;
    Endereco local;
    data aniversario;
    
    printf("\nQual o nome da pessoa ?");
    scanf("%s", pessoa.nome);
    printf("\nQual o e-mail da pessoa ?");
    scanf("%s", pessoa.e_mail);
    printf("\nQual o telefone da pessoa ?");
    scanf("%d", pessoa.telefone);
    printf("\nObservacao: ");
    scanf("%s", pessoa.observacao);
    printf("\nQual o endereco da pessoa ?");
    scanf("%s", local.rua);
    printf("\nQual o numero da casa ?");
    scanf("%d", &local.numero);
    printf("\nQual o complemento ?");
    scanf("%s", local.complemento);
    printf("\nQual o bairro ?");
    scanf("%s", local.bairro);
    printf("\nQual a CEP ?");
    scanf("%d", local.cep);
    printf("\nQual a cidade ?");
    scanf("%s", local.cidade);
    printf("\nQual o estado ?");
    scanf("%s", local.estado);
    printf("\nQual o pais ?");
    scanf("%s", local.pais);
    printf("\nQual a data de nascimento da pessoa ?");
    scanf("%d/%d/%d", &aniversario.dia, &aniversario.mes, &aniversario.ano);
    printf("\n");
}

void imprime_agenda(Agenda *Pessoa, Endereco *Local, data *Aniversario){
    
    Agenda pessoa[100];
    Endereco local;
    Endereco pessoa_end[100];
    data aniversario;
    data pessoa_niv[100];
    int opcao;
    
    printf("Escolha uma opcao");
    printf("Digite 1 para imprimir nome, telefone e e-mail");
    printf("Digite 2 para imprimir todos os dados");
    scanf("%d", opcao);
    
    switch (opcao){
    
    case 1:
        for(int i = 0;i<100;i++){
            printf("Nome: %s", pessoa[i].nome);
            printf("Telefone: %s", pessoa[i].telefone);
            printf("E-mail: %s", pessoa[i].e_mail);
        }
        break;
    case 2:
        
        for(int i = 0;i<100;i++){
            printf("\nNome: %s", pessoa[i].nome);
            printf("\nE-mail: %s", pessoa[i].e_mail);
            printf("\nTelefone: %d", pessoa[i].telefone);
            printf("\nObservacao: %s", pessoa[i].observacao);
            printf("\nEndereco: ");
            printf("\nNumero da casa: %d", pessoa_end[i].numero);
            printf("\nComplemento: %s", pessoa_end[i].complemento);
            printf("\nBairro: %s", pessoa_end[i].bairro);
            printf("\nCEP: %d", pessoa_end[i].cep);
            printf("\nCidade: %s", pessoa_end[i].cidade);
            printf("\nEstado: %s", pessoa_end[i].estado);
            printf("\nPais: %s", pessoa_end[i].pais);
            printf("\nData de nascimento: %d/%d/%d ", pessoa_niv[i].dia, pessoa_niv[i].mes, pessoa_niv[i].ano);
        }
        break;
    default:
        printf("\nopcao invalida");
        break; 
    }
}
void selecionar_opcao(){

    char opcao;

    printf("Escolha uma opcao");
    scanf("%c", opcao);

    switch (opcao){

        case 'a' || 'A' :
            define_estrutura();
            break;
        case 'b' || 'B':
            declara_agenda()
            break;
        case 'd' || 'D':
            Agenda vetor[100];
            break;
        case 'e' || 'E':
            
            break;
        case 'f' || 'F':
            
            break;
        case 'g' || 'G':
            
            break;
        case 'h'|| 'H':
            
            break;
        case 'i' || 'I':
            
            break;
        default:
            printf("\nopcao invalida");
            break;
        }
    }
}

int main(){


}
