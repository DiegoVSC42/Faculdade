/*
2 ) Faça um programa que leia do usuário um número N positivo e construa uma lista ligada de alunos. Cada aluno possui
    nome, matricula e media final. Disponibilize ao usuários as seguintes opções:
    a) Inserir aluno na lista
    b) Mostrar alunos aprovados
    c) Mostrar alunos reprovados
    d) Remover aluno da lista.
    Obs. É considerado um aluno aprovado aquele que conter média final >=5.0;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Lista{
    
    int qtd;
    struct Registro *inicio;

}Lista;

typedef struct Registro{

    char nome[30];
    long int matricula;
    float media;
    struct Registro*prox;

}Registro;

Lista *aloca_lista(){

    Lista *novo;
    novo = (Lista *)malloc(sizeof(Lista));
    novo->qtd = 0;
    novo->inicio = NULL;
    return novo;

}

Registro *aloca_registro(){

    Registro *novo;
    novo = (Registro *)malloc(sizeof(Registro));
    strcpy(novo->nome, "\0");
    novo->matricula = 0;
    novo->media = 0.0;
    novo->prox = NULL;
    return novo;

}

void incluir_no_final(Lista *lista, Registro aluno){


    Registro *novo, *auxiliar;
    novo = aloca_registro();
    strcpy(novo->nome, aluno.nome);
    novo->matricula = aluno.matricula;
    novo->media = aluno.media;

    if (lista->inicio == NULL){
        
        lista->inicio = novo;
    
    }else{

        auxiliar = lista->inicio;

        while(auxiliar->prox != NULL){

            auxiliar = auxiliar->prox;

        }

        auxiliar->prox = novo;
        
    }

    lista->qtd++;

}
void mostrar_aluno(Registro aluno){
    
    printf("\n      Nome: %s", aluno.nome);
    printf("\n      Matricula: %ld", aluno.matricula);
    printf("\n      Media: %.2f", aluno.media);
    printf("\n");

}

void mostrar_lista(Lista *lista){

    Registro *auxiliar;

    if (lista->inicio == NULL){

        printf("\n lista vazia");
    
    }else{

        auxiliar = lista->inicio;

        while (auxiliar != NULL){
            
            mostrar_aluno(*auxiliar);
            auxiliar = auxiliar->prox;
        
        }
    }
}

void mostrar_aprovacao(Lista *l, int aprovados)
{
    Registro *aux;

    if (l->inicio == NULL)
    {
        printf("\n lista vazia");
    }
    else
    {
        aux = l->inicio;

        while (aux != NULL)
        {
            if (aprovados)
            {
                if (aux->media >= 5.0)
                {
                    mostrar_aluno(*aux);
                }
            }
            else
            {
                if (aux->media < 5.0)
                {
                    mostrar_aluno(*aux);
                }

            }
            aux = aux->prox;
        }
    }
}
int remover_aluno(Lista *l, int matricula)
{
    if (l->inicio == NULL)
    {
        return 0;
    }

    Registro *aux = NULL, *ant = NULL;

    aux = l->inicio;
    while (aux != NULL)
    {
        
        if (aux->matricula == matricula)
        {
            
            if (ant == NULL)
            {
                l->inicio = aux->prox;
            }
            else
            {
                ant->prox = aux->prox;
            }
            l->qtd--;
            free(aux);
            return 1;
        }
        ant = aux;
        aux = aux->prox;
    }

    return 0;
}


void recebe_aluno(Registro *aluno){

    printf("\nDigite o nome do aluno: ");
    scanf("%s", aluno->nome);
    printf("\nDigite a matricula do aluno: ");
    scanf("%ld", &aluno->matricula);
    printf("\nDigite a media final do aluno: ");
    scanf("%f", &aluno->media);
    printf("\n");

}


void menu(Lista *lista){

    int opcao, numero;
    Registro aluno;

    do{
      
        printf("\n 1 - Inserir na lista");
        printf("\n 2 - Mostrar alunos aprovados");
        printf("\n 3 - Mostrar alunos reprovados");
        printf("\n 4 - Remover aluno");
        printf("\n");
        scanf("%d", &opcao);

        switch (opcao){

        case 1:
            recebe_aluno(&aluno);
            incluir_no_final(lista, aluno);
            break;
        case 2:
            mostrar_aprovacao(lista,1);
            break;
        case 3:
            mostrar_aprovacao(lista,0);
            break;
        case 4:
            printf("\n Digite a matricula do aluno que deseja remover na lista: ");
            scanf("%d", &numero);
            
            if(remover_aluno(lista, numero)){

                printf("\nRemovido com sucesso");
            
            }else{

                printf("\nLista vazia ou aluno nao esta na lista");

            }

        case 5:
            printf("\n Saindo do programa");
            break;
        default:
            printf("\n opcao invalida");
            break;
        }
    } while (opcao != 5);
}

int main(){

    Lista *lista;

    lista = aloca_lista();

    menu(lista);


}

