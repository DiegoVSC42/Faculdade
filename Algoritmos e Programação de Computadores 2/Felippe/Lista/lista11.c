/*    11. Faça um programa que leia os dados de 10 alunos (Nome, matricula, Média Final), arma-
zenando em um vetor. Uma vez lidos os dados, divida estes dados em 2 novos vetores,
o vetor dos aprovados e o vetor dos reprovados, considerando a média mı́nima para a
aprovação como sendo 5.0. Exibir na tela os dados do vetor de aprovados, seguido dos
dados do vetor de reprovados.*/

#include <stdio.h>
#include <stdlib.h>


typedef struct Aluno{

    char nome[30];
    int matricula;
    float media_final;

} Aluno;

void le_aluno(Aluno *aluno){

    for(int i = 0;i < 10;i ++){
        printf("\nDigite o nome do aluno: ");
        scanf("%s", aluno[i].nome);
        printf("\nDigite a matricula do aluno: ");
        scanf("%d", &aluno[i].matricula);
        printf("\nDigite a media do aluno: ");
        scanf("%f", &aluno[i].media_final);

    }


}

void aprovacao(Aluno *aluno){

    Aluno aprovados[30];
    Aluno reprovados[30];
    int contador_apr = 0;
    int contador_rec = 0;

    for(int i = 0;i<10;i++){
        
        if(aluno[i].media_final >= 5){
            aprovados[contador_apr] = aluno[i];
            contador_apr++;
        }else if(aluno[i].media_final < 5){
            reprovados[contador_rec] = aluno[i];
            contador_rec++;
        }  
    }

    printf("\nOs aprovados sao: ");
    for(int i = 0; i < contador_apr;i++){
        printf("%s, ", aprovados[i].nome);
    }
    printf("\nOs reprovados sao: ");
    for(int i = 0; i < contador_rec;i++){
        printf("%s, ", reprovados[i].nome);
    }
    printf("\n");
}

int main(){

    Aluno aluno[10];

    le_aluno(aluno);
    aprovacao(aluno);

    return 0;
}
