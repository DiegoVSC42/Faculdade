#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 30

typedef struct Pilha{

    char valor[TAM];
    int topo;

}Pilha;

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

int full(Pilha *pilha){

    if(pilha->topo == TAM-1){
        return 1;
    }else{
        return 0;
    }
}
int verifica_validez(Pilha *pilha){

    int qtd_par1 = 0,qtd_par2 = 0;
    int qtd_col1 = 0,qtd_col2 = 0;
    int qtd_cha1 = 0,qtd_cha2 = 0;
    int verif_par = 0,verif_col = 0,verif_cha = 0;
    printf("\nPilha topo: %c", pilha->valor[pilha->topo]);  
    for(int i = 0; i <= pilha->topo ; i++){
        if(pilha->valor[i] == '('){
            qtd_par1++;
        }
        if(pilha->valor[i] == ')'){
            qtd_par2++;
        }
        if(pilha->valor[i] == '['){
            qtd_col1++;
        }
        if(pilha->valor[i] == ']'){
            qtd_col2++;
        }
        if(pilha->valor[i] == '{'){
            qtd_cha1++;
        }
        if(pilha->valor[i] == '}'){
            qtd_cha2++;
        }
    }

    printf("\n(: %d",qtd_par1);
    printf("\n): %d",qtd_par2);
    printf("\n[: %d",qtd_col1);
    printf("\n]: %d",qtd_col2);
    printf("\n{: %d",qtd_cha1);
    printf("\n}: %d",qtd_cha2);

    if(qtd_cha1 == qtd_cha2 && qtd_par1 == qtd_par2 && qtd_col1 == qtd_col2){
        for(int i = pilha->topo; i >= 0 ; i--){
            if(pilha->valor[i] == ')'){
                if(pilha->valor[i-1] == '('){
                    verif_par++;
                }
            }        
            if(pilha->valor[i] == ']'){
                if(pilha->valor[i-1] == '['){
                    verif_cha++;
                }
            } 
            if(pilha->valor[i] == '}'){
                if(pilha->valor[i-1] == '{'){
                    verif_col++;
                }
            }
        }
            
        printf("\nVerificador (: %d",verif_par);
        printf("\nVerificador [: %d",verif_cha);
        printf("\nVerificador {: %d",verif_col);
        if(verif_par > 0 && verif_col > 0 && verif_cha > 0){
            return 1;
        }
    }
    return 0;

}
//push
void push(Pilha *pilha, char valor){

    if(full(pilha)){
        printf("\nErro: Pilha cheia");
    }else{
        if(valor == '(' || valor == '[' || valor == '{' || valor == ')' || valor == ']' || valor == '}' ){
            pilha->topo++;
            pilha->valor[pilha->topo] = valor;
        }
    }

}
//pop
char pop(Pilha *pilha){

    char aux;

    if(empty(pilha)){
        printf("\nErro: Pilha vazia");
    }else{
        aux = pilha->valor[pilha->topo];
        pilha->topo--;
    }
    return aux;
}

void show(Pilha *pilha){

    for(int i = pilha->topo; i >= 0 ; i--){
        printf("\nValor: %c", pilha->valor[i]);
    }

    printf("\n");

}
//size_da_pilha
int size(Pilha *pilha){
    return pilha->topo;
}
//stacktop
int stacktop(Pilha *pilha){
    return pilha->valor[pilha->topo];
}

int main(){

    int opcao,valor,n;
    char nome[TAM];
    Pilha *pilha;
    pilha = (Pilha*)calloc(1,sizeof(Pilha));
    inicia_pilha(pilha);
    printf("\nDigite a palavra a ser empilhada: ");
    scanf("%s", nome);
    printf("%s", nome);
    for(int i = 0; i < strlen(nome) ; i++){
        push(pilha,nome[i]);
    }
    show(pilha);
    if(!verifica_validez(pilha)){
        printf("\nOperacao invalida");
    }else{
        printf("\nOperacao valida");
    }
    //(A+B)-{C+D}-[F+G]


    printf("\n");
    return 0;

}

