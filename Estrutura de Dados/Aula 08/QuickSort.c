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
void quicksort(long long int *item, long long int left, long long int right){
        
    long long int i,j;
    long long int x,y;
    i = left;
    j = right;
    x = item [ (left+right)/2 ];

    do{
        while(item[i] < x && i < right){
            i++;
        }
        while(x < item[j] && j > left){
            j--;
        }
        if(i<=j){
            y = item[i];         
            item[i] = item[j];
            item[j] = y;
            i++;
            j--; 
        }
    }while(i <= j);

    if(left < j ){
    
        quicksort(item, left, j);
    
    }
    if(i < right ){

        quicksort(item, i, right);
    
    }
    return ;
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

    for (tam = 100000; tam <= 1000000; tam = tam + 10000)
    {
        vet = aloca_vetor(tam);
        //printf("\n Desordenado: ");
        //mostrar(vet, tam);
        t1 = clock();
        quicksort(vet,0, tam);
        t2 = clock();
        //printf("\n Ordenado: ");
        //mostrar(vet, tam);
        double diff = (((double)t2 - (double)t1) / 1000000.0);
        printf("\n  Tamanho %lld Tempo gasto: %f",tam, diff);
        fprintf(arq,"%lld;%f\n",tam, diff);
        free(vet);
    }
    fclose(arq);

    printf("\n");
    return 0;
}