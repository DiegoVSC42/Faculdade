#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aluno{

    char nome[30];
    int matricula;
    float *vetor_notas;
    int M;
    float media;

} Aluno;

float media(float *vetor_notas, int M){

    float media = 0;

    for(int i = 0;i < M;i++){
        
        media = media + vetor_notas[i];
    
    }
    return (media/M);
}

void preenche_aluno(Aluno * aluno){
        
    printf("Digite o nome do aluno: ");
    fflush(stdin);
    
    fgets(aluno->nome,30,stdin);
    aluno->nome[strlen(aluno->nome)-1] = '\0';

    printf("Digite a matricula do aluno %s: ", aluno->nome);
    scanf("%d", &aluno->matricula);
    printf("Digite a quantidade de notas de %s: ", aluno->nome);
    scanf("%d", &aluno->M);

    aluno->vetor_notas = (float*)malloc(sizeof(float)*aluno->M);

    for(int i = 0;i < aluno->M;i++){
        printf("Digite a nota %d de %s: ",i+1, aluno->nome);
        scanf("%f", &aluno->vetor_notas[i]);
    }

}

int main(){ 

    int N,M;

    Aluno *aluno;
    

    printf("Digite a quantidade de alunos: ");
    scanf("%d", &N);
    
    aluno = (Aluno*) malloc(sizeof(Aluno) * N);
    
    for(int i = 0;i < N;i++){
        preenche_aluno(&aluno[i]);
    }

    for(int i = 0;i < N; i++){
        float media_aluno;

        media_aluno = media(aluno[i].vetor_notas, aluno[i].M);
        printf("Media do Aluno %s: %.2f", aluno[i].nome, media_aluno);
    }

    
    printf("\n");
    return 0;
}