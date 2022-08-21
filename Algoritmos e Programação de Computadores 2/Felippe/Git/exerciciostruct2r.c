#include <stdio.h>
#include <stdlib.h>

typedef struct Data
{
    int dia, mes, ano;
} Data;

void CriaData(Data *D)
{
    D->mes = 1 + (rand() % 12);
    D->ano = 1950 + (rand() % 49);
    D->dia = 1 + (rand() % 30);
}

typedef struct Pessoa{
    
    long int matricula;
    float altura;
    Data nascimento;

} Pessoa;

void LePessoaDeTeclado(Pessoa *aluno){
    
    printf("\nEscreva a matricula do aluno : ");
    scanf("%d", &aluno->matricula);
    printf("\n Digite a altura do aluno :");
    scanf("%f", &aluno->altura);
    CriaData(&aluno->nascimento);
}
void ImprimeTodasAsPessoas(Pessoa *aluno, int qtdpessoas){
    
    for(int i = 0; i < qtdpessoas; i++){
        
        printf("\n");
        printf("\n Matricula do aluno : %d", aluno[i].matricula);
        printf("\n Altura do aluno : %.1f", aluno[i].altura);
        printf("\n Dia = %d, Mes = %d, Ano = %d",aluno[i].nascimento.dia,aluno[i].nascimento.mes,aluno[i].nascimento.ano);
        printf("\n");

    }

}

void ImprimeTelaDeOpcoes(){
    
    printf("\n Escolha uma opcao :");
    printf("\n Digite 1 para inserir uma matricula");
    printf("\n Digite 2 para listar todas as matriculas e respectivas alturas");
    printf("\n Digite 3 para listar as matriculas das pessoas que nasceram antes de uma certa data fornecida");
    printf("\n Digite 4 para finalizar o programa");
    printf("\n ");
}

int EscolheOpcao(){
    
    int qualquer1;
    scanf("%d", &qualquer1);
    return qualquer1;

}

void AdicionaPessoa(Pessoa *povo, Pessoa p, int qtdPessoas){
    povo[qtdPessoas] = p;
}
void LeDataDeTeclado(Data *dia){
    printf("Digite a data: ");
    scanf ("%d %d %d",&dia->dia, &dia->mes, &dia->ano);
}

void ImprimeMaisVelhos(Pessoa *povo, int qtdPessoas, Data dia){
    for(int i = 0; i < qtdPessoas;i++){
        if(povo[i].nascimento.ano < dia.ano){
            printf("%d\n", povo[i].matricula);
        
        }else if(povo[i].nascimento.mes < dia.mes && povo[i].nascimento.ano == dia.ano){
            printf("%d\n", povo[i].matricula);
        
        }else if(povo[i].nascimento.dia < dia.dia && povo[i].nascimento.mes == dia.mes){
            printf("%d\n", povo[i].matricula);
        
        }
        
    }
}
int main()
{
    Pessoa povo[10];
    Pessoa p;
    int opcao, qtdPessoas = 0;
    Data dia;

    ImprimeTelaDeOpcoes();
    do{
        opcao = EscolheOpcao();
        if (opcao == 1){
            LePessoaDeTeclado(&p);
            AdicionaPessoa(povo, p, qtdPessoas);
            qtdPessoas++;
        }
        if (opcao == 2){
            ImprimeTodasAsPessoas(povo, qtdPessoas);
        }
        if (opcao == 3){

            LeDataDeTeclado(&dia);
            ImprimeMaisVelhos(povo, qtdPessoas, dia);
        }
    } while (opcao != 4);
}