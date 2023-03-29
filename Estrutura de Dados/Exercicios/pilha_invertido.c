#include <stdio.h>
#include <stdlib.h>
#define tam 5

//2012082021 Luis Wagner

int contador = -1; // 0 - 4
int auxiliar_contador = -1;
int pilha[tam];
int auxiliar[tam];

int pilha_cheia(int contador_verificar) // passo parametro pra conferir o contador da pilha desejavel
{
    if (contador_verificar == tam - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int pilha_vazia(int contador_verificar) // passo parametro pra conferir o contador da pilha desejavel
{
    if (contador_verificar == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void inserir_pilha_principal(int valor)
{
    if (!pilha_cheia(contador)) // not pilha_cheia, pilha inserivel
    {
        contador++;
        pilha[contador] = valor;
    }
}

void inserir_pilha_auxiliar(int valor)
{
    if (!pilha_cheia(auxiliar_contador)) // not pilha_cheia, pilha inserivel
    {
        auxiliar_contador++;
        auxiliar[auxiliar_contador] = valor;
    }
}

int pop()
{
    if (!pilha_vazia) // not pilha vazia, pilha sem elementos
    {
        return -1;
    }

    int retorno = pilha[contador];
    pilha[contador] = 0; // resetando o valor da pilha q removemos
    contador--;
    return retorno;
}

void inverte_pilha()
{
    if (!pilha_vazia) // não se inverte pilha vazia
    {
        return;
    }


    for (int i = tam-1; i >= 0; i--) // for que itera ao contrario, ex: 4 ate 0, ou seja tamanho - 1 ate 0
    {
        int inserir = pop();
        inserir_pilha_auxiliar(inserir);
    }
}

void main()
{
    inserir_pilha_principal(3);
    inserir_pilha_principal(1);
    inserir_pilha_principal(4);
    inserir_pilha_principal(2);
    inserir_pilha_principal(5);

    for (int i = tam -1; i > -1; i--)
    {
        printf("%d\n", pilha[i]);
    }

    inverte_pilha();

    

    printf("\n\n\n");
    
    
    for(int i = tam -1; i > -1; i--){
        printf("%d\n", auxiliar[i]);
    }

    return;
}