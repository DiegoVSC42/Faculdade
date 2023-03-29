#include <stdio.h>
#include <stdlib.h>

typedef struct Aluno{

    char nome[20];
    int matricula;
    float M;
    float *nota;
    int qtd_nota;
    float media;
    
} Aluno;

void le_aluno(Aluno *aluno, int qtd_alunos){

    for(int i = 0; i < qtd_alunos;i++){
        
        printf("Digite o nome do aluno %d\n", i+1);
        scanf("%s", aluno[i].nome);
        printf("Digite a matricula do aluno %d\n", i+1);
        scanf("%d", aluno[i].matricula);
        printf("Digite a quantidade de notas do aluno %d\n", i+1);
        scanf("%d", &aluno[i].M);

    }

    aluno->qtd_nota = (int) malloc(aluno->M * sizeof(float));

    for(int j = 0;j < qtd_alunos;j++){
        for(int i =0;i < aluno[j].qtd_nota;i++){
            printf("Digite a nota %d do aluno: ", i+1);
            scanf("%f",aluno[j].nota[i]);
        }
    }    
}

float calcular_media(float *notas, float M){

    float media;
    int qtd_notas = 0;

    for(int i = 0;i < M;i++){
        if(i != '\0'){
            media = (notas[i] + notas[i+1]);
            qtd_notas++;
        }
    }
    return media/qtd_notas;
}

void mostrar_alunos(Aluno *aluno){

    int N;
    int *tam;

    tam = (int*) malloc(N * sizeof(int));
    for(int i = 0; i < N; i++){
        printf("\nNome: %s", aluno[i].nome);
        printf("\nMedia: %.1f", aluno[i].media);

    }
    printf("\n");
}

int main(){

    int *qtd_alunos, N;
    printf("Digite a quantidade de alunos: ");
    scanf("%d", &N);

    qtd_alunos = (int*) malloc(N * sizeof(int));

    Aluno aluno;

    for(int i = 0;i < N;i++){
        aluno.media = calcular_media(aluno.nota, aluno.M);
    }

    le_aluno(&aluno, *qtd_alunos);

    mostrar_alunos(&aluno);


    return 0;
}