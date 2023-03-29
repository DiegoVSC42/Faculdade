#include <stdio.h>
#include <stdlib.h>
#define TAM 5

typedef struct Pilha{

    int qtd;
    struct Registro *inicio;
    struct Registro *fim;

}Pilha;


typedef struct Registro{

    int valor[TAM];
    Struct Registro *prox;
    struct Registro *ant;
    

}Registro;
void inicia_pilha(Pilha *pilha){

    pilha->topo = -1;

}
//empty
int empty(Pilha *pilha){

    if(pilha->topo == -1){
       
        return 1;

    }else{

        return 0;
    }
}

int pilha_cheia(Pilha *pilha){

    if(pilha->topo == TAM-1){
        return 1;
    }else{
        return 0;
    }
}
//push
void insere_pilha(Pilha *pilha, int valor){

    int aux;

    if(pilha_cheia(pilha)){
        printf("\nErro: Pilha cheia");
    }else{
        pilha->topo++;
        pilha->valor[pilha->topo] = valor;
    }

}
//pop
int remove_pilha(Pilha *pilha){

    int aux;

    if(pilha_vazia(pilha)){
        printf("\nErro: Pilha vazia");
    }else{
        aux = pilha->valor[pilha->topo];
        pilha->topo--;
        return aux;
    }
}

void mostrar_pilha(Pilha *pilha){



    for(int i = pilha->topo; i >= 0 ; i--){
        printf("\nValor: %d", pilha->valor[i]);
    }

}
//size_da_pilha
int tamanho_pilha(Pilha *pilha){
    return pilha->topo;
}
//stackpop
int valor_no_topo(Pilha *pilha){
    return pilha->valor[pilha->topo];
}

int main(){

    int opcao,valor;
    Pilha *pilha;
    pilha = (Pilha*)calloc(1,sizeof(Pilha));
    inicia_pilha(pilha);

    do{
        printf("\nEscolha uma opcao:");
        printf("\n1 - Inserir valor na pilha:");
        printf("\n2 - Remover valor da pilha:");
        printf("\n3 - Mostrar pilha:");
        printf("\n4 - Verificar se a pilha esta vazia:");
        printf("\n5 - Verificar se a pilha esta cheia:");
        printf("\n6 - Verificar tamanho da pilha:");
        printf("\n7 - Verificar qual o valor do topo:");
        printf("\n8 - Sair:");
        printf("\nOpcao desejada: ");
        scanf("%d", &opcao);

        switch (opcao){

            case 1:
                printf("\nDigite o valor que deseja inserir: ");
                scanf("%d", &valor);
                insere_pilha(pilha,valor);
                printf("\n");
                break;
            case 2:
                if(pilha_vazia(pilha)){
                    printf("\nPilha vazia");
                }else{
                    printf("\nO valor %d foi removido com sucesso.", remove_pilha(pilha));
                }
                printf("\n");
                break;
            case 3:
                mostrar_pilha(pilha);
                printf("\n");
                break;
            case 4:
                if(pilha_vazia(pilha)){
                    printf("\nA pilha esta vazia");
                }else{
                    printf("\nA pilha nao esta vazia");
                }
                printf("\n");
                break;
            case 5:
                if(pilha_cheia(pilha)){
                    printf("\nA pilha esta cheia");
                }else{
                    printf("\nA pilha nao esta cheia");
                }
                printf("\n");
                break;
            case 6:
                printf("\nTamanho da pilha: %d", tamanho_pilha(pilha)+1);
                printf("\n");
                break;
            case 7:
                if(pilha_vazia(pilha)){
                    printf("\nA pilha esta vazia");
                }else{
                    printf("\nValor do topo: %d", valor_no_topo(pilha));
                }
                printf("\n");
                break;
            default:
                printf("\nSaindo do programa");
                printf("\n");   
                break;  
        }
        

    }while(opcao != 8);

    printf("\n");
    return 0;

}

