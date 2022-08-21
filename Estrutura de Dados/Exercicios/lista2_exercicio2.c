//2 ) Faça um programa que leia do usuário um número N positivo e construa uma lista ligada de alunos. Cada aluno possui
//    nome, matricula e media final. Disponibilize ao usuários as seguintes opções:
//    a) Inserir aluno na lista
//    b) Mostrar alunos aprovados
//    c) Mostrar alunos reprovados
//    d) Remover aluno da lista.
//    Obs. É considerado um aluno aprovado aquele que conter média final >=5.0;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Lista{

    int qtd;
    struct Registro *inicio;
    struct Registro *fim;

}Lista;

typedef struct Registro{

    char nome[30];
    long int matricula;
    float media;
    struct Registro *ant;
    struct Registro *prox;

}Registro;

Lista *aloca_lista(){

    Lista *novo;
    novo = (Lista*)calloc(1,sizeof(Lista));
    return novo;
}

Registro *aloca_registro(){

    Registro *novo;
    novo = (Registro*)calloc(1,sizeof(Registro));
    return novo;

}
void inserir_aluno(Lista *lista){

    Registro *novo, *aux;
    novo = aloca_registro();
    printf("\nDigite o nome do aluno: ");
    fflush(stdin);
    fgets(novo->nome,29,stdin);
    printf("Digite a matricula do aluno: ");
    scanf("%ld", &novo->matricula);
    printf("Digite a media do aluno: ");
    scanf("%f", &novo->media);
    
    if(lista->inicio == NULL){
        
        lista->inicio = novo;
        lista->fim = novo;

    }else{
        
        lista->fim->prox = novo;
        novo->ant = lista->fim;
        lista->fim = novo;

    }
    lista->qtd++;
}
void mostrar_aluno_apr(Lista *lista){

    Registro *aux;

    if(lista->inicio == NULL){
        printf("\nLista vazia");
        return;
    }else{
        
        aux = lista->inicio;
        
        while(aux != NULL){

            if(aux->media >= 5){
                printf("Nome: %s", aux->nome);
            }
            aux = aux->prox;


        }
    }
}
void mostrar_aluno_rep(Lista *lista){

    Registro *aux;

    if(lista->inicio == NULL){
        printf("\nLista vazia");
        return;
    }else{
        
        aux = lista->inicio;
        
        while(aux != NULL){

            if(aux->media < 5){
                printf("Nome: %s", aux->nome);
            }
            aux = aux->prox;


        }
    }
}

int remove_aluno(Lista *lista, int matricula){

    Registro *aux = NULL;

    if(lista->inicio == NULL || lista->fim == NULL){
        return 0;
    }
    aux = lista->inicio;
    while(aux != NULL){
        if(aux->matricula == matricula){
            if(aux->ant == NULL){
                lista->inicio = aux->prox;
            
            }else{
                
                if(aux->prox == NULL){
                    lista->fim = aux->ant;
                    aux->ant->prox = NULL;
                }else{
                    aux->ant->prox = aux->prox;
                }
            }
            lista->qtd--;
            free(aux);
            return 1;
        }
        aux->ant = aux;
        aux = aux->prox;
    }
    return 0;
}

void menu(Lista *lista){
    
    int opcao,matricula;
    
    do{
        
        printf("\nEscolha uma opcao:");
        printf("\n1 - Inserir aluno na lista");
        printf("\n2 - Mostrar alunos aprovados");
        printf("\n3 - Mostrar alunos reprovados");
        printf("\n4 - Remover aluno da lista.");
        printf("\n5 - Sair");
        printf("\nOpcao: ");
        scanf("%d", &opcao);

        switch (opcao){

            case 1:
                inserir_aluno(lista);
                break;
            case 2:
                printf("\n");
                mostrar_aluno_apr(lista);
                break;
            case 3:
                printf("\n");
                mostrar_aluno_rep(lista);
                break;
            case 4:
                printf("Digite a Matricula do aluno a ser removido: ");
                scanf("%d", &matricula);

                if(remove_aluno(lista,matricula)){
                    printf("\nAluno removido com sucesso");
                }else{
                    printf("\nAluno nao encontrado ou lista vazia");
                }
                printf("\n");
                break;
            case 5:
                printf("\nSaindo do programa");
                break;
            default:
                printf("\nOpcao invalida");
                break;
        }
    }while (opcao != 5);

}

int main(){

    Lista *lista;
    lista = aloca_lista();
    menu(lista);

    printf("\n");
    return 0;
}