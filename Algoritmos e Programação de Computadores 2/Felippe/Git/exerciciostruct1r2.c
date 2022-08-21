#include <stdio.h>
#include <stdlib.h>


// complete as funções restantes!

typedef struct aluno
{
   int matricula;
   float notas[3];

}aluno;

void LeAluno (aluno * usuario){
    printf("\nEscreva a matricula do aluno : ");
    scanf("%d", &usuario->matricula);
    printf("\n Digite a nota 1 do aluno :");
    scanf("%f", &usuario->notas[0]);
    printf("\n Digite a nota 2 do aluno :");
    scanf("%f", &usuario->notas[1]);
    printf("\n Digite a nota 3 do aluno :");
    scanf("%f", &usuario->notas[2]);
}

void ImprimeTurma (aluno usuario){
    printf("\n");
    printf("\n Matricula do aluno : %d", usuario.matricula);
    printf("\n Nota 1 do aluno : %.1f", usuario.notas[0]);
    printf("\n Nota 2 do aluno : %.1f", usuario.notas[1]);
    printf("\n Nota 3 do aluno : %.1f", usuario.notas[2]);
    printf("\n");
}

float CalculaMediaAluno(aluno valor){
    float media;
    media = (valor.notas[0] + valor.notas[1] + valor.notas[2])/3;
    return media;
}

int main()
{
    int i;
    aluno Turma[5];

    for(i=0; i< 5; i++){
        LeAluno(&Turma[i]);
        // LeAluno(.......);  // função que lê de teclado
        //                    // os dados do aluno
    }
    for(i=0; i< 5; i++){
        ImprimeTurma(Turma[i]);
    }
    
    // ImprimeTurma(Turma); Função que imprime os dados de todos os alunos


    for(i=0; i< 5; i++){

        float media;

        media = CalculaMediaAluno(Turma[i]);
        // media = CalculaMediaAluno(.......);// função que calcula a média das notas de um aluno
                                             
        printf("Aluno %d  - Media = %.1f\n", i+1, media); // imprime os dados do aluno

    }
    return 0;
}