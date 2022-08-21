#include<stdio.h>
#include<stdlib.h>

typedef struct Arvore{

    int qtd_elementos;
    struct No *raiz;

}Arvore;

typedef struct No{
    
    int valor;
    int qtd;
    struct No *menor;
    struct No *maior;

}No;

Arvore *aloca_arvore(){

    Arvore *nova;
    nova = (Arvore *)calloc(1, sizeof(Arvore));
    return nova;

}

No *aloca_no(){

    No *novo;
    novo = (No *)calloc(1, sizeof(No));
    return novo;

}
void insere_arvore(Arvore *arvore, int valor){

    No *novo, *aux;
    novo = aloca_no();
    novo->valor = valor;
    novo->qtd = 1;

        int Valor_inserido = 0;

    if (arvore->raiz == NULL){

        arvore->raiz = novo;
        arvore->qtd_elementos++;
    
    }else{
        aux = arvore->raiz;
        while (!Valor_inserido){

            if (aux->valor == valor){

                aux->qtd++;
                return;
            
            }else{
                if(valor < aux->valor){
                    if (aux->menor == NULL){

                        aux->menor = novo;
                        Valor_inserido = 1;
                        arvore->qtd_elementos++;
                    
                    }else{
                        
                        aux = aux->menor;
                    
                    }
                }else{

                    if(aux->maior == NULL){

                        aux->maior = novo;
                        Valor_inserido = 1;
                        arvore->qtd_elementos++;
                    
                    }else{

                        aux = aux->maior;
                    
                    }
                }
            }
        }
    }
}

int verifica_primo(int valor){

    for(int i = 2; i < valor; i++){
        if(valor % i == 0){
            return 0;
        }
    }

    return 1;
}

void qtd_primos(No * no, No *aux){

    if (no==NULL){
        return;
    }
    qtd_primos(no->menor, aux);
    qtd_primos(no->maior, aux);

    if(verifica_primo(no->valor)){

        aux->valor++;
    
    }

}


int main(){

    Arvore *arvore;
    No *no;
    no = aloca_no();
    
    arvore = aloca_arvore();
    insere_arvore(arvore,3);//primo
    insere_arvore(arvore,1);//primo
    insere_arvore(arvore,2);//primo
    insere_arvore(arvore,7);//primo
    insere_arvore(arvore,5);//primo
    insere_arvore(arvore,9);
    insere_arvore(arvore,15);
    insere_arvore(arvore,4);
    insere_arvore(arvore,14);
    insere_arvore(arvore,17);//primo
    insere_arvore(arvore,19);//primo
    insere_arvore(arvore,23);//primo
    insere_arvore(arvore,29);//primo
    insere_arvore(arvore,31);//primo
    insere_arvore(arvore,6);
    insere_arvore(arvore,8);
    insere_arvore(arvore,10);
    insere_arvore(arvore,12);
    insere_arvore(arvore,13);//primo
    insere_arvore(arvore,11);//primo
    insere_arvore(arvore,37);//primo
    insere_arvore(arvore,41);//primo
    insere_arvore(arvore,43);//primo
    qtd_primos(arvore->raiz, no);
    printf("\nQuantidade de primos: %d", no->valor);
    printf("\n");

    return 0;
}


