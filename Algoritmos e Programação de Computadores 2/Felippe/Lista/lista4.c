/*4. Crie uma estrutura representando os alunos de um determinado curso. A estrutura deve
conter a matrı́cula do aluno, nome, nota da primeira prova, nota da segunda prova e nota
da terceira prova.
(a) Permita ao usuário entrar com os dados de 5 alunos.
(b) Encontre o aluno com maior nota da primeira prova.
(c) Encontre o aluno com maior média geral.
(d) Encontre o aluno com menor média geral
(e) Para cada aluno diga se ele foi aprovado ou reprovado, considerando o valor 6 para
aprovação.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Aluno{

    char nome[20];
    int numero_matricula;
    float nota1;
    float nota2;
    float nota3;
    float media;

} Aluno;

void le_aluno(Aluno *aluno){

    for(int i = 0; i < 5;i++){
        
        printf("Digite o nome do aluno %d\n", i+1);
        scanf("%s", aluno[i].nome);
        printf("Digite o numero de matricula do aluno %d\n", i+1);
        scanf("%d", &aluno[i].numero_matricula);
        printf("Digite a nota 1 do aluno %d\n", i+1);
        scanf("%f", &aluno[i].nota1);
        printf("Digite a nota 2 do aluno %d\n", i+1);
        scanf("%f", &aluno[i].nota2);
        printf("Digite a nota 3 do aluno %d\n", i+1);
        scanf("%f", &aluno[i].nota3);
        printf("\n");
    }

}

void maior_nota1(Aluno *aluno){
    
    Aluno verificador;

    for (int i = 0; i < 5; i++){
        if(aluno[i].nota1 > verificador.nota1){
            verificador = aluno[i];
        }
    }
    for(int i = 0; i < 5; i++){
        if(aluno[i].nota1 == verificador.nota1){
            printf("\n");
            printf("O aluno %s tem a maior nota 1 da turma\n", aluno[i].nome);
            printf("\n");
        }
    }
}

void calcular_media(Aluno *aluno){

    for(int i = 0; i < 5; i++){
        aluno[i].media = (aluno[i].nota1 + aluno[i].nota2 + aluno[i].nota3)/3;
    }

}

void maior_media(Aluno *aluno){
    
    Aluno verificador;
    verificador.media = 0;

    for(int i = 0;i < 5; i++){
        if(aluno[i].media > verificador.media){
            verificador = aluno[i];
        }
    }
    for(int i = 0; i < 5; i++){
        if(aluno[i].media == verificador.media){
            printf("\n");
            printf("O aluno %s tem a maior media da turma\n", aluno[i].nome);
            printf("\n");
        }
    }
}

void menor_media(Aluno *aluno){
    
    Aluno verificador;
    verificador.media = 10;

    for(int i = 0;i < 5; i++){
        if(aluno[i].media < verificador.media){
            verificador = aluno[i];
        }
    }
    for(int i = 0; i < 5; i++){
        if(aluno[i].media == verificador.media){
            printf("\n");
            printf("O aluno %s tem a menor media da turma\n", aluno[i].nome);
            printf("\n");
        }
    }
}

void aprovacao(Aluno *aluno){
    
    printf("Os alunos aprovados sao:\n");
    for(int i = 0;i < 5; i++){
        if(aluno[i].media >= 6){
            printf ("%s\n", aluno[i].nome);
        }
    }
    printf("Os alunos reprovados sao:\n");
    for(int i = 0;i < 5; i++){
        if(aluno[i].media < 6){
            printf ("%s\n", aluno[i].nome);
        }
    }
    printf("\n");
}
void imprimir_tela(){

    printf("opcao uma das seguintes opcoes: \n");
    printf("1 - Inserir dados de 5 alunos \n");
    printf("2 - Encontrar o aluno com maior nota da primeira prova\n");
    printf("3 - Encontrar o aluno com maior media geral \n");
    printf("4 - Encontrar o aluno com menor media geral \n");
    printf("5 - Verificar quais alunos foram aprovados \n");
    printf("0 - Para finalizar o programa \n");

}   

int main(){

    int opcao;
    Aluno aluno[5];

    do{
        
        imprimir_tela();
        scanf("%d", &opcao);
        
        if(opcao == 1){
            
            le_aluno(aluno);    
            calcular_media(aluno);
        
        }else if(opcao == 2 ){

            maior_nota1(aluno);

        }else if (opcao == 3){

            maior_media(aluno);

        }else if(opcao == 4){
            
            menor_media(aluno);

        }else if (opcao == 5){

            aprovacao(aluno);

        }else if (opcao < 0 || opcao > 5){
            printf("\nopcao invalida");
            printf("\n");
        }

    }while (opcao != 0);
}