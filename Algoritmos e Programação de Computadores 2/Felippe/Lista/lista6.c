    /*6. Faça um programa que realize a leitura dos seguintes dados relativos a um conjunto de
alunos: Matricula, Nome, Código da Disciplina, Nota1 e Nota2. Considere uma turma de
até 10 alunos. Após ler todos os dados digitados, e depois de armazená-los em um vetor
de estrutura, exibir na tela a listagem final dos alunos com as suas respectivas médias
finais (use uma média ponderada: Nota1 com peso=1.0 e Nota2 com peso=2.0).*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Aluno{

    char nome[20];
    int numero_matricula;
    int codigo_disc;
    float nota1;
    float nota2;

} Aluno;

void le_aluno(Aluno *aluno){

    for(int i = 0; i < 10;i++){
        
        printf("Digite o nome do aluno %d\n", i+1);
        scanf("%s", aluno[i].nome);
        printf("Digite o numero de matricula do aluno %d\n", i+1);
        scanf("%d", &aluno[i].numero_matricula);
        printf("Digite o codigo da disciplina do aluno %d\n", i+1);
        scanf("%d", &aluno[i].codigo_disc);
        printf("Digite a nota 1 do aluno %d\n", i+1);
        scanf("%f", &aluno[i].nota1);
        printf("Digite a nota 2 do aluno %d\n", i+1);
        scanf("%f", &aluno[i].nota2);
        printf("\n");

    }

}

void calcular_media(float *media, Aluno *aluno){

    for(int i = 0;i < 10;i++){
        media[i] = (aluno[i].nota1 + (aluno[i].nota2 * 2))/2;
    }
}

void mostrar_alunos(Aluno *aluno){

    float media[10];

    calcular_media(media, aluno);
    for(int i = 0; i < 10; i++){
        printf("\nNome: %s", aluno[i].nome);
        printf("\nMedia: %.1f", media[i]);

    }
    printf("\n");
}

int main(){

    Aluno aluno;

    le_aluno(&aluno);
    mostrar_alunos(&aluno);


    return 0;
}