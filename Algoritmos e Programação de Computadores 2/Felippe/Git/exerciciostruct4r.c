#include <stdlib.h>
#include <stdio.h>

typedef struct dados{

    int matricula;
    float media_final;

} dados;

void dados_aluno(dados *aluno){
    printf("Digite a matricula: ");
    scanf("%d", &aluno->matricula);
    printf("Digite a media final: ");
    scanf("%f", &aluno->media_final);
}

int main (){
    
    dados alunos[10];
    dados vetor_apr[10];
    dados vetor_rep[10];
    int contador_apr = 0;
    int contador_rep = 0;

    for(int i = 0; i < 10;i++){
        dados_aluno(&alunos[i]);
    }
    for(int i = 0; i < 10;i++){
        if(alunos[i].media_final < 5){
            vetor_rep[contador_rep] = alunos[i];
            contador_rep++;
        }else if(alunos[i].media_final >= 5){
            vetor_apr[contador_apr] = alunos[i];
            contador_apr++;
        }
    }
    printf("\n Lista de reprovados: ");
    for(int i = 0;i < contador_rep;i++){
        printf("\n Matricula do aluno: ");
        printf("%d", vetor_rep[i].matricula);
        printf("\n Media final do aluno: ");
        printf("%.2f", vetor_rep[i].media_final);
    }
    printf("\n");
    printf("\n Lista de aprovados: ");
    for(int i = 0;i < contador_apr;i++){
        printf("\n Matricula do aluno: ");
        printf("%d", vetor_apr[i].matricula);
        printf("\n Media final do aluno: ");
        printf("%.2f", vetor_apr[i].media_final);
    }
    printf("\n");
    printf("\n");
    return 0;
}