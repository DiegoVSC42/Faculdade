#include <stdio.h>
#include <stdlib.h>
#include <time.h>


long long int *aloca_vetor(long long int x)
{
    long long int *vetor;
    vetor = (long long int *)calloc(x, sizeof(long long int));
    long long int i, sorteado, aux;

    for (i = 0; i < x; i++)
    {
        vetor[i] = i + 1;
    }

    for (i = 0; i < x; i++)
    {
        sorteado = rand() % x;
        aux = vetor[i];
        vetor[i] = vetor[sorteado];
        vetor[sorteado] = aux;
    }
    return vetor;
}

void mostrar(long long int *vet, long long int tam)
{
    int i;

    printf("\n Vetor: ");
    for (i = 0; i < tam; i++)
    {
        printf(" %lld", vet[i]);
    }
}

void insertion( long long int *piItem, int iQtdElementos ){

    register int i,j,iAux;

    for(i = 1; i < iQtdElementos; i++){
        iAux = piItem[i];
        for( j = i - 1; j >= 0 && iAux < piItem[j]; j--){

            piItem[j+1]=piItem[j];
        
        }
        piItem[j+1]=iAux; 
    }

    return;
}

int main()
{
    clock_t t1, t2;
    srand(time(NULL));
    long long int tam;
    long long int *vet;
    FILE * arq;

    arq = fopen("tempos.csv","w");

    if (arq==NULL)
    {
        printf("\n Problemas com arquivo");
        return 0;
    }

    for (tam = 10000; tam <= 100000; tam = tam + 1000)
    {
        vet = aloca_vetor(tam);
        // printf("\n Desordenado: ");
        // mostrar(vet, tam);
        t1 = clock();
        insertion(vet,tam);
        t2 = clock();
        // printf("\n Ordenado: ");
        // mostrar(vet, tam);
        double diff = (((double)t2 - (double)t1) / 1000000.0);
        printf("\n  Tamanho %lld Tempo gasto: %f",tam, diff);
        fprintf(arq,"%lld;%f\n",tam, diff);
        free(vet);
    }
    fclose(arq);

    printf("\n");
    return 0;
}