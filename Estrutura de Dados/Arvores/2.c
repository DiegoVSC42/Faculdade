//Cosntrua uma funcao que receba por parametro o no raiz de uma arvore e retorne quantos numeros primos há nessa arvore

#include<stdio.h>
#include<stdlib.h>

typedef struct Arvore{

    int qtd_elementos;
    struct No *raiz;

}Arvore;

typedef struct No{
    int valor;
    int qtd;
    struct No *esquerda;
    struct No *direita;
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
void preenche_arvore(Arvore *arvore, int valor){

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
                    if (aux->esquerda == NULL){

                        aux->esquerda = novo;
                        Valor_inserido = 1;
                        arvore->qtd_elementos++;
                    
                    }else{
                        
                        aux = aux->esquerda;
                    
                    }
                }else{

                    if(aux->direita==NULL){

                        aux->direita = novo;
                        Valor_inserido=1;
                        arvore->qtd_elementos++;
                    
                    }else{

                        aux = aux->direita;
                    
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

void qtd_primos(No * a, No *aux){

    if (a==NULL){
        return;
    }
    qtd_primos(a->esquerda, aux);
    qtd_primos(a->direita, aux);

    if(verifica_primo(a->valor)){
        aux->valor++;
    }

}


int main(){

    Arvore *arvore;
    No *no;
    no = aloca_no();
    
    arvore = aloca_arvore();
    preenche_arvore(arvore,3);
    preenche_arvore(arvore,5);
    preenche_arvore(arvore,2);
    preenche_arvore(arvore,1);
    preenche_arvore(arvore,7);
    preenche_arvore(arvore,9);
    preenche_arvore(arvore,15);
    preenche_arvore(arvore,17);
    preenche_arvore(arvore,19);
    preenche_arvore(arvore,4);
    preenche_arvore(arvore,6);
    preenche_arvore(arvore,8);
    preenche_arvore(arvore,10);
    preenche_arvore(arvore,12);
    preenche_arvore(arvore,13);
    preenche_arvore(arvore,11);
    
    qtd_primos(arvore->raiz, no);
    printf("\nQuantidade de primos: %d", no->valor);
    printf("\n");
  return 0;
}


