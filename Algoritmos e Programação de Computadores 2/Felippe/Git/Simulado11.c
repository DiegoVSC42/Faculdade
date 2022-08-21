#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

typedef struct Data{

    int dia;
    int mes;
    int ano;

} Data;
typedef struct Agenda{

    char nome[15];
    char email[30];
    int telefone;
    char observacao[50];
    Endereco endereco;
    Data data;
} Agenda;

void insere_pessoa(Agenda *pessoa){
    
    printf("\nQual o nome da pessoa ?");
    scanf("%s", pessoa->nome);
    printf("\nQual o e-mail da pessoa ?");
    scanf("%s", pessoa->email);
    printf("\nQual o telefone da pessoa ?");
    scanf("%d", &pessoa->telefone);
    printf("\nObservacao: ");
    scanf("%s", pessoa->observacao);
    printf("\nQual o endereco da pessoa ?");
    printf("\nQual a rua da pessoa ?");
    scanf("%s", pessoa->endereco.rua);
    printf("\nQual o numero da casa ?");
    scanf("%d", &pessoa->endereco.numero);
    printf("\nQual o complemento ?");
    scanf("%s", pessoa->endereco.complemento);
    printf("\nQual o bairro ?");
    scanf("%s", pessoa->endereco.bairro);
    printf("\nQual a CEP ?");
    scanf("%d", &pessoa->endereco.cep);
    printf("\nQual a cidade ?");
    scanf("%s", pessoa->endereco.cidade);
    printf("\nQual o estado ?");
    scanf("%s", pessoa->endereco.estado);
    printf("\nQual o pais ?");
    scanf("%s", pessoa->endereco.pais);
    printf("\nQual a data de nascimento da pessoa ?");
    scanf("%d/%d/%d", &pessoa->data.dia, &pessoa->data.mes, &pessoa->data.ano);
    printf("\n");
}
void organizar_pessoa(Agenda escolhido, Agenda *pessoa){ 

    for(int i = 0; i < 100; i++){
        if(strcmp(escolhido.nome, pessoa[i].nome)<0){
            for(int j = 100;j>=i;j--){
                pessoa[j+1]=pessoa[j];
            }
            pessoa[i]=escolhido;
            break;
        }

    }
}
void preenche_nome(Agenda *nome){
    
    for(int i = 0;i<100;i++){
        nome[i].nome[0]='z';
    }
    for(int i = 0;i<100;i++){
        nome[i].data.dia=0;
        nome[i].data.mes=0; 
        nome[i].data.ano=0;
    }
}

void imprime_pessoa(Agenda pessoa){
        
    printf("\nNome: %s", pessoa.nome);
    printf("\nE-mail: %s", pessoa.email);
    printf("\nTelefone: %d", pessoa.telefone);
    printf("\nObservacao: %s", pessoa.observacao);
    printf("\nEndereco: ");
    printf("\nNumero da casa: %d", pessoa.endereco.numero);
    printf("\nComplemento: %s", pessoa.endereco.complemento);
    printf("\nBairro: %s", pessoa.endereco.bairro);
    printf("\nCEP: %d", pessoa.endereco.cep);
    printf("\nCidade: %s", pessoa.endereco.cidade);
    printf("\nEstado: %s", pessoa.endereco.estado);
    printf("\nPais: %s", pessoa.endereco.pais);
    printf("\nData de nascimento: %d/%d/%d ", pessoa.data.dia, pessoa.data.mes, pessoa.data.ano);
    printf("\n");
}
void imprime_nome(Agenda pessoa){
        
    printf("\nNome: %s", pessoa.nome);
    printf("\nE-mail: %s", pessoa.email);
    printf("\nTelefone: %d", pessoa.telefone);
    printf("\n");
    
}

void busca_por_mes(Agenda *pessoa){
    
    int mes_escolhido;

    printf("Digite o mes do aniversario desejado:");
    scanf("%d", &mes_escolhido);

    for (int i = 0; i < 100;i++){
        if(mes_escolhido == pessoa[i].data.mes){
            imprime_pessoa (pessoa[i]);
        }
    }
    printf("\n");
}

void busca_por_dia_e_mes(Agenda *pessoa){

    int mes_escolhido;
    int dia_escolhido;

    printf("Digite o dia e o mes do aniversario desejado:");
    scanf("%d/%d", &dia_escolhido, &mes_escolhido);

    for (int i = 0; i < 100;i++){
        if(mes_escolhido == pessoa[i].data.mes && dia_escolhido == pessoa[i].data.dia){
            imprime_pessoa (pessoa[i]);
        }
    }
    printf("\n");
}

void define_agenda(Agenda *pessoa, int contador_pessoas){

    int opcao;
    printf("Digite uma opcao: ");
    printf("\n1 para imprimir nome, telefone e e-mail\n2 para imprimir todos os dados: ");
    scanf("%d", &opcao);

    if (opcao == 1){
        for(int i = 0; i < contador_pessoas;i++){
            imprime_nome (pessoa[i]);
        }
    }
    if (opcao == 2){
        for(int i = 0; i < contador_pessoas;i++){
            imprime_pessoa (pessoa[i]);
        }
    }else if (opcao > 2 || opcao < 0){
        printf("\n Opcao invalida\n");
    }
}
void imprimir_tela(){
    
    printf("\n");
    printf("Digite uma opcao: ");
    printf("\n1 - Inserir pessoas ");
    printf("\n2 - Buscar pessoa por mes de aniversario ");
    printf("\n3 - Buscar pessoa por dia e mes de aniversario ");
    printf("\n4 - Retirar pessoas ");
    printf("\n5 - Mostrar agenda com as opcoes: ");
    printf("\n    Imprime nome, telefone e e-mail ");
    printf("\n    Imprime todos os dados ");
    printf("\n0 - Para finalizar o programa ");
    printf("\n");
}
int main(){

    Agenda estrutura[100];
    int escolha = 0;
    int telefone;
    int qualquer_nome;
    int contador_pessoas = 0;
    Agenda escolhido;
    preenche_nome(estrutura);
    do{
        imprimir_tela();
        scanf("%d", &escolha);

        if(escolha == 1){
            insere_pessoa(&escolhido);
            organizar_pessoa(escolhido,estrutura);
            contador_pessoas++;
        }else if(escolha == 2){
            busca_por_mes(estrutura);
            
        }else if(escolha == 3){
            busca_por_dia_e_mes(estrutura);
            
        }else if(escolha == 4){
            printf("Digite o telefone da pessoa que sera excluida");
            scanf("%d", &telefone);
            qualquer_nome = 0;
            for(int i = 0; i < 100; i++){
                if(telefone == estrutura[i].telefone){
                    estrutura[i] = estrutura[i+1];
                    qualquer_nome++;
                }
            }
            if (qualquer_nome == 0){
                printf("\nNumero de telefone nao encontrado");
            }
            contador_pessoas--;
        }else if(escolha == 5){
            define_agenda(estrutura,contador_pessoas);

        }else if (escolha < 0 || escolha > 5){
            printf("\nopcao invalida");

        }
        
    }while(escolha != 0);     

}