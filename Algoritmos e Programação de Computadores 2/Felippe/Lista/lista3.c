#include <stdio.h>
#include <stdlib.h>

typedef struct Aluno{

    char nome[20];
    int numero_matricula;
    char curso[20];

} Aluno;

void le_aluno(Aluno *aluno){

    for(int i = 0; i < 5;i++){
        
        printf("Digite o nome do aluno %d\n", i+1);
        scanf("%s", aluno[i].nome);
        printf("Digite o numero de matricula do aluno %d\n", i+1);
        scanf("%d", &aluno[i].numero_matricula);
        printf("Digite o nome do curso do aluno %d\n", i+1);
        scanf("%s", aluno[i].curso);

    }
}
void imprime_aluno(Aluno *aluno){
    
    for(int i = 0; i < 5;i++){
        printf("Nome do aluno %d: %s\n", i+1, aluno[i].nome);
        printf("Matricula do aluno %d: %d\n", i+1, aluno[i].numero_matricula);
        printf("Curso do aluno %d: %s\n", i+1, aluno[i].curso);
        printf("\n");
    }

}

int main(){

    Aluno aluno[5];

    le_aluno(aluno);
    imprime_aluno(aluno);


    return 0;
}