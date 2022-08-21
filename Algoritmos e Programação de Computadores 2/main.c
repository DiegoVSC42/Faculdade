#include <stdio.h>
#include <stdlib.h>

typedef struct aluno
{
   int matricula;
   float notas[3];

}aluno;


void le_aluno(aluno * pessoa){
    printf("\nMatricula:");
    scanf("%d", &pessoa->matricula);
    printf("\nNota 1:");
    scanf("%f", &pessoa->notas[0]);
    printf("\nNota 2:");
    scanf("%f", &pessoa->notas[1]);
    printf("\nNota 3:");
    scanf("%f", &pessoa->notas[2]);
}

void ImprimeTurma(aluno pessoa){
    printf("\n");
    printf("\nMatricula: %d", pessoa.matricula);
    printf("\nNota 1: %f", pessoa.notas[0]);
    printf("\nNota 2:%f", pessoa.notas[1]);
    printf("\nNota 3:%f", pessoa.notas[2]);
    printf("\n");
}

float CalculaMediaAluno(aluno pessoa){
    float media;
    media = (pessoa.notas[1]+pessoa.notas[0]+pessoa.notas[2])/3;
    return media;
}

int main()
{
    int i;
    aluno Turma[5];

    for(i=0; i< 5; i++)
    {
        le_aluno(&Turma[i]);
    }

    
    for(i=0;i<5;i++){
        ImprimeTurma(Turma[i]);
    }


    for(i=0; i< 5; i++)
    {
        float media = CalculaMediaAluno(Turma[i]);  
        printf("\nAluno %d  - Media = %f\n",i,media); // imprime os dados do aluno
    }
    return 0;
}